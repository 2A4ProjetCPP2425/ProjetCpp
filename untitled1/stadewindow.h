#ifndef STADEWINDOW_H
#define STADEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StadeWindow; }
QT_END_NAMESPACE

class StadeWindow : public QMainWindow
{
    Q_OBJECT

public:
    StadeWindow(QWidget *parent = nullptr);
    ~StadeWindow();

private slots:
    void on_add_button_clicked();
    void on_modifStadeButton_clicked();
    void on_DeleteStadeButton_clicked();
    void on_tableViewStade_doubleClicked(const QModelIndex &index);
    void on_lineEdit_6_textChanged(const QString &arg1);
    void on_trier_Button_clicked();
    void on_pushButton_clicked();
    void displayStadiumLocationStats();
    void on_tableViewStade_clicked(const QModelIndex &index);

private:
    Ui::StadeWindow *ui;
    bool sendStatusChangeSMS(const QString& stadeName, const QString& newStatus);
    QString lastStatus; // To track previous status
};

#endif // STADEWINDOW_H
