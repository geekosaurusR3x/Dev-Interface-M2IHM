#include "arriereplanphoto.h"


ArrierePlanPhoto::ArrierePlanPhoto():ArrierePlan()
{
    this->setLienPhoto("");
}

ArrierePlanPhoto::ArrierePlanPhoto(QString lien):ArrierePlan()
{
    this->setLienPhoto(lien);
}

QString ArrierePlanPhoto::getLienPhoto() const
{
    return lienPhoto;
}

void ArrierePlanPhoto::setLienPhoto(const QString &value)
{
    lienPhoto = value;
}
