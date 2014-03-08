#ifndef DIALOGDESSINFORMEEXTRA_H
#define DIALOGDESSINFORMEEXTRA_H

#include <QDialog>
#include"labeldessinable.h"
#include <windowslave.h>
#include <QPolygon>

namespace Ui {
class DialogDessinFormeExtra;
}

class DialogDessinFormeExtra : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDessinFormeExtra(QWidget *parent = 0);
    ~DialogDessinFormeExtra();
    QPolygon getResult();

private:
    Ui::DialogDessinFormeExtra *ui;
    LabelDessinable  *label;

private slots:
};

#endif // DIALOGDESSINFORMEEXTRA_H
