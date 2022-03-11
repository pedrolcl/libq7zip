CONFIG -= debug_and_release debug_and_release_target
QT = core

android:TARGET = 7z_$${QT_ARCH}
else:TARGET = 7z

TEMPLATE = lib
INCLUDEPATH += . ..
CONFIG += staticlib

include(7zip.pri)
win32:include($$7ZIP_BASE/win.pri) #7zip
unix:include($$7ZIP_BASE/unix.pri) #p7zip

target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target
