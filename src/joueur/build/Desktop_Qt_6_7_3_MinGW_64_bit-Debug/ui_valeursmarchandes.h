/********************************************************************************
** Form generated from reading UI file 'valeursmarchandes.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALEURSMARCHANDES_H
#define UI_VALEURSMARCHANDES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_ValeursMarchandes
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ValeursMarchandes)
    {
        if (ValeursMarchandes->objectName().isEmpty())
            ValeursMarchandes->setObjectName("ValeursMarchandes");
        ValeursMarchandes->resize(1092, 742);
        ValeursMarchandes->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(../../Projet_joueur/images/images.jpeg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
"\n"
""));
        buttonBox = new QDialogButtonBox(ValeursMarchandes);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Orientation::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(ValeursMarchandes);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, ValeursMarchandes, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, ValeursMarchandes, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ValeursMarchandes);
    } // setupUi

    void retranslateUi(QDialog *ValeursMarchandes)
    {
        ValeursMarchandes->setWindowTitle(QCoreApplication::translate("ValeursMarchandes", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ValeursMarchandes: public Ui_ValeursMarchandes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALEURSMARCHANDES_H
