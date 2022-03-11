CONFIG -= debug_and_release debug_and_release_target
TEMPLATE = lib
INCLUDEPATH += . ..

#CONFIG += staticlib

include(../7zip/7zip.pri)

DEFINES += BUILD_LIB_Q7Z

QT = core
win32:QT += winextras

HEADERS += \
    q7z_create.h \
    q7z_errors.h \
    q7z_extract.h \
    q7z_facade.h \
    q7z_fileio.h \
    q7z_global.h \
    q7z_guid.h \
    q7z_list.h \
    q7z_range.h

SOURCES += \
    q7z_facade.cpp \
    q7z_fileio.cpp

#android:message("android arch is $${QT_ARCH}")
android:LIBS += -L../7zip -l7z_$${QT_ARCH}
else:LIBS += -L../7zip -l7z

win32 {
    LIBS += -loleaut32 -luser32 -ladvapi32
    win32-g++*:LIBS += -lmpr -luuid
    win32-g++*:QMAKE_CXXFLAGS += -Wno-missing-field-initializers
}

macx {
    LIBS += -framework CoreFoundation
}
