#ifndef WIZARDINFOS_H
#define WIZARDINFOS_H
#include<QWizardPage>

/**
 * @brief Première page du wizard d'aide à la création du collage
 */
class WizardInfos : public QWizardPage
{
    Q_OBJECT
public:
    WizardInfos(QWidget *parent = 0);
};

#endif // WIZARDINFOS_H
