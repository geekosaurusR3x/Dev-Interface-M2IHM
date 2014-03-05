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
    QSize collageSize;
    int photoSize;
    int distanceBetweenPhotos;

    // Clear
    mCanvas->clear();

    // Check parameters
    if (params.getCollageSize().rheight() < 0) {
        collageSize = QSize(1600, 900);
    } else {
       collageSize = params.getCollageSize();
    }

    if (params.getPhotoSize() < 0) {
        photoSize = 200;
    } else {
        photoSize = params.getPhotoSize();
    }

    if (params.getDistanceBetweenPhotos() < 0) {
        distanceBetweenPhotos = 200;
    } else {
        distanceBetweenPhotos = params.getDistanceBetweenPhotos();
    }

    mPixmap = new QPixmap(collageSize);
    // mPixmap->setMask(mPixmap->createHeuristicMask(true));
    QPixmap picture;
    QPainter painter(mPixmap);
    //painter.setCompositionMode(QPainter::CompositionMode_Clear);
    // Background image
    //mPixmap->fill(params.getBackground());
    // painter.background(params.getBackground());
    painter.drawImage(QRect(0, 0 , collageSize.rwidth(), collageSize.rheight()), params.getBackground());

    foreach (QString imgStr, params.getPhotoList()) {
        #ifdef linux
           imgStr = "/" + imgStr;
        #endif
        qDebug() << "Draw : " << imgStr;
        if (!picture.load(imgStr)) {
            qDebug() << "FAILURE";
            // return;
        }

        // Scale picture
        if (picture.width() > picture.height()){
            picture = picture.scaledToWidth(photoSize);
        } else {
            picture = picture.scaledToHeight(photoSize);
        }

        // TODO position
        painter.drawPixmap(0, 0, picture);
    }

    // TODO strech / repeat
    mCanvas->setPixmap(mPixmap->scaled(mCanvas->width(), mCanvas->height()));

    mCanvas->show();
    mAlreadyGenerated = true;
    return true;
}

bool DaVinci::exportImage(Parameters params) {
    QFile file("/tmp/tmp.png");
    file.open(QIODevice::WriteOnly);
    mPixmap->save(&file, "PNG");
    return true;
}

bool DaVinci::getAlreadyGenerated() const
{
    return mAlreadyGenerated;
}

