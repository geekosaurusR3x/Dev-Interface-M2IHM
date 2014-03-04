#include "wizardcollage.h"
#include<QLabel>
#include<QLayout>
#include"labelclicable.h"

WizardCollage::WizardCollage(QWidget* parent):QWizardPage(parent)
{
    this->setTitle("Votre collage");
    QLabel *label = new QLabel("Voici votre collage. "
                               "Cliquez sur \"terminer\" pour l'enregistrer");
    label->setWordWrap(true);

    LabelClicable* collage = new LabelClicable(false,parent);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(collage);
    this->setLayout(layout);
}
