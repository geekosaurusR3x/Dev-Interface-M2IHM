#ifndef ARRIEREPLANCOLORIE_H
#define ARRIEREPLANCOLORIE_H
#include"arriereplan.h"
#include<QColor>
class ArrierePlanColorie : public ArrierePlan
{
public:
    ArrierePlanColorie();
    ArrierePlanColorie(QColor coul);
    ~ArrierePlanColorie();
    QColor getCouleur() const;
    void setCouleur(QColor value);
    void Draw();

private:
    QColor couleur;
};

#endif // ARRIEREPLANCOLORIE_H
