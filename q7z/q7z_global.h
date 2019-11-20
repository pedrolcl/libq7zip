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

#ifndef Q7Z_GLOBAL_H
#define Q7Z_GLOBAL_H

#include <QtCore/QtGlobal>

#ifndef QT_STATIC
#  ifdef BUILD_LIB_Q7Z
#    define Q7Z_EXPORT Q_DECL_EXPORT
#  else
#    define Q7Z_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q7Z_EXPORT
#endif

#endif //Q7Z_GLOBAL_H
