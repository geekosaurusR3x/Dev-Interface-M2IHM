#ifndef DIALOGDESSINFORMEEXTRA_H
#define DIALOGDESSINFORMEEXTRA_H

#include <QDialog>
#include"labeldessinable.h"
#include <QPolygon>

namespace Ui {
class DialogDessinFormeExtra;
}

/**
 * @brief Classe de dialogue de dessin de polygone
 */
class DialogDessinFormeExtra : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogDessinFormeExtra(LabelDessinable*, QWidget *parent = 0);
    ~DialogDessinFormeExtra();
    int getNbVertex();
    bool isValid();
private:
    Ui::DialogDessinFormeExtra *ui;
    LabelDessinable  *label;
    int defaultSliderValue;
    LabelDessinable* mMainPreviewLabel;
private slots:
    void on_SliderTaillePainceau_valueChanged(int value);
    void on_BoutonReinitialiser_clicked();
};

#endif // DIALOGDESSINFORMEEXTRA_H
