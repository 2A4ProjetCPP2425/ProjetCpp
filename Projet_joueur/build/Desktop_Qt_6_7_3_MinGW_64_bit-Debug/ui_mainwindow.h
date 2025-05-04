/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_pic;
    QPushButton *Tours_b;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QLabel *label;
    QPushButton *joueur_b;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1129, 632);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #0037DA, stop:1 #001B6E);\n"
"    color: #FFD700;\n"
"    border: 2px solid #FFD700;\n"
"    border-radius: 7px;\n"
"    padding: 10px 20px;\n"
"    font: bold 14px 'Verdana';\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #0028A5, stop:1 #000F3C);\n"
"    border: 2px solid #FFFFFF;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background: #000000;\n"
"    color: #FFD700;\n"
"    border-bottom: 2px solid #FFD700;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: #0037DA;\n"
"}\n"
"\n"
"QStatusBar {\n"
"    background: #000000;\n"
"    color: #FFD700;\n"
"    border-top: 2px solid #FFD700;\n"
"}\n"
"\n"
"QToolBar {\n"
"    background: #1A1A1A;\n"
"    border: 2px solid #FFD700;\n"
"    spacing: 5px;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    color: #FFD700;\n"
"    font: bold 24px 'A\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(-40, -10, 1231, 641));
        label_pic->setPixmap(QPixmap(QString::fromUtf8("images/ucl.jpeg")));
        label_pic->setScaledContents(true);
        Tours_b = new QPushButton(centralwidget);
        Tours_b->setObjectName("Tours_b");
        Tours_b->setGeometry(QRect(260, 250, 231, 71));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(740, 250, 231, 71));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(500, 250, 231, 71));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(500, 340, 231, 71));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(740, 340, 231, 71));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(560, 120, 281, 91));
        QFont font;
        font.setPointSize(28);
        label_2->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(430, 10, 441, 101));
        QFont font1;
        font1.setPointSize(36);
        label->setFont(font1);
        joueur_b = new QPushButton(centralwidget);
        joueur_b->setObjectName("joueur_b");
        joueur_b->setGeometry(QRect(260, 340, 231, 71));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_pic->setText(QString());
        Tours_b->setText(QCoreApplication::translate("MainWindow", "Gestion des Tours", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Gestion des Matches", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Gestion des Equipes", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Gestion des Stades", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Gestion des Entraineurs", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "By Winners", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "UCL specialists ", nullptr));
        joueur_b->setText(QCoreApplication::translate("MainWindow", "Gestion des joueurs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
