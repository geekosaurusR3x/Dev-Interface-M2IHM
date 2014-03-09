#-------------------------------------------------
#
# Project created by QtCreator 2013-10-28T13:30:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sape_Collage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogapropos.cpp \
    grillephotos.cpp \
    convertisseur.cpp \
    windowslave.cpp \
    labelclicable.cpp \
    wizard.cpp \
    wizardinfos.cpp \
    wizardselectionphotos.cpp \
    wizardselectionforme.cpp \
    wizardselectionarriereplan.cpp \
    wizardselectiontaille.cpp \
    dialogdessinformeextra.cpp \
    wizardcollage.cpp \
    parameters.cpp \
    davinci.cpp \
    labeldessinable.cpp \
    mathhelper.cpp

HEADERS  += mainwindow.h \
    dialogapropos.h \
    grillephotos.h \
    convertisseur.h \
    windowslave.h \
    labelclicable.h \
    wizard.h \
    wizardinfos.h \
    wizardselectionphotos.h \
    wizardselectionforme.h \
    wizardselectionarriereplan.h \
    wizardselectiontaille.h \
    dialogdessinformeextra.h \
    wizardcollage.h \
    parameters.h \
    davinci.h \
    labeldessinable.h \
    mathhelper.h

FORMS    += mainwindow.ui \
    dialogapropos.ui \
    dialogdessinformeextra.ui

RESOURCES += \
    MesRessources.qrc
