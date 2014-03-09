#ifndef WIZARDSELECTIONFORME_H
#define WIZARDSELECTIONFORME_H
#include<QWizardPage>
#include<QLabel>
#include<QRadioButton>
#include<QLayout>
#include"labeldessinable.h"
#include"windowslave.h"
#include"parameters.h"

/**
 * @brief Page du wizard permettant de sélectionner la forme du collage
 */
class WizardSelectionForme: public QWizardPage
{
    Q_OBJECT
public:
    WizardSelectionForme(QWidget *parent = 0);
    ~WizardSelectionForme();
    CollageForm GetValue();

private:
    QRadioButton *rectangle;
    QRadioButton *cercle;
    QRadioButton *extra;
    LabelDessinable *labelExtra;
private slots:
    void DessinerForme();
    void DessinerFormeSiVide();
};

#endif // WIZARDSELECTIONFORME_H
