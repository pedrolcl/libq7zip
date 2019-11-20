/**************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <https://www.gnu.org/licenses/>.
**
**************************************************************************/

#include <q7z_create.h>
#include <q7z_extract.h>
#include <q7z_facade.h>
#include <q7z_list.h>

#include <QDir>
#include <QObject>
#include <QTemporaryFile>
#include <QTest>
#include <QDebug>

class TestQ7Zip : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        Q7z::initSevenZ();

        m_file.path = "q7z_facade.cpp";
        m_file.permissions = QFlags<QFileDevice::Permission>(0x644);
        m_file.compressedSize = 8379;
        m_file.uncompressedSize = 36736;
        m_file.isDirectory = false;
        m_file.archiveIndex = QPoint(0, 0);
        m_file.utcTime = QDateTime::fromString("2019-11-18T16:47:15Z", Qt::ISODate);
    }

    void testIsSupportedArchive()
    {
        QCOMPARE(Q7z::isSupportedArchive(":///testdata.7z"), true);

        try {
            QFile file(":///testdata.7z");
            QVERIFY(file.open(QIODevice::ReadOnly));
            QCOMPARE(Q7z::isSupportedArchive(&file), true);
        } catch (...) {
            QFAIL("Unexpected error during Q7z::isSupportedArchive.");
        }
    }

    void testListArchive()
    {
        try {
            QFile file(":///testdata.7z");
            QVERIFY(file.open(QIODevice::ReadOnly));

            QVector<Q7z::File> files = Q7z::listArchive(&file);
            QCOMPARE(files.count(), 1);
            QCOMPARE(files.first(), m_file);
        } catch (...) {
            QFAIL("Unexpected error during list archive.");
        }
    }

    void testCreateArchive()
    {
        try {
            const QString path = tempSourceFile("Source File 1.");
            const QString path2 = tempSourceFile("Source File 2.");

            QTemporaryFile target;
            QVERIFY(target.open());
            Q7z::createArchive(&target, QStringList() << path << path2);
            QCOMPARE(Q7z::listArchive(&target).count(), 2);
        } catch (const Q7z::SevenZipException& e) {
            QFAIL(e.message().toUtf8());
        } catch (...) {
            QFAIL("Unexpected error during create archive.");
        }

        try {
            const QString path1 = tempSourceFile(
                "Source File 1.",
                QDir::tempPath() + "/temp file with spaces.XXXXXX"
            );
            const QString path2 = tempSourceFile(
                "Source File 2.",
                QDir::tempPath() + "/temp file with spaces.XXXXXX"
            );

            QTemporaryFile target(QDir::tempPath() + "/target file with spaces.XXXXXX");
            QVERIFY(target.open());
            Q7z::createArchive(&target, QStringList() << path1 << path2);
            QCOMPARE(Q7z::listArchive(&target).count(), 2);
        } catch (const Q7z::SevenZipException& e) {
            QFAIL(e.message().toUtf8());
        } catch (...) {
            QFAIL("Unexpected error during create archive.");
        }

    }

    void testExtractArchive()
    {
        QFile source(":///testdata.7z");
        QVERIFY(source.open(QIODevice::ReadOnly));

        try {
            Q7z::extractArchive(&source, QDir::tempPath());
            QCOMPARE(QFile::exists(QDir::tempPath() + QString("/q7z_facade.cpp")), true);
        } catch (const Q7z::SevenZipException& e) {
            QFAIL(e.message().toUtf8());
        } catch (...) {
            QFAIL("Unexpected error during extract archive.");
        }
    }

private:
    QString tempSourceFile(const QByteArray &data, const QString &templateName = QString())
    {
        QTemporaryFile source;
        if (!templateName.isEmpty()) {
            source.setFileTemplate(templateName);
        }
        source.open();
        source.write(data);
        source.setAutoRemove(false);
        return source.fileName();
    }

private:
    Q7z::File m_file;
};

QTEST_MAIN(TestQ7Zip)

#include "testq7z.moc"
