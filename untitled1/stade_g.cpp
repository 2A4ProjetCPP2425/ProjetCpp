#include "stade_g.h"
#include "ui_stade_g.h"

Stade_g::Stade_g(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stade_g)
{
    ui->setupUi(this);
}

Stade_g::~Stade_g()
{
    delete ui;
}
