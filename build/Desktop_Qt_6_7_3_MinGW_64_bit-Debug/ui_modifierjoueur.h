/********************************************************************************
** Form generated from reading UI file 'modifierjoueur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERJOUEUR_H
#define UI_MODIFIERJOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModifierJoueur
{
public:
    QLabel *label_4;
    QLineEdit *lineEdit_7;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;

    void setupUi(QDialog *ModifierJoueur)
    {
        if (ModifierJoueur->objectName().isEmpty())
            ModifierJoueur->setObjectName("ModifierJoueur");
        ModifierJoueur->resize(1119, 736);
        ModifierJoueur->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(../../Projet_joueur/images/images.jpeg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
"\n"
""));
        label_4 = new QLabel(ModifierJoueur);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 120, 221, 41));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);
        lineEdit_7 = new QLineEdit(ModifierJoueur);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(180, 190, 113, 28));
        label_8 = new QLabel(ModifierJoueur);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 170, 191, 71));
        label_8->setFont(font);
        lineEdit_3 = new QLineEdit(ModifierJoueur);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(180, 130, 113, 28));
        label_7 = new QLabel(ModifierJoueur);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(500, 40, 181, 71));
        label_7->setFont(font);
        lineEdit_6 = new QLineEdit(ModifierJoueur);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(680, 60, 113, 28));
        label = new QLabel(ModifierJoueur);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 10, 421, 131));
        QFont font1;
        font1.setPointSize(24);
        font1.setUnderline(true);
        label->setFont(font1);
        pushButton_2 = new QPushButton(ModifierJoueur);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(840, 60, 251, 51));
        pushButton = new QPushButton(ModifierJoueur);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 670, 161, 41));
        label_2 = new QLabel(ModifierJoueur);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 240, 351, 81));
        label_2->setFont(font);
        label_3 = new QLabel(ModifierJoueur);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 310, 351, 61));
        label_3->setFont(font);
        label_5 = new QLabel(ModifierJoueur);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 370, 371, 71));
        label_5->setFont(font);
        label_6 = new QLabel(ModifierJoueur);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 420, 371, 81));
        label_6->setFont(font);
        lineEdit_8 = new QLineEdit(ModifierJoueur);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(460, 270, 113, 28));
        lineEdit_9 = new QLineEdit(ModifierJoueur);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(460, 390, 113, 28));
        lineEdit_10 = new QLineEdit(ModifierJoueur);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(460, 320, 113, 28));
        lineEdit_11 = new QLineEdit(ModifierJoueur);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(460, 440, 113, 28));

        retranslateUi(ModifierJoueur);

        QMetaObject::connectSlotsByName(ModifierJoueur);
    } // setupUi

    void retranslateUi(QDialog *ModifierJoueur)
    {
        ModifierJoueur->setWindowTitle(QCoreApplication::translate("ModifierJoueur", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("ModifierJoueur", "Age:", nullptr));
        label_8->setText(QCoreApplication::translate("ModifierJoueur", "id_equipe:", nullptr));
        label_7->setText(QCoreApplication::translate("ModifierJoueur", "id_joueur:", nullptr));
        label->setText(QCoreApplication::translate("ModifierJoueur", "Modifier Joueur", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ModifierJoueur", "Appliquer modification", nullptr));
        pushButton->setText(QCoreApplication::translate("ModifierJoueur", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("ModifierJoueur", "Nombre de matches jou\303\250es", nullptr));
        label_3->setText(QCoreApplication::translate("ModifierJoueur", "Nombre de buts marqu\303\250es", nullptr));
        label_5->setText(QCoreApplication::translate("ModifierJoueur", "Nombre de passes decisifs", nullptr));
        label_6->setText(QCoreApplication::translate("ModifierJoueur", "Nombre de clean sheets", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifierJoueur: public Ui_ModifierJoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERJOUEUR_H
