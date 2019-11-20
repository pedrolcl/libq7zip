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

#ifndef ERRORS_H
#define ERRORS_H

#include <QtCore/QDebug>
#include <QtCore/QString>

#include <stdexcept>

namespace Q7z {

class Error : public std::exception
{
public:
    Error()
    {}

    explicit Error(const QString &message)
        : m_message(message)
    {}

    virtual ~Error() throw()
    {}

    QString message() const { return m_message; }

private:
    QString m_message;
};

}

#endif // ERRORS_H
