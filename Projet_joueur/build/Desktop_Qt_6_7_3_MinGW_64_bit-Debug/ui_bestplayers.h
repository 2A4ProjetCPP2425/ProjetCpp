/********************************************************************************
** Form generated from reading UI file 'bestplayers.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BESTPLAYERS_H
#define UI_BESTPLAYERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BestPlayers
{
public:
    QTabWidget *tabWidget;
    QWidget *Tour1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QWidget *tab_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *tab_8;
    QWidget *tab_9;
    QWidget *tab_10;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *BestPlayers)
    {
        if (BestPlayers->objectName().isEmpty())
            BestPlayers->setObjectName("BestPlayers");
        BestPlayers->resize(1149, 712);
        BestPlayers->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(../../Projet_joueur/images/images.jpeg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
"\n"
""));
        tabWidget = new QTabWidget(BestPlayers);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 110, 1121, 441));
        Tour1 = new QWidget();
        Tour1->setObjectName("Tour1");
        Tour1->setMaximumSize(QSize(537, 384));
        label_2 = new QLabel(Tour1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 30, 211, 41));
        label_3 = new QLabel(Tour1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 100, 251, 71));
        label_4 = new QLabel(Tour1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 180, 221, 61));
        label_5 = new QLabel(Tour1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 270, 201, 71));
        lineEdit = new QLineEdit(Tour1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(280, 40, 113, 28));
        lineEdit_2 = new QLineEdit(Tour1);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(290, 90, 113, 28));
        lineEdit_3 = new QLineEdit(Tour1);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(280, 180, 113, 28));
        lineEdit_4 = new QLineEdit(Tour1);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(300, 290, 113, 28));
        tabWidget->addTab(Tour1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 30, 211, 41));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 90, 211, 41));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 180, 211, 41));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 260, 211, 41));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        tabWidget->addTab(tab_10, QString());
        label = new QLabel(BestPlayers);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 421, 81));
        QFont font;
        font.setPointSize(16);
        font.setUnderline(true);
        label->setFont(font);
        pushButton = new QPushButton(BestPlayers);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 620, 151, 41));

        retranslateUi(BestPlayers);

        tabWidget->setCurrentIndex(10);


        QMetaObject::connectSlotsByName(BestPlayers);
    } // setupUi

    void retranslateUi(QDialog *BestPlayers)
    {
        BestPlayers->setWindowTitle(QCoreApplication::translate("BestPlayers", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        Tour1->setToolTip(QCoreApplication::translate("BestPlayers", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_2->setText(QCoreApplication::translate("BestPlayers", "Best attaquant ", nullptr));
        label_3->setText(QCoreApplication::translate("BestPlayers", "Best milieu", nullptr));
        label_4->setText(QCoreApplication::translate("BestPlayers", "Best defenseur", nullptr));
        label_5->setText(QCoreApplication::translate("BestPlayers", "Best gardien", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tour1), QCoreApplication::translate("BestPlayers", "Tour 1       ", nullptr));
        label_6->setText(QCoreApplication::translate("BestPlayers", "Best attaquant ", nullptr));
        label_7->setText(QCoreApplication::translate("BestPlayers", "Best Milieu", nullptr));
        label_8->setText(QCoreApplication::translate("BestPlayers", "Best Defenseur", nullptr));
        label_9->setText(QCoreApplication::translate("BestPlayers", "Best Gardien", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("BestPlayers", "Tour 2    ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("BestPlayers", "Tour 3    ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("BestPlayers", "Tour 4    ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("BestPlayers", "Tour 5    ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("BestPlayers", "Tour 6    ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("BestPlayers", "16\303\250me de final", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("BestPlayers", "8eme de final", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("BestPlayers", "4\303\250me de final", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("BestPlayers", "Demi final  ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QCoreApplication::translate("BestPlayers", "Final     ", nullptr));
        label->setText(QCoreApplication::translate("BestPlayers", "Best Players of every journey", nullptr));
        pushButton->setText(QCoreApplication::translate("BestPlayers", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BestPlayers: public Ui_BestPlayers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BESTPLAYERS_H
