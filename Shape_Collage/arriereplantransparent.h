#ifndef ARRIEREPLANTRANSPARENT_H
#define ARRIEREPLANTRANSPARENT_H
#include "arriereplan.h"
#include<QColor>

class ArrierePlanTransparent : public ArrierePlan
{
public:
    ArrierePlanTransparent();
    QColor getCouleur() const;
    void setCouleur(const QColor &value);

private:
    QColor couleur;

};

#endif // ARRIEREPLANTRANSPARENT_H
