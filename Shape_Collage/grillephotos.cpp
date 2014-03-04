#include "grillephotos.h"
#include<QDragEnterEvent>
#include<QMimeData>
#include<QDrag>
#include<QDirIterator>
#include<QPixmap>
#include<QDebug>
#include"windowslave.h"

GrillePhotos::GrillePhotos(QWidget *parent) :
    QListWidget(parent)
{

    listePhoto = QStringList();
    setDragEnabled(true);
    setViewMode(QListView::IconMode);
    setSelectionMode(QAbstractItemView::ExtendedSelection);
    setIconSize(QSize(100,100));
    setWordWrap(true);
    setSpacing(2);
    setAcceptDrops(true);
}

void GrillePhotos::dragEnterEvent(QDragEnterEvent *event)
{
    // if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
    event->accept();
    // else
    //   event->ignore();
}

void GrillePhotos::dragMoveEvent(QDragMoveEvent *event)
{
    //if (event->mimeData()->hasFormat("image/x-puzzle-piece"))
    {
       event->setDropAction(Qt::CopyAction);
       event->accept();
    }
    //else
    //  event->ignore();
}

void GrillePhotos::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasUrls())
    {
        for (int i = 0; i < event->mimeData()->urls().count(); ++i)
        {
            QString fichier = event->mimeData()->urls().at(i).url().mid(8);
            //est-ce un fichier ou un dossier
            if(fichier.lastIndexOf(".")==-1)
            {
                QStringList listFilter;
                QDirIterator dossier(fichier,listFilter,QDir::Files|QDir::Dirs,QDirIterator::Subdirectories);
                while (dossier.hasNext())
                {
                    AjoutePhoto(dossier.next());
                }
            }
            else
            {
                AjoutePhoto(fichier);
            }
        }

        emit clicked();

        event->setDropAction(Qt::CopyAction);
        event->accept();
    }
}

void GrillePhotos::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event);
    if(!this->selectedItems().isEmpty())
        emit clicked();
    else
        emit clacked();
}

void GrillePhotos::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    QListWidget::currentChanged(current,previous);
    if(!this->selectedItems().isEmpty())
        emit clicked();
    else
        emit clacked();
}

void GrillePhotos::AjoutePhoto(QString photo)
{
    //tester si c'est une image!!!!!!!!!!!!!!!!!!!!!
    if(WindowSlave::EstUneImage(photo))
    {
        listePhoto<<photo;
        QString titre=photo.section("/",-1);
        QListWidgetItem *element=new QListWidgetItem(titre);
        element->setIcon(QIcon(photo));
        this->addItem(element);
    }
}

void GrillePhotos::RetirerPhoto()
{
    int nbsuppr = 0;
    for(int i=0;i<this->count();i++)
    {
        if(this->item(i)->isSelected())
        {
            listePhoto.removeAt(i-nbsuppr);
            nbsuppr++;
        }
    }
    //qDebug()<<"numéro "<<listePhoto<<endl;
    foreach (QListWidgetItem *it,this->selectedItems())
    {
        delete it;
    }
}

void GrillePhotos::EffacerListe()
{
    listePhoto.clear();
    this->clear();
}

bool GrillePhotos::EstUneImage(QString &photo)
{
    QString extension = photo.mid(photo.lastIndexOf(".")+1).toLower();
    QStringList Autorisee;
    Autorisee <<"jpg"<<"jpeg"<<"bmp"<<"png";
    return Autorisee.contains(extension);
}

QStringList GrillePhotos::getListePhoto() const
{
    return listePhoto;
}

void GrillePhotos::setListePhoto(const QStringList &value)
{
    listePhoto = value;
}
