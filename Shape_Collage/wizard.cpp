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

    mParams = new Parameters();
    mInfoId = this->addPage(information);
    mPhotoId = this->addPage(selectionPhoto);
    mFormId = this->addPage(selectionFrome);
    mSizeId = this->addPage(selectionTaille);
    mBackgroundId = this->addPage(selectionArrierePlan);
    mCollageId = this->addPage(collage);
    setWindowIcon(QIcon(":/Images/Icone"));
    setWindowTitle("Assistant de création de collage");

}

bool Wizard::validateCurrentPage() {
    bool valid = false;
    switch (this->currentId()) {
        //case mInfoId:
        case 0:
        {
            valid = true;
            break;
        }
        //case mPhotoId:
        case 1:
        {
            if (selectionPhoto->getPhotos()->getListePhoto().size() > 0) {
                mParams->setPhotoList(selectionPhoto->getPhotos()->getListePhoto());
                mParams->setNbPhotos(selectionPhoto->getPhotos()->getListePhoto().size());
                valid = true;
            } else {
                // TODO show error dialog
                showErrorDialog("Veuillez ajouter au moins une photo.");
            }
            break;
        }
        //case mFormId:
        case 2:
            mParams->setForm(selectionFrome->GetValue());
            valid = true;
            break;
        //case mSizeId:
        case 3:
            selectionTaille->SetParam(*mParams);
            valid = true;
            break;
        // case mBackgroundId:
        case 4:
            mParams->setBackground(selectionArrierePlan->GetBackground());
            collage->Draw(*mParams);
            valid = true;
            break;
        //case mCollageId:
        case 5:
        {
            QString defaultLocation = "";
            #ifdef linux
                defaultLocation = "/tmp";
            #endif
            QString fichier = QFileDialog::getSaveFileName(this, "Choisissez où enregistrer votre collage", defaultLocation, ".png");

            if (fichier != NULL) {
                collage->Save(fichier);
            }
            valid = true;
            break;
        }
        default: // shouldn't ever be called
            break;
    }

    qDebug() << *mParams;
    return valid;
}

void Wizard::showErrorDialog(QString errMsg)  {
    QMessageBox msgBox;
    msgBox.setText("Erreur !");
    msgBox.setInformativeText(errMsg);
    msgBox.exec();
}

Wizard::~Wizard()
{
    information = NULL; delete information;
    selectionPhoto = NULL; delete selectionPhoto;
    selectionFrome = NULL; delete selectionFrome;
    selectionTaille = NULL; delete selectionTaille;
    selectionArrierePlan = NULL; delete selectionArrierePlan;
    collage =NULL;
    delete collage;
}
