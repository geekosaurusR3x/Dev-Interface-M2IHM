#include "wizardselectionforme.h"

WizardSelectionForme::WizardSelectionForme(QWidget *parent):QWizardPage(parent)
{
    this->setTitle("Sélection de la forme");
    QLabel *label = new QLabel("Maintenant choisissez la forme dans laquelle vos photos seront disposées."
                               " Cliquez sur \"suivant\" pour continuer");
    label->setWordWrap(true);

    this->rectangle = new QRadioButton("Rectangle");
    rectangle->setChecked(true);
    this->cercle = new QRadioButton("Cercle");
    this->extra = new QRadioButton("Extra");
    this->labelExtra = new LabelDessinable(parent);
    labelExtra->setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding ) );

    QVBoxLayout *boiteVerticalePrincipale = new QVBoxLayout();
    boiteVerticalePrincipale->addWidget(label);
    QHBoxLayout *boiteHorizontaleExtra = new QHBoxLayout();
    boiteHorizontaleExtra->addWidget(extra);
    boiteHorizontaleExtra->addWidget(labelExtra);
    QVBoxLayout *boiteVerticaleRectCrcle = new QVBoxLayout();
    boiteVerticaleRectCrcle->addWidget(rectangle);
    boiteVerticaleRectCrcle->addWidget(cercle);
    QHBoxLayout *boiteHorizontaleFormes = new QHBoxLayout();
    boiteHorizontaleFormes->addLayout(boiteVerticaleRectCrcle);
    boiteHorizontaleFormes->addLayout(boiteHorizontaleExtra);
    boiteVerticalePrincipale->addLayout(boiteHorizontaleFormes);
    this->setLayout(boiteVerticalePrincipale);
    //connexion des signaux
    connect(labelExtra,SIGNAL(clicked()),this,SLOT(DessinerForme()));
    connect(extra,SIGNAL(clicked()),this,SLOT(DessinerFormeSiVide()));
}


WizardSelectionForme::~WizardSelectionForme()
{
    rectangle = NULL;
    cercle = NULL;
    extra = NULL;
    labelExtra = NULL;
    delete rectangle;
    delete cercle;
    delete extra;
    delete labelExtra;
}

CollageForm WizardSelectionForme::GetValue()
{
    CollageForm form;
    if (extra->isChecked()) {
        form = FREEHAND;
    } else if (cercle->isChecked()) {
        form = CIRCLE;
    } else {
        form = RECTANGLE;
    }

    return form;
}

void WizardSelectionForme::DessinerForme()
{
    WindowSlave::DessinerForme(labelExtra);
}

void WizardSelectionForme::DessinerFormeSiVide()
{
    WindowSlave::DessinerForme(labelExtra);
}
