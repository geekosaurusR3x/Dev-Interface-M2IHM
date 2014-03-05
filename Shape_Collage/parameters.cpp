#include "parameters.h"

Parameters::Parameters(QSize& collageSize, int& photoSize, int& nbPhotos, int& distanceBetweenPhotos, QImage& background, CollageForm form, QStringList photoList, QObject* parent) : QObject(parent) {

    this->collageSize = collageSize;
    this->photoSize = photoSize;
    this->nbPhotos = nbPhotos;
    this->distanceBetweenPhotos = distanceBetweenPhotos;
    this->background = background;
    this->form = form;
    this->photoList = photoList;
}

Parameters::Parameters(const Parameters& params) {
    this->collageSize = params.getCollageSize();
    this->photoSize = params.getPhotoSize();
    this->nbPhotos = params.getNbPhotos();
    this->distanceBetweenPhotos = params.getDistanceBetweenPhotos();
    this->background = params.getBackground();
    this->form = params.getForm();
    this->photoList = params.getPhotoList();
}

QSize Parameters::getCollageSize() const
{
    return collageSize;
}

void Parameters::setCollageSize(const QSize &value)
{
    collageSize = value;
}
int Parameters::getPhotoSize() const
{
    return photoSize;
}

void Parameters::setPhotoSize(const int &value)
{
    photoSize = value;
}
int Parameters::getNbPhotos() const
{
    return nbPhotos;
}

void Parameters::setNbPhotos(const int &value)
{
    nbPhotos = value;
}
int Parameters::getDistanceBetweenPhotos() const
{
    return distanceBetweenPhotos;
}

void Parameters::setDistanceBetweenPhotos(const int &value)
{
    distanceBetweenPhotos = value;
}
QImage Parameters::getBackground() const
{
    return background;
}

void Parameters::setBackground(const QImage &value)
{
    background = value;
}
CollageForm Parameters::getForm() const
{
    return form;
}

void Parameters::setForm(const CollageForm &value)
{
    form = value;
}
QStringList Parameters::getPhotoList() const
{
    return photoList;
}

void Parameters::setPhotoList(const QStringList &value)
{
    photoList = value;
}


std::ostream& operator <<(std::ostream& out, const Parameters& obj) {
    out << "CollageSize: " << obj.getCollageSize().rheight() << "x" << obj.getCollageSize().rwidth() ;
    out << "PhotoSize: " << obj.getPhotoSize();
    out << "Nb Photos: " << obj.getNbPhotos();
    // out << "Background: " << obj.getBackground();
    out << "form: " << obj.getForm();
    out << "PhotoList"; //<< obj.getPhotoList();
    return out;
}
