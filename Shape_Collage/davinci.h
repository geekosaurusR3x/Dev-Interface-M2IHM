#ifndef DAVINCI_H
#define DAVINCI_H

#include <QObject>
#include <QLabel>
#include "parameters.h"
#include <QPainter>
#include <QPicture>
#include <QStringList>
#include <QFile>
#include <qmath.h>
#include <QBitmap>
#include <QProgressBar>
#include <ctime>
#include "windowslave.h"

/**
 * @brief L'original, le peintre par excellence. Cette classe réalise le collage selon les paramètres renseignés dans l'interface
 */
class DaVinci : public QObject
{
    Q_OBJECT
public:
    DaVinci(QObject *parent = 0);
    DaVinci(QLabel*&, QObject *parent = 0);
    DaVinci(const DaVinci&);
    /**
     * @brief Fontion de dessin
     * @return true si le collage a été généré sans erreur
     */
    bool draw(Parameters, QProgressBar*&);
    /**
     * @brief Fonction d'export d'image
     * @return true si l'enregistrement s'est bien passé
     */
    bool exportImage(QString);
    /**
     * @brief Fonction permettant de vérifier si un collage a déjà été généré
     * @return true si le collage a déjà été généré
     */
    bool getAlreadyGenerated() const;

private:
    /**
     * @brief Label sur lequel on dessine
     */
    QLabel *mCanvas;
    /**
     * @brief Si le collage a été généré
     */
    bool mAlreadyGenerated;
    /**
     * @brief Pixmap final, qui sera affiché dans le label et/ou enregistré lors de l'export
     */
    QPixmap* mFinalPixmap;
signals:

public slots:

};

#endif // DAVINCI_H
