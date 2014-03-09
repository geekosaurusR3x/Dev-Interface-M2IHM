#ifndef LABELDESSINABLE_H
#define LABELDESSINABLE_H

#include <QWidget>
#include <QList>
#include <QPoint>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QPainter>
#include <QLineF>
#include <qmath.h>
#include "labelclicable.h"
#include "mathhelper.h"

class LabelDessinable : public LabelClicable
{
    Q_OBJECT
public:
    explicit LabelDessinable(QWidget *parent = 0);
    int getNbVertex() const;
    void setNbVertex(int value);
    void setPreviewLabel(LabelDessinable *value);
    QPolygon getPolygon();
    /**
     * @brief Demande la remise a jour du polygone en memoire et son redessin
     */
    void update();
    /**
     * @brief Efface le contenu du label, le polygone et le label de preview si celui ci est present
     */
    void clear();

private:
    /**
     * @brief Vector de sommets du polygone
     */
    QVector<QPoint> mPoints;
    /**
     * @brief Polygone à afficher
     */
    QPolygon mPolygon;
    /**
     * @brief Qpoint representant la position de la sourie au moment du click gauche
     */
    QPoint mClick;
    /**
     * @brief Qpoint representant la position de la sourie au moment du relachement du boutton gauche
     */
    QPoint mLastClickPos;
    /**
     * @brief Label de previsualisation
     */
    LabelDessinable* mPreviewLabel;
    /**
     * @brief Booleen representant l'etat de dessin
     */
    bool mDraw;
    /**
     * @brief Nombre de sommet du polygone
     */
    int mNbVertex;
    /**
     * @brief Dessine le polygone dans le label
     */
    void draw();
signals:
    void clicked();
public slots:
    /**
     * \brief traitement du signal de click souris sur le label
     * \a event évènement souris
     */
    void mousePressEvent (QMouseEvent * event);
    /**
     * @brief traitement du signal de mouvement de la sourie sur le label
     * @param event évènement souris
     */
    void mouseMoveEvent(QMouseEvent* event);
    /**
     * @brief traitement du signal de relachement de bouton de la sourie sur le label
     * @param event évènement souris
     */
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // LABELDESSINABLE_H
