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


class LabelDessinable : public LabelClicable
{
    Q_OBJECT
public:
    explicit LabelDessinable(QWidget *parent = 0);

private:
    QVector<QPoint> mPoints;
    QPolygon mPolygon;
    QPoint mClick;
    bool mDraw;
    void draw();
    void drawLine(QLineF);
    void computePolygon(QPoint);

signals:
    void clicked();
public slots:
    void mousePressEvent (QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // LABELDESSINABLE_H
