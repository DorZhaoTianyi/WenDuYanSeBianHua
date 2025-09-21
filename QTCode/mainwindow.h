#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFont>
#include <QList>
#include <QVector>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_scan_clicked();
    void on_turnon_clicked();
    void on_save_clicked();
    void data_Receive();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial = new QSerialPort(this);
    QByteArray buffer; // 缓冲区用于存储接收到的数据

    // 压力值变量
    int P11 = 0;
    int P12 = 0;
    int P13 = 0;
    int P14 = 0;
    int P21 = 0;
    int P22 = 0;
    int P23 = 0;
    int P24 = 0;
    int P31 = 0;
    int P32 = 0;
    int P33 = 0;
    int P34 = 0;

    QVector<QVector<int>> allData; // 存储所有数据

    void serialSet();
    void setButtonColor(QPushButton* button, int value);

    // 内联钳位函数：小于0时取0，大于等于0时取本身
    int clampToZero(int value) {
        return (value < 0) ? 0 : value;
    }
};

#endif // MAINWINDOW_H
