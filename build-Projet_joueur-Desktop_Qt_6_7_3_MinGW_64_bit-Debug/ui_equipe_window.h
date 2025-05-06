/********************************************************************************
** Form generated from reading UI file 'equipe_window.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPE_WINDOW_H
#define UI_EQUIPE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_equipe_window
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Liste_equipe;
    QTableView *Liste_equipes;
    QPushButton *PDF;
    QWidget *Ajouter_eq;
    QLabel *label_24;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLineEdit *id_equ;
    QLineEdit *Nom_eq;
    QLineEdit *Participation_ajout;
    QLineEdit *moy_buts_ajout;
    QLineEdit *buteur_ajout;
    QLineEdit *tot_matchs_ajout;
    QPushButton *valider_ajout;
    QLabel *label_39;
    QLineEdit *Classe_ajout;
    QWidget *Modifier_equipe;
    QLabel *label_2;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *participations_modif;
    QLineEdit *Buteur_modif;
    QLineEdit *Total_matches_modif;
    QLineEdit *Moyen_but_modif;
    QPushButton *valider_modifier;
    QLabel *label_25;
    QLineEdit *Classe_modif;
    QWidget *Supprimer_equipe;
    QLabel *label_37;
    QPushButton *Valider_supprimer;
    QWidget *tab;
    QPushButton *Tirageausort;
    QTableView *groupe2;
    QTableView *groupe3;
    QTableView *groupe1;
    QTableView *groupe4;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tab_2;
    QLineEdit *valeurmarchande;
    QLabel *label_6;
    QTableView *joueursList;
    QPushButton *rechercher_button;
    QLabel *label_38;
    QLineEdit *recherche;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *equipe_window)
    {
        if (equipe_window->objectName().isEmpty())
            equipe_window->setObjectName("equipe_window");
        equipe_window->resize(1554, 874);
        equipe_window->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: white;\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"    border: 2px solid gray;\n"
"    background: darkgray;\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"    border: 2px solid red;\n"
"    background: blue;\n"
"}"));
        centralwidget = new QWidget(equipe_window);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 90, 1521, 711));
        Liste_equipe = new QWidget();
        Liste_equipe->setObjectName("Liste_equipe");
        Liste_equipes = new QTableView(Liste_equipe);
        Liste_equipes->setObjectName("Liste_equipes");
        Liste_equipes->setGeometry(QRect(50, 40, 871, 631));
        PDF = new QPushButton(Liste_equipe);
        PDF->setObjectName("PDF");
        PDF->setGeometry(QRect(1000, 40, 181, 71));
        tabWidget->addTab(Liste_equipe, QString());
        Ajouter_eq = new QWidget();
        Ajouter_eq->setObjectName("Ajouter_eq");
        label_24 = new QLabel(Ajouter_eq);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(40, 30, 161, 31));
        label_32 = new QLabel(Ajouter_eq);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(40, 180, 141, 31));
        label_33 = new QLabel(Ajouter_eq);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(40, 240, 191, 31));
        label_34 = new QLabel(Ajouter_eq);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(40, 310, 161, 41));
        label_35 = new QLabel(Ajouter_eq);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(30, 380, 251, 61));
        label_36 = new QLabel(Ajouter_eq);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(40, 90, 171, 61));
        id_equ = new QLineEdit(Ajouter_eq);
        id_equ->setObjectName("id_equ");
        id_equ->setGeometry(QRect(320, 40, 113, 28));
        Nom_eq = new QLineEdit(Ajouter_eq);
        Nom_eq->setObjectName("Nom_eq");
        Nom_eq->setGeometry(QRect(320, 110, 113, 28));
        Participation_ajout = new QLineEdit(Ajouter_eq);
        Participation_ajout->setObjectName("Participation_ajout");
        Participation_ajout->setGeometry(QRect(320, 180, 113, 28));
        moy_buts_ajout = new QLineEdit(Ajouter_eq);
        moy_buts_ajout->setObjectName("moy_buts_ajout");
        moy_buts_ajout->setGeometry(QRect(320, 250, 113, 28));
        buteur_ajout = new QLineEdit(Ajouter_eq);
        buteur_ajout->setObjectName("buteur_ajout");
        buteur_ajout->setGeometry(QRect(320, 320, 113, 28));
        tot_matchs_ajout = new QLineEdit(Ajouter_eq);
        tot_matchs_ajout->setObjectName("tot_matchs_ajout");
        tot_matchs_ajout->setGeometry(QRect(320, 400, 113, 28));
        valider_ajout = new QPushButton(Ajouter_eq);
        valider_ajout->setObjectName("valider_ajout");
        valider_ajout->setGeometry(QRect(580, 370, 311, 61));
        label_39 = new QLabel(Ajouter_eq);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(30, 440, 251, 61));
        Classe_ajout = new QLineEdit(Ajouter_eq);
        Classe_ajout->setObjectName("Classe_ajout");
        Classe_ajout->setGeometry(QRect(320, 460, 113, 28));
        tabWidget->addTab(Ajouter_eq, QString());
        Modifier_equipe = new QWidget();
        Modifier_equipe->setObjectName("Modifier_equipe");
        label_2 = new QLabel(Modifier_equipe);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 191, 71));
        label_21 = new QLabel(Modifier_equipe);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 130, 201, 71));
        label_22 = new QLabel(Modifier_equipe);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(10, 220, 191, 71));
        label_23 = new QLabel(Modifier_equipe);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 320, 151, 81));
        participations_modif = new QLineEdit(Modifier_equipe);
        participations_modif->setObjectName("participations_modif");
        participations_modif->setGeometry(QRect(250, 70, 113, 28));
        Buteur_modif = new QLineEdit(Modifier_equipe);
        Buteur_modif->setObjectName("Buteur_modif");
        Buteur_modif->setGeometry(QRect(250, 140, 113, 28));
        Total_matches_modif = new QLineEdit(Modifier_equipe);
        Total_matches_modif->setObjectName("Total_matches_modif");
        Total_matches_modif->setGeometry(QRect(250, 240, 113, 28));
        Moyen_but_modif = new QLineEdit(Modifier_equipe);
        Moyen_but_modif->setObjectName("Moyen_but_modif");
        Moyen_but_modif->setGeometry(QRect(250, 350, 113, 28));
        valider_modifier = new QPushButton(Modifier_equipe);
        valider_modifier->setObjectName("valider_modifier");
        valider_modifier->setGeometry(QRect(690, 360, 311, 61));
        label_25 = new QLabel(Modifier_equipe);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 410, 151, 81));
        Classe_modif = new QLineEdit(Modifier_equipe);
        Classe_modif->setObjectName("Classe_modif");
        Classe_modif->setGeometry(QRect(250, 440, 113, 28));
        tabWidget->addTab(Modifier_equipe, QString());
        Supprimer_equipe = new QWidget();
        Supprimer_equipe->setObjectName("Supprimer_equipe");
        label_37 = new QLabel(Supprimer_equipe);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(60, 50, 331, 61));
        Valider_supprimer = new QPushButton(Supprimer_equipe);
        Valider_supprimer->setObjectName("Valider_supprimer");
        Valider_supprimer->setGeometry(QRect(410, 70, 141, 51));
        tabWidget->addTab(Supprimer_equipe, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        Tirageausort = new QPushButton(tab);
        Tirageausort->setObjectName("Tirageausort");
        Tirageausort->setGeometry(QRect(1270, 530, 221, 71));
        groupe2 = new QTableView(tab);
        groupe2->setObjectName("groupe2");
        groupe2->setGeometry(QRect(1130, 160, 321, 281));
        groupe3 = new QTableView(tab);
        groupe3->setObjectName("groupe3");
        groupe3->setGeometry(QRect(760, 160, 321, 281));
        groupe1 = new QTableView(tab);
        groupe1->setObjectName("groupe1");
        groupe1->setGeometry(QRect(0, 160, 321, 281));
        groupe4 = new QTableView(tab);
        groupe4->setObjectName("groupe4");
        groupe4->setGeometry(QRect(340, 160, 341, 281));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 50, 221, 71));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(390, 50, 221, 71));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(850, 70, 221, 71));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1240, 60, 221, 71));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        valeurmarchande = new QLineEdit(tab_2);
        valeurmarchande->setObjectName("valeurmarchande");
        valeurmarchande->setGeometry(QRect(630, 70, 181, 61));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 50, 311, 101));
        joueursList = new QTableView(tab_2);
        joueursList->setObjectName("joueursList");
        joueursList->setGeometry(QRect(400, 250, 591, 211));
        tabWidget->addTab(tab_2, QString());
        rechercher_button = new QPushButton(centralwidget);
        rechercher_button->setObjectName("rechercher_button");
        rechercher_button->setGeometry(QRect(640, 10, 311, 61));
        label_38 = new QLabel(centralwidget);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(70, 10, 241, 61));
        recherche = new QLineEdit(centralwidget);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(300, 20, 211, 41));
        equipe_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(equipe_window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1554, 25));
        equipe_window->setMenuBar(menubar);
        statusbar = new QStatusBar(equipe_window);
        statusbar->setObjectName("statusbar");
        equipe_window->setStatusBar(statusbar);

        retranslateUi(equipe_window);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(equipe_window);
    } // setupUi

    void retranslateUi(QMainWindow *equipe_window)
    {
        equipe_window->setWindowTitle(QCoreApplication::translate("equipe_window", "equipe_window", nullptr));
        PDF->setText(QCoreApplication::translate("equipe_window", "PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Liste_equipe), QCoreApplication::translate("equipe_window", "Liste des equipes", nullptr));
        label_24->setText(QCoreApplication::translate("equipe_window", "ID_equipe", nullptr));
        label_32->setText(QCoreApplication::translate("equipe_window", "Participations", nullptr));
        label_33->setText(QCoreApplication::translate("equipe_window", "Moyen de buts", nullptr));
        label_34->setText(QCoreApplication::translate("equipe_window", "Buteur", nullptr));
        label_35->setText(QCoreApplication::translate("equipe_window", "Total de matches", nullptr));
        label_36->setText(QCoreApplication::translate("equipe_window", "Nom equipe", nullptr));
        valider_ajout->setText(QCoreApplication::translate("equipe_window", "Valider Ajout", nullptr));
        label_39->setText(QCoreApplication::translate("equipe_window", "Classe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Ajouter_eq), QCoreApplication::translate("equipe_window", "Ajouter une equipe", nullptr));
        label_2->setText(QCoreApplication::translate("equipe_window", "Participations", nullptr));
        label_21->setText(QCoreApplication::translate("equipe_window", "Buteur", nullptr));
        label_22->setText(QCoreApplication::translate("equipe_window", "Total des matches", nullptr));
        label_23->setText(QCoreApplication::translate("equipe_window", "Moyen de buts", nullptr));
        valider_modifier->setText(QCoreApplication::translate("equipe_window", "Valider Modification", nullptr));
        label_25->setText(QCoreApplication::translate("equipe_window", "Classe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Modifier_equipe), QCoreApplication::translate("equipe_window", "Modifier equipes", nullptr));
        label_37->setText(QCoreApplication::translate("equipe_window", "Voulez vous supprimer cet equipe?", nullptr));
        Valider_supprimer->setText(QCoreApplication::translate("equipe_window", "Valider suppression", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Supprimer_equipe), QCoreApplication::translate("equipe_window", "Supprimer une equipe", nullptr));
        Tirageausort->setText(QCoreApplication::translate("equipe_window", "Tirage au sort", nullptr));
        label->setText(QCoreApplication::translate("equipe_window", "Groupe1:", nullptr));
        label_3->setText(QCoreApplication::translate("equipe_window", "Groupe2:", nullptr));
        label_4->setText(QCoreApplication::translate("equipe_window", "Groupe3:", nullptr));
        label_5->setText(QCoreApplication::translate("equipe_window", "Groupe4:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("equipe_window", "Tirage au sort", nullptr));
        label_6->setText(QCoreApplication::translate("equipe_window", "Voici la valeur marchande de l'equipe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("equipe_window", "Valeur marchande d'une equipe", nullptr));
        rechercher_button->setText(QCoreApplication::translate("equipe_window", "Valider recherche", nullptr));
        label_38->setText(QCoreApplication::translate("equipe_window", "Recherche d'equipe par ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class equipe_window: public Ui_equipe_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPE_WINDOW_H
