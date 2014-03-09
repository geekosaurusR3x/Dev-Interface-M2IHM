#ifndef LABELCLICABLE_H
#define LABELCLICABLE_H
#include<QLabel>
#include<QColor>
/**
 * \brief Label repondant au click gauche souris et pouvant afficher une image
 */
class LabelClicable : public QLabel
{
    Q_OBJECT
    public:
    LabelClicable(bool acceptdrop, QWidget * parent = 0, QString text = "");
    ~LabelClicable(){}
    /**
     * \brief change la couleur de fond du label
     * \a couleur nouvelle couleur du label
     */
    void ChangeCouleur(QColor couleur);

signals:
    /**
     * \brief signal créer pour interactions diverses
     */
    void clicked();
    void clacked(QString filename);
protected:
    /**
     * \brief traitement du signal d'entré d'éléments sur le label via drag and drop
     * \a event évènement d'entrée
     */
    void dragEnterEvent(QDragEnterEvent *event);

    /**
     * \brief traitement du signal de mouvement d'éléments sur le label via drag and drop
     * \a event évènement de mouvement
     */
    void dragMoveEvent(QDragMoveEvent *event);

    /**
     * \brief traitement du signal de dépot d'éléments sur le label via drag and drop
     * \a event évènement de dépot
     */
    void dropEvent(QDropEvent *event);

    /**
     * \brief traitement du signal de click souris sur le label
     * \a event évènement souris
     */
    void mousePressEvent (QMouseEvent * event) ;

};
#endif // LABELCLICABLE_H
