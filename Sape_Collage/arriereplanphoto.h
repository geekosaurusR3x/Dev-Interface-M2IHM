#ifndef ARRIEREPLANPHOTO_H
#define ARRIEREPLANPHOTO_H
#include "arriereplan.h"
#include<QString>

class ArrierePlanPhoto : public ArrierePlan
{
public:
    ArrierePlanPhoto();
    ArrierePlanPhoto(QString lien);
    QString getLienPhoto() const;
    void setLienPhoto(const QString &value);

private:
    QString lienPhoto;
};

#endif // ARRIEREPLANPHOTO_H
