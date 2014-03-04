#include "dialogapropos.h"
#include "ui_dialogapropos.h"

DialogAPropos::DialogAPropos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAPropos)
{
    ui->setupUi(this);
}

DialogAPropos::~DialogAPropos()
{
    delete ui;
}
