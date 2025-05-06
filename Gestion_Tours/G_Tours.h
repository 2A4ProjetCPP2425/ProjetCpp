#ifndef G_TOURS_H
#define G_TOURS_H

#include <QMainWindow>
#include <QTimer>
#include <QButtonGroup>

namespace Ui {
class G_Tours;
}

class G_Tours : public QMainWindow
{
    Q_OBJECT

public:
    explicit G_Tours(QWidget *parent = nullptr);
    ~G_Tours();

private slots:
    void on_pushButton1_clicked();
    void on_pushButton_3_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pushButton5_clicked();
    void on_pushButton_exportPDF_clicked();
    void on_pushButton_clicked();
    void on_btnStatistique_clicked();
    void populateTourComboBox();
    void submitRating();
    void updateTopRatedTours();
    void on_pushButton_4_clicked();

private:
    QButtonGroup* ratingButtons;

private:
    Ui::G_Tours *ui;
    void clearForm();
    void loadDataToTable();
};

#endif // G_TOURS_H
