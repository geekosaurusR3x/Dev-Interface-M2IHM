#ifndef FORMERECTANGLE_H
#define FORMERECTANGLE_H
#include "forme.h"

class FormeRectangle : public Forme
{
public:
    FormeRectangle();
    FormeRectangle(int l , int h);
    int getLargeur() const;
    void setLargeur(int value);

    int getHauteur() const;
    void setHauteur(int value);

private:
    int largeur;
    int hauteur;
};

#endif // FORMERECTANGLE_H
