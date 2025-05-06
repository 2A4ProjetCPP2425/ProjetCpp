/********************************************************************************
** Form generated from reading UI file 'G_Tours.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_G_TOURS_H
#define UI_G_TOURS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_G_Tours
{
public:
    QWidget *centralwidget;
    QTabWidget *tableWidgetTours;
    QWidget *tab;
    QPushButton *pushButton1;
    QLineEdit *linetourname;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_21;
    QLineEdit *linetourname_4;
    QLabel *label_22;
    QComboBox *comboBox_7;
    QWidget *tab_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QTableWidget *linetourname_5;
    QLineEdit *lineEdit;
    QLabel *label_13;
    QRadioButton *radioName;
    QRadioButton *radioRounds;
    QRadioButton *radioLevel;
    QPushButton *pushButton_exportPDF;
    QWidget *tab_3;
    QLabel *label_7;
    QLCDNumber *lcdActive;
    QLCDNumber *lcdNonActive;
    QLabel *label_8;
    QPushButton *pushButton;
    QWidget *tab_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QComboBox *comboBox_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *G_Tours)
    {
        if (G_Tours->objectName().isEmpty())
            G_Tours->setObjectName("G_Tours");
        G_Tours->resize(800, 600);
        centralwidget = new QWidget(G_Tours);
        centralwidget->setObjectName("centralwidget");
        tableWidgetTours = new QTabWidget(centralwidget);
        tableWidgetTours->setObjectName("tableWidgetTours");
        tableWidgetTours->setGeometry(QRect(0, 0, 801, 551));
        tableWidgetTours->setMinimumSize(QSize(801, 551));
        tableWidgetTours->setMaximumSize(QSize(801, 551));
        tableWidgetTours->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #1A3D7C; /* Bleu fonc\303\251 inspir\303\251 du football */\n"
"    border: 2px solid #FFD700; /* Dor\303\251 pour une touche premium */\n"
"}\n"
"\n"
"QLabel {\n"
"    color: black;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 2px solid #FFD700;\n"
"    background: #1A3D7C;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #0E2A58;\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: 1px solid #FFD700;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: #FFD700;\n"
"    color: #1A3D7C;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #FFD700;\n"
"    color: #1A3D7C;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #FFC107;\n"
"}\n"
"\n"
"QLineEdit, QTextEdit "
                        "{\n"
"    background-color: white;\n"
"    border: 1px solid #FFD700;\n"
"    padding: 5px;\n"
"    border-radius: 3px;\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        pushButton1 = new QPushButton(tab);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(20, 390, 192, 81));
        pushButton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E7D32; /* Vert fonc\303\251, style football */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border-radius: 5px;\n"
"    border: 2px solid #1B5E20; /* Vert plus fonc\303\251 pour une touche premium */\n"
"    transition: background-color 0.3s, border-color 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43A047; /* Vert plus clair pour l'effet hover */\n"
"    border-color: #388E3C;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1B5E20; /* Vert tr\303\250s fonc\303\251 pour effet de pression */\n"
"    border-color: #145A32;\n"
"}\n"
""));
        linetourname = new QLineEdit(tab);
        linetourname->setObjectName("linetourname");
        linetourname->setGeometry(QRect(230, 20, 431, 41));
        linetourname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;  /* White background */\n"
"    color: #333333;             /* Dark gray text */\n"
"    border: 1px solid #cccccc;  /* Light gray border */\n"
"    border-radius: 5px;         /* Rounded corners */\n"
"    padding: 10px;              /* Padding for inner space */\n"
"    font: 14px \"Segoe UI\", sans-serif; /* Modern font */\n"
"    transition: all 0.3s ease;  /* Smooth transition for all visual changes */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: #007bff;      /* Blue border on hover */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #007bff;      /* Blue border on focus */\n"
"    box-shadow: 0 0 5px rgba(0, 123, 255, 0.6); /* Soft blue glow effect */\n"
"    background-color: #f7f7f7;  /* Light gray background on focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #f0f0f0;  /* Light gray background when disabled */\n"
"    color: #999999;              /* Light gray text when disabled */\n"
"    border-color: #dddddd;     "
                        " /* Light border color */\n"
"    cursor: not-allowed;        /* Disabled cursor */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #999999;              /* Placeholder text in light gray */\n"
"    font-style: italic;          /* Italic placeholder text */\n"
"}\n"
""));
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(230, 170, 431, 28));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(230, 120, 431, 28));
        dateEdit = new QDateEdit(tab);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(230, 270, 431, 29));
        dateEdit_2 = new QDateEdit(tab);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(230, 320, 431, 29));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(510, 390, 271, 85));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: white;\n"
"    color: black;  /* You can change the text color if needed */\n"
"}\n"
""));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 141, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 170, 141, 31));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 120, 141, 31));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 270, 141, 31));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(80, 320, 141, 31));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(350, 420, 151, 31));
        label_21 = new QLabel(tab);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(80, 70, 141, 31));
        linetourname_4 = new QLineEdit(tab);
        linetourname_4->setObjectName("linetourname_4");
        linetourname_4->setGeometry(QRect(230, 70, 431, 41));
        linetourname_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;  /* White background */\n"
"    color: #333333;             /* Dark gray text */\n"
"    border: 1px solid #cccccc;  /* Light gray border */\n"
"    border-radius: 5px;         /* Rounded corners */\n"
"    padding: 10px;              /* Padding for inner space */\n"
"    font: 14px \"Segoe UI\", sans-serif; /* Modern font */\n"
"    transition: all 0.3s ease;  /* Smooth transition for all visual changes */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: #007bff;      /* Blue border on hover */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #007bff;      /* Blue border on focus */\n"
"    box-shadow: 0 0 5px rgba(0, 123, 255, 0.6); /* Soft blue glow effect */\n"
"    background-color: #f7f7f7;  /* Light gray background on focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #f0f0f0;  /* Light gray background when disabled */\n"
"    color: #999999;              /* Light gray text when disabled */\n"
"    border-color: #dddddd;     "
                        " /* Light border color */\n"
"    cursor: not-allowed;        /* Disabled cursor */\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #999999;              /* Placeholder text in light gray */\n"
"    font-style: italic;          /* Italic placeholder text */\n"
"}\n"
""));
        label_22 = new QLabel(tab);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(80, 220, 141, 31));
        comboBox_7 = new QComboBox(tab);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");
        comboBox_7->setGeometry(QRect(230, 220, 431, 28));
        tableWidgetTours->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(100, 420, 83, 51));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton *championsButton = new QPushButton(\"Champions League\", rightPanel);\n"
"championsButton->setGeometry(50, 50, 200, 50); // Position and size of the button\n"
"\n"
"// Applying the stylesheet for the button\n"
"championsButton->setStyleSheet(\n"
"    \"background-color: #005bbb; \"\n"
"    \"color: white; \"\n"
"    \"font: bold 14px; \"\n"
"    \"padding: 10px 20px; \"\n"
"    \"border: 2px solid #003366; \"\n"
"    \"border-radius: 12px; \"\n"
"    \"text-align: center; \"\n"
"    \"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.3);\"\n"
"    \"QPushButton:hover { \"\n"
"    \"background-color: #003366; \"\n"
"    \"border: 2px solid #005bbb; \"\n"
"    \"} \"\n"
"    \"QPushButton:pressed { \"\n"
"    \"background-color: #001f3d; \"\n"
"    \"border: 2px solid #003366; \"\n"
"    \"box-shadow: 0 2px 4px rgba(0, 0, 0, 0.5); \"\n"
"    \"} \"\n"
"    \"QPushButton:focus { \"\n"
"    \"outline: none; \"\n"
"    \"}\"\n"
");\n"
""));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(100, 370, 83, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton *championsButton = new QPushButton(\"Champions League\", rightPanel);\n"
"championsButton->setGeometry(50, 50, 200, 50); // Position and size of the button\n"
"\n"
"// Applying the stylesheet for the button\n"
"championsButton->setStyleSheet(\n"
"    \"background-color: #005bbb; \"\n"
"    \"color: white; \"\n"
"    \"font: bold 14px; \"\n"
"    \"padding: 10px 20px; \"\n"
"    \"border: 2px solid #003366; \"\n"
"    \"border-radius: 12px; \"\n"
"    \"text-align: center; \"\n"
"    \"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.3);\"\n"
"    \"QPushButton:hover { \"\n"
"    \"background-color: #003366; \"\n"
"    \"border: 2px solid #005bbb; \"\n"
"    \"} \"\n"
"    \"QPushButton:pressed { \"\n"
"    \"background-color: #001f3d; \"\n"
"    \"border: 2px solid #003366; \"\n"
"    \"box-shadow: 0 2px 4px rgba(0, 0, 0, 0.5); \"\n"
"    \"} \"\n"
"    \"QPushButton:focus { \"\n"
"    \"outline: none; \"\n"
"    \"}\"\n"
");\n"
""));
        linetourname_5 = new QTableWidget(tab_2);
        if (linetourname_5->columnCount() < 8)
            linetourname_5->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        linetourname_5->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        linetourname_5->setObjectName("linetourname_5");
        linetourname_5->setGeometry(QRect(10, 140, 781, 192));
        linetourname_5->setRowCount(0);
        linetourname_5->setColumnCount(8);
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 10, 411, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #0077cc;  /* Bleu professionnel */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 6px 12px;          /* Espacement interne */\n"
"    font-size: 14px;            /* Taille du texte */\n"
"    color: #333;                /* Couleur du texte */\n"
"    background-color: #f8f8f8;  /* Fond l\303\251g\303\250rement gris */\n"
"    selection-background-color: #0077cc; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QLineEdit:hover {\n"
"    border: 2px solid #005fa3; /* Bleu plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet quand on clique (focus) */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #004080;\n"
"    background-color: white;\n"
"}\n"
""));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(50, 10, 101, 31));
        radioName = new QRadioButton(tab_2);
        radioName->setObjectName("radioName");
        radioName->setGeometry(QRect(140, 50, 112, 26));
        radioRounds = new QRadioButton(tab_2);
        radioRounds->setObjectName("radioRounds");
        radioRounds->setGeometry(QRect(300, 50, 112, 26));
        radioLevel = new QRadioButton(tab_2);
        radioLevel->setObjectName("radioLevel");
        radioLevel->setGeometry(QRect(460, 50, 112, 26));
        pushButton_exportPDF = new QPushButton(tab_2);
        pushButton_exportPDF->setObjectName("pushButton_exportPDF");
        pushButton_exportPDF->setGeometry(QRect(350, 390, 101, 51));
        pushButton_exportPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E7D32; /* Vert fonc\303\251, style football */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border-radius: 5px;\n"
"    border: 2px solid #1B5E20; /* Vert plus fonc\303\251 pour une touche premium */\n"
"    transition: background-color 0.3s, border-color 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43A047; /* Vert plus clair pour l'effet hover */\n"
"    border-color: #388E3C;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1B5E20; /* Vert tr\303\250s fonc\303\251 pour effet de pression */\n"
"    border-color: #145A32;\n"
"}\n"
""));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MailAttachment));
        pushButton_exportPDF->setIcon(icon);
        tableWidgetTours->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_7 = new QLabel(tab_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(130, 90, 121, 20));
        lcdActive = new QLCDNumber(tab_3);
        lcdActive->setObjectName("lcdActive");
        lcdActive->setGeometry(QRect(90, 160, 201, 231));
        lcdNonActive = new QLCDNumber(tab_3);
        lcdNonActive->setObjectName("lcdNonActive");
        lcdNonActive->setGeometry(QRect(390, 160, 201, 231));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(410, 90, 161, 20));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(270, 440, 171, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E7D32; /* Vert fonc\303\251, style football */\n"
"    color: white;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    border-radius: 5px;\n"
"    border: 2px solid #1B5E20; /* Vert plus fonc\303\251 pour une touche premium */\n"
"    transition: background-color 0.3s, border-color 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #43A047; /* Vert plus clair pour l'effet hover */\n"
"    border-color: #388E3C;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1B5E20; /* Vert tr\303\250s fonc\303\251 pour effet de pression */\n"
"    border-color: #145A32;\n"
"}\n"
""));
        tableWidgetTours->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        radioButton = new QRadioButton(tab_4);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(240, 160, 21, 26));
        radioButton_2 = new QRadioButton(tab_4);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(260, 160, 21, 26));
        radioButton_3 = new QRadioButton(tab_4);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(280, 160, 21, 26));
        radioButton_4 = new QRadioButton(tab_4);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(300, 160, 21, 26));
        radioButton_5 = new QRadioButton(tab_4);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(320, 160, 21, 26));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(530, 160, 151, 41));
        tableWidget = new QTableWidget(tab_4);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(75, 270, 381, 192));
        comboBox_3 = new QComboBox(tab_4);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(220, 80, 311, 28));
        tableWidgetTours->addTab(tab_4, QString());
        G_Tours->setCentralWidget(centralwidget);
        menubar = new QMenuBar(G_Tours);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        G_Tours->setMenuBar(menubar);
        statusbar = new QStatusBar(G_Tours);
        statusbar->setObjectName("statusbar");
        G_Tours->setStatusBar(statusbar);

        retranslateUi(G_Tours);

        tableWidgetTours->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(G_Tours);
    } // setupUi

    void retranslateUi(QMainWindow *G_Tours)
    {
        G_Tours->setWindowTitle(QCoreApplication::translate("G_Tours", "MainWindow", nullptr));
        pushButton1->setText(QCoreApplication::translate("G_Tours", "add", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("G_Tours", "3", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("G_Tours", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("G_Tours", "1", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("G_Tours", "Quatre Final", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("G_Tours", "Demi Final", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("G_Tours", "Final", nullptr));

        label->setText(QCoreApplication::translate("G_Tours", "TOURS NAME :", nullptr));
        label_2->setText(QCoreApplication::translate("G_Tours", "TOUR_LEVEL", nullptr));
        label_3->setText(QCoreApplication::translate("G_Tours", "ROUNDS :", nullptr));
        label_4->setText(QCoreApplication::translate("G_Tours", "start_date", nullptr));
        label_5->setText(QCoreApplication::translate("G_Tours", "end_date", nullptr));
        label_6->setText(QCoreApplication::translate("G_Tours", "descreption", nullptr));
        label_21->setText(QCoreApplication::translate("G_Tours", "TOUR_location :", nullptr));
        label_22->setText(QCoreApplication::translate("G_Tours", "status :", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("G_Tours", "active", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("G_Tours", "non active", nullptr));

        tableWidgetTours->setTabText(tableWidgetTours->indexOf(tab), QCoreApplication::translate("G_Tours", "ADD TOUR", nullptr));
        pushButton_4->setText(QCoreApplication::translate("G_Tours", "update", nullptr));
        pushButton_3->setText(QCoreApplication::translate("G_Tours", "delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = linetourname_5->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("G_Tours", "tour id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = linetourname_5->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("G_Tours", "tour name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = linetourname_5->horizontalHeaderItem(4);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("G_Tours", "Rounds", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = linetourname_5->horizontalHeaderItem(5);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("G_Tours", "End Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = linetourname_5->horizontalHeaderItem(6);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("G_Tours", "Start Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = linetourname_5->horizontalHeaderItem(7);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("G_Tours", "Status", nullptr));
        lineEdit->setText(QString());
        label_13->setText(QCoreApplication::translate("G_Tours", "Rechercher :", nullptr));
        radioName->setText(QCoreApplication::translate("G_Tours", "Name", nullptr));
        radioRounds->setText(QCoreApplication::translate("G_Tours", "Rounds", nullptr));
        radioLevel->setText(QCoreApplication::translate("G_Tours", "Level", nullptr));
        pushButton_exportPDF->setText(QCoreApplication::translate("G_Tours", "pdf", nullptr));
        tableWidgetTours->setTabText(tableWidgetTours->indexOf(tab_2), QCoreApplication::translate("G_Tours", "LISTE_TOUR", nullptr));
        label_7->setText(QCoreApplication::translate("G_Tours", "TOURS ACTIVE ", nullptr));
        label_8->setText(QCoreApplication::translate("G_Tours", "TOURS NON ACTIVE ", nullptr));
        pushButton->setText(QCoreApplication::translate("G_Tours", "statistique", nullptr));
        tableWidgetTours->setTabText(tableWidgetTours->indexOf(tab_3), QCoreApplication::translate("G_Tours", "Statistiques", nullptr));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        radioButton_5->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("G_Tours", "Submit Rating", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("G_Tours", "Tour Name ", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("G_Tours", "Average Rating", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("G_Tours", "Number of Ratings   ", nullptr));
        tableWidgetTours->setTabText(tableWidgetTours->indexOf(tab_4), QCoreApplication::translate("G_Tours", "Tour Ratings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class G_Tours: public Ui_G_Tours {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_G_TOURS_H
