#include "dialogdessinformeextra.h"
#include "ui_dialogdessinformeextra.h"

DialogDessinFormeExtra::DialogDessinFormeExtra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDessinFormeExtra)
{
    ui->setupUi(this);
    label = new LabelClicable(this);
    ui->LaoyoutDessinPolygone->addWidget(label);
}

DialogDessinFormeExtra::~DialogDessinFormeExtra()
{
    delete ui;
    label=NULL;
    delete label;
}
