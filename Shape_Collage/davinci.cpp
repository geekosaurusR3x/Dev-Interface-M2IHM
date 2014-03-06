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
    float distanceBetweenPhotos;

    // Clear
    mCanvas->clear();

    if (params.getPhotoSize() < 0) {
        // TODO default photo size
        photoSize = 200;
    } else {
        photoSize = params.getPhotoSize();
    }

    if (params.getDistanceBetweenPhotos() < 0) {
        // TODO default distance
        distanceBetweenPhotos = 200;
    } else {
        distanceBetweenPhotos = params.getDistanceBetweenPhotos();
    }
    distanceBetweenPhotos *= 0.01;

    // TODO position
    int nbPhotos = params.getNbPhotos();
    int cols = qFloor(qSqrt(nbPhotos));
    int lines = qFloor(nbPhotos / cols);
    int nbRandomImages = nbPhotos - (cols * lines);

    // Cell size
    int cellWidth = photoSize * distanceBetweenPhotos;
    int cellHeight = photoSize * distanceBetweenPhotos;

    // Check parameters
    if (params.getCollageSize().rheight() < 0) {
        // TODO compute default collage size
        collageSize = QSize(cellWidth * cols, cellHeight * lines);
    } else {
       collageSize = params.getCollageSize();
    }

    // TODO randomize photo array
    // Iterate over images
    QStringList imageSrcList = params.getPhotoList();
    QList<QString>::iterator it;
    it = imageSrcList.begin();
    QPixmap currentImage;

    mPixmap = new QPixmap(collageSize);
    // mPixmap->setMask(mPixmap->createHeuristicMask(true));
    QPainter painter(mPixmap);
    painter.setCompositionMode(QPainter::CompositionMode_Source);

    // Background image
    // mPixmap->fill(params.getBackground());
    // painter.background(params.getBackground());
    // painter.drawImage(QRect(0, 0 , collageSize.rwidth(), collageSize.rheight()), params.getBackground());
    painter.drawPixmap(0, 0 , collageSize.rwidth(), collageSize.rheight(), params.getBackground());
    // painter.fillRect(mPixmap->rect(), QColor(0,0,0,0));

    QList<int> xPos, yPos;

    for (int c = 0; c < cols; ++c) {
        for (int l = 0; l < lines; ++l) {
            int currentCellX = l * cellWidth;
            int currentCellY = c * cellHeight;

            qDebug() << "current X: " << currentCellX <<  " current Y: " << currentCellY;

            xPos.push_back(currentCellX);
            yPos.push_back(currentCellY);
        }
    }

    // Randomly place the remaining images
    for (int i = 0; i < nbRandomImages; i++) {
        currentImage.load(imageSrcList.at(imageSrcList.size() - i));
        // TODO Placement
    }

    // Randomly place images (normal placement)
    srand (time(NULL));
    while (!imageSrcList.empty()) {
        int index = rand() % imageSrcList.size();

        QString imgSrc = imageSrcList.at(index);
            #ifdef linux
                imgSrc = "/" + imgSrc;
            #endif
            qDebug() << "Draw : " << imgSrc;
            // Load image
            if (!currentImage.load(imgSrc)) {
            qDebug() << "FAILURE";
            break;
            // return;
            }

            // Scale image
            if (currentImage.width() > currentImage.height()) {
                currentImage = currentImage.scaledToWidth(photoSize);
            } else {
                currentImage = currentImage.scaledToHeight(photoSize);
            }

        painter.drawPixmap(xPos.at(index), yPos.at(index), currentImage);
        // Delete img
        imageSrcList.removeAt(index);
        xPos.removeAt(index);
        yPos.removeAt(index);
    }


    /*
    QPixmap picture;
    foreach (QString imgStr, params.getPhotoList()) {
        #ifdef linux
           imgStr = "/" + imgStr;
        #endif
        qDebug() << "Draw : " << imgStr;
        if (!picture.load(imgStr)) {
            qDebug() << "FAILURE";
            break;
            // return;
        }

        // Scale picture
        if (picture.width() > picture.height()){
            picture = picture.scaledToWidth(photoSize);
        } else {
            picture = picture.scaledToHeight(photoSize);
        }


        painter.drawPixmap(0, 0, picture);
    }*/

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

