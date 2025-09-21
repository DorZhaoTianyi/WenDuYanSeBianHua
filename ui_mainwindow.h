/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *name;
    QComboBox *botelu;
    QLabel *label_5;
    QComboBox *jiaoyanwei;
    QComboBox *shujuwei;
    QComboBox *tingzhiwei;
    QPushButton *turnon;
    QPushButton *scan;
    QRadioButton *radioButton;
    QFrame *line;
    QPushButton *M11;
    QPushButton *M21;
    QPushButton *M31;
    QPushButton *M12;
    QPushButton *M22;
    QPushButton *M32;
    QPushButton *M13;
    QPushButton *M23;
    QPushButton *M33;
    QPushButton *M14;
    QPushButton *M34;
    QPushButton *M24;
    QPushButton *save;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        MainWindow->setMaximumSize(QSize(1000, 600));
        QFont font;
        font.setPointSize(15);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 120, 50));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 120, 50));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 170, 120, 50));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 250, 120, 50));
        label_4->setFont(font);
        name = new QComboBox(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(130, 10, 120, 51));
        name->setFont(font);
        botelu = new QComboBox(centralwidget);
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->addItem(QString());
        botelu->setObjectName(QString::fromUtf8("botelu"));
        botelu->setGeometry(QRect(130, 90, 120, 51));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 330, 120, 50));
        label_5->setFont(font);
        jiaoyanwei = new QComboBox(centralwidget);
        jiaoyanwei->addItem(QString());
        jiaoyanwei->addItem(QString());
        jiaoyanwei->addItem(QString());
        jiaoyanwei->setObjectName(QString::fromUtf8("jiaoyanwei"));
        jiaoyanwei->setGeometry(QRect(130, 169, 120, 51));
        shujuwei = new QComboBox(centralwidget);
        shujuwei->addItem(QString());
        shujuwei->addItem(QString());
        shujuwei->addItem(QString());
        shujuwei->addItem(QString());
        shujuwei->setObjectName(QString::fromUtf8("shujuwei"));
        shujuwei->setGeometry(QRect(130, 250, 120, 51));
        tingzhiwei = new QComboBox(centralwidget);
        tingzhiwei->addItem(QString());
        tingzhiwei->addItem(QString());
        tingzhiwei->addItem(QString());
        tingzhiwei->setObjectName(QString::fromUtf8("tingzhiwei"));
        tingzhiwei->setGeometry(QRect(130, 330, 120, 51));
        turnon = new QPushButton(centralwidget);
        turnon->setObjectName(QString::fromUtf8("turnon"));
        turnon->setGeometry(QRect(10, 490, 120, 40));
        scan = new QPushButton(centralwidget);
        scan->setObjectName(QString::fromUtf8("scan"));
        scan->setGeometry(QRect(10, 410, 120, 40));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(140, 490, 101, 41));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(290, 0, 16, 551));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        M11 = new QPushButton(centralwidget);
        M11->setObjectName(QString::fromUtf8("M11"));
        M11->setGeometry(QRect(450, 20, 71, 71));
        M21 = new QPushButton(centralwidget);
        M21->setObjectName(QString::fromUtf8("M21"));
        M21->setGeometry(QRect(620, 20, 71, 71));
        M31 = new QPushButton(centralwidget);
        M31->setObjectName(QString::fromUtf8("M31"));
        M31->setGeometry(QRect(780, 20, 71, 71));
        M12 = new QPushButton(centralwidget);
        M12->setObjectName(QString::fromUtf8("M12"));
        M12->setGeometry(QRect(450, 130, 71, 71));
        M22 = new QPushButton(centralwidget);
        M22->setObjectName(QString::fromUtf8("M22"));
        M22->setGeometry(QRect(620, 130, 71, 71));
        M32 = new QPushButton(centralwidget);
        M32->setObjectName(QString::fromUtf8("M32"));
        M32->setGeometry(QRect(780, 130, 71, 71));
        M13 = new QPushButton(centralwidget);
        M13->setObjectName(QString::fromUtf8("M13"));
        M13->setGeometry(QRect(450, 240, 71, 71));
        M23 = new QPushButton(centralwidget);
        M23->setObjectName(QString::fromUtf8("M23"));
        M23->setGeometry(QRect(620, 240, 71, 71));
        M33 = new QPushButton(centralwidget);
        M33->setObjectName(QString::fromUtf8("M33"));
        M33->setGeometry(QRect(780, 240, 71, 71));
        M14 = new QPushButton(centralwidget);
        M14->setObjectName(QString::fromUtf8("M14"));
        M14->setGeometry(QRect(450, 350, 71, 71));
        M34 = new QPushButton(centralwidget);
        M34->setObjectName(QString::fromUtf8("M34"));
        M34->setGeometry(QRect(780, 350, 71, 71));
        M24 = new QPushButton(centralwidget);
        M24->setObjectName(QString::fromUtf8("M24"));
        M24->setGeometry(QRect(620, 350, 71, 71));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(580, 450, 141, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\220\215\347\247\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215:", nullptr));
        botelu->setItemText(0, QCoreApplication::translate("MainWindow", "110", nullptr));
        botelu->setItemText(1, QCoreApplication::translate("MainWindow", "300", nullptr));
        botelu->setItemText(2, QCoreApplication::translate("MainWindow", "600", nullptr));
        botelu->setItemText(3, QCoreApplication::translate("MainWindow", "1200", nullptr));
        botelu->setItemText(4, QCoreApplication::translate("MainWindow", "2400", nullptr));
        botelu->setItemText(5, QCoreApplication::translate("MainWindow", "4800", nullptr));
        botelu->setItemText(6, QCoreApplication::translate("MainWindow", "9600", nullptr));
        botelu->setItemText(7, QCoreApplication::translate("MainWindow", "14400", nullptr));
        botelu->setItemText(8, QCoreApplication::translate("MainWindow", "19200", nullptr));
        botelu->setItemText(9, QCoreApplication::translate("MainWindow", "38400", nullptr));
        botelu->setItemText(10, QCoreApplication::translate("MainWindow", "43000", nullptr));
        botelu->setItemText(11, QCoreApplication::translate("MainWindow", "56000", nullptr));
        botelu->setItemText(12, QCoreApplication::translate("MainWindow", "57600", nullptr));
        botelu->setItemText(13, QCoreApplication::translate("MainWindow", "115200", nullptr));
        botelu->setItemText(14, QCoreApplication::translate("MainWindow", "128000", nullptr));
        botelu->setItemText(15, QCoreApplication::translate("MainWindow", "256000", nullptr));
        botelu->setItemText(16, QCoreApplication::translate("MainWindow", "460800", nullptr));
        botelu->setItemText(17, QCoreApplication::translate("MainWindow", "921600", nullptr));
        botelu->setItemText(18, QCoreApplication::translate("MainWindow", "1382400", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215:", nullptr));
        jiaoyanwei->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\346\240\241\351\252\214", nullptr));
        jiaoyanwei->setItemText(1, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));
        jiaoyanwei->setItemText(2, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));

        shujuwei->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        shujuwei->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        shujuwei->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        shujuwei->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        tingzhiwei->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        tingzhiwei->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        tingzhiwei->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        turnon->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        scan->setText(QCoreApplication::translate("MainWindow", "\346\211\253\346\217\217\344\270\262\345\217\243", nullptr));
        radioButton->setText(QString());
        M11->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M21->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M31->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M12->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M22->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M32->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M13->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M23->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M33->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M14->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M34->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        M24->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
