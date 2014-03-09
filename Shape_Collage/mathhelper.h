#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QLine>
#include <qmath.h>

#define PI 3.141592653

/**
 * @brief Classe de fonctions mathématiques
 */
class MathHelper
{
public:
    MathHelper();
    /**
     * @brief Calcul un polygone entre depart, fin avec nbsommets comme nombre de sommet
     * @param depart Qpoint (0,0) du caré englobant le polygone
     * @param fin Qpoint (width,height) du caré englobant le polygone
     * @param nbsommets int representant le nombre de sommets voulu dans le polygone
     * @return Un vecteur de points contenant tous les sommets du polygone
     */
    static QVector<QPoint> computePolygon(QPoint, QPoint, int);
};

#endif // MATHHELPER_H
