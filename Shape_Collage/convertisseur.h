#ifndef CONVERTISSEUR_H
#define CONVERTISSEUR_H

/**
 * \brief Classe Convertisseur permettant de convertir des valeur en pixel, en pouce ou en centimètre
 */
class Convertisseur
{
public:
    Convertisseur();

    /**
     * \brief Convertis une valeur (en pixel) en pouce
     * \a nbr valeur à convertir, cette valeur doit être en pixel
     * \return la valeur de \a nbr convertie en pouce
     */
    static double PixelsToPouce(float nbr);

    /**
     * \brief Convertis une valeur (en pixel) en centimètre
     * \a nbr valeur à convertir, cette valeur doit être en pixel
     * \return la valeur de \a nbr convertie en centimètre
     */
    static double PixelsToCm(float nbr);

    /**
     * \brief Convertis une valeur (en pouce) en pixel
     * \a nbr valeur à convertir, cette valeur doit être en pouce
     * \return la valeur de \a nbr convertie en pixel
     */
    static double PouceToPixels(float nbr);

    /**
     * \brief Convertis une valeur (en pouce) en centimetre
     * \a nbr valeur à convertir, cette valeur doit être en pouce
     * \return la valeur de \nbr convertie en centimètre
     */
    static double PouceToCm(float nbr);

    /**
     * \brief convertis une valeur (en centimètre)en pouce
     * \a nbr valeur à convertir, cette valeur doit être en centimètre
     * \return la valeur de \a nbr convertie en pouce
     */
    static double CmToPouce(float nbr);

    /**
     * \brief Convertis une valeur (en centimètre) en pixel
     * \a nbr valeur à convetir, cette valeur doit être en centimètre
     * \return la valeur de \a nbr convertie en pixel
     */
    static double CmToPixel(float nbr);
};

#endif // CONVERTISSEUR_H
