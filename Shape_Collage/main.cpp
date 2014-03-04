#include "mainwindow.h"
#include <QApplication>
#include<QTranslator>
#include<QLibraryInfo>
int main(int argc, char *argv[])
{
    //traduction de l'application
    QApplication a(argc, argv);
    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&a);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        a.installTranslator(translator);
    //fin traduction

    MainWindow w;
    w.show();
    
    return a.exec();
}
