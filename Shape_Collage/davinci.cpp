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

void DaVinci::draw(Parameters& params)
{
    // TODO
    this->mCanvas->setText("TEST");
    mAlreadyGenerated = true;
}

void DaVinci::exportImage(Parameters& params) {
    // TODO
}

bool DaVinci::getAlreadyGenerated() const
{
    return mAlreadyGenerated;
}

