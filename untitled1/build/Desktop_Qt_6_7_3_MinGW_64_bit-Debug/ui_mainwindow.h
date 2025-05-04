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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *lineEdit_nomStade;
    QLineEdit *lineEdit_localisation;
    QLineEdit *lineEdit_capacite;
    QPushButton *add_button;
    QPushButton *modifStadeButton;
    QPushButton *DeleteStadeButton;
    QPushButton *pushButton_4;
    QComboBox *comboBoxsortchamp;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QLabel *label_8;
    QTableView *tableViewStade;
    QLabel *label;
    QLineEdit *idStade;
    QComboBox *comboBox_order;
    QPushButton *trier_Button;
    QComboBox *comboBox_statut;
    QLabel *label_5;
    QPushButton *pushButton;
    QFrame *frame;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1601, 987);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/ucl.jpg);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 1421, 681));
        page = new QWidget();
        page->setObjectName("page");
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 210, 111, 20));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 330, 101, 17));
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 270, 71, 17));
        lineEdit_nomStade = new QLineEdit(page);
        lineEdit_nomStade->setObjectName("lineEdit_nomStade");
        lineEdit_nomStade->setGeometry(QRect(140, 200, 161, 41));
        lineEdit_localisation = new QLineEdit(page);
        lineEdit_localisation->setObjectName("lineEdit_localisation");
        lineEdit_localisation->setGeometry(QRect(140, 320, 161, 41));
        lineEdit_capacite = new QLineEdit(page);
        lineEdit_capacite->setObjectName("lineEdit_capacite");
        lineEdit_capacite->setGeometry(QRect(140, 260, 161, 41));
        add_button = new QPushButton(page);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(160, 440, 141, 41));
        add_button->setStyleSheet(QString::fromUtf8(""));
        modifStadeButton = new QPushButton(page);
        modifStadeButton->setObjectName("modifStadeButton");
        modifStadeButton->setGeometry(QRect(820, 390, 121, 41));
        DeleteStadeButton = new QPushButton(page);
        DeleteStadeButton->setObjectName("DeleteStadeButton");
        DeleteStadeButton->setGeometry(QRect(950, 390, 101, 41));
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(650, 40, 111, 41));
        comboBoxsortchamp = new QComboBox(page);
        comboBoxsortchamp->addItem(QString());
        comboBoxsortchamp->setObjectName("comboBoxsortchamp");
        comboBoxsortchamp->setGeometry(QRect(1220, 120, 101, 41));
        lineEdit_6 = new QLineEdit(page);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(410, 40, 181, 41));
        label_7 = new QLabel(page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 10, 161, 20));
        label_7->setStyleSheet(QString::fromUtf8("color:white;"));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1230, 90, 63, 20));
        label_8->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        tableViewStade = new QTableView(page);
        tableViewStade->setObjectName("tableViewStade");
        tableViewStade->setGeometry(QRect(330, 90, 691, 281));
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 150, 63, 20));
        idStade = new QLineEdit(page);
        idStade->setObjectName("idStade");
        idStade->setGeometry(QRect(140, 140, 151, 41));
        comboBox_order = new QComboBox(page);
        comboBox_order->addItem(QString());
        comboBox_order->addItem(QString());
        comboBox_order->setObjectName("comboBox_order");
        comboBox_order->setGeometry(QRect(1220, 180, 101, 41));
        trier_Button = new QPushButton(page);
        trier_Button->setObjectName("trier_Button");
        trier_Button->setGeometry(QRect(1220, 240, 101, 41));
        comboBox_statut = new QComboBox(page);
        comboBox_statut->setObjectName("comboBox_statut");
        comboBox_statut->setGeometry(QRect(140, 380, 161, 31));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 390, 101, 17));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(570, 400, 93, 29));
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(740, 450, 521, 211));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1601, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom du stade:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "localisation", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Capacit\303\251:", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        modifStadeButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        DeleteStadeButton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        comboBoxsortchamp->setItemText(0, QCoreApplication::translate("MainWindow", "capacite", nullptr));

        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter un stade", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Rechercher par stade:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "idStade", nullptr));
        comboBox_order->setItemText(0, QCoreApplication::translate("MainWindow", "Ascendant", nullptr));
        comboBox_order->setItemText(1, QCoreApplication::translate("MainWindow", "Descendant", nullptr));

        trier_Button->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
