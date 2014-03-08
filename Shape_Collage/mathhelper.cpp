#include "mathhelper.h"

MathHelper::MathHelper()
{

}

QVector<QPoint> MathHelper::computePolygon(QPoint start, QPoint end, int nbVertex) {
    qDebug() << "Start computing Polygon" << start.x() << " " << start.y();

    float rayon = QLineF(start, end).length();
    rayon = rayon/2;
    QVector<QPoint> points;
    int x,y;
    float pas_angle = 2 * PI / nbVertex;
    int centreX = (start.x() + end.x())/2;
    int centreY = (start.y() + end.y())/2;;
    float angle = pas_angle;
    for(int i = 0; i < nbVertex; i++)
    {
        x = centreX + rayon*qCos(angle);
        y = centreY + rayon*qSin(angle);
        points.push_back(QPoint(x,y));
        angle += pas_angle;
    }

    qDebug() << "End computing Polygon";

    return points;
}
