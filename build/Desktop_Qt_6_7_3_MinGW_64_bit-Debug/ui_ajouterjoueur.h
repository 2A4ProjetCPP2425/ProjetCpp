/********************************************************************************
** Form generated from reading UI file 'ajouterjoueur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERJOUEUR_H
#define UI_AJOUTERJOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AjouterJoueur
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *AjouterJoueur)
    {
        if (AjouterJoueur->objectName().isEmpty())
            AjouterJoueur->setObjectName("AjouterJoueur");
        AjouterJoueur->resize(1221, 757);
        AjouterJoueur->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(../../Projet_joueur/images/images.jpeg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
"\n"
""));
        label_2 = new QLabel(AjouterJoueur);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 110, 181, 41));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_3 = new QLabel(AjouterJoueur);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 180, 231, 41));
        label_3->setFont(font);
        label_4 = new QLabel(AjouterJoueur);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 240, 221, 41));
        label_4->setFont(font);
        label_5 = new QLabel(AjouterJoueur);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 300, 161, 31));
        label_5->setFont(font);
        label_6 = new QLabel(AjouterJoueur);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 360, 141, 41));
        label_6->setFont(font);
        label_7 = new QLabel(AjouterJoueur);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 410, 181, 71));
        label_7->setFont(font);
        label_8 = new QLabel(AjouterJoueur);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 500, 191, 71));
        label_8->setFont(font);
        lineEdit = new QLineEdit(AjouterJoueur);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 110, 113, 28));
        lineEdit_2 = new QLineEdit(AjouterJoueur);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 180, 113, 28));
        lineEdit_3 = new QLineEdit(AjouterJoueur);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(300, 240, 113, 28));
        lineEdit_4 = new QLineEdit(AjouterJoueur);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(300, 300, 113, 28));
        lineEdit_5 = new QLineEdit(AjouterJoueur);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(300, 360, 113, 28));
        lineEdit_6 = new QLineEdit(AjouterJoueur);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(300, 430, 113, 28));
        lineEdit_7 = new QLineEdit(AjouterJoueur);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(300, 520, 113, 28));
        pushButton = new QPushButton(AjouterJoueur);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 660, 161, 41));
        pushButton_2 = new QPushButton(AjouterJoueur);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(540, 300, 171, 41));
        label = new QLabel(AjouterJoueur);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 311, 71));
        label->setFont(font);

        retranslateUi(AjouterJoueur);

        QMetaObject::connectSlotsByName(AjouterJoueur);
    } // setupUi

    void retranslateUi(QDialog *AjouterJoueur)
    {
        AjouterJoueur->setWindowTitle(QCoreApplication::translate("AjouterJoueur", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("AjouterJoueur", "Nom:", nullptr));
        label_3->setText(QCoreApplication::translate("AjouterJoueur", "Prenom:", nullptr));
        label_4->setText(QCoreApplication::translate("AjouterJoueur", "Age:", nullptr));
        label_5->setText(QCoreApplication::translate("AjouterJoueur", "Nationalit\303\250:", nullptr));
        label_6->setText(QCoreApplication::translate("AjouterJoueur", "Poste:", nullptr));
        label_7->setText(QCoreApplication::translate("AjouterJoueur", "id_joueur:", nullptr));
        label_8->setText(QCoreApplication::translate("AjouterJoueur", "id_equipe:", nullptr));
        pushButton->setText(QCoreApplication::translate("AjouterJoueur", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AjouterJoueur", "Valider l'ajout", nullptr));
        label->setText(QCoreApplication::translate("AjouterJoueur", "Ajouter joueur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjouterJoueur: public Ui_AjouterJoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERJOUEUR_H
