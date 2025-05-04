#ifndef STADE_G_H
#define STADE_G_H

#include <QDialog>

namespace Ui {
class Stade_g;
}

class Stade_g : public QDialog
{
    Q_OBJECT

public:
    explicit Stade_g(QWidget *parent = nullptr);
    ~Stade_g();

private:
    Ui::Stade_g *ui;
};

#endif // STADE_G_H
