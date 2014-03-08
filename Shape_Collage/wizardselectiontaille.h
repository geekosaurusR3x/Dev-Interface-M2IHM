#ifndef WIZARDSELECTIONTAILLE_H
#define WIZARDSELECTIONTAILLE_H
#include<QWizardPage>
#include<QLabel>
#include<QLayout>
#include<QGroupBox>
#include<QPushButton>
#include<QLineEdit>
#include<QComboBox>
#include<QRadioButton>
#include<QSlider>
#include<QSpinBox>
#include"windowslave.h"
#include"parameters.h"

class WizardSelectionTaille: public QWizardPage
{
    Q_OBJECT
public:
    WizardSelectionTaille(QWidget *parent = 0);
    ~WizardSelectionTaille();
    QGroupBox * PlacerTailleCollage();
    QGroupBox * PlacerTaillePhoto();
    QGroupBox * PlacerNombrePhoto();
    QGroupBox * PlacerDistanceEntrePhoto();
    void SetParam(Parameters&param);
private:
    QPushButton *boutonModeTailleCollage;
    QLineEdit *largeur;
    QLineEdit *hauteur;
    QComboBox *combotc;
    QLabel *labelX;
    bool ModeTailleCollage;

    QPushButton *boutonModeTaillePhoto;
    QLineEdit *taillPhoto;
    QComboBox *combotp;
    bool ModeTaillePhoto;

    QPushButton *boutonModeNombrePhoto;
    QRadioButton *toutePhotos;
    QRadioButton *nomrePrecisPhotos;
    QLineEdit *nombrePhotos;
    QLabel *nombrePhotoActuel;
    QLabel *labelPhotos;
    bool ModeNombrePhoto;

    QPushButton *boutonModeDistancePhotos;
    QSlider *sliderDistancePhotos;
    QSpinBox *spinboxDistancePhoto;
    QLabel *labelPourcent;
    bool ModeDistanceEntrePhotos;

   int UMTaillePhoto;
   int UMTailleCollage;
private slots:
    void GriseOuDegriseTailleCollage();
    void GriseOuDegriseTaillePhoto();
    void GriseOuDegriseNombrePhoto();
    void GriseOuDegriseDistancePhoto();

    void MAJLargeurHauteur(int index);
    void MAJTaillePhoto(int index);

    void SetEnabledTailleCollage();
    void SetEnabledTaillePhoto();
    void SetEnabledNombrePhoto();
    void SetEnabledDistancePhoto();
};

#endif // WIZARDSELECTIONTAILLE_H
