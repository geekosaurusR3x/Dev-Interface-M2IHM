#ifndef WIZARDSELECTIONPHOTOS_H
#define WIZARDSELECTIONPHOTOS_H
#include<QWizardPage>
#include<QLabel>
#include<QLayout>
#include<QPushButton>
#include"windowslave.h"
#include"grillephotos.h"

class WizardSelectionPhotos : public QWizardPage
{
    Q_OBJECT
public:
    WizardSelectionPhotos(QWidget *parent = 0);
    ~WizardSelectionPhotos();
    /**
     * \return la grille d'image
     */
    GrillePhotos *getPhotos() const;

    /**
     * \brief change la grille d'image
     * \param value nouvelle grille d'image
     */
    void setPhotos(GrillePhotos *value);

private:
    GrillePhotos *photos;
    QLabel *nombrePhotos;
    QPushButton *boutonPlus;
    QPushButton *boutonMoins;
    QPushButton *boutonClear;
private slots:
    /**
     * \brief Ajoute des images dans la grille d'image
     */
    void AjouterPhotos();

    /**
     * \brief Retire l'image sélectionnée dans la grille
     */
    void RetirerPhotos();

    /**
     * \brief Efface la liste des photos de la grille d'images
     */
    void EffacerListe();

    /**
     * \brief Dégrise le bouton boutonMoins
     */
    void DegriseBoutonRetirerImage();

    /**
     * \brief Grise le bouton boutonMoins
     */
    void GriserBoutonRetirerImage();
};

#endif // WIZARDSELECTIONPHOTOS_H
