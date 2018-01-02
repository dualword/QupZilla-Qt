/* ============================================================
* QupZilla - Qt web browser
* Copyright (C) 2010-2014 Franz Fellner <alpine.art.de@googlemail.com>
* Copyright (C) 2010-2018 David Rosca <nowrep@gmail.com>
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
#include "restoremanager.h"
#include "recoveryjsobject.h"
#include "datapaths.h"

#include <QFile>

RestoreManager::RestoreManager(const QString &file)
    : m_recoveryObject(new RecoveryJsObject(this))
{
    createFromFile(file);
}

RestoreManager::~RestoreManager()
{
    delete m_recoveryObject;
}

RestoreData RestoreManager::restoreData() const
{
    return m_data;
}

bool RestoreManager::isValid() const
{
    return !m_data.isEmpty();
}

QObject *RestoreManager::recoveryObject(WebPage *page)
{
    m_recoveryObject->setPage(page);
    return m_recoveryObject;
}

void RestoreManager::createFromFile(const QString &file, RestoreData &data)
{
    if (!QFile::exists(file)) {
        return;
    }

    QFile recoveryFile(file);
    recoveryFile.open(QIODevice::ReadOnly);
    QDataStream stream(&recoveryFile);

    int version;
    stream >> version;

    if (version != Qz::sessionVersion && version != Qz::sessionVersionQt5) {
        return;
    }

    int windowCount;
    stream >> windowCount;
    data.reserve(windowCount);

    for (int i = 0; i < windowCount; ++i) {
        BrowserWindow::SavedWindow window;
        stream >> window;
        data.append(window);
    }
}

void RestoreManager::createFromFile(const QString &file)
{
    createFromFile(file, m_data);
}
