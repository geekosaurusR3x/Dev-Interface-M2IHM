#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "ostream"

#include <QObject>
#include <QPixmap>
#include <QSize>
#include <QStringList>
#include <QDebug>

enum CollageForm {
    CIRCLE = 0,
    RECTANGLE,
    FREEHAND
};

class Parameters : public QObject
{
    Q_OBJECT
    friend QDebug operator <<(QDebug dbg, const Parameters& obj);
    public:
    Parameters(QSize&, int&, int&, int&, QPixmap&, CollageForm, QStringList, QObject *parent = 0);
    Parameters(const Parameters&);
    QSize getCollageSize() const;
    void setCollageSize(const QSize &value);

    int getPhotoSize() const;
    void setPhotoSize(const int &value);

    int getNbPhotos() const;
    void setNbPhotos(const int &value);

    int getDistanceBetweenPhotos() const;
    void setDistanceBetweenPhotos(const int &value);

    QPixmap getBackground() const;
    void setBackground(const QPixmap &value);

    CollageForm getForm() const;
    void setForm(const CollageForm &value);

    QStringList getPhotoList() const;
    void setPhotoList(const QStringList &value);

signals:

public slots:

private:
    QSize collageSize;
    int photoSize;
    int nbPhotos;
    int distanceBetweenPhotos;
    QPixmap background;
    CollageForm form;
    QStringList photoList;
};


#endif // PARAMETERS_H
