#include "windowslave.h"

WindowSlave::WindowSlave()
{
}

void WindowSlave::ConvertAndMAJLineEdit(int index, int &oldindex, QLineEdit *lineedit)
{
    float text=lineedit->text().toFloat();
    switch (index)
    {
        case 0:
        {
             if(oldindex==1)
             {
                text=Convertisseur::PouceToPixels(text);
             }
             else
             {
                text=Convertisseur::CmToPixel(text);
             }
             //oldindex=0;
        } break;

        case 1:
        {
            if(oldindex==0)
            {
               text=Convertisseur::PixelsToPouce(text);
            }
            else
            {
               text=Convertisseur::CmToPouce(text);
            }
            //oldindex=1;
        } break;

        case 2:
        {
            if(oldindex==0)
            {
               text=Convertisseur::PixelsToCm(text);
            }
            else
            {
               text=Convertisseur::PouceToCm(text);
            }
           //oldindex=2;
        } break;
    }
    //on arrondit le nombre si possible
    /*int ratio = (int)text;
    float mantisse = text - (float) ratio;
    float ratiof = (mantisse * 10);
    if(mantisse<0.6)
    {
       text = (float) floor(text);
    }
    else
    {
        text +=1.0 ;
    }


    qDebug()<<" Valeur "<<mantisse<<endl;*/
    lineedit->setText(QString::number(text));
}

void WindowSlave::AjouterImage(GrillePhotos *g, QPushButton *moins, QPushButton* clear, QLabel *l)
{
    QStringList images;
    images=QFileDialog::getOpenFileNames(g,"Ajouter des photos","","Images (*.png *.jpg *.bmp *.jpeg)");
    if(!images.isEmpty())
    {
        for (int i = 0; i < images.count(); ++i)
        {
            g->AjoutePhoto(images.at(i));
        }
        moins->setEnabled(true);
        clear->setEnabled(true);
        l->setText(QString::number(g->count())+" Photos");
    }
}

void WindowSlave::RetirerImage(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel *l)
{
    g->RetirerPhoto();
    moins->setEnabled(false);
    int nb=g->count();
    l->setText(QString::number(nb)+" Photos");
    if(nb<=0)
    {
        clear->setEnabled(false);
    }
}

void WindowSlave::ViderGrillePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel* l)
{
    g->EffacerListe();
    clear->setEnabled(false);
    moins->setEnabled(false);
    l->setText("0 Photos");
}

void WindowSlave::EffacerListePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel* l)
{
    if(QMessageBox::question(g,"Effacé la liste des photos",
                             "Ête-vous sûr de vouloir supprimer toutes les photos du cadre?",
                             QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        ViderGrillePhoto(g,moins,clear,l);
    }
}

void WindowSlave::SetTextBouton(bool value, QPushButton *bouton, const QString& section)
{
    if(value)
    {
        bouton->setText("Manuel");
        bouton->setStatusTip("cliquez pour ajuster automatiquement "+section);
    }
    else
    {
        bouton->setText("Auto");
        bouton->setStatusTip("cliquez pour regler manuellement "+section);
    }
}

void WindowSlave::GriseOuDegriseGroupe(bool &mode, QPushButton *boutonMode, const QString& section, QWidget **groupe, int nb)
{
    mode = !mode;
    SetTextBouton(mode,boutonMode,section);
    for(int i=0; i<nb; i++)
    {
        groupe[i]->setEnabled(mode);
    }
}

QColor WindowSlave::ChangerCouleurArrierePlan(LabelClicable *label)
{
    QColor couleur=QColorDialog::getColor(Qt::white,label,"Choisissez la couleur de l'arrière plan");
    if(couleur.isValid())
    {
        label->ChangeCouleur(couleur);
    }
    return couleur;
}

void WindowSlave::ChargerPhotoArrierePlan(LabelClicable *label, QString &lienPhoto)
{

    QStringList Autorisee;
    Autorisee<<"jpg"<<"jpeg"<<"bmp"<<"png";
    QString fichier=QFileDialog::getOpenFileName(label,"Choisir la photo de l'arrière-plan","","Image (*.png *.jpg *.bmp *.jpeg)");
    if(!fichier.isEmpty()&& (Autorisee.contains(fichier.mid(fichier.lastIndexOf(".")+1).toLower())))
    {
        lienPhoto=fichier;
        if(QMessageBox::question(label,"Taille du collage",
                                 "Désirez-vous adapter la taille du collage à celle de la photo d'arrière-plan ?",
                                 QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
        {
            qDebug()<<"adapter"<<endl;
        }
        else
        {
            qDebug()<<"ne pas adapter"<<endl;
        }
        label->setPixmap(QPixmap(lienPhoto));
        label->setScaledContents(true);
        label->adjustSize();
    }
}

void WindowSlave::DessinerForme()
{
    DialogDessinFormeExtra dlg;
    dlg.exec();
}

void WindowSlave::DessinerFormeSetPoint(LabelClicable* label) {


}

bool WindowSlave::EstUneImage(QString &fichier)
{
    QString extension = fichier.mid(fichier.lastIndexOf(".")+1).toLower();
    QStringList Autorisee;
    Autorisee <<"jpg"<<"jpeg"<<"bmp"<<"png";
    return Autorisee.contains(extension);
}

void WindowSlave::RemettreValeursParDefaut(QRadioButton* radioRectangle,QComboBox *comboTaillecollage,
                                           QLineEdit* largeur,QLineEdit* hauteur,QComboBox* comboTaillePhoto,
                                           QLineEdit* taillePhoto,QRadioButton* tout,QLineEdit* nbPhoto,
                                           QSlider* distance,QRadioButton* arrierePlan,LabelClicable* couleur)
{
    radioRectangle->setChecked(true);
    comboTaillecollage->setCurrentIndex(0);
    largeur->setText("1366");
    hauteur->setText("768");

    comboTaillePhoto->setCurrentIndex(0);
    taillePhoto->setText("200");

    tout->setChecked(true);
    nbPhoto->setText("150");

    distance->setValue(67);

    arrierePlan->setChecked(true);
    couleur->ChangeCouleur(Qt::white);
}


