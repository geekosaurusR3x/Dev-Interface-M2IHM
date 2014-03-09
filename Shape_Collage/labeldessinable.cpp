#include "labeldessinable.h"

LabelDessinable::LabelDessinable(QWidget *parent) :
    LabelClicable(parent)
{
    mDraw = false;
    mPreviewLabel = NULL;
}

void LabelDessinable::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
            QPoint pt(event->pos());
            mClick = pt;
            mDraw = true;

        qDebug() << "New point: " << pt.x() << " " << pt.y();
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
