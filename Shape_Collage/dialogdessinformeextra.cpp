#include "dialogdessinformeextra.h"
#include "ui_dialogdessinformeextra.h"

DialogDessinFormeExtra::DialogDessinFormeExtra(LabelDessinable* previewLabel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDessinFormeExtra)
{
    ui->setupUi(this);
    label = new LabelDessinable(this);
    mMainPreviewLabel = previewLabel;
    ui->LayoutDessinPolygone->addWidget(label);
    label->setNbVertex(ui->SliderTaillePainceau->value());
    label->setPreviewLabel(mMainPreviewLabel);
    defaultSliderValue = ui->SliderTaillePainceau->value();
    connect(label, SIGNAL(clicked()), this, SLOT(SetPoint()));
}

int DialogDessinFormeExtra::getNbVertex() {
    return label->getNbVertex();
}

DialogDessinFormeExtra::~DialogDessinFormeExtra()
{
    delete ui;
    label=NULL;
    delete label;
}

void DialogDessinFormeExtra::on_SliderTaillePainceau_valueChanged(int value)
{
    label->setNbVertex(value);
    label->update();
}

void DialogDessinFormeExtra::on_BoutonReinitialiser_clicked()
{
   ui->SliderTaillePainceau->setValue(defaultSliderValue);
   label->setNbVertex(ui->SliderTaillePainceau->value());
   label->clear();
}
