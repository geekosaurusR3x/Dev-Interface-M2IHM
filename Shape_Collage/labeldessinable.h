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
#include "mathhelper.h"

class LabelDessinable : public LabelClicable
{
    Q_OBJECT
public:
    explicit LabelDessinable(QWidget *parent = 0);
    QPolygon getPolygon();
    int getNbVertex() const;
    void setNbVertex(int value);
    void update();
    void clear();
    void setPreviewLabel(LabelDessinable *value);

private:
    QVector<QPoint> mPoints;
    QPolygon mPolygon;
    QPoint mClick;
    QPoint mLastClickPos;
    bool mDraw;
    int mNbVertex;
    void draw();
    void drawLine(QLineF);
    LabelDessinable* mPreviewLabel;
signals:
    void clicked();
public slots:
    void mousePressEvent (QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // LABELDESSINABLE_H
