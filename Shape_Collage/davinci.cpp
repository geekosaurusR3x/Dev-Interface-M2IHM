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

bool DaVinci::draw(Parameters params, QProgressBar*& progressBar)
{
    QSize collageSize = params.getCollageSize();
    int photoSize = params.getPhotoSize();
    float distanceBetweenPhotos = params.getDistanceBetweenPhotos();
    int nbPhotos = params.getNbPhotos();
    int horizontalPadding, verticalPadding;
    CollageForm form = params.getForm();
    int progress = 0;
    progressBar->setValue(0);
    mCanvas->clear();
    // Collage size is set manually
    if (collageSize.width() > 0) {
        horizontalPadding = collageSize.width() * 0.1;
        verticalPadding = collageSize.height() * 0.1;
    }

    // nbPhoto is auto
    if (nbPhotos < 0) {
        // TODO: AUTO
        int nbPhotosLine = (collageSize.width() - horizontalPadding) / photoSize;
        int nbPhotosCol = (collageSize.height() - verticalPadding) / photoSize;
        nbPhotos = nbPhotosLine * nbPhotosCol;
        if (nbPhotos > params.getPhotoList().size()) {
            nbPhotos = params.getPhotoList().size();
        }
    }
    progress = 100 / nbPhotos;


    int cols = qFloor(qSqrt(nbPhotos));
    int lines = qFloor(nbPhotos / cols);
    int nbRandomImages = nbPhotos - (cols * lines);

    // Photo size is auto
    if (params.getPhotoSize() < 0) {
        int photoSizeWidth = (collageSize.width() - horizontalPadding) / cols;
        int photoSizeHeight = (collageSize.height() - verticalPadding) / lines;
        photoSize = qMax(photoSizeWidth, photoSizeHeight);
    }

    // Clear
    mCanvas->clear();

    // init random number generator
    srand (time(NULL));

    if (params.getDistanceBetweenPhotos() < 0) {
        // TODO default distance
        distanceBetweenPhotos = 100;
    }
    distanceBetweenPhotos *= 0.01;

    // Cell size
    int cellWidth = photoSize * distanceBetweenPhotos;
    int cellHeight = photoSize * distanceBetweenPhotos;

    // Check parameters
    if (params.getCollageSize().rheight() < 0 || params.getCollageSize().rwidth() < 0) {
        int w = cellWidth * cols;
        int h = cellHeight * lines;
        collageSize = QSize(1.1 * w, 1.1 * h);
    }

    // Padding
    mFinalPixmap = new QPixmap(collageSize);
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

    QPixmap pixmap(collageSize);
    pixmap.fill(Qt::transparent);
    mFinalPixmap->fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPainter finalPainter(mFinalPixmap);

    // Background image
    finalPainter.drawPixmap(0, 0 , mFinalPixmap->width(), mFinalPixmap->height(), params.getBackground());

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

            switch (form) {
            case CIRCLE:
            {
                // Circle
                float radius = qMax(collageSize.height(), collageSize.width()) / 2;
                float centerX = collageSize.width() / 2;
                float centerY = collageSize.height() / 2;

                float currentCellCenterX = currentCellX + (cellWidth / 2);
                float currentCellCenterY = currentCellY + (cellHeight / 2);

                float distance = qSqrt(qPow((currentCellCenterX - centerX), 2) + qPow((currentCellCenterY - centerY), 2));

                qDebug() << "Radius:" << radius << " centerX" << centerX << " centerY " << centerY  << " CurCellX: " << currentCellCenterX << " CurCellY :"  << currentCellCenterY << " Distance: " << distance;

                if (distance < radius) {
                    // position in circle
                    xPos.push_back(currentCellX);
                    yPos.push_back(currentCellY);
                } else {
                    nbRandomImages++;
                }
                break;
            }
            case RECTANGLE:
            {
                // Rectangle
                xPos.push_back(currentCellX);
                yPos.push_back(currentCellY);
                break;
            }
            case FREEHAND:
            {
                // TODO resize?
                QPolygon pol(MathHelper::computePolygon(QPoint(0,0), QPoint(collageSize.width(), collageSize.height()), params.getNbVertex()));

                foreach (QPoint pt, pol) {
                    qDebug() << "pt: " << pt.x() << pt.y();
                }

                float currentCellCenterX = currentCellX + (cellWidth / 2);
                float currentCellCenterY = currentCellY + (cellHeight / 2);

                if (pol.containsPoint(QPoint(currentCellCenterX, currentCellCenterY), Qt::OddEvenFill)) {
                    xPos.push_back(currentCellX);
                    yPos.push_back(currentCellY);
                } else {
                    nbRandomImages++;
                }
                break;
            }

            }
        }
    }

    // Randomly place the remaining images
    for (int i = 0; i < nbRandomImages; i++) {
            xPos.push_back(rand() % cols*cellWidth - photoSize);
            yPos.push_back(rand() % lines*cellHeight - photoSize);
    }


    // Randomly place images
    while (nbPhotos > 0) {
        int index = rand() % nbPhotos;

        qDebug() << "current index: " << index;

        QString imgSrc = imageSrcList.at(index);
#ifdef linux
        imgSrc = "/" + imgSrc;
#endif
        qDebug() << "Draw : " << imgSrc;
        // Load image
        if (!currentImage.load(imgSrc)) {
            qDebug() << "FAILURE";
            // return;
        } else {
            // Rotation
            QTransform rotation;
            float randRotation = -30 + rand() % 60;
            rotation.rotate(randRotation);
            currentImage = currentImage.transformed(rotation);

            // Scale image
            if (currentImage.width() > currentImage.height()) {
                currentImage = currentImage.scaledToWidth(photoSize);
            } else {
                currentImage = currentImage.scaledToHeight(photoSize);
            }

            qDebug() << "xpos size: " << xPos.size() << " ypos size: " << yPos.size() << " srcList" << "rotation: " << randRotation << "ImgSrcSize: " << imageSrcList.size();

            painter.drawPixmap(xPos.at(index), yPos.at(index), currentImage);
            finalPainter.drawPixmap(horizontalPadding / 2, verticalPadding / 2, pixmap);
            if (params.getDrawingAnimation()) {
                mCanvas->setPixmap(mFinalPixmap->scaled(mCanvas->width(), mCanvas->height()));
            }
            progressBar->setValue(progressBar->value() + progress);
        }
        // Pop
        nbPhotos--;
        imageSrcList.removeAt(index);
        xPos.removeAt(index);
        yPos.removeAt(index);
    }

    // We are done
    progressBar->setValue(100);

    finalPainter.drawPixmap(horizontalPadding / 2, verticalPadding / 2, pixmap);

    // TODO strech / repeat
    /*if (mFinalPixmap->width() < mCanvas->width() && mFinalPixmap->height() < mCanvas->height()) {
        mCanvas->setPixmap(*mFinalPixmap);
    } else {
    */
       mCanvas->setPixmap(mFinalPixmap->scaled(mCanvas->width(), mCanvas->height()));
    // }
    mCanvas->show();
    mAlreadyGenerated = true;
    return true;
}

bool DaVinci::exportImage(QString filename) {
    QFile file(filename + ".png");
    file.open(QIODevice::WriteOnly);
    mFinalPixmap->save(&file, "PNG");
    return true;
}

bool DaVinci::getAlreadyGenerated() const
{
    return mAlreadyGenerated;
}

