#ifndef GRILLEPHOTOS_H
#define GRILLEPHOTOS_H
#include<QString>
#include <QListWidget>
#include<QLabel>

class GrillePhotos : public QListWidget
{
    Q_OBJECT
private:
    QStringList listePhoto;

public:
    explicit GrillePhotos(QWidget *parent = 0);
    void AjoutePhoto(QString photo);
    void RetirerPhoto();
    void EffacerListe();
    bool EstUneImage(QString &photo);
    QStringList getListePhoto() const;
    void setListePhoto(const QStringList &value);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
        void dropEvent(QDropEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void currentChanged(const QModelIndex &current, const QModelIndex &previous);
    signals:
        void clicked();
        void clacked();
public slots:

    
};

#endif // GRILLEPHOTOS_H
