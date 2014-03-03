#ifndef LABELCLICABLE_H
#define LABELCLICABLE_H
#include<QLabel>
#include<QColor>
class LabelClicable : public QLabel
{
    Q_OBJECT
    public:
    LabelClicable(bool acceptdrop, QWidget * parent = 0 );
    ~LabelClicable(){}
    void ChangeCouleur(QColor couleur);

signals:
    void clicked();
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent ( QMouseEvent * event ) ;

};
#endif // LABELCLICABLE_H
