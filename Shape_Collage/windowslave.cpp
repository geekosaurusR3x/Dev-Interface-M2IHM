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
    images=QFileDialog::getOpenFileNames(g,"Ajouter des photos",QDir::homePath(),"Images (*.png *.jpg *.bmp *.jpeg)");
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

bool WindowSlave::AskCollageSizeToBackgroundAdjustement() {
   return QMessageBox::question(0, "Taille du collage",
                             "Désirez-vous adapter la taille du collage à celle de la photo d'arrière-plan ?",
                             QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes;
}

void WindowSlave::AdjustCollageSize(QLineEdit* lineEditWidth, QLineEdit* lineEditHeight, int width, int height) {
    if (lineEditHeight != NULL) {
        lineEditHeight->setText(QString::number(height));
    }
    if (lineEditWidth != NULL) {
        lineEditWidth->setText(QString::number(width));
    }
}

void WindowSlave::ChangerPhotoArrierePlan(LabelClicable* label, QString &fichier, QLineEdit* lineEditWidth, QLineEdit* lineEditHeight) {
    QStringList Autorisee;
    Autorisee<<"jpg"<<"jpeg"<<"bmp"<<"png";
    if(!fichier.isEmpty()&& (Autorisee.contains(fichier.mid(fichier.lastIndexOf(".")+1).toLower())))
    {
        QPixmap pixmap(fichier);
        if (AskCollageSizeToBackgroundAdjustement()) {
            AdjustCollageSize(lineEditWidth, lineEditHeight, pixmap.width(), pixmap.height());
        }
        label->setPixmap(WindowSlave::ResizeToFit(pixmap, label));
        label->setScaledContents(false);
        label->adjustSize();
    }
}

void WindowSlave::ChargerPhotoArrierePlan(LabelClicable* label, QString &lienPhoto, QLineEdit* lineEditWidth, QLineEdit* lineEditHeight)
{
    QString fichier = QFileDialog::getOpenFileName(label,"Choisir la photo de l'arrière-plan","","Image (*.png *.jpg *.bmp *.jpeg)");
    ChangerPhotoArrierePlan(label, fichier, lineEditWidth, lineEditHeight);
}

QPixmap WindowSlave::ResizeToFit(QPixmap& pixmap, QLabel* label) {
    int pixmapMax = qMax(pixmap.height(), pixmap.width());
    int labelMax = qMax(label->height(), label->width());
    int minSize = qMin(pixmapMax, labelMax);
    if (pixmap.height() == pixmapMax) {
        pixmap = pixmap.scaledToHeight(minSize);
    } else if (pixmap.width() == pixmapMax) {
        pixmap = pixmap.scaledToWidth(minSize);
    }
    return pixmap;
}

int WindowSlave::DessinerForme(LabelDessinable*& previewLabel)
{
    DialogDessinFormeExtra dlg(previewLabel);
    if (dlg.exec() == QDialog::Accepted) {
        if (dlg.isValid()) {
            qDebug() << "IS VALID";
        } else {
            qDebug() << "NOT VALID";
            // showFailureDialog("La forme que vous avez dessinée n'est pas valide");
        }
        return dlg.getNbVertex();
    } else {
        previewLabel->clear();
    }
}

bool WindowSlave::EstUneImage(QString &fichier)
{
    QString extension = fichier.mid(fichier.lastIndexOf(".")+1).toLower();
    QStringList Autorisee;
    Autorisee <<"jpg"<<"jpeg"<<"bmp"<<"png";
    return Autorisee.contains(extension);
}

void WindowSlave::showSuccessDialog() {
    QMessageBox msgBox;
    msgBox.setText("Votre image a bien été enregistrée!");
    msgBox.exec();
}

void WindowSlave::showFailureDialog(QString errMsg)  {
    QMessageBox msgBox;
    msgBox.setText("Erreur !");
    msgBox.setInformativeText(errMsg);
    msgBox.exec();
}


void WindowSlave::RemettreValeursParDefaut(QRadioButton* radioRectangle,QComboBox *comboTaillecollage,
                                           QLineEdit* largeur,QLineEdit* hauteur,QComboBox* comboTaillePhoto,
                                           QLineEdit* taillePhoto,QRadioButton* tout,QLineEdit* nbPhoto,
                                           QSlider* distance,QRadioButton* arrierePlan,LabelClicable* couleur, LabelDessinable* preview, LabelClicable *labelPhotoBackground)
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
    labelPhotoBackground->clear();
    labelPhotoBackground->setText("<b>Faites glisser une image ici</b>");
    preview->clear();
}

QSize WindowSlave::SizeUiToParam(int modeValeur, QLineEdit *largeur, QLineEdit *hauteur)
{

    float width = largeur->text().toFloat();
    float height = hauteur->text().toFloat();
    qDebug() << "orig W: " << largeur->text() << " orig H: " << hauteur->text();
    qDebug() << "W: " << width << " H:" << height;

    switch (modeValeur) {
        case 1: // Current: inch (pouces)
            height = Convertisseur::PouceToPixels(height);
            width = Convertisseur::PouceToPixels(width);
            break;
        case 2: // Current: cm
            height = Convertisseur::CmToPixel(height);
            width = Convertisseur::CmToPixel(width);
            break;
    }

    return QSize(width, height);
}

int WindowSlave::PhotoSizeUiToParam(int modeValeur, QLineEdit *size)
{
    double imageSize = size->text().toFloat();
    switch (modeValeur) {
    case 1:
        imageSize = Convertisseur::PouceToPixels(imageSize);
        break;
    case 2:
        imageSize = Convertisseur::CmToPixel(imageSize);
        break;
    }

    qDebug() << "UI Image size: " << size->text();
    return static_cast<int>(imageSize);
}

int WindowSlave::NbPhotoUiToParam(int nbphotolist, QRadioButton* radiobuttonphoto, QLineEdit* lideeditbutton)
{
    int nbPhotos;
    if (radiobuttonphoto->isChecked()) {
        nbPhotos = qMin(nbphotolist,lideeditbutton->text().toInt());
    } else {
        nbPhotos = nbphotolist;
    }

    return nbPhotos;
}

int WindowSlave::DistancePhotoUItoParam(QSpinBox* spinsize)
{
    return spinsize->value();
}

CollageForm WindowSlave::FormUIToParam(QRadioButton *extra, QRadioButton *cercle)
{
    CollageForm form;
    if (extra->isChecked()) {
        form = FREEHAND;
    } else if (cercle->isChecked()) {
        form = CIRCLE;
    } else {
        form = RECTANGLE;
    }
    return form;
}

QPixmap WindowSlave::BackgroundUiToParam(QRadioButton* radiocolor, QColor color, QRadioButton* radiotransparent, QString lienPhoto)
{
    QPixmap pixmap;
    if (radiocolor->isChecked()) {
        pixmap = QPixmap(1, 1);
        pixmap.fill(color);
    } else if (radiotransparent->isChecked()) {
        pixmap = QPixmap(1,1);
        pixmap.fill(Qt::transparent);
    } else {
        pixmap = QPixmap::fromImage(QImage(lienPhoto));
    }

    return pixmap;
}


