#include "arriereplantransparent.h"

ArrierePlanTransparent::ArrierePlanTransparent():ArrierePlan()
{
    couleur =Qt::transparent;
}

QColor ArrierePlanTransparent::getCouleur() const
{
return couleur;
}

void ArrierePlanTransparent::setCouleur(const QColor &value)
{
couleur = value;
}
