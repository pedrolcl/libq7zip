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

#ifndef Q7Z_LIST_H
#define Q7Z_LIST_H

#include "q7z_global.h"

#include <QDateTime>
#include <QFile>
#include <QPoint>

namespace Q7z
{
    struct Q7Z_EXPORT File
    {
    public:
        QString path;
        QDateTime utcTime;
        QPoint archiveIndex;
        bool isDirectory = false;
        quint64 compressedSize = 0;
        quint64 uncompressedSize = 0;
        QFile::Permissions permissions = QFile::Permissions();
    };
    Q7Z_EXPORT bool operator==(const File &lhs, const File &rhs);

    QVector<File> Q7Z_EXPORT listArchive(QFileDevice *archive);

} // namespace Q7z

#endif // Q7Z_LIST_H
