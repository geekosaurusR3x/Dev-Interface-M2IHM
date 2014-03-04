#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

class Convertisseur
{
public:
    Convertisseur();
    static double PixelsToPouce(float nbr);
    static double PixelsToCm(float nbr);
    static double PouceToPixels(float nbr);
    static double PouceToCm(float nbr);
    static double CmToPouce(float nbr);
    static double CmToPixel(float nbr);
};

#endif // CONVERTISSEUR_H
