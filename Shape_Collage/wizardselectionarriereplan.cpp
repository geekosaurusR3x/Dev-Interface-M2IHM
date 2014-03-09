#include "wizardselectionarriereplan.h"

WizardSelectionArrierePlan::WizardSelectionArrierePlan(QWidget *parent):QWizardPage(parent)
{
    this->setTitle("Sélection de l'arrière-plan du collage");
    QLabel *label = new QLabel("Sélectionnez un arrière-plan pour votre collage."
                               " Cliquez sur \"suivant\" pour créer le collage");
    label->setWordWrap(true);

    QVBoxLayout *boiteVerticale = new QVBoxLayout();

    QHBoxLayout *boiteHorizontale1 = PlacerArrierePlanTransparent();

    QHBoxLayout *boiteHorizontale2 = PlacerArrierePlanColorie();

    QHBoxLayout *boiteHorizontale3 = PlacerArrierePlanPhoto();

    boiteVerticale->addWidget(label);
    boiteVerticale->addLayout(boiteHorizontale1);
    boiteVerticale->addLayout(boiteHorizontale2);
    boiteVerticale->addLayout(boiteHorizontale3);
    this->setLayout(boiteVerticale);

    connect(labelCouleur,SIGNAL(clicked()),this,SLOT(ChangerCouleurArrierePlan()));
    connect(labelPhoto,SIGNAL(clicked()),this,SLOT(ChargerPhotoArrierePlan()));
    connect(boutonRadioPhoto,SIGNAL(clicked()),this,SLOT(PhotoSelected()));

    mBackgroundColor = Qt::white;
}

WizardSelectionArrierePlan::~WizardSelectionArrierePlan()
{
    boutonRadioTransparent = NULL;
    boutonRadioCouleur = NULL;
    labelCouleur = NULL;
    boutonRadioPhoto = NULL;
    labelPhoto = NULL;
    delete boutonRadioTransparent;
    delete boutonRadioCouleur;
    delete labelCouleur;
    delete boutonRadioPhoto;
    delete labelPhoto;
}

QHBoxLayout * WizardSelectionArrierePlan::PlacerArrierePlanPhoto()
{
    QHBoxLayout *boiteHorizontale3 = new QHBoxLayout();
    this->boutonRadioPhoto = new QRadioButton("Photo");
    this->labelPhoto = new LabelClicable(true);
    boiteHorizontale3->addWidget(boutonRadioPhoto);
    boiteHorizontale3->addWidget(labelPhoto);
    boiteHorizontale3->setSizeConstraint(QLayout::SetMinimumSize);
    lienPhoto="";

    return boiteHorizontale3;
}

QHBoxLayout * WizardSelectionArrierePlan::PlacerArrierePlanColorie()
{
    QHBoxLayout *boiteHorizontale2 = new QHBoxLayout();
    this->boutonRadioCouleur = new QRadioButton("Couleur");
    boutonRadioCouleur->setChecked(true);
    this->labelCouleur = new LabelClicable(false);
    boiteHorizontale2->addWidget(boutonRadioCouleur);
    boiteHorizontale2->addWidget(labelCouleur);
    boiteHorizontale2->setSizeConstraint(QLayout::SetMinimumSize);
    labelCouleur->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Fixed ) );

    return boiteHorizontale2;
}

QHBoxLayout * WizardSelectionArrierePlan::PlacerArrierePlanTransparent()
{
    QHBoxLayout *boiteHorizontale1 = new QHBoxLayout();
    this->boutonRadioTransparent = new QRadioButton("Transparent");
    boiteHorizontale1->addWidget(boutonRadioTransparent);

    return boiteHorizontale1;
}

QPixmap WizardSelectionArrierePlan::GetBackground()
{
     QPixmap background;
     if (boutonRadioCouleur->isChecked()) {
         background = QPixmap(1, 1);
         background.fill(mBackgroundColor);
     } else if (boutonRadioTransparent->isChecked()) {
         background = QPixmap(1,1);
         background.fill(Qt::transparent);
     } else {
         background = QPixmap::fromImage(QImage(lienPhoto));
     }
    return background;
}

void WizardSelectionArrierePlan::ChangerCouleurArrierePlan()
{
    mBackgroundColor = WindowSlave::ChangerCouleurArrierePlan(labelCouleur);
}

void WizardSelectionArrierePlan::ChargerPhotoArrierePlan()
{
    WindowSlave::ChargerPhotoArrierePlan(labelPhoto, lienPhoto);
}

void WizardSelectionArrierePlan::PhotoSelected()
{
    ChargerPhotoArrierePlan();
}

