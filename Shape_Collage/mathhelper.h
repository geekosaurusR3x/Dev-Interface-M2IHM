#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QLine>
#include <qmath.h>

#define PI 3.141592653

class MathHelper
{
public:
    MathHelper();
    static QVector<QPoint> computePolygon(QPoint, QPoint, int);
};

#endif // MATHHELPER_H
