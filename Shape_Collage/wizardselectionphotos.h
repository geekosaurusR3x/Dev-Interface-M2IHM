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
private:
    GrillePhotos *photos;
    QLabel *nombrePhotos;
    QPushButton *boutonPlus;
    QPushButton *boutonMoins;
    QPushButton *boutonClear;
private slots:
    void AjouterPhotos();
    void RetirerPhotos();
    void EffacerListe();
    void DegriseBoutonRetirerImage();
    void GriserBoutonRetirerImage();
};

#endif // WIZARDSELECTIONPHOTOS_H
