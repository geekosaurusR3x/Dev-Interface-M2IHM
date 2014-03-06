#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grillePhotos = new GrillePhotos(ui->GroupeBoxPhotos);
    ui->VerticalLayoutPhotos->addWidget(grillePhotos);
    LabelCouleurArrierePlan = new LabelClicable(false,this);
    ui->LayoutCouleurArrirePlan->addWidget(LabelCouleurArrierePlan);
    LabelPhotoArrierePlan = new LabelClicable(true,this);
    ui->LayoutPhotoArrierePlan->addWidget(LabelPhotoArrierePlan);
    LabelFormeExtra = new LabelClicable(false,this);
    ui->LayoutFormeExtra->addWidget(LabelFormeExtra);
    ModeTailleCollage = false;
    ModeTaillePhoto = true;
    ModeNombrePhoto = true;
    ModeDistanceEntrePhotos = true;
    UMTailleCollage = 0;
    UMTaillePhoto = 0;
    LienPhotoArrierePlan="";

    grillePhotos->setStatusTip("Deposer des photos ici ou cliquer sur \"+\" pour ajouter des photos");
    LabelFormeExtra->setStatusTip("Dessiner votre propre forme");
    LabelCouleurArrierePlan->setStatusTip("Couleur d'arrière-plan");
    LabelPhotoArrierePlan->setStatusTip("Utiliser une photo pour l'arrière-plan");

    mDaVinci = new DaVinci(ui->LabelEtat);
    mBackgroundColor = Qt::white;

    connect(grillePhotos,SIGNAL(clicked()),this,SLOT(DegriseRetirerImage()));
    connect(grillePhotos,SIGNAL(clacked()),this,SLOT(GriserBoutonRetirerImage()));
    connect(LabelCouleurArrierePlan, SIGNAL( clicked() ), this, SLOT( ChangerCouleurArrierePlan()));
    connect(LabelPhotoArrierePlan, SIGNAL(clicked()), this, SLOT(ChargerPhotoArrierePlan()));
    connect(LabelFormeExtra, SIGNAL(clicked()), this, SLOT(DessinerPolygone()));

//    {
//        throw  ExceptionErreure("test rien à signaler");
//    } catch (ExceptionErreure &e)
//    {
//        e.Afficher(this);
//    }

   // Wizard wiz;
   // wiz.exec();

    //grillePhotos->AjoutePhoto("C:/Users/DANIEL-6/Pictures/dora.jpg");
    //grillePhotos->AjoutePhoto("C:/Users/DANIEL-6/Pictures/dora.jpg");
    //grillePhotos->AjoutePhoto("C:/Users/DANIEL-6/Pictures/drole.jpg");

//    QPixmap pixmap(100,100);
//    pixmap.fill(QColor("transparent"));
//    QPainter painter(&pixmap);
//    painter.setBrush(QBrush(Qt::blue));
//    painter.drawRect(10, 10, 100, 100);
//    painter.setBrush(QBrush(Qt::red));
//    painter.drawEllipse(10, 10, 50, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
    grillePhotos = NULL;
    delete grillePhotos;

    LabelCouleurArrierePlan = NULL;
    delete LabelCouleurArrierePlan;

    LabelPhotoArrierePlan = NULL;
    delete LabelPhotoArrierePlan;

    LabelFormeExtra = NULL;
    delete LabelFormeExtra;
}


void MainWindow::GriseOuDegriseTailleCollage()
{
    QWidget* temp[4]={ui->LineEditLargeur,ui->LabelX,ui->LineEditHauteur,ui->ComboBoxTailleCollage};
    WindowSlave::GriseOuDegriseGroupe(this->ModeTailleCollage,ui->BoutonTailleCollage,
                                      QString("la taille du collage"),temp,4);
}

void MainWindow::GriseOuDegriseTaillePhoto()
{
    QWidget* temp[2]={ui->LineEditTaillePhoto, ui->ComboBoxTaillePhoto};
    WindowSlave::GriseOuDegriseGroupe(this->ModeTaillePhoto, ui->BoutonTaillePhoto,
                                      QString("la taille de la photo dans le collage"),temp,2);
}

void MainWindow::GriseOuDegriseNombrePhoto()
{
    QWidget* temp[4]={ui->RadioBoutonTout,ui->RadioBoutonPhotos,ui->LineEditNombrePhoto, ui->LabelPhotos};
    WindowSlave::GriseOuDegriseGroupe(this->ModeNombrePhoto,ui->BoutonNombrePhotos,
                                      QString("le nombre de photos du collage"),temp,4);
}

void MainWindow::GriseOuDegriseDistancePhoto()
{
    QWidget* temp[3]={ ui->SliderDistancePhotos,ui->SpinBoxDistancePhotos,ui->LabelPourcentage};
    WindowSlave::GriseOuDegriseGroupe(this->ModeDistanceEntrePhotos, ui->BoutonDistancePhotos,
                                      QString("l'espacement des photos du collage"),temp,3);
}

void MainWindow::MAJLargeurHauteur(int index)
{
    WindowSlave::ConvertAndMAJLineEdit(index,UMTailleCollage,ui->LineEditLargeur);
    WindowSlave::ConvertAndMAJLineEdit(index,UMTailleCollage,ui->LineEditHauteur);
    UMTailleCollage=index;
}

void MainWindow::MAJTaillePhoto(int index)
{
    WindowSlave::ConvertAndMAJLineEdit(index,UMTaillePhoto,ui->LineEditTaillePhoto);
    UMTaillePhoto=index;
}

void MainWindow::SetEnabledTailleCollage()
{
    bool mode=this->ModeTailleCollage;
    GriseOuDegriseTailleCollage();
    if(!mode){
        GriseOuDegriseTaillePhoto();
    }
    else{
        if(!this->ModeTaillePhoto){
            GriseOuDegriseTaillePhoto();
        }
        else{
            if(!this->ModeNombrePhoto){
                GriseOuDegriseNombrePhoto();
            }
            else{
                GriseOuDegriseDistancePhoto();
            }
        }
    }
}

void MainWindow::SetEnabledTaillePhoto()
{
    bool mode=this->ModeTaillePhoto;
    GriseOuDegriseTaillePhoto();
    if(!mode){
        GriseOuDegriseTailleCollage();
    }
    else{
        if(!this->ModeTailleCollage){
            GriseOuDegriseTailleCollage();
        }
        else{
            if(!this->ModeNombrePhoto){
                GriseOuDegriseNombrePhoto();
            }
            else{
                GriseOuDegriseDistancePhoto();
            }
        }
    }

}

void MainWindow::SetEnabledNombrePhoto()
{
    bool mode=this->ModeNombrePhoto;
    GriseOuDegriseNombrePhoto();
    if(!mode){
        GriseOuDegriseTailleCollage();
    }
    else{
        if(!this->ModeTailleCollage){
            GriseOuDegriseTailleCollage();
        }
        else{
            if(!this->ModeTaillePhoto){
                GriseOuDegriseTaillePhoto();
            }
            else{
                GriseOuDegriseDistancePhoto();
            }
        }
    }

}

void MainWindow::SetEnabledDistancePhoto()
{
    bool mode = this->ModeDistanceEntrePhotos;
    GriseOuDegriseDistancePhoto();
    if(!mode){
        GriseOuDegriseTailleCollage();
    }
    else{
        if(!this->ModeTailleCollage){
            GriseOuDegriseTailleCollage();
        }
        else{
            if(!this->ModeTaillePhoto){
                GriseOuDegriseTaillePhoto();
            }
            else{
                GriseOuDegriseNombrePhoto();
            }
        }
    }

}

void MainWindow::ChangerCouleurArrierePlan()
{
    mBackgroundColor = WindowSlave::ChangerCouleurArrierePlan(LabelCouleurArrierePlan);
}

void MainWindow::RestaurerValParDefaut()
{
    if(QMessageBox::question(this,"Remettre les paramètre par défaut",
                             "Ête-vous sûr de vouloir remettre les paramètres par défaut ?",
                             QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        Remettre_Valeurs_Par_Defaut();
    }

}

void MainWindow::ClicArrierePlanPhoto()
{
    if(LienPhotoArrierePlan=="")
    {
        ChargerPhotoArrierePlan();
    }
}

void MainWindow::ChargerPhotoArrierePlan()
{
    WindowSlave::ChargerPhotoArrierePlan(LabelPhotoArrierePlan,LienPhotoArrierePlan);
}

void MainWindow::DessinerPolygone()
{
    WindowSlave::DessinerForme();
}

void MainWindow::DessinerPolygoneSivide()
{
    //tester si il n'y a pas déjà un polygone dans le label forme extra
    WindowSlave::DessinerForme();
    //qDebug()<<"tester si vide"<<endl;
}

void MainWindow::EffacerListePhoto()
{
    WindowSlave::EffacerListePhoto(this->grillePhotos, ui->BoutonRetirerImage,
                                   ui->BoutonEffacerListe,ui->LabelNombrePhotosAffichees);
}


void MainWindow::OnActionQuitter()
{
    qApp->quit();
}

void MainWindow::OnActionAPropos()
{
    DialogAPropos dlg;
    dlg.exec();
}

void MainWindow::OnActionAideCreation()
{
    Wizard wiz;
    wiz.exec();
}

void MainWindow::Vider_GrillePhotos()
{
    WindowSlave::ViderGrillePhoto(this->grillePhotos, ui->BoutonRetirerImage,
                                  ui->BoutonEffacerListe,ui->LabelNombrePhotosAffichees);
}

void MainWindow::Remettre_Valeurs_Par_Defaut()
{
    if(ui->BoutonTailleCollage->text()=="Manuel")
    {
        SetEnabledTailleCollage();
    }
    WindowSlave::RemettreValeursParDefaut(ui->RadioBoutonRectangle,ui->ComboBoxTailleCollage,ui->LineEditLargeur,
                                          ui->LineEditHauteur,ui->ComboBoxTaillePhoto,ui->LineEditTaillePhoto,
                                          ui->RadioBoutonTout,ui->LineEditNombrePhoto,ui->SliderDistancePhotos,
                                          ui->RadioBoutonArrierePlanColorie,LabelCouleurArrierePlan);
}

void MainWindow::OnActionNouveauProjet()
{
    if(QMessageBox::question(this,"Remettre les paramètre par défaut",
                             "Voulez-vous vraiment réinitialiser l'application?\n"
                             "(toutes les photos du cadre \"Photos\" seront supprimées)",
                             QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        Remettre_Valeurs_Par_Defaut();
        //effacage de la liste de photo
        Vider_GrillePhotos();

    }

}

void MainWindow::OnAjouterImage()
{
    WindowSlave::AjouterImage(this->grillePhotos, ui->BoutonRetirerImage,
                              ui->BoutonEffacerListe,ui->LabelNombrePhotosAffichees);
}

void MainWindow::OnRetirerImage()
{
    WindowSlave::RetirerImage(this->grillePhotos, ui->BoutonRetirerImage,
                              ui->BoutonEffacerListe,ui->LabelNombrePhotosAffichees);
}

void MainWindow::DegriseRetirerImage()
{
    if(grillePhotos->selectedItems().count()>0)
    {
        ui->BoutonRetirerImage->setEnabled(true);
    }
    ui->BoutonEffacerListe->setEnabled(true);
    ui->LabelNombrePhotosAffichees->setText(QString::number(grillePhotos->count())+" Photos");
}

void MainWindow::GriserBoutonRetirerImage()
{
    ui->BoutonRetirerImage->setEnabled(false);
}

/*on_LineEditTaillePhoto_textChanged( QString &arg1)
{
    QChar c =arg1.at(arg1.length()-1);
    if(!c.isDigit())
    {
        if(c=='.'&&(arg1.left(arg1.length()-1).contains(".")))
        {
            arg1.replace(arg1.length()-1,1,"");
            QString aux = arg1;//.mid(0,arg1.count()-1);
            //aux.replace(arg1.length()-1,1,"");
            qDebug()<<"nouveau  point  "<<arg1<<endl;
        }
    }
}*/

Parameters MainWindow::getParameters() {
    QSize collageSize;
    double imageSize = -1;
    int nbPhotos = -1;
    int distanceBetweenPhotos = -1;
    QPixmap background; //  = QImage(this->LienPhotoArrierePlan);
    CollageForm form;

    if (this->ModeTailleCollage) {
            float height = ui->LineEditHauteur->text().toFloat();
            float width = ui->LineEditLargeur->text().toFloat();
            qDebug() << "orig W: " << ui->LineEditLargeur->text() << " orig H: " << ui->LineEditHauteur;
            qDebug() << "W: " << width << " H:" << height;

            switch (this->UMTailleCollage) {
                case 1: // Current: inch (pouces)
                    height = Convertisseur::PouceToPixels(height);
                    width = Convertisseur::PouceToPixels(width);
                    break;
                case 2: // Current: cm
                    height = Convertisseur::CmToPixel(height);
                    width = Convertisseur::CmToPixel(width);
                    break;
            }
            // TODO Multiply by 100 to get rid float
            collageSize = QSize(width, height);
    }

    if (this->ModeTaillePhoto) {
        imageSize = ui->LineEditTaillePhoto->text().toFloat();
        switch (this->UMTaillePhoto) {
        case 1:
            imageSize = Convertisseur::PouceToPixels(imageSize);
            break;
        case 2:
            imageSize = Convertisseur::CmToPixel(imageSize);
            break;
        }

        qDebug() << "UI Image size: " << ui->LineEditTaillePhoto->text();
    }

    if (this->ModeNombrePhoto) {
        int maxPhotos = this->grillePhotos->getListePhoto().size();
        if (ui->RadioBoutonPhotos->isChecked()) {
            nbPhotos = qMin(maxPhotos,ui->LineEditNombrePhoto->text().toInt());
        } else {
            nbPhotos = maxPhotos;
        }
    }

    if (this->ModeDistanceEntrePhotos) {
        distanceBetweenPhotos = ui->SpinBoxDistancePhotos->value();
    }

    if (ui->RadioBoutonExtra->isChecked()) {
        form = FREEHAND;
    } else if (ui->RadioBoutonCercle->isChecked()) {
        form = CIRCLE;
    } else {
        form = RECTANGLE;
    }

    if (ui->RadioBoutonArrierePlanColorie->isChecked()) {
        background = QPixmap(1, 1);
        background.fill(mBackgroundColor);
    } else if (ui->RadioBoutonArrierePlanTransparent->isChecked()) {
        background = QPixmap(1,1);
        background.fill(Qt::transparent);
    } else {
        // background = QImage(this->LienPhotoArrierePlan);
        background = QPixmap::fromImage(QImage(this->LienPhotoArrierePlan));
    }

    int intImgSize = static_cast<int>(imageSize);
    Parameters params = Parameters(collageSize, intImgSize, nbPhotos, distanceBetweenPhotos, background, form, this->grillePhotos->getListePhoto());
    params.setDrawingAnimation(ui->CheckBoxActiverAnimation->isChecked());
    qDebug() << params;
    return params;
}

void MainWindow::on_BoutonNombrePhotos_clicked() {

}

void MainWindow::on_BoutonApercu_clicked()
{
    Parameters params = getParameters();
    if (this->grillePhotos->getListePhoto().size() > 0) {
        mDaVinci->draw(params, ui->ProgressBarJauge);
    } else {
        showFailureDialog("Veuillez ajouter au moins une photo.");
    }
}

void MainWindow::showSuccessDialog() {
    QMessageBox msgBox;
    msgBox.setText("Votre image a bien été enregistrée!");
    msgBox.exec();
}

void MainWindow::showFailureDialog(QString errMsg)  {
    QMessageBox msgBox;
    msgBox.setText("Erreur!");
    msgBox.setInformativeText(errMsg);
    msgBox.exec();
}

void MainWindow::on_BoutonCreer_clicked()
{
    Parameters params = getParameters();
    // TODO Uncomment
    if (!mDaVinci->getAlreadyGenerated()) {
        // mDaVinci->draw(params);
        this->on_BoutonApercu_clicked();
    }
    if (mDaVinci->getAlreadyGenerated()) {
        // FIXME check file existance
        QString defaultLocation = "";
#ifdef linux
        defaultLocation = "/tmp";
#endif
        QString fichier = QFileDialog::getSaveFileName(this,"Choisir où enregistrer votre collage", defaultLocation, ".png");

        if (fichier != NULL) {
            if (mDaVinci->exportImage(fichier)) {
                showSuccessDialog();
            } else {
                showFailureDialog("Votre collage n'a pas pu être enregistré.");
            }
        }
    }
}
