#include "labeldessinable.h"

LabelDessinable::LabelDessinable(QWidget *parent) :
    LabelClicable(parent)
{
    mDraw = false;
    mPreviewLabel = NULL;
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
    if(mDraw)
    {
        mPoints = MathHelper::computePolygon(mClick, event->pos(), mNbVertex);
        draw();
    }
}

int LabelDessinable::getNbVertex() const
{
    return mNbVertex;
}

void LabelDessinable::setNbVertex(int value)
{
    mNbVertex = value;
}


void LabelDessinable::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mLastClickPos = event->pos();
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

void LabelDessinable::setPreviewLabel(LabelDessinable *value)
{
    mPreviewLabel = value;
}

QPolygon LabelDessinable::getPolygon() {
    QPolygon pol(mPoints);
    return pol;
}

void LabelDessinable::update() {
    if (!mClick.isNull() && !mLastClickPos.isNull()) {
        mPoints = MathHelper::computePolygon(mClick, mLastClickPos, mNbVertex);
        draw();
    }
}

void LabelDessinable::clear() {
    LabelClicable::clear();
    mClick = QPoint();
    mLastClickPos = QPoint();
    if (mPreviewLabel != NULL) {
        mPreviewLabel->clear();
    }
}

void LabelDessinable::draw() {
    // TODO Draw
    qDebug() << "test";
    QPixmap pixmap(this->width(), this->height());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPolygon polygon(mPoints);
    QBrush brush(Qt::red);
    painter.setBrush(brush);
    painter.drawPolygon(polygon);
    this->setPixmap(pixmap);
    if (mPreviewLabel != NULL)
    {
        mPreviewLabel->mPoints=MathHelper::computePolygon(QPoint(12,12),QPoint(mPreviewLabel->width()-12,mPreviewLabel->height()-12),mNbVertex);
        mPreviewLabel->draw();
    }
}
