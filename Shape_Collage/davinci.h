#ifndef DAVINCI_H
#define DAVINCI_H

#include <QObject>
#include <QLabel>
#include "parameters.h"
#include <QPainter>
#include <QPicture>
#include <QStringList>
#include <QFile>
#include <qmath.h>
#include <QBitmap>
#include <QProgressBar>
#include <ctime>
#include "windowslave.h"

class DaVinci : public QObject
{
    Q_OBJECT
public:
    DaVinci(QObject *parent = 0);
    DaVinci(QLabel*&, QObject *parent = 0);
    DaVinci(const DaVinci&);
    bool draw(Parameters, QProgressBar*&);
    bool exportImage(QString);
    bool getAlreadyGenerated() const;

private:
    QLabel *mCanvas;
    bool mAlreadyGenerated;
    QPixmap* mFinalPixmap;
signals:

public slots:

};

#endif // DAVINCI_H
