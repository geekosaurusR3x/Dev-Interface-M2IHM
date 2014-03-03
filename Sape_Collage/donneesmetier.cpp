#include "donneesmetier.h"

DonneesMetier::DonneesMetier(Forme form, Taille taill, ArrierePlan arrierePla)
{
    this->forme = form;
    this->taille = taill;
    this->arrierePlan = arrierePla;
}

ArrierePlan DonneesMetier::getArrierePlan() const
{
    return arrierePlan;
}

void DonneesMetier::setArrierePlan(const ArrierePlan &value)
{
    arrierePlan = value;
}

Taille DonneesMetier::getTaille() const
{
    return taille;
}

void DonneesMetier::setTaille(const Taille &value)
{
    taille = value;
}

Forme DonneesMetier::getForme() const
{
    return forme;
}

void DonneesMetier::setForme(const Forme &value)
{
    forme = value;
}
