#include "wizardcollage.h"
#include<QLabel>
#include<QLayout>
#include"labelclicable.h"

WizardCollage::WizardCollage(QWidget* parent):QWizardPage(parent)
{
    this->setTitle("Votre collage");
    QLabel *label = new QLabel("Voici votre collage. "
                               "Cliquez sur \"Terminer\" pour l'enregistrer");
    label->setWordWrap(true);

    mCollage = new QLabel(parent);
    mCollage->setFixedSize(QSize(500, 500));
    mBar = new QProgressBar();
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(mCollage);

    mDavinci = new DaVinci(mCollage);
    this->setLayout(layout);

}

void WizardCollage::Draw(Parameters &param)
{
    mDavinci->draw(param,mBar);
}

bool WizardCollage::Save(QString fichier){
    return mDavinci->exportImage(fichier);
}
