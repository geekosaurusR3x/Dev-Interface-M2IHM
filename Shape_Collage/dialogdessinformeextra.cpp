#include "dialogdessinformeextra.h"
#include "ui_dialogdessinformeextra.h"

DialogDessinFormeExtra::DialogDessinFormeExtra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDessinFormeExtra)
{
    ui->setupUi(this);
    label = new LabelDessinable(this);

    ui->LayoutDessinPolygone->addWidget(label);

    connect(label, SIGNAL(clicked()), this, SLOT(SetPoint()));
}


void DialogDessinFormeExtra::SetPoint() {
    qDebug() << "Set point";
    WindowSlave::DessinerFormeSetPoint(this->label);
}

DialogDessinFormeExtra::~DialogDessinFormeExtra()
{
    delete ui;
    label=NULL;
    delete label;
}
