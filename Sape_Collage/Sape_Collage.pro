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
    forme.cpp \
    arriereplan.cpp \
    arriereplancolorie.cpp \
    arriereplantransparent.cpp \
    arriereplanphoto.cpp \
    formerectangle.cpp \
    formecercle.cpp \
    formeextra.cpp \
    dialogapropos.cpp \
    arriereplancolorie.cpp \
    grillephotos.cpp \
    convertisseur.cpp \
    windowslave.cpp \
    labelclicable.cpp \
    taille.cpp \
    donneesmetier.cpp \
    wizard.cpp \
    wizardinfos.cpp \
    wizardselectionphotos.cpp \
    wizardselectionforme.cpp \
    wizardselectionarriereplan.cpp \
    wizardselectiontaille.cpp \
    dialogdessinformeextra.cpp \
    exceptionattention.cpp \
    exceptionerreure.cpp \
    wizardcollage.cpp

HEADERS  += mainwindow.h \
    forme.h \
    arriereplan.h \
    arriereplancolorie.h \
    arriereplantransparent.h \
    arriereplanphoto.h \
    formerectangle.h \
    formecercle.h \
    formeextra.h \
    dialogapropos.h \
    grillephotos.h \
    convertisseur.h \
    windowslave.h \
    labelclicable.h \
    taille.h \
    donneesmetier.h \
    wizard.h \
    wizardinfos.h \
    wizardselectionphotos.h \
    wizardselectionforme.h \
    wizardselectionarriereplan.h \
    wizardselectiontaille.h \
    dialogdessinformeextra.h \
    exceptionattention.h \
    exceptionerreure.h \
    wizardcollage.h

FORMS    += mainwindow.ui \
    dialogapropos.ui \
    dialogdessinformeextra.ui

RESOURCES += \
    MesRessources.qrc
