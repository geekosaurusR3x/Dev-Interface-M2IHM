#ifndef LABELDESSINABLE_H
#define LABELDESSINABLE_H

#include <QWidget>
#include <QList>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QPainter>
#include <QLineF>
#include <qmath.h>
#include "labelclicable.h"
#define PI 3.141592653

class LabelDessinable : public LabelClicable
{
    Q_OBJECT
public:
    explicit LabelDessinable(QWidget *parent = 0);
    QPolygon getPolygon();
    static QVector<QPoint> computePolygon(QPoint start, QPoint end);
private:
    QVector<QPoint> mPoints;
    QPolygon mPolygon;
    QPoint mClick;
    bool mDraw;
    void draw();
    void drawLine(QLineF);
signals:
    void clicked();
public slots:
    void mousePressEvent (QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // LABELDESSINABLE_H
