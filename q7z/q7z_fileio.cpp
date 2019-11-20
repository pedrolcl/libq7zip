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

#include "q7z_fileio.h"

#include "q7z_errors.h"
#include "q7z_range.h"

#include <QCoreApplication>
#include <QByteArray>
#include <QDir>
#include <QFileDevice>
#include <QString>

qint64 Q7z::retrieveInt64(QFileDevice *in)
{
    qint64 n = 0;
    Q7z::blockingRead(in, reinterpret_cast<char*>(&n), sizeof(n));
    return n;
}

void Q7z::appendInt64(QFileDevice *out, qint64 n)
{
    Q7z::blockingWrite(out, reinterpret_cast<const char*>(&n), sizeof(n));
}

Range<qint64> Q7z::retrieveInt64Range(QFileDevice *in)
{
    const quint64 start = Q7z::retrieveInt64(in);
    const quint64 length = Q7z::retrieveInt64(in);
    return Range<qint64>::fromStartAndLength(start, length);
}

void Q7z::appendInt64Range(QFileDevice *out, const Range<qint64> &r)
{
    Q7z::appendInt64(out, r.start());
    Q7z::appendInt64(out, r.length());
}

QString Q7z::retrieveString(QFileDevice *in)
{
    return QString::fromUtf8(Q7z::retrieveByteArray(in));
}

void Q7z::appendString(QFileDevice *out, const QString &str)
{
    Q7z::appendByteArray(out, str.toUtf8());
}

QByteArray Q7z::retrieveByteArray(QFileDevice *in)
{
    QByteArray ba(Q7z::retrieveInt64(in), '\0');
    Q7z::blockingRead(in, ba.data(), ba.size());
    return ba;
}

void Q7z::appendByteArray(QFileDevice *out, const QByteArray &ba)
{
    Q7z::appendInt64(out, ba.size());
    Q7z::blockingWrite(out, ba.constData(), ba.size());
}

QByteArray Q7z::retrieveData(QFileDevice *in, qint64 size)
{
    QByteArray ba(size, '\0');
    Q7z::blockingRead(in, ba.data(), size);
    return ba;
}

void Q7z::appendData(QFileDevice *out, QFileDevice *in, qint64 size)
{
    Q_ASSERT(!in->isSequential());
    Q7z::blockingCopy(in, out, size);
}

void Q7z::openForRead(QFileDevice *dev)
{
    Q_ASSERT(dev);
    if (!dev->open(QIODevice::ReadOnly)) {
        throw Error(QCoreApplication::translate("Q7z",
            "Cannot open file \"%1\" for reading: %2").arg(
                        QDir::toNativeSeparators(dev->fileName()), dev->errorString()));
    }
}

void Q7z::openForWrite(QFileDevice *dev)
{
    Q_ASSERT(dev);
    if (!dev->open(QIODevice::WriteOnly)) {
        throw Error(QCoreApplication::translate("Q7z",
            "Cannot open file \"%1\" for writing: %2").arg(
                        QDir::toNativeSeparators(dev->fileName()), dev->errorString()));
    }
}

void Q7z::openForAppend(QFileDevice *dev)
{
    Q_ASSERT(dev);
    if (!dev->open(QIODevice::WriteOnly | QIODevice::Append)) {
        throw Error(QCoreApplication::translate("Q7z",
            "Cannot open file \"%1\" for writing: %2").arg(
                        QDir::toNativeSeparators(dev->fileName()), dev->errorString()));
    }
}

qint64 Q7z::blockingRead(QFileDevice *in, char *buffer, qint64 size)
{
    if (in->atEnd())
        return 0;
    qint64 left = size;
    while (left > 0) {
        const qint64 n = in->read(buffer, left);
        if (n < 0) {
            throw Error(QCoreApplication::translate("Q7z",
                "Read failed after %1 bytes: %2").arg(QString::number(size - left),
                in->errorString()));
        }
        left -= n;
        buffer += n;
    }
    return size;
}

qint64 Q7z::blockingCopy(QFileDevice *in, QFileDevice *out, qint64 size)
{
    static const qint64 blockSize = 4096;
    QByteArray ba(blockSize, '\0');
    qint64 actual = qMin(blockSize, size);
    while (actual > 0) {
        try {
            Q7z::blockingRead(in, ba.data(), actual);
            Q7z::blockingWrite(out, ba.constData(), actual);
            size -= actual;
            actual = qMin(blockSize, size);
        } catch (const Error &error) {
            throw Error(QCoreApplication::translate("Q7z", "Copy failed: %1")
                .arg(error.message()));
        }
    }
    return size;
}

qint64 Q7z::blockingWrite(QFileDevice *out, const QByteArray &data)
{
    return Q7z::blockingWrite(out, data.constData(), data.size());
}

qint64 Q7z::blockingWrite(QFileDevice *out, const char *data, qint64 size)
{
    qint64 left = size;
    while (left > 0) {
        const qint64 n = out->write(data, left);
        if (n < 0) {
            throw Error(QCoreApplication::translate("Q7z",
                "Write failed after %1 bytes: %2").arg(QString::number(size - left),
                out->errorString()));
        }
        left -= n;
    }
    return size;
}
