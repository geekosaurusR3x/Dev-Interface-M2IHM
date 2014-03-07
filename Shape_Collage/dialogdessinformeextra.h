#ifndef DIALOGDESSINFORMEEXTRA_H
#define DIALOGDESSINFORMEEXTRA_H

#include <QDialog>
#include"labeldessinable.h"
#include <windowslave.h>

namespace Ui {
class DialogDessinFormeExtra;
}

class DialogDessinFormeExtra : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDessinFormeExtra(QWidget *parent = 0);
    ~DialogDessinFormeExtra();
    
private:
    Ui::DialogDessinFormeExtra *ui;
    LabelClicable  *label;

private slots:
    void SetPoint();
};

#endif // DIALOGDESSINFORMEEXTRA_H
