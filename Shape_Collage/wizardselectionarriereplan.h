#ifndef WIZARDSELECTIONARRIEREPLAN_H
#define WIZARDSELECTIONARRIEREPLAN_H
#include<QWizardPage>
#include<QLabel>
#include<QLayout>
#include"labelclicable.h"
#include"windowslave.h"
#include<QRadioButton>
#include"parameters.h"

class WizardSelectionArrierePlan: public QWizardPage
{
    Q_OBJECT
public:
    WizardSelectionArrierePlan(QWidget *parent = 0);
    ~WizardSelectionArrierePlan();
    QHBoxLayout * PlacerArrierePlanPhoto();
    QHBoxLayout * PlacerArrierePlanColorie();
    QHBoxLayout * PlacerArrierePlanTransparent();
    QPixmap GetBackground();
private:
    QRadioButton *boutonRadioTransparent;

    QRadioButton *boutonRadioCouleur;
    LabelClicable *labelCouleur;

    QRadioButton *boutonRadioPhoto;
    LabelClicable *labelPhoto;
    QString lienPhoto;
    QColor mBackgroundColor;
private slots:
    void ChangerCouleurArrierePlan();
    void ChargerPhotoArrierePlan();
    void PhotoSelected();

};

#endif // WIZARDSELECTIONARRIEREPLAN_H
