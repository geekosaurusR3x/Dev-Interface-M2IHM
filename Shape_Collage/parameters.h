#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "ostream"

#include <QObject>
#include <QPixmap>
#include <QSize>
#include <QStringList>
#include <QDebug>

/**
 * @brief Enum décrivant les formes de collages disponibles
 * CIRCLE: Cercle
 * RECTANGLE: Rectangle
 * FREEHAND: Polygone
 */
enum CollageForm {
    CIRCLE = 0,
    RECTANGLE,
    FREEHAND
};

/**
 * @brief Classe Parameters: Cette classe est construite lors du click sur les boutons Aperçu et Créer
 * Elle contient tous les paramètres saisis par l'utilisateur et est donc passée à DaVinci, qui lui se
 * charge de créer le collage en adéquation.
 */
class Parameters : public QObject
{
    Q_OBJECT
    friend QDebug operator <<(QDebug dbg, const Parameters& obj);
    public:
    Parameters(QObject *parent = 0);
    Parameters(QSize&, int&, int&, int&, QPixmap&, CollageForm, QStringList, QObject *parent = 0);
    Parameters(const Parameters&);
    /**
     * @brief getCollageSize Retourne la taille du collage désirée
     * @return La taille du collage. NOTE: Si la taille est en automatique une taille de -1 x -1 est renvoyée
     */
    QSize getCollageSize() const;
    /**
     * @brief setCollageSize Change la taille du collage demandée
     * @param value La taille du collage désirée
     */
    void setCollageSize(const QSize &value);

    /**
     * @brief getPhotoSize Renvoit la taille maximale (hauteur OU largeur) qu'une photo peut avoir dans le collage
     * @return La taille maximale d'une photo
     */
    int getPhotoSize() const;
    /**
     * @brief setPhotoSize Fixe la taille des photos
     * @param value La tailler maximale des photos
     */
    void setPhotoSize(const int &value);

    /**
     * @brief getNbPhotos Combien de photos doivent être utilisées pour le collage
     * @return Le nombre de photos à utiliser pour le collage
     */
    int getNbPhotos() const;
    /**
     * @brief setNbPhotos Fixe le nombre de photos à utiliser parmis les photos importées
     * @param value Le nombre de photos à utiliser
     */
    void setNbPhotos(const int &value);

    /**
     * @brief getDistanceBetweenPhotos Retourne la distance relative désirée entre deux photos
     * @return La distance relative entre les photos
     */
    int getDistanceBetweenPhotos() const;
    /**
     * @brief setDistanceBetweenPhotos Fixe la distance entre les photos (pourcentage)
     * @param value La distance relative desirée
     */
    void setDistanceBetweenPhotos(const int &value);

    /**
     * @brief getBackground Retourne une pixmap avec l'arrière-plan du collage
     * @return La pixmap d'arrière-plan
     */
    QPixmap getBackground() const;

    /**
     * @brief setBackground Fixe l'image d'arrière-plan
     * @param value La pixmap d'arrière-plan désirée
     */
    void setBackground(const QPixmap &value);

    /**
     * @brief getForm Retourn la forme de collage désirée (CIRCLE, RECTANGLE ou FREEHAND)
     * @return La forme de collage désirée
     */
    CollageForm getForm() const;

    /**
     * @brief setForm Fixe la forme du collage
     * @param value La nouvelle forme du collage
     */
    void setForm(const CollageForm &value);

    /**
     * @brief getPhotoList Retourne une liste contenant les chemins vers les photos à utiliser pour le collage
     * @return La liste des chemins vers les photos
     */
    QStringList getPhotoList() const;

    /**
     * @brief setPhotoList Fixe les chemins vers les photos à utiliser
     * @param value La liste des chemins vers les photos
     */
    void setPhotoList(const QStringList &value);

    /**
     * @brief getDrawingAnimation Retourne la préférence relative à l'animation du collage
     * @return True si l'utilisateur désire voir l'animation
     */
    bool getDrawingAnimation() const;

    /**
     * @brief setDrawingAnimation Fixe la préférence d'animation
     * @param value La valeur de la préférence d'animation
     */
    void setDrawingAnimation(bool value);

    /**
     * @brief getPolygon Retourne polygone dessiné par l'utilisateur (forme FREEHAND seulement)
     * Confer labeldessinable
     * @return Le polygone dessiné par l'utilisateur
     */
    QPolygon getPolygon() const;

    /**
     * @brief setPolygon Fixe le polygone dessiné par l'utilisateur (forme FREEHAND seulement)
     * @param value Le polygone dessiné
     */
    void setPolygon(const QPolygon &value);

    /**
     * @brief getNbVertex Retourne le nombre de sommets du polygone dessiné par l'utilisateur (forme FREEHAND seulement)
     * @return Le nombre de sommets du polygone dessiné
     */
    int getNbVertex() const;
    /**
     * @brief setNbVertex Fixe le nombre de sommets du polygone de l'utilisateur
     * @param value Le nombre de sommets du polygone dessiné
     */
    void setNbVertex(int value);

signals:

public slots:

private:
    QSize collageSize;
    int photoSize;
    int nbPhotos;
    int distanceBetweenPhotos;
    QPixmap background;
    CollageForm form;
    QStringList photoList;
    bool drawingAnimation;
    QPolygon polygon;
    int nbVertex;
};


#endif // PARAMETERS_H
