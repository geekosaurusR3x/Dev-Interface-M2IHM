#ifndef EXCEPTIONERREURE_H
#define EXCEPTIONERREURE_H

#include<QException>
#include<QString>
#include<QMessageBox>
#include<QWidget>

class ExceptionErreure: public QException
{
public:
    ExceptionErreure(QString msg);
    void raise() const { throw *this; }
    ExceptionErreure *clone() const { return new ExceptionErreure(*this); }
    void Afficher(QWidget* parent);
    virtual ~ExceptionErreure() throw() {}
private:
    QString message;
};

#endif // EXCEPTIONERREURE_H
