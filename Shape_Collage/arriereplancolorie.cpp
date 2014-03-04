#include "arriereplancolorie.h"

ArrierePlanColorie::ArrierePlanColorie():ArrierePlan()
{
    this->setCouleur(Qt::white);
}

ArrierePlanColorie::ArrierePlanColorie(QColor coul)
{
    this->setCouleur(coul);
}

ArrierePlanColorie::~ArrierePlanColorie()
{
}

QColor ArrierePlanColorie::getCouleur() const
{
    return couleur;
}

void ArrierePlanColorie::setCouleur(QColor value)
{
    couleur = value;
}

void ArrierePlanColorie::Draw()
{

}

