#ifndef FORMECERCLE_H
#define FORMECERCLE_H
#include "forme.h"
class FormeCercle : public Forme
{
public:
    FormeCercle();
    FormeCercle(int r);
    int getRayon() const;
    void setRayon(int value);
    void Draw();

private:
    int rayon;
};

#endif // FORMECERCLE_H
