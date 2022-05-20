QT -= gui
QT += network
QT += core
QT+=sql

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cfactoryprotocol.cpp \
        cprotocol.cpp \
        database.cpp \
        iprotocol.cpp \
        main.cpp \
        protocoldeleteanswer.cpp \
        protocoldeletequestion.cpp \
        protocoldislikeanswer.cpp \
        protocoleditanswer.cpp \
        protocoleditquestion.cpp \
        protocollikeanswer.cpp \
        protocollogin.cpp \
        protocolprintanswers.cpp \
        protocolprintquestions.cpp \
        protocolregister.cpp \
        protocolsubmitanswer.cpp \
        protocolsubmitquestion.cpp \
        server.cpp \
        thread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ProtocolList.h \
    cfactoryprotocol.h \
    cprotocol.h \
    database.h \
    iprotocol.h \
    protocoldeleteanswer.h \
    protocoldeletequestion.h \
    protocoldislikeanswer.h \
    protocoleditanswer.h \
    protocoleditquestion.h \
    protocollikeanswer.h \
    protocollogin.h \
    protocolprintanswers.h \
    protocolprintquestions.h \
    protocolregister.h \
    protocolsubmitanswer.h \
    protocolsubmitquestion.h \
    server.h \
    thread.h
