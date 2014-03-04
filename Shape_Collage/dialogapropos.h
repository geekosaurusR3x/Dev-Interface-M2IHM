#ifndef DIALOGAPROPOS_H
#define DIALOGAPROPOS_H

#include <QDialog>

namespace Ui {
class DialogAPropos;
}

class DialogAPropos : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogAPropos(QWidget *parent = 0);
    ~DialogAPropos();
    
private:
    Ui::DialogAPropos *ui;
};

#endif // DIALOGAPROPOS_H
