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

#ifndef Q7Z_CREATE_H
#define Q7Z_CREATE_H

#include "q7z_global.h"

#include <Common/MyCom.h>
#include <7zip/UI/Common/Update.h>

#include <QStringList>

QT_BEGIN_NAMESPACE
class QFileDevice;
QT_END_NAMESPACE

namespace Q7z
{
    enum struct QTmpFile {
        No,
        Yes
    };

    enum struct Compression {
        Non = 0,
        Fastest = 1,
        Fast = 3,
        Normal = 5,
        Maximum = 7,
        Ultra = 9
    };

    class Q7Z_EXPORT UpdateCallback : public IUpdateCallbackUI2, public CMyUnknownImp
    {
        Q_DISABLE_COPY(UpdateCallback)

    public:
        UpdateCallback() = default;
        virtual ~UpdateCallback() {}

        MY_UNKNOWN_IMP
        INTERFACE_IUpdateCallbackUI2(;)
    };

    void Q7Z_EXPORT createArchive(QFileDevice *archive, const QStringList &sources,
        Compression level = Compression::Normal, UpdateCallback *callback = 0);
    void Q7Z_EXPORT createArchive(const QString &archive, const QStringList &sources,
        QTmpFile mode, Compression level = Compression::Normal, UpdateCallback *callback = 0);

} // namespace Q7z

#endif // Q7Z_CREATE_H
