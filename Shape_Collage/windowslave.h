#ifndef WINDOWSLAVE_H
#define WINDOWSLAVE_H
#include"convertisseur.h"
#include<QLineEdit>
#include<QPushButton>
#include"grillephotos.h"
#include<QWidget>
#include<QLabel>
#include<QDebug>
#include<QFileDialog>
#include<QColorDialog>
#include<QMessageBox>
#include<QRadioButton>
#include<QComboBox>
#include<QLineEdit>
#include <QPoint>
#include <QVector>
#include "labeldessinable.h"
#include"dialogdessinformeextra.h"
#include"labelclicable.h"

#include <QDesktopServices>

#define PI 3.141592653
/**
 * \brief Cette classe fournis, exclusivement, des services spécifiques à la fenetre principale et ses composants
 */
class WindowSlave
{
public:
    WindowSlave();

    /**
     * \brief Convertis la valeur du text d'un QLineEdit au format de la valeur d'un index vers le format d'un de la valeur d'un autre index
     * \a index index du format vers lequel la la valeur du text du QLineEdit sera convertis
     * \a oldindex index du format actuel de la valeur à convertir
     * \a lineedit Champ de text (QLineEdit) dont la valeur sera convertie
     */
    static void ConvertAndMAJLineEdit(int index, int &oldindex, QLineEdit *lineedit);

    /**
     * \brief Ajoute une image a un champ GrillePhotos et met à jour les champs qui lui sont associés
     * \a g GrillePhotos dans laquelle l'image est ajoutée
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void AjouterImage(GrillePhotos* g, QPushButton* moins, QPushButton *clear, QLabel* l);

    /**
     * \brief Retire une image d'un champ GrillePhotos et met à jour les champs qui lui sont associés
     * \a g GrillePhotos de laquelle l'image est retirée
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void RetirerImage(GrillePhotos* g, QPushButton* moins, QPushButton *clear, QLabel* l);

    /**
     * \brief supprime toutes les images d'une GrillePhotos et met à jour les champs associés
     * \a g GrillePhotos dont on supprime les image
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void ViderGrillePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel* l);

    /**
     * \brief supprime toutes les images d'une GrillePhotos et met à jour les champs associés après validation d'une boite de dialogue
     * \a g GrillePhotos dont on supprime les image
     * \a moins Bouton de suppression d'images selectionnées dans la grille
     * \a clear Bouton de suppression de toutes les images de la grille
     * \a l label affichant le nombre d'images contenues dans la grille
     */
    static void EffacerListePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel *l);

    /**
     * \brief Change le text d'un bouton selon la valeur d'un booleen ("Manuel" pour vrai et "Auto" pour faux) et met à jour son statustip
     * \a value booleen à tester
     * \a bouton bouton dont le text est changé
     * \a section nom de la section à laquelle le bouton appartient
     */
    static void SetTextBouton(bool value, QPushButton *bouton, const QString &section);

    /**
     * \brief Grise ou dégrise les éléments d'un tableau de QWidget selon un booleen
     * \a mode booleen selon lequel les champs seront grisés ou non
     * \a boutonMode bouton de la section traitée
     * \a section nom de la section à laquelle appartiennent les champs traités
     * \a groupe Tableau de QWidget à grisé ou dégrisé
     * \a nb nombre d'élément du tableau \a groupe
     */
    static void GriseOuDegriseGroupe(bool &mode, QPushButton *boutonMode, const QString &section, QWidget * *groupe, int nb);

    /**
     * \brief Change la couleur d'un LabelClicable et retourne la couleur courante de ce label
     * \a label label à modifier
     * \return La couleur actuelle du LabelClicable \a label
     */
    static QColor ChangerCouleurArrierePlan(LabelClicable* label);

    /**
     * \brief Change l'arriere-plan d'un LabelClicable avec une image
     * \a label le label dont l'arriere plan est changé
     * \a lienPhoto lien de l'image à afficher
     */
    static void ChargerPhotoArrierePlan(LabelClicable* label,QString& lienPhoto, QLineEdit* leWidth = 0, QLineEdit* leHeight = 0);


    static int DessinerForme(LabelDessinable*&);

    /**
     * \brief Teste si un fichier est une image
     * \a fichier fichier à tester
     * \return vrai si \a fichier est une image et faux sinon
     */
    static bool EstUneImage(QString& fichier);

    /**
     * \brief Remet toutes les valeurs par défaut en vue de créer un nouveau projet
     * \a radioRectangle bouton radio correspondant à la forme rectangle sur l'UI
     * \a comboTaillecollage combobox d'unité de mesure d'affichage de la taille du collage
     * \a champ de texte de saisie de la largeur largeur du collage
     * \a champ de texte de saisie de la hauteur hauteur du collage
     * \a comboTaillePhoto combobox d'unité de mesure d'affichage de la taille de la photo
     * \a taillePhoto taille de la photo
     * \a tout bouton radio de selection de toutes les photos pour le collage
     * \a nbPhoto champ de texte de saisie du nombre de photos utilisées pour le collage
     * \a distance slider pour modifier la distance entre les photos
     * \a arrierePlan bouton radio de selection du style de l'arriere-plan
     * \a couleur label de selection de la couleur de l'arrière-plan
     */
    static void RemettreValeursParDefaut(QRadioButton* radioRectangle,QComboBox *comboTaillecollage,
                                         QLineEdit* largeur,QLineEdit* hauteur,QComboBox* comboTaillePhoto,
                                         QLineEdit* taillePhoto,QRadioButton* tout,QLineEdit* nbPhoto,
                                         QSlider* distance,QRadioButton* arrierePlan,LabelClicable* couleur, LabelDessinable* preview, LabelClicable* photoBackground);
};

#endif // WINDOWSLAVE_H
