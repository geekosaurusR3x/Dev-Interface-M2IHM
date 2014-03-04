#include "convertisseur.h"

Convertisseur::Convertisseur()
{

}

double Convertisseur::PixelsToPouce(float nbr)
{
    return nbr*0.01041666666667;
}

double Convertisseur::PixelsToCm(float nbr)
{
    return nbr*0.02645833333333;
}

double Convertisseur::PouceToPixels(float nbr)
{
    return nbr*96.0;
}

double Convertisseur::PouceToCm(float nbr)
{
    return nbr*2.54;
}

double Convertisseur::CmToPouce(float nbr)
{
    return nbr*0.3937007874016;
}

double Convertisseur::CmToPixel(float nbr)
{
    return nbr*37.79527559055;
}
/*ceil(variable) et floor(variable) */
