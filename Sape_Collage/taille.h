#ifndef TAILLE_H
#define TAILLE_H
#include<QSize>
class Taille
{
public:
    Taille();
    Taille(int largeur,int hauteur, int taillePhoto, int nombrePhoto, int distancePhoto);
    QSize getTailleCollage() const;
    void setTailleCollage(const QSize &value);

    int getTaillePhoto() const;
    void setTaillePhoto(int value);

    int getNombrePhoto() const;
    void setNombrePhoto(int value);

    int getDistanceEntrePhoto() const;
    void setDistanceEntrePhoto(int value);

private:
    QSize TailleCollage;
    int TaillePhoto;
    int NombrePhoto;
    int DistanceEntrePhoto;
};

#endif // TAILLE_H
