#ifndef WIZARDCOLLAGE_H
#define WIZARDCOLLAGE_H
#include<QWidget>
#include<QWizardPage>
#include"parameters.h"
#include"davinci.h"

/**
 * @brief Dernière page du wizard permettant d'enregistrer le collage généré
 */
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
