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

    /**
     * \return Initialise et retourne une boite horizontale contenant les élément de sélection d'un arrière-plan photo
     */
    QHBoxLayout * PlacerArrierePlanPhoto();

    /**
     * \return Initialise et retourne une boite horizontale contenant les élément de sélection d'un arrière-plan colorié
     */
    QHBoxLayout * PlacerArrierePlanColorie();

    /**
     * \return Initialise et retourne une boite horizontale contenant les élément de sélection d'un arrière-plan transparent
     */
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
    /**
     * \brief Change la couleur de l'arrière-plan colorié
     */
    void ChangerCouleurArrierePlan();

    /**
     * \brief Change l'image de l'arrière-plan photo
     */
    void ChargerPhotoArrierePlan();

    /**
     * \brief Change l'image de l'arrière-plan photo si le lien de la photo sélectionnée n'est pas vide
     */
    void PhotoSelected();

};

#endif // WIZARDSELECTIONARRIEREPLAN_H
