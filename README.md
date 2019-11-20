# libq7zip
7-zip library and buildsystems for Qt based applications.

This repository contains source code from the [7-zip](https://www.7-zip.org) and [p7zip](http://p7zip.sourceforge.net) projects and some classes from the [Qt Installer Framework](https://doc.qt.io/qtinstallerframework/index.html), with CMake and Qmake buildsystems allowing to build static and dynamic libraries for most operating systems and platforms.

This library allows easy and comfortable file and resource compress and uncompress using the 7z format in Qt applications. The following example snippets are taken from the library unit tests.

## compress files

    #include <q7z_create.h>
    #include <q7z_facade.h>

    [...]

    Q7z::initSevenZ();
    QTemporaryFile target;
    target.open();
    Q7z::createArchive(&target, QStringList() << path1 << path2);


## check compressed archive format
 
    #include <q7z_facade.h>

    [...]
    
    Q7z::initSevenZ();
    bool ok = Q7z::isSupportedArchive("data.7z")


## list compressed archive contents

    #include <q7z_facade.h>
    #include <q7z_list.h>

    [...]
    
    Q7z::initSevenZ();
    QFile file(":///testdata.7z"); // embedded resource
    file.open(QIODevice::ReadOnly);

    QVector<Q7z::File> files = Q7z::listArchive(&file);


## extract compressed files

    #include <q7z_extract.h>
    #include <q7z_facade.h>

    [...]

    Q7z::initSevenZ();
    QFile source(":///testdata.7z"); // embedded resource
    source.open(QIODevice::ReadOnly);
    Q7z::extractArchive(&source, QDir::tempPath());
