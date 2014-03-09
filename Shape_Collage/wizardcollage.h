#ifndef WIZARDCOLLAGE_H
#define WIZARDCOLLAGE_H
#include<QWidget>
#include<QWizardPage>
#include"parameters.h"
#include"davinci.h"

class WizardCollage : public QWizardPage
{
    Q_OBJECT
public:
    WizardCollage(QWidget* parent=0);
    void Draw(Parameters&);
    bool Save(QString);
private:
    DaVinci* mDavinci;
    QLabel* mCollage;
    QProgressBar* mBar;
};

#endif // WIZARDCOLLAGE_H
