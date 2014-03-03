#include "formerectangle.h"

FormeRectangle::FormeRectangle()
{
    this->setLargeur(0);
    this->setHauteur(0);
}

FormeRectangle::FormeRectangle(int l, int h)
{
    this->setLargeur(l);
    this->setHauteur(h);
}

int FormeRectangle::getHauteur() const
{
    return hauteur;
}

void FormeRectangle::setHauteur(int value)
{
    hauteur = value;
}

int FormeRectangle::getLargeur() const
{
    return largeur;
}

void FormeRectangle::setLargeur(int value)
{
    largeur = value;
}
