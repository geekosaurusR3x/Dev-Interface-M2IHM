#include "wizardselectiontaille.h"

WizardSelectionTaille::WizardSelectionTaille(QWidget *parent):QWizardPage(parent)
{
    this->setTitle("Paramètrage des tailles");
    QLabel *label = new QLabel("Modifiez la taille des différents éléments de votre collage."
                               " Cliquez sur \"suivant\" pour continuer");
    label->setWordWrap(true);
    //taille du collage
    QGroupBox *taille_collage = PlacerTailleCollage();
    //taille photo
    QGroupBox *GBtaille_photo = PlacerTaillePhoto();
    //nombre de photo
    QGroupBox *GBnombrePhoto = PlacerNombrePhoto();
    //distance entre les photos
    QGroupBox *GBdistancePhotos = PlacerDistanceEntrePhoto();

    ModeTailleCollage = false;
    ModeTaillePhoto = true;
    ModeNombrePhoto = true;
    ModeDistanceEntrePhotos = true;

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(taille_collage);
    layout->addWidget(GBtaille_photo);
    layout->addWidget(GBnombrePhoto);
    layout->addWidget(GBdistancePhotos);
    this->setLayout(layout);
    //connexion des signaux
    connect(boutonModeTailleCollage,SIGNAL(clicked()),this,SLOT(SetEnabledTailleCollage()));
    connect(boutonModeTaillePhoto,SIGNAL(clicked()),this,SLOT(SetEnabledTaillePhoto()));
    connect(boutonModeNombrePhoto,SIGNAL(clicked()),this,SLOT(SetEnabledNombrePhoto()));
    connect(boutonModeDistancePhotos,SIGNAL(clicked()),this,SLOT(SetEnabledDistancePhoto()));
    connect(sliderDistancePhotos,SIGNAL(valueChanged(int)),spinboxDistancePhoto,SLOT(setValue(int)));
    connect(spinboxDistancePhoto,SIGNAL(valueChanged(int)),sliderDistancePhotos,SLOT(setValue(int)));
    connect(combotc,SIGNAL(currentIndexChanged(int)),this,SLOT(MAJLargeurHauteur(int)));
    connect(combotp,SIGNAL(currentIndexChanged(int)),this,SLOT(MAJTaillePhoto(int)));
    sliderDistancePhotos->setValue(67);

}

WizardSelectionTaille::~WizardSelectionTaille()
{
    boutonModeTailleCollage = NULL; delete boutonModeTailleCollage;
    largeur = NULL; delete largeur;
    hauteur = NULL; delete hauteur;
    combotc = NULL; delete combotc;
    labelX = NULL; delete labelX;
    boutonModeTaillePhoto = NULL; delete boutonModeTaillePhoto;
    taillPhoto = NULL; delete taillPhoto;
    combotp = NULL; delete combotp;
    boutonModeNombrePhoto = NULL; delete boutonModeNombrePhoto;
    toutePhotos = NULL; delete toutePhotos;
    nomrePrecisPhotos = NULL; delete nomrePrecisPhotos;
    nombrePhotos = NULL; delete nombrePhotos;
    nombrePhotoActuel = NULL; delete nombrePhotoActuel;
    labelPhotos = NULL; delete labelPhotos;
    boutonModeDistancePhotos = NULL; delete boutonModeDistancePhotos;
    sliderDistancePhotos = NULL; delete sliderDistancePhotos;
    spinboxDistancePhoto = NULL; delete spinboxDistancePhoto;
    labelPourcent = NULL; delete labelPourcent;
}

QGroupBox * WizardSelectionTaille::PlacerTailleCollage()
{
    QGroupBox *taille_collage = new QGroupBox("Taille du collage");
    QVBoxLayout *boiteVerticaleTailleCollage = new QVBoxLayout();
    QHBoxLayout *boiteHorizontaleTailleCollage1 = new QHBoxLayout();
    boiteHorizontaleTailleCollage1->addWidget(new QLabel("Mode"));
    boiteHorizontaleTailleCollage1->addWidget(new QLabel("Largeur"));
    boiteHorizontaleTailleCollage1->addWidget(new QLabel(" "));
    boiteHorizontaleTailleCollage1->addWidget(new QLabel("Hauteur"));
    boiteHorizontaleTailleCollage1->addWidget(new QLabel(" "));
    boiteVerticaleTailleCollage->addLayout(boiteHorizontaleTailleCollage1);
    QHBoxLayout *boiteHorizontaleTailleCollage2 = new QHBoxLayout();
    this->boutonModeTailleCollage = new QPushButton("Auto");
    this->largeur = new QLineEdit("1366");
    largeur->setEnabled(false);
    this->hauteur = new QLineEdit("768");
    hauteur->setEnabled(false);
    this->combotc = new QComboBox();
    combotc->setEnabled(false);
    this->labelX = new QLabel("X");
    labelX->setEnabled(false);
    combotc->addItem("Pixels");
    combotc->addItem("Pouces");
    combotc->addItem("Cm");
    combotc->setEnabled(false);
    boiteHorizontaleTailleCollage2->addWidget(boutonModeTailleCollage);
    boiteHorizontaleTailleCollage2->addWidget(largeur);
    boiteHorizontaleTailleCollage2->addWidget(labelX);
    boiteHorizontaleTailleCollage2->addWidget(hauteur);
    boiteHorizontaleTailleCollage2->addWidget(combotc);
    boiteVerticaleTailleCollage->addLayout(boiteHorizontaleTailleCollage2);
    taille_collage->setLayout(boiteVerticaleTailleCollage);

    return taille_collage;
}

QGroupBox * WizardSelectionTaille::PlacerTaillePhoto()
{
    QGroupBox *GBtaille_photo = new QGroupBox("Taille de la photo");
    QHBoxLayout *boiteVerticaleTaillePhoto = new QHBoxLayout();
    this->boutonModeTaillePhoto = new QPushButton("Manuel");
    this->taillPhoto = new QLineEdit("200");
    this->combotp = new QComboBox();
    combotp->addItem("Pixels");
    combotp->addItem("Pouces");
    combotp->addItem("Cm");
    boiteVerticaleTaillePhoto->addWidget(boutonModeTaillePhoto);
    boiteVerticaleTaillePhoto->addWidget(taillPhoto);
    boiteVerticaleTaillePhoto->addWidget(combotp);
    GBtaille_photo->setLayout(boiteVerticaleTaillePhoto);

    return GBtaille_photo;
}

QGroupBox * WizardSelectionTaille::PlacerNombrePhoto()
{
    QGroupBox *GBnombrePhoto = new QGroupBox("Nombre de Photo");
    QVBoxLayout *boiteVerticaleNombrePhoto = new QVBoxLayout();
    QHBoxLayout *boiteHorizontaleNombrePhoto1 = new QHBoxLayout();
    QHBoxLayout *boiteHorizontaleNombrePhoto2 = new QHBoxLayout();
    this->nombrePhotoActuel = new QLabel("Nombre actuel de photo :");
    boiteHorizontaleNombrePhoto1->addWidget(nombrePhotoActuel);
    this->boutonModeNombrePhoto = new QPushButton("Manuel");
    this->toutePhotos = new QRadioButton("Tout");
    this->nomrePrecisPhotos = new QRadioButton("");
    this->nombrePhotos = new QLineEdit("150");
    this->labelPhotos = new QLabel("photos");
    boiteHorizontaleNombrePhoto2->addWidget(boutonModeNombrePhoto);
    boiteHorizontaleNombrePhoto2->addWidget(toutePhotos);
    boiteHorizontaleNombrePhoto2->addWidget(nomrePrecisPhotos);
    boiteHorizontaleNombrePhoto2->addWidget(nombrePhotos);
    boiteHorizontaleNombrePhoto2->addWidget(labelPhotos);
    boiteVerticaleNombrePhoto->addLayout(boiteHorizontaleNombrePhoto1);
    boiteVerticaleNombrePhoto->addLayout(boiteHorizontaleNombrePhoto2);
    GBnombrePhoto->setLayout(boiteVerticaleNombrePhoto);

    return GBnombrePhoto;
}

QGroupBox * WizardSelectionTaille::PlacerDistanceEntrePhoto()
{
    QGroupBox *GBdistancePhotos = new QGroupBox("Distance entre les photos");
    QHBoxLayout *boiteHorizontaleDistancePhotos = new QHBoxLayout();
    this->boutonModeDistancePhotos = new QPushButton("Manuel");
    this->sliderDistancePhotos = new QSlider(Qt::Horizontal);
    sliderDistancePhotos->setRange(0,200);
    this->spinboxDistancePhoto = new QSpinBox();
    spinboxDistancePhoto->setRange(0,500);
    this->labelPourcent = new QLabel("%");
    boiteHorizontaleDistancePhotos->addWidget(boutonModeDistancePhotos);
    boiteHorizontaleDistancePhotos->addWidget(sliderDistancePhotos);
    boiteHorizontaleDistancePhotos->addWidget(spinboxDistancePhoto);
    boiteHorizontaleDistancePhotos->addWidget(labelPourcent);
    GBdistancePhotos->setLayout(boiteHorizontaleDistancePhotos);

    return GBdistancePhotos;
}



void WizardSelectionTaille::GriseOuDegriseTailleCollage()
{
    QWidget *temp[4]={largeur,hauteur,combotc,labelX};
    WindowSlave::GriseOuDegriseGroupe(ModeTailleCollage,boutonModeTailleCollage,
                                      QString("la taille du collage"),temp,4);
}

void WizardSelectionTaille::GriseOuDegriseTaillePhoto()
{
    QWidget *temp[2]={taillPhoto,combotp};
    WindowSlave::GriseOuDegriseGroupe(ModeTaillePhoto,boutonModeTaillePhoto,
                                      QString("la taille de la photo dans le collage"),temp,2);
}

void WizardSelectionTaille::GriseOuDegriseNombrePhoto()
{
    QWidget *temp[4]={nombrePhotos,nomrePrecisPhotos,toutePhotos,labelPhotos};
    WindowSlave::GriseOuDegriseGroupe(ModeNombrePhoto,boutonModeNombrePhoto,
                                      QString("le nombre de photos du collage"),temp,4);
}

void WizardSelectionTaille::GriseOuDegriseDistancePhoto()
{
    QWidget *temp[3]={sliderDistancePhotos,spinboxDistancePhoto,labelPourcent};
    WindowSlave::GriseOuDegriseGroupe(ModeDistanceEntrePhotos,boutonModeDistancePhotos,
                                      QString("l'espacement des photos du collage"),temp,3);
}

void WizardSelectionTaille::SetEnabledTailleCollage()
{
    bool mode=this->ModeTailleCollage;
    GriseOuDegriseTailleCollage();
    if(!mode){
        GriseOuDegriseTaillePhoto();
    }
    else{
        if(!this->ModeTaillePhoto){
            GriseOuDegriseTaillePhoto();
        }
        else{
            if(!this->ModeNombrePhoto){
                GriseOuDegriseNombrePhoto();
            }
            else{
                GriseOuDegriseDistancePhoto();
            }
        }
    }

}

void WizardSelectionTaille::SetEnabledTaillePhoto()
{
    bool mode=this->ModeTaillePhoto;
    GriseOuDegriseTaillePhoto();
    if(!mode){
        GriseOuDegriseTailleCollage();
    }
    else{
        if(!this->ModeTailleCollage){
            GriseOuDegriseTailleCollage();
        }
        else{
            if(!this->ModeNombrePhoto){
                GriseOuDegriseNombrePhoto();
            }
            else{
                GriseOuDegriseDistancePhoto();
            }
        }
    }
}

void WizardSelectionTaille::SetEnabledNombrePhoto()
{
    bool mode=this->ModeNombrePhoto;
    GriseOuDegriseNombrePhoto();
    if(!mode){
        GriseOuDegriseTailleCollage();
    }
    else{
        if(!this->ModeTailleCollage){
            GriseOuDegriseTailleCollage();
        }
        else{
            if(!this->ModeTaillePhoto){
                GriseOuDegriseTaillePhoto();
            }
            else{
                GriseOuDegriseDistancePhoto();
            }
        }
    }
}

void WizardSelectionTaille::SetEnabledDistancePhoto()
{
    bool mode = this->ModeDistanceEntrePhotos;
    GriseOuDegriseDistancePhoto();
    if(!mode){
        GriseOuDegriseTailleCollage();
    }
    else{
        if(!this->ModeTailleCollage){
            GriseOuDegriseTailleCollage();
        }
        else{
            if(!this->ModeTaillePhoto){
                GriseOuDegriseTaillePhoto();
            }
            else{
                GriseOuDegriseNombrePhoto();
            }
        }
    }
}


void WizardSelectionTaille::MAJLargeurHauteur(int index)
{
    WindowSlave::ConvertAndMAJLineEdit(index,UMTailleCollage,largeur);
    WindowSlave::ConvertAndMAJLineEdit(index,UMTailleCollage,hauteur);
    UMTailleCollage=index;
}

void WizardSelectionTaille::MAJTaillePhoto(int index)
{
    WindowSlave::ConvertAndMAJLineEdit(index,UMTaillePhoto,taillPhoto);
    UMTaillePhoto=index;
}

void WizardSelectionTaille::SetParam(Parameters& param )
{
    QSize collageSize;
    double imageSize = -1;
    int nbPhotos = -1;
    int distanceBetweenPhotos = -1;

    if (this->ModeTailleCollage) {
            float height = hauteur->text().toFloat();
            float width = largeur->text().toFloat();
            qDebug() << "orig W: " << hauteur->text().toFloat() << " orig H: " <<  largeur->text().toFloat();
            qDebug() << "W: " << width << " H:" << height;

            switch (UMTailleCollage) {
                case 1: // Current: inch (pouces)
                    height = Convertisseur::PouceToPixels(height);
                    width = Convertisseur::PouceToPixels(width);
                    break;
                case 2: // Current: cm
                    height = Convertisseur::CmToPixel(height);
                    width = Convertisseur::CmToPixel(width);
                    break;
            }
            // TODO Multiply by 100 to get rid float
            collageSize = QSize(width, height);
    }

    if (this->ModeTaillePhoto) {
        imageSize = taillPhoto->text().toFloat();
        switch (UMTaillePhoto) {
        case 1:
            imageSize = Convertisseur::PouceToPixels(imageSize);
            break;
        case 2:
            imageSize = Convertisseur::CmToPixel(imageSize);
            break;
        }

        qDebug() << "UI Image size: " << taillPhoto->text();
    }

    if (this->ModeNombrePhoto) {
        int maxPhotos = param.getNbPhotos();
        if (nomrePrecisPhotos->isChecked()) {
            nbPhotos = qMin(maxPhotos,nombrePhotos->text().toInt());
        } else {
            nbPhotos = maxPhotos;
        }
    }

    if (this->ModeDistanceEntrePhotos) {
        distanceBetweenPhotos = sliderDistancePhotos->value();
    }

    int intImgSize = static_cast<int>(imageSize);

    param.setCollageSize(collageSize);
    param.setPhotoSize(intImgSize);
    param.setNbPhotos(nbPhotos);
    param.setDistanceBetweenPhotos(distanceBetweenPhotos);

}
