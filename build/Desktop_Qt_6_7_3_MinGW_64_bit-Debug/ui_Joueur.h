/********************************************************************************
** Form generated from reading UI file 'Joueur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOUEUR_H
#define UI_JOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_joueur
{
public:
    QTabWidget *tabWidget;
    QWidget *Consulter_j;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_3;
    QLabel *label_6;
    QTextBrowser *Nom;
    QTextBrowser *Prenom;
    QTextBrowser *Age;
    QTextBrowser *Nationalite;
    QTextBrowser *Poste;
    QTextBrowser *Equipe_Actuelle;
    QTextBrowser *ID_joueur;
    QTextBrowser *nb_matches;
    QTextBrowser *nb_passes;
    QTextBrowser *nb_cleansheet;
    QLabel *label_19;
    QTextBrowser *nb_buts;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QWidget *Ajouter_j;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_20;
    QLineEdit *Nom2;
    QLineEdit *Prenom2;
    QLineEdit *Age2;
    QLineEdit *Poste2;
    QLineEdit *Nationalite2;
    QLineEdit *Equipe_Actuelle2;
    QLineEdit *ID_joueur2;
    QWidget *Modifier_j;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QPushButton *pushButton_2;
    QWidget *Supprimer_j;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;
    QWidget *Valeur_m;
    QLabel *label_30;
    QTextBrowser *Valeur_marchande;
    QWidget *Best_player;
    QTabWidget *tabWidget_2;
    QWidget *Round_of16;
    QLabel *label_84;
    QLabel *label_85;
    QLabel *label_86;
    QLabel *label_87;
    QLineEdit *nb_passes_17;
    QLineEdit *nb_passes_18;
    QLineEdit *nb_passes_19;
    QLineEdit *nb_passes_20;
    QWidget *Quarter_finals;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QLabel *label_83;
    QLineEdit *nb_passes_13;
    QLineEdit *nb_passes_14;
    QLineEdit *nb_passes_15;
    QLineEdit *nb_passes_16;
    QWidget *Semi_final;
    QLabel *label_77;
    QLabel *label_78;
    QLabel *label_79;
    QLineEdit *nb_passes_9;
    QLineEdit *nb_passes_10;
    QLineEdit *nb_passes_11;
    QLineEdit *nb_passes_12;
    QLabel *label_76;
    QWidget *Final;
    QLabel *label_45;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLineEdit *nb_buts2_2;
    QLineEdit *nb_passes_4;
    QLineEdit *nb_passes_7;
    QLineEdit *nb_passes_8;
    QLineEdit *Recherche;
    QLabel *label_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *joueur)
    {
        if (joueur->objectName().isEmpty())
            joueur->setObjectName("joueur");
        joueur->resize(1663, 785);
        joueur->setMouseTracking(false);
        joueur->setTabletTracking(false);
        joueur->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(x.jpg);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
""));
        joueur->setSizeGripEnabled(true);
        joueur->setModal(true);
        tabWidget = new QTabWidget(joueur);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 110, 1571, 611));
        tabWidget->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        Consulter_j = new QWidget();
        Consulter_j->setObjectName("Consulter_j");
        label_11 = new QLabel(Consulter_j);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 10, 251, 61));
        QFont font;
        font.setPointSize(16);
        font.setUnderline(true);
        label_11->setFont(font);
        label_12 = new QLabel(Consulter_j);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 100, 251, 61));
        label_12->setFont(font);
        label_13 = new QLabel(Consulter_j);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(0, 200, 251, 61));
        label_13->setFont(font);
        label_14 = new QLabel(Consulter_j);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 310, 251, 61));
        label_14->setFont(font);
        label_15 = new QLabel(Consulter_j);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(0, 390, 251, 61));
        label_15->setFont(font);
        label_16 = new QLabel(Consulter_j);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(380, 10, 251, 61));
        label_16->setFont(font);
        label_17 = new QLabel(Consulter_j);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(380, 180, 271, 61));
        label_17->setFont(font);
        label_18 = new QLabel(Consulter_j);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(380, 270, 271, 61));
        label_18->setFont(font);
        label_3 = new QLabel(Consulter_j);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(380, 340, 241, 61));
        label_3->setFont(font);
        label_6 = new QLabel(Consulter_j);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 420, 291, 61));
        label_6->setFont(font);
        Nom = new QTextBrowser(Consulter_j);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(160, 30, 201, 51));
        Prenom = new QTextBrowser(Consulter_j);
        Prenom->setObjectName("Prenom");
        Prenom->setGeometry(QRect(160, 120, 201, 51));
        Age = new QTextBrowser(Consulter_j);
        Age->setObjectName("Age");
        Age->setGeometry(QRect(160, 210, 201, 51));
        Nationalite = new QTextBrowser(Consulter_j);
        Nationalite->setObjectName("Nationalite");
        Nationalite->setGeometry(QRect(160, 310, 201, 51));
        Poste = new QTextBrowser(Consulter_j);
        Poste->setObjectName("Poste");
        Poste->setGeometry(QRect(160, 390, 201, 51));
        Equipe_Actuelle = new QTextBrowser(Consulter_j);
        Equipe_Actuelle->setObjectName("Equipe_Actuelle");
        Equipe_Actuelle->setGeometry(QRect(730, 30, 201, 51));
        ID_joueur = new QTextBrowser(Consulter_j);
        ID_joueur->setObjectName("ID_joueur");
        ID_joueur->setGeometry(QRect(730, 110, 201, 51));
        nb_matches = new QTextBrowser(Consulter_j);
        nb_matches->setObjectName("nb_matches");
        nb_matches->setGeometry(QRect(730, 190, 201, 51));
        nb_passes = new QTextBrowser(Consulter_j);
        nb_passes->setObjectName("nb_passes");
        nb_passes->setGeometry(QRect(730, 340, 201, 51));
        nb_cleansheet = new QTextBrowser(Consulter_j);
        nb_cleansheet->setObjectName("nb_cleansheet");
        nb_cleansheet->setGeometry(QRect(730, 430, 201, 51));
        label_19 = new QLabel(Consulter_j);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(380, 110, 241, 51));
        label_19->setFont(font);
        nb_buts = new QTextBrowser(Consulter_j);
        nb_buts->setObjectName("nb_buts");
        nb_buts->setGeometry(QRect(730, 270, 201, 51));
        label_21 = new QLabel(Consulter_j);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(940, 30, 371, 61));
        label_21->setFont(font);
        label_22 = new QLabel(Consulter_j);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(940, 90, 331, 61));
        label_22->setFont(font);
        label_23 = new QLabel(Consulter_j);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(940, 180, 321, 61));
        label_23->setFont(font);
        label_24 = new QLabel(Consulter_j);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(940, 260, 361, 61));
        label_24->setFont(font);
        textBrowser = new QTextBrowser(Consulter_j);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(1310, 40, 251, 51));
        textBrowser_2 = new QTextBrowser(Consulter_j);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(1310, 100, 251, 51));
        textBrowser_3 = new QTextBrowser(Consulter_j);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(1310, 180, 251, 51));
        textBrowser_4 = new QTextBrowser(Consulter_j);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setGeometry(QRect(1310, 260, 251, 51));
        tabWidget->addTab(Consulter_j, QString());
        Ajouter_j = new QWidget();
        Ajouter_j->setObjectName("Ajouter_j");
        label_4 = new QLabel(Ajouter_j);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 20, 201, 51));
        label_4->setFont(font);
        label_5 = new QLabel(Ajouter_j);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 130, 161, 41));
        label_5->setFont(font);
        label_7 = new QLabel(Ajouter_j);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(460, 30, 221, 41));
        label_7->setFont(font);
        label_8 = new QLabel(Ajouter_j);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 320, 191, 51));
        label_8->setFont(font);
        label_9 = new QLabel(Ajouter_j);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 190, 201, 81));
        label_9->setFont(font);
        label_10 = new QLabel(Ajouter_j);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(460, 120, 151, 51));
        label_10->setFont(font);
        label_20 = new QLabel(Ajouter_j);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(0, 400, 231, 61));
        label_20->setFont(font);
        Nom2 = new QLineEdit(Ajouter_j);
        Nom2->setObjectName("Nom2");
        Nom2->setGeometry(QRect(190, 30, 121, 41));
        Prenom2 = new QLineEdit(Ajouter_j);
        Prenom2->setObjectName("Prenom2");
        Prenom2->setGeometry(QRect(190, 140, 121, 41));
        Age2 = new QLineEdit(Ajouter_j);
        Age2->setObjectName("Age2");
        Age2->setGeometry(QRect(190, 220, 121, 41));
        Poste2 = new QLineEdit(Ajouter_j);
        Poste2->setObjectName("Poste2");
        Poste2->setGeometry(QRect(190, 340, 121, 41));
        Nationalite2 = new QLineEdit(Ajouter_j);
        Nationalite2->setObjectName("Nationalite2");
        Nationalite2->setGeometry(QRect(190, 410, 121, 41));
        Equipe_Actuelle2 = new QLineEdit(Ajouter_j);
        Equipe_Actuelle2->setObjectName("Equipe_Actuelle2");
        Equipe_Actuelle2->setGeometry(QRect(780, 40, 141, 41));
        ID_joueur2 = new QLineEdit(Ajouter_j);
        ID_joueur2->setObjectName("ID_joueur2");
        ID_joueur2->setGeometry(QRect(780, 120, 141, 41));
        tabWidget->addTab(Ajouter_j, QString());
        Modifier_j = new QWidget();
        Modifier_j->setObjectName("Modifier_j");
        label_25 = new QLabel(Modifier_j);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 40, 221, 41));
        label_25->setFont(font);
        label_26 = new QLabel(Modifier_j);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(50, 90, 271, 61));
        label_26->setFont(font);
        label_27 = new QLabel(Modifier_j);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(50, 170, 271, 61));
        label_27->setFont(font);
        label_28 = new QLabel(Modifier_j);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(50, 240, 241, 61));
        label_28->setFont(font);
        label_29 = new QLabel(Modifier_j);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(50, 320, 291, 61));
        label_29->setFont(font);
        lineEdit_12 = new QLineEdit(Modifier_j);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(510, 50, 141, 41));
        lineEdit_13 = new QLineEdit(Modifier_j);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(510, 110, 141, 41));
        lineEdit_14 = new QLineEdit(Modifier_j);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(510, 180, 141, 41));
        lineEdit_15 = new QLineEdit(Modifier_j);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(510, 250, 141, 41));
        lineEdit_16 = new QLineEdit(Modifier_j);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setGeometry(QRect(510, 330, 141, 41));
        pushButton_2 = new QPushButton(Modifier_j);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(670, 390, 241, 81));
        QFont font1;
        font1.setPointSize(16);
        pushButton_2->setFont(font1);
        tabWidget->addTab(Modifier_j, QString());
        Supprimer_j = new QWidget();
        Supprimer_j->setObjectName("Supprimer_j");
        label = new QLabel(Supprimer_j);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 30, 251, 61));
        label->setFont(font);
        radioButton = new QRadioButton(Supprimer_j);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(230, 120, 112, 26));
        radioButton_2 = new QRadioButton(Supprimer_j);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(230, 160, 112, 26));
        radioButton_2->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(Supprimer_j);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(340, 140, 241, 81));
        pushButton->setFont(font1);
        tabWidget->addTab(Supprimer_j, QString());
        Valeur_m = new QWidget();
        Valeur_m->setObjectName("Valeur_m");
        label_30 = new QLabel(Valeur_m);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(110, 110, 561, 121));
        label_30->setFont(font1);
        Valeur_marchande = new QTextBrowser(Valeur_m);
        Valeur_marchande->setObjectName("Valeur_marchande");
        Valeur_marchande->setGeometry(QRect(570, 150, 231, 51));
        tabWidget->addTab(Valeur_m, QString());
        Best_player = new QWidget();
        Best_player->setObjectName("Best_player");
        tabWidget_2 = new QTabWidget(Best_player);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 0, 1071, 541));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        Round_of16 = new QWidget();
        Round_of16->setObjectName("Round_of16");
        label_84 = new QLabel(Round_of16);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(30, 50, 221, 41));
        label_84->setFont(font);
        label_85 = new QLabel(Round_of16);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(30, 260, 271, 61));
        label_85->setFont(font);
        label_86 = new QLabel(Round_of16);
        label_86->setObjectName("label_86");
        label_86->setGeometry(QRect(610, 40, 271, 61));
        label_86->setFont(font);
        label_87 = new QLabel(Round_of16);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(590, 280, 241, 61));
        label_87->setFont(font);
        nb_passes_17 = new QLineEdit(Round_of16);
        nb_passes_17->setObjectName("nb_passes_17");
        nb_passes_17->setGeometry(QRect(330, 60, 141, 41));
        nb_passes_18 = new QLineEdit(Round_of16);
        nb_passes_18->setObjectName("nb_passes_18");
        nb_passes_18->setGeometry(QRect(320, 290, 141, 41));
        nb_passes_19 = new QLineEdit(Round_of16);
        nb_passes_19->setObjectName("nb_passes_19");
        nb_passes_19->setGeometry(QRect(890, 60, 141, 41));
        nb_passes_20 = new QLineEdit(Round_of16);
        nb_passes_20->setObjectName("nb_passes_20");
        nb_passes_20->setGeometry(QRect(900, 310, 141, 41));
        tabWidget_2->addTab(Round_of16, QString());
        Quarter_finals = new QWidget();
        Quarter_finals->setObjectName("Quarter_finals");
        label_80 = new QLabel(Quarter_finals);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(50, 70, 221, 41));
        label_80->setFont(font);
        label_81 = new QLabel(Quarter_finals);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(50, 280, 271, 61));
        label_81->setFont(font);
        label_82 = new QLabel(Quarter_finals);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(520, 70, 271, 61));
        label_82->setFont(font);
        label_83 = new QLabel(Quarter_finals);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(530, 290, 241, 61));
        label_83->setFont(font);
        nb_passes_13 = new QLineEdit(Quarter_finals);
        nb_passes_13->setObjectName("nb_passes_13");
        nb_passes_13->setGeometry(QRect(310, 80, 141, 41));
        nb_passes_14 = new QLineEdit(Quarter_finals);
        nb_passes_14->setObjectName("nb_passes_14");
        nb_passes_14->setGeometry(QRect(310, 300, 141, 41));
        nb_passes_15 = new QLineEdit(Quarter_finals);
        nb_passes_15->setObjectName("nb_passes_15");
        nb_passes_15->setGeometry(QRect(820, 80, 141, 41));
        nb_passes_16 = new QLineEdit(Quarter_finals);
        nb_passes_16->setObjectName("nb_passes_16");
        nb_passes_16->setGeometry(QRect(820, 300, 141, 41));
        tabWidget_2->addTab(Quarter_finals, QString());
        Semi_final = new QWidget();
        Semi_final->setObjectName("Semi_final");
        label_77 = new QLabel(Semi_final);
        label_77->setObjectName("label_77");
        label_77->setGeometry(QRect(60, 220, 271, 61));
        label_77->setFont(font);
        label_78 = new QLabel(Semi_final);
        label_78->setObjectName("label_78");
        label_78->setGeometry(QRect(560, 60, 271, 61));
        label_78->setFont(font);
        label_79 = new QLabel(Semi_final);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(560, 220, 241, 61));
        label_79->setFont(font);
        nb_passes_9 = new QLineEdit(Semi_final);
        nb_passes_9->setObjectName("nb_passes_9");
        nb_passes_9->setGeometry(QRect(360, 60, 141, 41));
        nb_passes_10 = new QLineEdit(Semi_final);
        nb_passes_10->setObjectName("nb_passes_10");
        nb_passes_10->setGeometry(QRect(360, 230, 141, 41));
        nb_passes_11 = new QLineEdit(Semi_final);
        nb_passes_11->setObjectName("nb_passes_11");
        nb_passes_11->setGeometry(QRect(840, 90, 141, 41));
        nb_passes_12 = new QLineEdit(Semi_final);
        nb_passes_12->setObjectName("nb_passes_12");
        nb_passes_12->setGeometry(QRect(830, 230, 141, 41));
        label_76 = new QLabel(Semi_final);
        label_76->setObjectName("label_76");
        label_76->setGeometry(QRect(60, 50, 221, 41));
        label_76->setFont(font);
        tabWidget_2->addTab(Semi_final, QString());
        Final = new QWidget();
        Final->setObjectName("Final");
        label_45 = new QLabel(Final);
        label_45->setObjectName("label_45");
        label_45->setGeometry(QRect(10, 20, 221, 41));
        label_45->setFont(font);
        label_50 = new QLabel(Final);
        label_50->setObjectName("label_50");
        label_50->setGeometry(QRect(0, 220, 271, 61));
        label_50->setFont(font);
        label_51 = new QLabel(Final);
        label_51->setObjectName("label_51");
        label_51->setGeometry(QRect(470, 20, 271, 61));
        label_51->setFont(font);
        label_52 = new QLabel(Final);
        label_52->setObjectName("label_52");
        label_52->setGeometry(QRect(460, 230, 241, 61));
        label_52->setFont(font);
        nb_buts2_2 = new QLineEdit(Final);
        nb_buts2_2->setObjectName("nb_buts2_2");
        nb_buts2_2->setGeometry(QRect(720, 40, 141, 41));
        nb_passes_4 = new QLineEdit(Final);
        nb_passes_4->setObjectName("nb_passes_4");
        nb_passes_4->setGeometry(QRect(720, 250, 141, 41));
        nb_passes_7 = new QLineEdit(Final);
        nb_passes_7->setObjectName("nb_passes_7");
        nb_passes_7->setGeometry(QRect(290, 30, 141, 41));
        nb_passes_8 = new QLineEdit(Final);
        nb_passes_8->setObjectName("nb_passes_8");
        nb_passes_8->setGeometry(QRect(290, 240, 141, 41));
        tabWidget_2->addTab(Final, QString());
        tabWidget->addTab(Best_player, QString());
        Recherche = new QLineEdit(joueur);
        Recherche->setObjectName("Recherche");
        Recherche->setGeometry(QRect(300, 20, 201, 41));
        label_2 = new QLabel(joueur);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 311, 51));
        label_2->setFont(font);
        pushButton_3 = new QPushButton(joueur);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(550, 20, 281, 61));
        pushButton_3->setFont(font1);

        retranslateUi(joueur);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(joueur);
    } // setupUi

    void retranslateUi(QDialog *joueur)
    {
        joueur->setWindowTitle(QCoreApplication::translate("joueur", "Dialog", nullptr));
        label_11->setText(QCoreApplication::translate("joueur", "Nom", nullptr));
        label_12->setText(QCoreApplication::translate("joueur", "Prenom", nullptr));
        label_13->setText(QCoreApplication::translate("joueur", "Age", nullptr));
        label_14->setText(QCoreApplication::translate("joueur", "Nationalit\303\250", nullptr));
        label_15->setText(QCoreApplication::translate("joueur", "Poste", nullptr));
        label_16->setText(QCoreApplication::translate("joueur", "Equipe Actuelle", nullptr));
        label_17->setText(QCoreApplication::translate("joueur", "Nombres des matches", nullptr));
        label_18->setText(QCoreApplication::translate("joueur", "Nombres de buts", nullptr));
        label_3->setText(QCoreApplication::translate("joueur", "Nombre de passes", nullptr));
        label_6->setText(QCoreApplication::translate("joueur", "Nombre de clean sheet", nullptr));
        Nom->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Lionel</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Prenom->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Messi</p></body></html>", nullptr));
        Age->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">38</p></body></html>", nullptr));
        Nationalite->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Argentin</p></body></html>", nullptr));
        Poste->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Attaquant</p></body></html>", nullptr));
        Equipe_Actuelle->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Inter Miami</p></body></html>", nullptr));
        ID_joueur->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">001</p></body></html>", nullptr));
        nb_matches->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">900</p></body></html>", nullptr));
        nb_passes->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">369</p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("joueur", "ID de joueur", nullptr));
        nb_buts->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">684</p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("joueur", "Nombres des matches en ucl", nullptr));
        label_22->setText(QCoreApplication::translate("joueur", "Nombres de buts en ucl", nullptr));
        label_23->setText(QCoreApplication::translate("joueur", "Nombre de passes en ucl", nullptr));
        label_24->setText(QCoreApplication::translate("joueur", "Nombre de clean sheet en ucl", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">14</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">12</p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">8</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Consulter_j), QCoreApplication::translate("joueur", "Consulter Joueur", nullptr));
        label_4->setText(QCoreApplication::translate("joueur", "Nom", nullptr));
        label_5->setText(QCoreApplication::translate("joueur", "Prenom", nullptr));
        label_7->setText(QCoreApplication::translate("joueur", "Equipe actuel", nullptr));
        label_8->setText(QCoreApplication::translate("joueur", "Poste", nullptr));
        label_9->setText(QCoreApplication::translate("joueur", "Age", nullptr));
        label_10->setText(QCoreApplication::translate("joueur", "ID_joueur", nullptr));
        label_20->setText(QCoreApplication::translate("joueur", "Nationalit\303\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Ajouter_j), QCoreApplication::translate("joueur", "Ajouter Joueur", nullptr));
        label_25->setText(QCoreApplication::translate("joueur", "Equipe actuel", nullptr));
        label_26->setText(QCoreApplication::translate("joueur", "Nombres des matches", nullptr));
        label_27->setText(QCoreApplication::translate("joueur", "Nombres de buts", nullptr));
        label_28->setText(QCoreApplication::translate("joueur", "Nombre de passes", nullptr));
        label_29->setText(QCoreApplication::translate("joueur", "Nombre de clean sheet", nullptr));
        pushButton_2->setText(QCoreApplication::translate("joueur", "Valid\303\250 Modification", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Modifier_j), QCoreApplication::translate("joueur", "Modifier Joueur", nullptr));
        label->setText(QCoreApplication::translate("joueur", "Etes vous sure?", nullptr));
        radioButton->setText(QCoreApplication::translate("joueur", "Oui", nullptr));
        radioButton_2->setText(QCoreApplication::translate("joueur", "Non", nullptr));
        pushButton->setText(QCoreApplication::translate("joueur", "Valid\303\250 Suppression", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Supprimer_j), QCoreApplication::translate("joueur", "Supprimer Joueur", nullptr));
        label_30->setText(QCoreApplication::translate("joueur", "La Valeur marchande de ce joueur est:", nullptr));
        Valeur_marchande->setHtml(QCoreApplication::translate("joueur", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">200.000.00$</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Valeur_m), QCoreApplication::translate("joueur", "Valeur marchande", nullptr));
        label_84->setText(QCoreApplication::translate("joueur", "Best goalkeeper", nullptr));
        label_85->setText(QCoreApplication::translate("joueur", "Best defender", nullptr));
        label_86->setText(QCoreApplication::translate("joueur", "Best midlefielder", nullptr));
        label_87->setText(QCoreApplication::translate("joueur", "Best Stricker", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Round_of16), QCoreApplication::translate("joueur", "Round of 16", nullptr));
        label_80->setText(QCoreApplication::translate("joueur", "Best goalkeeper", nullptr));
        label_81->setText(QCoreApplication::translate("joueur", "Best defender", nullptr));
        label_82->setText(QCoreApplication::translate("joueur", "Best midlefielder", nullptr));
        label_83->setText(QCoreApplication::translate("joueur", "Best Stricker", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Quarter_finals), QCoreApplication::translate("joueur", "Quarter finals", nullptr));
        label_77->setText(QCoreApplication::translate("joueur", "Best defender", nullptr));
        label_78->setText(QCoreApplication::translate("joueur", "Best midlefielder", nullptr));
        label_79->setText(QCoreApplication::translate("joueur", "Best Stricker", nullptr));
        label_76->setText(QCoreApplication::translate("joueur", "Best goalkeeper", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Semi_final), QCoreApplication::translate("joueur", "Semi final", nullptr));
        label_45->setText(QCoreApplication::translate("joueur", "Best goalkeeper", nullptr));
        label_50->setText(QCoreApplication::translate("joueur", "Best defender", nullptr));
        label_51->setText(QCoreApplication::translate("joueur", "Best midlefielder", nullptr));
        label_52->setText(QCoreApplication::translate("joueur", "Best Stricker", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Final), QCoreApplication::translate("joueur", "Final", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Best_player), QCoreApplication::translate("joueur", "Best Player", nullptr));
        label_2->setText(QCoreApplication::translate("joueur", "Donnez l'ID du joueur:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("joueur", "Valider la recherche", nullptr));
    } // retranslateUi

};

namespace Ui {
    class joueur: public Ui_joueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOUEUR_H
