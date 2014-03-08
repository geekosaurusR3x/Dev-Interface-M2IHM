#ifndef WIZARD_H
#define WIZARD_H
#include<QWizard>
#include"wizardinfos.h"
#include"wizardselectionphotos.h"
#include"wizardselectionforme.h"
#include"wizardselectiontaille.h"
#include"wizardselectionarriereplan.h"
#include"wizardcollage.h"
#include<QGroupBox>
#include"parameters.h"

class Wizard : public QWizard
{
    Q_OBJECT
public:
    Wizard(QWidget *parent = 0);
    ~Wizard();
private:
    Parameters *mParams;
    WizardInfos *information;
    WizardSelectionPhotos *selectionPhoto;
    WizardSelectionForme *selectionFrome;
    WizardSelectionTaille *selectionTaille;
    WizardSelectionArrierePlan *selectionArrierePlan;
    WizardCollage *collage;
    bool validateCurrentPage();
    int mInfoId, mPhotoId, mFormId, mSizeId, mBackgroundId, mCollageId;
    void showErrorDialog(QString);
};

#endif // WIZARD_H
