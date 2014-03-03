#include "wizardinfos.h"
#include<QLabel>
#include<QLayout>

WizardInfos::WizardInfos(QWidget *parent):QWizardPage(parent)
{
    this->setTitle("Assistant de création d'image");
    QLabel *label = new QLabel("Cet assistant va vous aider à réaliser un collage pas à pas."
                               " Cliquez sur \"suivant\" pour commencer");
    label->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    this->setLayout(layout);
}
