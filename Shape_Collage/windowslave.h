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
#include"dialogdessinformeextra.h"
#include"labelclicable.h"

class WindowSlave
{
public:
    WindowSlave();
    static void ConvertAndMAJLineEdit(int index, int &oldindex, QLineEdit *lineedit);
    static void AjouterImage(GrillePhotos* g, QPushButton* moins, QPushButton *clear, QLabel* l);
    static void RetirerImage(GrillePhotos* g, QPushButton* moins, QPushButton *clear, QLabel* l);
    static void ViderGrillePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel* l);
    static void EffacerListePhoto(GrillePhotos *g, QPushButton *moins, QPushButton *clear, QLabel *l);
    static void SetTextBouton(bool value, QPushButton *bouton, const QString &section);
    static void GriseOuDegriseGroupe(bool &mode, QPushButton *boutonMode, const QString &section, QWidget * *groupe, int nb);
    static void ChangerCouleurArrierePlan(LabelClicable* label);
    static void ChargerPhotoArrierePlan(LabelClicable* label,QString& lienPhoto);
    static void DessinerForme();
    static bool EstUneImage(QString& fichier);
    static void RemettreValeursParDefaut(QRadioButton* radioRectangle,QComboBox *comboTaillecollage,
                                         QLineEdit* largeur,QLineEdit* hauteur,QComboBox* comboTaillePhoto,
                                         QLineEdit* taillePhoto,QRadioButton* tout,QLineEdit* nbPhoto,
                                         QSlider* distance,QRadioButton* arrierePlan,LabelClicable* couleur);
};

#endif // WINDOWSLAVE_H
