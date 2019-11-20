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

#ifndef Q7Z_FACADE_H
#define Q7Z_FACADE_H

#include "q7z_global.h"
#include "q7z_errors.h"

#include <Common/MyWindows.h>
#include <7zip/UI/Console/PercentPrinter.h>

QT_BEGIN_NAMESPACE
class QFileDevice;
QT_END_NAMESPACE

namespace Q7z
{
    void Q7Z_EXPORT initSevenZ();
    bool Q7Z_EXPORT isSupportedArchive(QFileDevice *archive);
    bool Q7Z_EXPORT isSupportedArchive(const QString &archive);

    class Q7Z_EXPORT SevenZipException : public Q7z::Error
    {
    public:
        explicit SevenZipException(const QString &msg)
            : Q7z::Error(msg)
        {}

        explicit SevenZipException(const char *msg)
            : Q7z::Error(QString::fromLocal8Bit(msg))
        {}
    };

    class Q7Z_EXPORT PercentPrinter : public CPercentPrinter
    {
    public:
        PercentPrinter() : CPercentPrinter(1 << 16) {
            OutStream = &g_StdOut;
        }

        void PrintRatio() { CPercentPrinter::PrintRatio(); }
        void ClosePrint() { CPercentPrinter::ClosePrint(); }
        void RePrintRatio() { CPercentPrinter::RePrintRatio(); }
        void PrintNewLine() { CPercentPrinter::PrintNewLine(); }
        void PrintString(const char *s) { CPercentPrinter::PrintString(s); }
        void PrintString(const wchar_t *s) { CPercentPrinter::PrintString(s); }
    };

} // namespace Q7z

#endif // Q7Z_FACADE_H
