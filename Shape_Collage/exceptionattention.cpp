#include "exceptionattention.h"


ExceptionAttention::ExceptionAttention(QString msg): QException()
{
    message = msg;
}

void ExceptionAttention::Afficher(QWidget *parent)
{
    QMessageBox::warning(parent,"Attention",message,QMessageBox::Ok);
}
