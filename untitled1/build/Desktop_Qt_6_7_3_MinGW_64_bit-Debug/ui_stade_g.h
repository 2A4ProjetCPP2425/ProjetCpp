/********************************************************************************
** Form generated from reading UI file 'stade_g.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STADE_G_H
#define UI_STADE_G_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_Stade_g
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Stade_g)
    {
        if (Stade_g->objectName().isEmpty())
            Stade_g->setObjectName("Stade_g");
        Stade_g->resize(1129, 781);
        buttonBox = new QDialogButtonBox(Stade_g);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Orientation::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(Stade_g);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Stade_g, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Stade_g, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Stade_g);
    } // setupUi

    void retranslateUi(QDialog *Stade_g)
    {
        Stade_g->setWindowTitle(QCoreApplication::translate("Stade_g", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stade_g: public Ui_Stade_g {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STADE_G_H
