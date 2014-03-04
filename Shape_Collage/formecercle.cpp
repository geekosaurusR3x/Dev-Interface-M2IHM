#include "formecercle.h"

FormeCercle::FormeCercle():Forme()
{
    this->setRayon(0);
}

FormeCercle::FormeCercle(int r):Forme()
{
    this->setRayon(r);
}

int FormeCercle::getRayon() const
{
    return rayon;
}

void FormeCercle::setRayon(int value)
{
    rayon = value;
}

void FormeCercle::Draw()
{
}
