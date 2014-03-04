#ifndef WIZARDCOLLAGE_H
#define WIZARDCOLLAGE_H
#include<QWidget>
#include<QWizardPage>

class WizardCollage : public QWizardPage
{
    Q_OBJECT
public:
    WizardCollage(QWidget* parent=0);
};

#endif // WIZARDCOLLAGE_H
