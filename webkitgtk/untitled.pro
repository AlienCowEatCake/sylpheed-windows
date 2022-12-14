TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

INCLUDEPATH += $${PWD}\webkitgtk-1.0
INCLUDEPATH += C:\msys64\ucrt64\include\glib-2.0
INCLUDEPATH += C:\msys64\ucrt64\lib\glib-2.0\include
INCLUDEPATH += C:\msys64\ucrt64\include\gtk-2.0
INCLUDEPATH += C:\msys64\ucrt64\include\cairo
INCLUDEPATH += C:\msys64\ucrt64\include\pango-1.0
INCLUDEPATH += C:\msys64\ucrt64\include\harfbuzz
INCLUDEPATH += C:\msys64\ucrt64\lib\gtk-2.0\include
INCLUDEPATH += C:\msys64\ucrt64\include\gdk-pixbuf-2.0
INCLUDEPATH += C:\msys64\ucrt64\include\atk-1.0
