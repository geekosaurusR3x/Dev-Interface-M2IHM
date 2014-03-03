#ifndef EXCEPTIONATTENTION_H
#define EXCEPTIONATTENTION_H

#include<QException>
#include<QString>
#include<QMessageBox>
#include<QWidget>

class ExceptionAttention : public QException
{
public:
    ExceptionAttention(QString msg);
    void raise() const { throw *this; }
    ExceptionAttention *clone() const { return new ExceptionAttention(*this); }
    void Afficher(QWidget* parent);
private:
    QString message;
};

#endif // EXCEPTIONATTENTION_H
