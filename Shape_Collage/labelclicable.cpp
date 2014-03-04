#include "labelclicable.h"
#include<QDebug>
#include<QColorDialog>
#include<QPalette>
#include<QDragEnterEvent>
#include<QMimeData>
#include<QDrag>
#include<QDirIterator>
#include<QString>
#include"windowslave.h"
#include<QPixmap>


LabelClicable::LabelClicable(bool acceptdrop, QWidget * parent )
:QLabel(parent)
{
    setFrameShape(QFrame::Box);
    this->ChangeCouleur(Qt::white);
    setAcceptDrops(acceptdrop);
    if(acceptdrop)
    {
        setText("<b>Faite glisser la photo ici</b>");
        setWordWrap(acceptdrop);
        setAlignment(Qt::AlignCenter);
    }
    setSizePolicy( QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding ) );

}

void LabelClicable::ChangeCouleur(QColor couleur)
{
    QPalette p;
    p.setColor(QPalette::Background,couleur);
    this->setPalette(p);
    this->setAutoFillBackground(true);
}



void LabelClicable::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
}


void LabelClicable::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void LabelClicable::dragMoveEvent(QDragMoveEvent *event)
{
    event->setDropAction(Qt::CopyAction);
    event->accept();
}

void LabelClicable::dropEvent(QDropEvent *event)
{
    QString fichier = event->mimeData()->urls().at(0).url().mid(8);
    //tester si c'est une image!
    if(WindowSlave::EstUneImage(fichier))
    {
        setPixmap(QPixmap(fichier));
        setScaledContents(true);
        adjustSize();
    }
}
