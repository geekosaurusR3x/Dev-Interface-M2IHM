#include "exceptionerreure.h"

ExceptionErreure::ExceptionErreure(QString msg): QException()
{
    message = msg;
}

void ExceptionErreure::Afficher(QWidget *parent)
{
    QMessageBox::critical(parent,"Attention",message,QMessageBox::Ok);
}
