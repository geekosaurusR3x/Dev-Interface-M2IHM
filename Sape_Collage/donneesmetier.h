#ifndef DONNEESMETIER_H
#define DONNEESMETIER_H
#include"forme.h"
#include"taille.h"
#include"arriereplan.h"

class DonneesMetier
{
public:
    DonneesMetier(Forme form, Taille taill, ArrierePlan arrierePla);
    Forme getForme() const;
    void setForme(const Forme &value);

    Taille getTaille() const;
    void setTaille(const Taille &value);

    ArrierePlan getArrierePlan() const;
    void setArrierePlan(const ArrierePlan &value);

private:
    Forme forme;
    Taille taille;
    ArrierePlan arrierePlan;
};

#endif // DONNEESMETIER_H
