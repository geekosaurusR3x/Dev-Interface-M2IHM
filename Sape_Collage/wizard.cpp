#include "wizard.h"
#include<QIcon>

Wizard::Wizard(QWidget *parent):QWizard(parent)
{
    information = new WizardInfos(this);
    selectionPhoto = new WizardSelectionPhotos(this);
    selectionFrome = new WizardSelectionForme(this);
    selectionTaille = new WizardSelectionTaille(this);
    selectionArrierePlan = new WizardSelectionArrierePlan(this);
    collage = new WizardCollage(this);

    this->addPage(information);
    this->addPage(selectionPhoto);
    this->addPage(selectionFrome);
    this->addPage(selectionTaille);
    this->addPage(selectionArrierePlan);
    this->addPage(collage);
    setWindowIcon(QIcon(":/Images/Icone"));
    setWindowTitle("Assistant de création de collage");
}

Wizard::~Wizard()
{
    information = NULL; delete information;
    selectionPhoto = NULL; delete selectionPhoto;
    selectionFrome = NULL; delete selectionFrome;
    selectionTaille = NULL; delete selectionTaille;
    selectionArrierePlan = NULL; delete selectionArrierePlan;
    collage =NULL; delete collage;
}
