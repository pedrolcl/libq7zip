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

#ifndef FILEIO_H
#define FILEIO_H

#include "q7z_global.h"

QT_BEGIN_NAMESPACE
class QByteArray;
class QFileDevice;
class QString;
QT_END_NAMESPACE

template <typename T>
class Range;

namespace Q7z {

qint64 Q7Z_EXPORT retrieveInt64(QFileDevice *in);
void Q7Z_EXPORT appendInt64(QFileDevice *out, qint64 n);

Range<qint64> Q7Z_EXPORT retrieveInt64Range(QFileDevice *in);
void Q7Z_EXPORT appendInt64Range(QFileDevice *out, const Range<qint64> &r);

QString Q7Z_EXPORT retrieveString(QFileDevice *in);
void Q7Z_EXPORT appendString(QFileDevice *out, const QString &str);

QByteArray Q7Z_EXPORT retrieveByteArray(QFileDevice *in);
void Q7Z_EXPORT appendByteArray(QFileDevice *out, const QByteArray &ba);

QByteArray Q7Z_EXPORT retrieveData(QFileDevice *in, qint64 size);
void Q7Z_EXPORT appendData(QFileDevice *out, QFileDevice *in, qint64 size);

void Q7Z_EXPORT openForRead(QFileDevice *dev);
void Q7Z_EXPORT openForWrite(QFileDevice *dev);
void Q7Z_EXPORT openForAppend(QFileDevice *dev);

qint64 Q7Z_EXPORT blockingRead(QFileDevice *in, char *buffer, qint64 size);
qint64 Q7Z_EXPORT blockingCopy(QFileDevice *in, QFileDevice *out, qint64 size);

qint64 Q7Z_EXPORT blockingWrite(QFileDevice *out, const QByteArray &data);
qint64 Q7Z_EXPORT blockingWrite(QFileDevice *out, const char *data, qint64 size);

} // namespace Q7z

#endif // FILEIO_H
