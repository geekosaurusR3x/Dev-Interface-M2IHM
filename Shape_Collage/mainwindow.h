#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogapropos.h"
#include <QPixmap>
#include <QPainter>
#include <QVBoxLayout>
#include <QPoint>
#include <QIcon>
#include "convertisseur.h"
#include <QMessageBox>
#include <QDebug>
#include <QStringList>
#include <QColorDialog>
#include <QChar>
#include <QRegExp>
#include <QFileDialog>
#include "labelclicable.h"
#include <QPushButton>
#include <QString>
#include "dialogdessinformeextra.h"
#include "grillephotos.h"
#include "windowslave.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wizard.h"
#include "exceptionattention.h"
#include "exceptionerreure.h"
#include "parameters.h"
#include "davinci.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Vider_GrillePhotos();
    void Remettre_Valeurs_Par_Defaut();
private:
    Ui::MainWindow *ui;
    GrillePhotos *grillePhotos;
    LabelClicable *LabelCouleurArrierePlan;
    LabelClicable *LabelPhotoArrierePlan;
    LabelClicable *LabelFormeExtra;

    QString LienPhotoArrierePlan;

    int UMTailleCollage;
    int UMTaillePhoto;

    bool ModeTailleCollage;
    bool ModeTaillePhoto;
    bool ModeNombrePhoto;
    bool ModeDistanceEntrePhotos;


    void GriseOuDegriseTailleCollage();
    void GriseOuDegriseTaillePhoto();
    void GriseOuDegriseNombrePhoto();
    void GriseOuDegriseDistancePhoto();

    DaVinci* mDaVinci;

private slots:
    void OnActionQuitter();
    void OnActionAPropos();
    void OnActionAideCreation();
    void OnActionNouveauProjet();
    void OnAjouterImage();
    void OnRetirerImage();
    void DegriseRetirerImage();
    void GriserBoutonRetirerImage();

    void MAJLargeurHauteur(int index);
    void MAJTaillePhoto(int index);

    void SetEnabledTailleCollage();
    void SetEnabledTaillePhoto();
    void SetEnabledNombrePhoto();
    void SetEnabledDistancePhoto();

    void ChangerCouleurArrierePlan();

    void RestaurerValParDefaut();

    void ClicArrierePlanPhoto();
    void ChargerPhotoArrierePlan();
    void DessinerPolygone();
    void DessinerPolygoneSivide();
    void EffacerListePhoto();

    void on_BoutonApercu_clicked();
    void on_BoutonCreer_clicked();
    void on_BoutonNombrePhotos_clicked();
};

#endif // MAINWINDOW_H


