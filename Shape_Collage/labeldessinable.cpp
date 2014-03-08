#include "labeldessinable.h"

LabelDessinable::LabelDessinable(QWidget *parent) :
    LabelClicable(parent)
{
    mDraw = false;
}

void LabelDessinable::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
             // QPointF pt = mapToScene(event->pos());
            // mPoints.push_back(pt);
            QPoint pt(event->pos());
            mClick = pt;
            mDraw = true;
            /*
            bool intersects = false;
            if (mPoints.size() > 2) {
                QPoint previousPt = mPoints.at(1);
                QPoint newPoint = event->pos();

                QVector<QPoint> temp = mPoints.mid(2, -1);
                QLineF previousSegment(mPoints.first(), mPoints.at(1));
                QLineF firstSegment = previousSegment;
                this->drawLine(firstSegment);
                QLineF line;
                float angle = 0.0;

                foreach (QPoint point, temp) {
                    line = QLineF(previousPt, point);
                    this->drawLine(line);
                    angle += previousSegment.angleTo(line);
                    qDebug() << "PREVIOUS TO LINE - ANGLE: "  << previousSegment.angleTo(line);

                    previousSegment = line;
                    previousPt = point;
                }

                line = QLineF(previousPt, pt);
                angle += previousSegment.angleTo(line);
                qDebug() << "PREVIOUS TO LINE - ANGLE: "  << previousSegment.angleTo(line);

                this->drawLine(line);
                previousSegment = line;

                line = QLineF(pt, mPoints.first());
                angle += previousSegment.angleTo(line);
                qDebug() << "PREVIOUS TO LINE - ANGLE: "  << previousSegment.angleTo(line);

                this->drawLine(line);
                previousSegment = line;

                angle += previousSegment.angleTo(firstSegment);
                qDebug() << "PREVIOUS TO LINE - ANGLE: "  << previousSegment.angleTo(line);

                qDebug() << "ANGLE: " << angle;


                float anglesSum = (mPoints.size() + 1)  * 180 -360;
                qDebug() << "ANGLE SOMME: " << anglesSum;


    //            if (angle < 360)



                QVector<QPoint> temp = mPoints.mid(0, mPoints.size() - 2);

                QLineF newLine(mPoints.last(), pt);
                qDebug() << "New line: " << newLine.dx() << " - " << newLine.dy();
                QPoint lastPoint = mPoints.last();
                // QPoint lastPoint = mPoints.first();

                QPointF* intersection;

                foreach (QPoint polPt,temp) {
                    qDebug() << "Intersection? laspt: " << lastPoint.rx() << " " << lastPoint.ry() << "";
                    qDebug() << "temp: " << polPt.rx() << " " << polPt.ry() << "";
                    QLineF cLine(lastPoint, polPt);
                    if (cLine.intersect(newLine, NULL) == QLineF::BoundedIntersection) {
                        qDebug() << "-> INTERSECTION <-";
                        intersects = true;
                        break;
                    } else {
                        qDebug() << "NO INTERSECTION";
                    }
                    lastPoint = polPt;
                }
                *
            }

            if (!intersects) {
                mPoints.push_back(pt);
            }

            */

            qDebug() << "New point: " << pt.x() << " " << pt.y();
            // draw(pt);
    }
}


void LabelDessinable::mouseMoveEvent(QMouseEvent* event) {
    // TODO draw?
    // draw(event->pos());
    if(mDraw)
    {
        // computePolygon(event->pos());
        mPoints = computePolygon(mClick, event->pos());
        draw();
    }
}

// TODO deleteme
QVector<QPoint> LabelDessinable::computePolygon(QPoint start, QPoint end) {
    qDebug() << "Start computing Polygon" << start.x() << " " << start.y();
    float rayon = QLineF(start, end).length();
    rayon = rayon/2;
    // mPoints.clear();
    QVector<QPoint> points;
    int x,y;
    int nb_points = 3;
    float pas_angle = 2 * PI /nb_points;
    int centreX = (start.x() + end.x())/2;
    int centreY = (start.y() + end.y())/2;;
    float angle = pas_angle;
    for(int i = 0; i < nb_points ; i++)
    {
        x = centreX + rayon*qCos(angle);
        y = centreY + rayon*qSin(angle);
        points.push_back(QPoint(x,y));
        angle += pas_angle;
    }

    qDebug() << "End computing Polygon";

    return points;
}

void LabelDessinable::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mDraw = false;
    }

}

void LabelDessinable::drawLine(QLineF line)  {
    // TODO Draw
    QPixmap pixmap = pixmap;
    QPainter painter(&pixmap);
    painter.drawLine(line);
    this->setPixmap(pixmap);
}

QPolygon LabelDessinable::getPolygon() {
    QPolygon pol(mPoints);
    return pol;
}

void LabelDessinable::draw() {
    // TODO Draw
    QPixmap pixmap(this->width(), this->height());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPolygon polygon(mPoints);
    QBrush brush(Qt::red);
    painter.setBrush(brush);
    painter.drawPolygon(polygon);
    this->setPixmap(pixmap);
}
