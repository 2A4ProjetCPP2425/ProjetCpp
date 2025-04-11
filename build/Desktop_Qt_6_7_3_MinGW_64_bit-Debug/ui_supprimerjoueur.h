/********************************************************************************
** Form generated from reading UI file 'supprimerjoueur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERJOUEUR_H
#define UI_SUPPRIMERJOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_supprimerjoueur
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *supprimerjoueur)
    {
        if (supprimerjoueur->objectName().isEmpty())
            supprimerjoueur->setObjectName("supprimerjoueur");
        supprimerjoueur->resize(1091, 695);
        buttonBox = new QDialogButtonBox(supprimerjoueur);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Orientation::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(supprimerjoueur);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, supprimerjoueur, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, supprimerjoueur, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(supprimerjoueur);
    } // setupUi

    void retranslateUi(QDialog *supprimerjoueur)
    {
        supprimerjoueur->setWindowTitle(QCoreApplication::translate("supprimerjoueur", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class supprimerjoueur: public Ui_supprimerjoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERJOUEUR_H
