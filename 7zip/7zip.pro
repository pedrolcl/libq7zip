QT = core
TARGET = 7z
TEMPLATE = lib
INCLUDEPATH += . ..
CONFIG += staticlib

include(7zip.pri)
win32:include($$7ZIP_BASE/win.pri) #7zip
unix:include($$7ZIP_BASE/unix.pri) #p7zip

target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target
