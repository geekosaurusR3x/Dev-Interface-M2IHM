#include "taille.h"


Taille::Taille()
{
}

Taille::Taille(int largeur, int hauteur, int taillePhoto, int nombrePhoto, int distancePhoto)
{
    this->TailleCollage = QSize(largeur,hauteur);
    this->TaillePhoto = taillePhoto;
    this->NombrePhoto = nombrePhoto;
    this->DistanceEntrePhoto = distancePhoto;
}

QSize Taille::getTailleCollage() const
{
    return TailleCollage;
}

void Taille::setTailleCollage(const QSize &value)
{
    TailleCollage = value;
}

int Taille::getDistanceEntrePhoto() const
{
    return DistanceEntrePhoto;
}

void Taille::setDistanceEntrePhoto(int value)
{
    DistanceEntrePhoto = value;
}

int Taille::getNombrePhoto() const
{
    return NombrePhoto;
}

void Taille::setNombrePhoto(int value)
{
    NombrePhoto = value;
}

int Taille::getTaillePhoto() const
{
    return TaillePhoto;
}

void Taille::setTaillePhoto(int value)
{
    TaillePhoto = value;
}

