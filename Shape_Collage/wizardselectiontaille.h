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

class WizardSelectionTaille: public QWizardPage
{
    Q_OBJECT
public:
    WizardSelectionTaille(QWidget *parent = 0);
    ~WizardSelectionTaille();
    /**
     * \return Initialise et retourne le groupebox et les champs de la section Taille du collage
     */
    QGroupBox * PlacerTailleCollage();

    /**
     * \return Initialise et retourne le groupebox et les champs de la section Taille de la photo
     */
    QGroupBox * PlacerTaillePhoto();

    /**
     * \return Initialise et retourne le groupebox et les champs de la section Nombre de photo
     */
    QGroupBox * PlacerNombrePhoto();

    /**
     * \return Initialise et retourne le groupebox et les champs de la section Distance entre les photos
     */
    QGroupBox * PlacerDistanceEntrePhoto();
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
private slots:

    /**
     * \brief Grise les champs de la section Taille du collage si ils sontdégrisés et les dégrise sinon
     */
    void GriseOuDegriseTailleCollage();

    /**
     * \brief Grise les champs de la section Taille de la photo si ils sontdégrisés et les dégrise sinon
     */
    void GriseOuDegriseTaillePhoto();

    /**
     * \brief Grise les champs de la section Nombre de photos si ils sontdégrisés et les dégrise sinon
     */
    void GriseOuDegriseNombrePhoto();

    /**
     * \brief Grise les champs de la section Distance entre les photos si ils sontdégrisés et les dégrise sinon
     */
    void GriseOuDegriseDistancePhoto();

    /**
     * \brief grise ou dégrise les champs de la section Taille du collage et met à jour les autres sections
     */
    void SetEnabledTailleCollage();

    /**
     * \brief grise ou dégrise les champs de la section Taille de la photo et met à jour les autres sections
     */
    void SetEnabledTaillePhoto();

    /**
     * \brief grise ou dégrise les champs de la section Nombre de photos et met à jour les autres sections
     */
    void SetEnabledNombrePhoto();

    /**
     * \brief grise ou dégrise les champs de la section Distanre entre les photos et met à jour les autres sections
     */
    void SetEnabledDistancePhoto();
};

#endif // WIZARDSELECTIONTAILLE_H
