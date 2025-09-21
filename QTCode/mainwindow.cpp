#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , allData()  // 初始化数据存储
{
    ui->setupUi(this);
    ui->radioButton->setEnabled(false);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::data_Receive);
    buffer.clear(); // 初始化缓冲区

    // 设置深蓝色背景
    this->setStyleSheet("background-color: #001a33;");  // 深蓝色背景
    // 设置主窗口中央widget的背景色
    ui->centralwidget->setStyleSheet("background-color: #001a33;");

    // 设置字体样式
    QFont font;
    font.setPointSize(15);
    font.setBold(true);  // 设置加粗

    // 应用字体到所有控件
    QList<QWidget*> widgets = {
        ui->name, ui->botelu, ui->tingzhiwei, ui->shujuwei, ui->jiaoyanwei,ui->save,
        ui->turnon, ui->radioButton, ui->scan, ui->M11, ui->M12, ui->M13, ui->M14,
        ui->M21, ui->M22, ui->M23, ui->M24, ui->M31, ui->M32, ui->M33, ui->M34,
        ui->label, ui->label_2, ui->label_3, ui->label_4, ui->label_5
    };

    // 设置字体和颜色
    for (auto widget : widgets) {
        widget->setFont(font);
        widget->setStyleSheet("color: white;");  // 设置字体颜色为白色
    }

    // 设置背景颜色为更加透明的青蓝色，并添加圆角
    QString backgroundColor = "background-color: rgba(0, 255, 255, 64); border-radius: 10px;";  // alpha值改为64
    for (auto widget : widgets) {
        widget->setStyleSheet(widget->styleSheet() + backgroundColor);  // 保持原有字体颜色并设置背景颜色和圆角
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scan_clicked()
{
    ui->name->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort com;
        com.setPort(info);
        if(com.open(QIODevice::ReadWrite))
        {
            ui->name->addItem(info.portName());
            com.close();
        }
    }
}

void MainWindow::on_turnon_clicked()
{
    if(!serial->isOpen())
    {
        serialSet();
        serial->open(QIODevice::ReadWrite);
        ui->radioButton->setChecked(true);
        ui->turnon->setText("关闭串口");
        allData.clear(); // 清空之前的数据
    }
    else if(serial->isOpen())
    {
        serial->close();
        ui->radioButton->setChecked(false);
        ui->turnon->setText("打开串口");
    }
}

void MainWindow::serialSet()
{
    serial->setPortName(ui->name->currentText());
    serial->setBaudRate(ui->botelu->currentText().toLong());
    switch (ui->tingzhiwei->currentIndex())
    {
        case 0:serial->setStopBits(QSerialPort::OneStop);break;
        case 1:serial->setStopBits(QSerialPort::OneAndHalfStop);break;
        case 2:serial->setStopBits(QSerialPort::TwoStop);break;
    }
    switch (ui->shujuwei->currentText().toLong())
    {
        case 5:serial->setDataBits(QSerialPort::Data5);break;
        case 6:serial->setDataBits(QSerialPort::Data6);break;
        case 7:serial->setDataBits(QSerialPort::Data7);break;
        case 8:serial->setDataBits(QSerialPort::Data8);break;
    }
    switch (ui->jiaoyanwei->currentIndex())
    {
        case 0:serial->setParity(QSerialPort::NoParity);break;
        case 1:serial->setParity(QSerialPort::EvenParity);break;
        case 2:serial->setParity(QSerialPort::OddParity);break;
    }
}

void MainWindow::setButtonColor(QPushButton* button, int value)
{
    // 确保数值在0-200范围内
    value = qBound(0, value, 200);

    // 计算蓝色分量（0-255）
    int blue = value * 255 / 200;

    // 设置按钮背景色（白色到蓝色渐变）
    QString style = QString(
        "QPushButton {"
        "   background-color: rgb(%1, %1, 255);"  // 从白色到蓝色渐变
        "   border: 1px solid gray;"
        "   border-radius: 3px;"
        "   padding: 2px;"
        "   color: %2;"  // 文字颜色
        "}"
        "QPushButton:pressed {"
        "   background-color: rgb(%3, %3, 200);"  // 按下时的颜色
        "}"
        ).arg(255 - blue/2)  // 背景R和G分量从255到127
         .arg(value > 2048 ? "white" : "black")  // 文字颜色
         .arg(200 - blue/3);  // 按下时的R和G分量

    button->setStyleSheet(style);
}

void MainWindow::data_Receive()
{
    // 将新数据追加到缓冲区
    buffer.append(serial->readAll());

    // 持续处理缓冲区中的数据
    while(buffer.size() >= 34)
    {
        // 检查帧头和帧尾
        // 修改后的帧检查逻辑，只验证帧头和帧尾
        if(static_cast<uint8_t>(buffer[0]) == 0x0A &&  // 帧头
           static_cast<uint8_t>(buffer[25]) == 0x0B)   // 帧尾
          {
            // 解析ADC值（连续存放，无分隔符）
            // 先计算原始值，然后进行钳位处理
            int rawP11 = static_cast<uint16_t>(buffer[1] << 8) | static_cast<uint8_t>(buffer[2]);
            int rawP12 = static_cast<uint16_t>(buffer[3] << 8) | static_cast<uint8_t>(buffer[4]);
            int rawP13 = static_cast<uint16_t>(buffer[5] << 8) | static_cast<uint8_t>(buffer[6]);
            int rawP14 = static_cast<uint16_t>(buffer[7] << 8) | static_cast<uint8_t>(buffer[8]);
            int rawP21 = static_cast<uint16_t>(buffer[9] << 8) | static_cast<uint8_t>(buffer[10]);
            int rawP22 = static_cast<uint16_t>(buffer[11] << 8) | static_cast<uint8_t>(buffer[12]);
            int rawP23 = static_cast<uint16_t>(buffer[13] << 8) | static_cast<uint8_t>(buffer[14]);
            int rawP24 = static_cast<uint16_t>(buffer[15] << 8) | static_cast<uint8_t>(buffer[16]);
            int rawP31 = static_cast<uint16_t>(buffer[17] << 8) | static_cast<uint8_t>(buffer[18]);
            int rawP32 = static_cast<uint16_t>(buffer[19] << 8) | static_cast<uint8_t>(buffer[20]);
            int rawP33 = static_cast<uint16_t>(buffer[21] << 8) | static_cast<uint8_t>(buffer[22]);
            int rawP34 = static_cast<uint16_t>(buffer[23] << 8) | static_cast<uint8_t>(buffer[24]);

            // 钳位处理：小于0时取0，大于等于0时保持原值
            P11 = clampToZero(rawP11);
            P12 = clampToZero(rawP12);
            P13 = clampToZero(rawP13);
            P14 = clampToZero(rawP14);
            P21 = clampToZero(rawP21);
            P22 = clampToZero(rawP22);
            P23 = clampToZero(rawP23);
            P24 = clampToZero(rawP24);
            P31 = clampToZero(rawP31);
            P32 = clampToZero(rawP32);
            P33 = clampToZero(rawP33);
            P34 = clampToZero(rawP34);

            // 设置字体
            QFont font;
            font.setPointSize(15);
            font.setBold(true);  // 加粗

            QVector<int> currentData;
            currentData << P11 << P12 << P13 << P14
                        << P21 << P22 << P23 << P24
                        << P31 << P32 << P33 << P34;
            // 将当前数据添加到所有数据列表中
            allData.append(currentData);

            // 更新UI显示并设置字体和颜色
            QString fontStyle = "color: white;";  // 设置字体颜色为白色

            ui->M11->setFont(font); ui->M11->setText(QString::number(P11)); ui->M11->setStyleSheet(fontStyle); setButtonColor(ui->M11, P11);
            ui->M12->setFont(font); ui->M12->setText(QString::number(P12)); ui->M12->setStyleSheet(fontStyle); setButtonColor(ui->M12, P12);
            ui->M13->setFont(font); ui->M13->setText(QString::number(P13)); ui->M13->setStyleSheet(fontStyle); setButtonColor(ui->M13, P13);
            ui->M14->setFont(font); ui->M14->setText(QString::number(P14)); ui->M14->setStyleSheet(fontStyle); setButtonColor(ui->M14, P14);

            ui->M21->setFont(font); ui->M21->setText(QString::number(P21)); ui->M21->setStyleSheet(fontStyle); setButtonColor(ui->M21, P21);
            ui->M22->setFont(font); ui->M22->setText(QString::number(P22)); ui->M22->setStyleSheet(fontStyle); setButtonColor(ui->M22, P22);
            ui->M23->setFont(font); ui->M23->setText(QString::number(P23)); ui->M23->setStyleSheet(fontStyle); setButtonColor(ui->M23, P23);
            ui->M24->setFont(font); ui->M24->setText(QString::number(P24)); ui->M24->setStyleSheet(fontStyle); setButtonColor(ui->M24, P24);

            ui->M31->setFont(font); ui->M31->setText(QString::number(P31)); ui->M31->setStyleSheet(fontStyle); setButtonColor(ui->M31, P31);
            ui->M32->setFont(font); ui->M32->setText(QString::number(P32)); ui->M32->setStyleSheet(fontStyle); setButtonColor(ui->M32, P32);
            ui->M33->setFont(font); ui->M33->setText(QString::number(P33)); ui->M33->setStyleSheet(fontStyle); setButtonColor(ui->M33, P33);
            ui->M34->setFont(font); ui->M34->setText(QString::number(P34)); ui->M34->setStyleSheet(fontStyle); setButtonColor(ui->M34, P34);

            // 移除已处理的数据包
            buffer.remove(0, 26);
        }
        else
        {
            // 如果帧头不匹配，丢弃第一个字节并继续查找
            buffer.remove(0, 1);
        }
    }
}

void MainWindow::on_save_clicked()
{
    if(allData.isEmpty()) {
        QMessageBox::information(this, "提示", "没有数据可保存");
        return;
    }

    // 使用 QFileDialog 获取保存路径
    QString fileName = QFileDialog::getSaveFileName(this,
                                                  "保存数据",
                                                  QDir::homePath() + "/data.csv",
                                                  "CSV文件 (*.csv);;所有文件 (*)");

    if(fileName.isEmpty()) {
        return; // 用户取消了保存
    }

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误",
                            QString("无法打开文件进行写入:\n%1\n错误: %2")
                            .arg(fileName)
                            .arg(file.errorString()));
        return;
    }

    QTextStream out(&file);

    // 写入UTF-8 BOM头，确保Excel能正确识别中文
    out.setGenerateByteOrderMark(true);

    // 写入表头
    out << "P11,P12,P13,P14,P21,P22,P23,P24,P31,P32,P33,P34\n";

    // 写入所有数据
    for(const auto &data : allData) {
        for(int i = 0; i < data.size(); ++i) {
            if(i != 0) out << ",";
            out << data[i];
        }
        out << "\n";
    }

    file.close();

    QMessageBox::information(this, "成功",
                           QString("共保存 %1 条数据到:\n%2")
                           .arg(allData.size())
                           .arg(fileName));
}
