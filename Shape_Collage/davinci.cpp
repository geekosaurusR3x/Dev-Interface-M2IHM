#include "davinci.h"

DaVinci::DaVinci(QObject* parent) : QObject(parent) {
    this->mAlreadyGenerated = false;
}

DaVinci::DaVinci(const DaVinci& obj) {
    this->mCanvas = obj.mCanvas;
    this->mAlreadyGenerated = obj.mAlreadyGenerated;
}

DaVinci::DaVinci(QLabel*& label, QObject *parent) :
    QObject(parent)
{
    mCanvas = label;
    mAlreadyGenerated = false;
}

bool DaVinci::draw(Parameters params)
{
    // TODO
    // this->mCanvas->setText("TEST");

    // TODO Check size
    QPixmap pixmap(params.getCollageSize());
    QPixmap picture;
    QPainter painter(&pixmap);

    foreach (QString imgStr, params.getPhotoList()) {
        imgStr = "/" + imgStr;
        qDebug() << "Draw : " << imgStr;
        if (!picture.load(imgStr)) {
                qDebug() << "FAILURE";
        }

        painter.drawPixmap(0, 0, picture);
    }

    mCanvas->setPixmap(pixmap);
    mCanvas->show();
    mAlreadyGenerated = true;
    return true;
}

bool DaVinci::exportImage(Parameters params) {
    // TODO
    return true;
}

bool DaVinci::getAlreadyGenerated() const
{
    return mAlreadyGenerated;
}

