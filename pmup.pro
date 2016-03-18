#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T19:30:05
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pmup
TEMPLATE = app

INCLUDEPATH += pmupIHM
INCLUDEPATH += pmupIHM/pmupCamaradePage/
INCLUDEPATH += pmupIHM/pmupMinePage/
INCLUDEPATH += pmupIHM/pmupNearbyPage/
INCLUDEPATH += pmupIHM/pmupFirstPage/
INCLUDEPATH += pissConnectionFactory


SOURCES +=  main.cpp\
            pmupIHM\pmupMainWindow.cpp \
            pmupIHM/pmupNearbyPage/pmupNearbyPage.cpp \
            pmupIHM/pmupCamaradePage/pmupCamaradePage.cpp \
            pmupIHM/pmupMinePage/pmupMinePage.cpp \
            pmupIHM/pmupFirstPage/pmupFirstPage.cpp \
            pmupIHM/pmupFirstPage/SearchingArea.cpp \
            pissConnectionFactory/CDatagramme.cpp \
            pissConnectionFactory/DatagrammeAnalyser.cpp \
            pissConnectionFactory/GlobalTime.cpp \
            pissConnectionFactory/InputQueue.cpp \
            pissConnectionFactory/ModuleIpConfig.cpp \
            pissConnectionFactory/OutputQueue.cpp \
            pissConnectionFactory/pissCommunicationStack.cpp \
            pissConnectionFactory/pissInputInformationDecoder.cpp \
            pissConnectionFactory/pissNetworkEnvironment.cpp \
            pissConnectionFactory/pissOutputInformationEncoder.cpp \
            pissConnectionFactory/pissReceptionTask.cpp \
            pissConnectionFactory/pissServer.cpp \
            pissConnectionFactory/pissTransmissionTask.cpp \
    pmupIHM/pmupFirstPage/pmupSubjectsPage.cpp


HEADERS  += pmupIHM\pmupMainWindow.h \
            pmupIHM/pmupNearbyPage/pmupNearbyPage.h \
            pmupIHM/pmupCamaradePage/pmupCamaradePage.h \
            pmupIHM/pmupMinePage/pmupMinePage.h \
            pmupIHM/pmupFirstPage/pmupFirstPage.h \
            pmupIHM/pmupFirstPage/SearchingArea.h \
            pissConnectionFactory/CDatagramme.h \
            pissConnectionFactory/DatagrammeAnalyser.h \
            pissConnectionFactory/GlobalTime.h \
            pissConnectionFactory/InputQueue.h \
            pissConnectionFactory/ModuleIpConfig.h \
            pissConnectionFactory/OutputQueue.h \
            pissConnectionFactory/pissCommunicationStack.h \
            pissConnectionFactory/pissInputInformationDecoder.h \
            pissConnectionFactory/pissNetworkEnvironment.h \
            pissConnectionFactory/pissOutputInformationEncoder.h \
            pissConnectionFactory/pissReceptionTask.h \
            pissConnectionFactory/pissServer.h \
            pissConnectionFactory/pissTransmissionTask.h \
    pmupIHM/pmupFirstPage/pmupSubjectsPage.h


RESOURCES += imageresources.qrc

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    pissConnectionFactory/.DS_Store

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

