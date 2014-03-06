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
    QSize collageSize = params.getCollageSize();
    int photoSize;
    float distanceBetweenPhotos;
    // TODO Auto photo number
    int nbPhotos = params.getNbPhotos();

    int cols = qFloor(qSqrt(nbPhotos));
    int lines = qFloor(nbPhotos / cols);
    int nbRandomImages = nbPhotos - (cols * lines);

    int horizontalPadding, verticalPadding;

    if (collageSize.width() > 0) {
        horizontalPadding = collageSize.width() * 0.1;
        verticalPadding = collageSize.height() * 0.1;
    }

    // Clear
    mCanvas->clear();

    // init random number generator
    srand (time(NULL));

    if (params.getPhotoSize() < 0) {
        int photoSizeWidth = (collageSize.width() - horizontalPadding) / cols;
        int photoSizeHeight = (collageSize.height() - verticalPadding) / lines;
        photoSize = qMax(photoSizeWidth, photoSizeHeight);
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

    // Cell size
    int cellWidth = photoSize * distanceBetweenPhotos;
    int cellHeight = photoSize * distanceBetweenPhotos;

    // Check parameters
    if (params.getCollageSize().rheight() < 0) {
        collageSize = QSize((cellWidth * cols), (cellHeight * lines));
    }

    // Padding
    QPixmap finalPixmap(collageSize);
    horizontalPadding = collageSize.width() * 0.1;
    verticalPadding = collageSize.height() * 0.1;

    collageSize.setHeight(collageSize.height() - verticalPadding);
    collageSize.setWidth(collageSize.width() - horizontalPadding);


    // TODO randomize photo array
    // Iterate over images
    QStringList imageSrcList = params.getPhotoList();
    QList<QString>::iterator it;
    it = imageSrcList.begin();
    QPixmap currentImage;

    mPixmap = new QPixmap(collageSize);
    // mPixmap->setMask(mPixmap->createHeuristicMask(true));
    QPainter painter(mPixmap);
    QPainter finalPainter(&finalPixmap);
    painter.setCompositionMode(QPainter::CompositionMode_Source);

    // Background image
    finalPainter.drawPixmap(0, 0 , finalPixmap.width(), finalPixmap.height(), params.getBackground());

    QList<int> xPos, yPos;

    // DEBUG
    qDebug() << "CollageSize: " << collageSize.width() << "x" << collageSize.height();
    qDebug() << "Padding h:" << horizontalPadding << " v: " << verticalPadding;
    qDebug() << "PhotoSize: " << photoSize;
    qDebug() << "Distance BPhotos: " << distanceBetweenPhotos;
    qDebug() << "NbPhotos: " << nbPhotos << " ";

    for (int c = 0; c < cols; ++c) {
        for (int l = 0; l < lines; ++l) {
            int currentCellX = l * cellWidth;
            int currentCellY = c * cellHeight;

            qDebug() << "current X: " << currentCellX <<  " current Y: " << currentCellY;

            // TODO other forms
            xPos.push_back(currentCellX);
            yPos.push_back(currentCellY);
        }
    }

    // Randomly place the remaining images
    for (int i = 0; i < nbRandomImages; i++) {
        xPos.push_back(rand() % collageSize.width());
        yPos.push_back(rand() % collageSize.height());
    }

    // Randomly place images (normal placement)
    while (!imageSrcList.empty()) {
        int index = rand() % imageSrcList.size();

        qDebug() << "current index: " << index;

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

        qDebug() << "xpos size: " << xPos.size() << " ypos size: " << yPos.size() << " srcList" << imageSrcList.size();

        painter.drawPixmap(xPos.at(index), yPos.at(index), currentImage);
        // Pop
        imageSrcList.removeAt(index);
        xPos.removeAt(index);
        yPos.removeAt(index);
    }

    finalPainter.drawPixmap(horizontalPadding / 2, verticalPadding / 2, *mPixmap);

    // TODO strech / repeat
    if (finalPixmap.width() < mCanvas->width() && finalPixmap.height() < mCanvas->height()) {
        mCanvas->setPixmap(finalPixmap);
    } else {
       mCanvas->setPixmap(finalPixmap.scaled(mCanvas->width(), mCanvas->height()));
    }
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

