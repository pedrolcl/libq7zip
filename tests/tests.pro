CONFIG -= debug_and_release debug_and_release_target
TEMPLATE=app
TARGET=q7ztest
QT = core
QT += testlib
CONFIG += qt warn_on console depend_includepath testcase
DEFINES -= QT_NO_CAST_FROM_ASCII

include(../7zip/7zip.pri)
INCLUDEPATH += ../q7z
LIBS += -L../q7z -lq7z

RESOURCES += data.qrc
SOURCES = testq7z.cpp

