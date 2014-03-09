#ifndef GRILLEPHOTOS_H
#define GRILLEPHOTOS_H
#include<QString>
#include <QListWidget>
#include<QLabel>
/**
 * \brief Classe heritant de QListWidget et permettant d'afficher des images sous forme de grille
 */
class GrillePhotos : public QListWidget
{
    Q_OBJECT
private:
    QStringList listePhoto;

public:
    explicit GrillePhotos(QWidget *parent = 0);
    /**
     * \brief Ajoute une image à la grille
     * \a photo lien de l'image à ajoutée
     */
    void AjoutePhoto(QString photo);

    /**
     * \brief Retire une photo de la grille
     */
    void RetirerPhoto();

    /**
     * \brief Efface toutes les images de la grille
     */
    void EffacerListe();

    /**
     * \brief Test si un fichier est une image
     * \a photo lien de l'image à tester
     * \return vrai si \photo est une image et faux sinon
     */
    bool EstUneImage(QString &photo);

    /**
     * \return la liste des images contenues dans la grille
     */
    QStringList getListePhoto() const;

    /**
     * \brief change la liste des images de la grille
     * \a value nouvelle valeur de la liste d'images de la grille
     */
    void setListePhoto(const QStringList &value);

protected:
    /**
     * \brief détecte l'entré d'éléments via drag and drop sur la grille
     * \a event évenement détecté
     */
    void dragEnterEvent(QDragEnterEvent *event);

    /**
     * \brief détecte le mouvement d'éléments via drag and drop sur la grille
     * \a event évenement détecté
     */
    void dragMoveEvent(QDragMoveEvent *event);

    /**
     * \brief détecte le dépot d'éléments via drag and drop sur la grille
     * \a event
     */
    void dropEvent(QDropEvent *event);

    /**
     * \brief détecte le click souris
     * \a event évenement souris
     */
    void mousePressEvent(QMouseEvent *event);

    /**
     * \brief détecte le changement de l'élément courant sélectionné
     * \a current élément actuel sélectionné
     * \a previous ancien élément sélectionné
     */
    void currentChanged(const QModelIndex &current, const QModelIndex &previous);
signals:
    /**
     * \brief signal créer pour interactions diverses
     */
    void clicked();

    /**
     * \brief signal créer pour interactions diverses
     */
    void clacked();
public slots:

    
};

#endif // GRILLEPHOTOS_H
