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
#include "labeldessinable.h"
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
#include <QBitmap>

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * \brief Vider_GrillePhotos
     */
    void Vider_GrillePhotos();

    /**
     * \brief Procédure permettant de remettre les valeurs par défaut des paramètres pour le collage
     */
    void Remettre_Valeurs_Par_Defaut();
private:
    Ui::MainWindow *ui;
    GrillePhotos *grillePhotos;
    LabelClicable *LabelCouleurArrierePlan;
    LabelClicable *LabelPhotoArrierePlan;
    LabelDessinable *LabelFormeExtra;

    QString LienPhotoArrierePlan;

    int UMTailleCollage;
    int UMTaillePhoto;

    bool ModeTailleCollage;
    bool ModeTaillePhoto;
    bool ModeNombrePhoto;
    bool ModeDistanceEntrePhotos;

    /**
     * \brief Procédure permettant de griser les champs de paramètres du groupe Taille du collage si ils sont dégrisés ou de les dégrisés sinon
     */
    void GriseOuDegriseTailleCollage();

    /**
     * \brief Procédure permettant de griser les champs de paramètres du groupe Taille de la photo si ils sont dégrisés ou de les dégrisés sinon
     */
    void GriseOuDegriseTaillePhoto();

    /**
     * \brief Procédure permettant de griser les champs de paramètres du groupe Nombre de photos si ils sont dégrisés ou de les dégrisés sinon
     */
    void GriseOuDegriseNombrePhoto();

    /**
     * \brief Procédure permettant de griser les champs de paramètres du groupe Distance entre les photos si ils sont dégrisés ou de les dégrisés sinon
     */
    void GriseOuDegriseDistancePhoto();

    Parameters getParameters();
    DaVinci* mDaVinci;
    void showSuccessDialog();
    void showFailureDialog(QString);
    QColor mBackgroundColor;
    int mNbVertex;
private slots:
    /**
     * \brief procédure appelée au click sur le menu MenuQuitter pour Quitter l'application
     */
    void OnActionQuitter();

    /**
     * \brief procédure appelée au click sur le menu MenuA_propos pour afficher la fenetre à propos
     */
    void OnActionAPropos();

    /**
     * \brief procédure appelée au click sur le menu MenuAide_creation pour créer un nouveau projet de collage
     */
    void OnActionAideCreation();

    /**
     * \brief procédure appelée au click sur le menu MenuNouveau_Projet pour créer un nouveau projet de collage
     */
    void OnActionNouveauProjet();

    /**
     * \brief Procédure appelée au click du bouton BoutonAjouterImage
     */
    void OnAjouterImage();

    /**
     * \brief Procédure appelée au click du bouton BoutonRetirerImage
     */
    void OnRetirerImage();

    /**
     * \brief Procédure appelée pour dégriser le bouton BoutonRetirerImage
     */
    void DegriseRetirerImage();

    /**
     * \brief Procédure appelée pour griser le bouton BoutonRetirerImage
     */
    void GriserBoutonRetirerImage();

    /**
     * \brief procédure Appelée au changement de valeur de la combbox ComboBoxTailleCollage pour mettre à jour les valeurs affichées dans les champ de text correspondant
     * \a index l'indice de la nouvelle unité de mesure affichée et à utiliser
     */
    void MAJLargeurHauteur(int index);

    /**
     * \brief procédure Appelée au changement de valeur de la combbox ComboBoxTaillePhoto pour mettre à jour la valeur affichée dans le champ de text correspondant
     * \a index l'indice de la nouvelle unité de mesure affichée et  à utiliser
     */
    void MAJTaillePhoto(int index);

    /**
     * \brief procédure Appelée au click sur le bouton BoutonTailleCollage pour rendre modifiable ou non les paramètres du groupe Taille du collage
     */
    void SetEnabledTailleCollage();

    /**
     * \brief procédure Appelée au click sur le bouton BoutonTaillePhoto pour rendre modifiable ou non les paramètres du groupe Taille de la photo
     */
    void SetEnabledTaillePhoto();

    /**
     * \brief procédure Appelée au click sur le bouton BoutonNombrePhotos pour rendre modifiable ou non les paramètres du groupe Nombre de photos
     */
    void SetEnabledNombrePhoto();

    /**
     * \brief procédure Appelée au click sur le bouton BoutonDistancePhotos pour rendre modifiable ou non les paramètres du groupe Distance entre les photos
     */
    void SetEnabledDistancePhoto();

    /**
     * \brief procédure permettant de changer la couleur de l'arriere-plan
     */
    void ChangerCouleurArrierePlan();

    /**
     * \brief procédure Appelée au click sur le bouton BoutonRestaurerValeurs pour remmettre toutes les valeurs de paramètrage du collage par défaut
     */
    void RestaurerValParDefaut();

    /**
     * \brief procédure Appelée au click sur le bouton radio RadioBoutonArrierePlanPhoto pour sélectionner unephoto d'arriere-plan
     */
    void ClicArrierePlanPhoto();

    /**
     * \brief Procédure permettant de télécharger une image pour la mettre en arriere-plan du collage
     */
    void ChargerPhotoArrierePlan();
    /**
     * \brief DessinerPolygone
     */
    void DessinerPolygone();
    /**
     * \brief DessinerPolygoneSivide
     */
    void DessinerPolygoneSivide();
    /**
     * \brief procédure Appelée au click sur le bouton BoutonEffacerListe
     */
    void EffacerListePhoto();
    /**
     * \brief procédure Appelée au click sur le bouton BoutonApercu
     */
    void on_BoutonApercu_clicked();
    /**
     * \brief procédure Appelée au click sur le bouton BoutonCreer
     */
    void on_BoutonCreer_clicked();
    /**
     * \brief procédure Appelée au click sur le bouton BoutonNombrePhotos
     */
    void on_BoutonNombrePhotos_clicked();
};

#endif // MAINWINDOW_H


