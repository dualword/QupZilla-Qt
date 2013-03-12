/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2013  David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef PROFILEUPDATER_H
#define PROFILEUPDATER_H

#include <QString>

#include "qz_namespace.h"

class ProfileUpdater
{
public:
    explicit ProfileUpdater(const QString &profilePath);
    void checkProfile();

private:
    void updateProfile(const QString &current, const QString &profile);
    void copyDataToProfile();

    void update100();
    void update118();
    void update120();
    void update130();

    QString m_profilePath;
};

#endif // PROFILEUPDATER_H
