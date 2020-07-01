TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        elements.cpp \
        main.cpp \
        platform.cpp \
        player.cpp

LIBS += -LF:/AIR-Studia/SFML-2.5.1/lib
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += F:/AIR-Studia/SFML-2.5.1/include
DEPENDPATH += F:/AIR-Studia/SFML-2.5.1/include

HEADERS += \
    elements.h \
    platform.h \
    player.h
