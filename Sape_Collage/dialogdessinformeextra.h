#ifndef DIALOGDESSINFORMEEXTRA_H
#define DIALOGDESSINFORMEEXTRA_H

#include <QDialog>
#include"labelclicable.h"

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
};

#endif // DIALOGDESSINFORMEEXTRA_H
