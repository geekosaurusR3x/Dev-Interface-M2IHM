#include "wizardselectionphotos.h"

WizardSelectionPhotos::WizardSelectionPhotos(QWidget *parent):QWizardPage(parent)
{
    this->setTitle("Sélection des photos pour le collage");
    QLabel *label = new QLabel("Cliquez sur '+' ou glissez et déposez les  pour ajouter des photos dans le cadre."
                               " Cliquez sur \"suivant\" pour continuer");
    label->setWordWrap(true);

    this->photos = new GrillePhotos();

    QVBoxLayout *boiteVerticale = new QVBoxLayout();
    this->boutonPlus = new QPushButton("+");
    this->boutonMoins = new QPushButton("-");
    this->boutonMoins->setEnabled(false);
    this->boutonClear = new QPushButton("Effacer la liste");
    this->boutonClear->setEnabled(false);

    QHBoxLayout *boiteHorizontale1 = new QHBoxLayout();
    nombrePhotos = new QLabel("0 photos");
    boiteHorizontale1->addWidget(nombrePhotos);

    QHBoxLayout *boiteHorizontale2 = new QHBoxLayout();
    boiteHorizontale2->addWidget(boutonPlus);
    boiteHorizontale2->addWidget(boutonMoins);
    boiteHorizontale2->addWidget(boutonClear);

    boiteVerticale->addWidget(label);
    boiteVerticale->addWidget(photos);
    boiteVerticale->addLayout(boiteHorizontale1);
    boiteVerticale->addLayout(boiteHorizontale2);

    this->setLayout(boiteVerticale);

    //connexion des signaux
    connect(boutonPlus,SIGNAL(clicked()), this,SLOT(AjouterPhotos()));
    connect(boutonMoins,SIGNAL(clicked()), this,SLOT(RetirerPhotos()));
    connect(boutonClear,SIGNAL(clicked()), this,SLOT(EffacerListe()));
    connect(photos,SIGNAL(clicked()),this,SLOT(DegriseBoutonRetirerImage()));
    connect(photos,SIGNAL(clacked()),this,SLOT(GriserBoutonRetirerImage()));
}

WizardSelectionPhotos::~WizardSelectionPhotos()
{
    photos = NULL;
    nombrePhotos = NULL;
    boutonPlus = NULL;
    boutonMoins = NULL;
    boutonClear = NULL;
    delete photos;
    delete nombrePhotos;
    delete boutonPlus;
    delete boutonMoins;
    delete boutonClear;
}
GrillePhotos *WizardSelectionPhotos::getPhotos() const
{
    return photos;
}

void WizardSelectionPhotos::setPhotos(GrillePhotos *value)
{
    photos = value;
}


void WizardSelectionPhotos::AjouterPhotos()
{
    WindowSlave::AjouterImage(photos,boutonMoins,boutonClear,nombrePhotos);
}

void WizardSelectionPhotos::RetirerPhotos()
{
    WindowSlave::RetirerImage(photos,boutonMoins,boutonClear,nombrePhotos);
}

void WizardSelectionPhotos::EffacerListe()
{
    WindowSlave::EffacerListePhoto(photos,boutonMoins,boutonClear,nombrePhotos);
}

void WizardSelectionPhotos::DegriseBoutonRetirerImage()
{
    if(photos->selectedItems().count()>0)
    {
        boutonMoins->setEnabled(true);
    }
    boutonClear->setEnabled(true);
    nombrePhotos->setText(QString::number(photos->count())+" Photos");
}

void WizardSelectionPhotos::GriserBoutonRetirerImage()
{
    boutonMoins->setEnabled(false);
}
