/* QupZillKa (2021-2025) https://github.com/dualword/QupZillKa License:GNU GPL v3*/
/* ============================================================
* QupZilla - Qt web browser
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
#include "adblockaddsubscriptiondialog.h"
#include "ui_adblockaddsubscriptiondialog.h"
#include "adblockmanager.h"

AdBlockAddSubscriptionDialog::AdBlockAddSubscriptionDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AdBlockAddSubscriptionDialog)
{
    ui->setupUi(this);

    m_knownSubscriptions << Subscription("EasyList (English)", ADBLOCK_EASYLIST_URL)
                         << Subscription("EasyPrivacy (English)", "https://easylist-downloads.adblockplus.org/easyprivacy.txt")
                         << Subscription("RU Adlist (Russian)", "https://easylist-downloads.adblockplus.org/advblock.txt")
                         << Subscription("Easylist China (Chinese)", "https://easylist-downloads.adblockplus.org/easylistchina.txt")
                         << Subscription(tr("Other..."), QString());

    foreach (const Subscription &subscription, m_knownSubscriptions) {
        ui->comboBox->addItem(subscription.title);
    }

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(indexChanged(int)));
    indexChanged(0);
}

QString AdBlockAddSubscriptionDialog::title() const
{
    return ui->title->text();
}

QString AdBlockAddSubscriptionDialog::url() const
{
    return ui->url->text();
}

void AdBlockAddSubscriptionDialog::indexChanged(int index)
{
    const Subscription subscription = m_knownSubscriptions.at(index);

    // "Other..." entry
    if (subscription.url.isEmpty()) {
        ui->title->clear();
        ui->url->clear();
    }
    else {
        int pos = subscription.title.indexOf(QLatin1Char('('));
        QString title = subscription.title;

        if (pos > 0) {
            title = title.left(pos).trimmed();
        }

        ui->title->setText(title);
        ui->title->setCursorPosition(0);

        ui->url->setText(subscription.url);
        ui->url->setCursorPosition(0);
    }
}

AdBlockAddSubscriptionDialog::~AdBlockAddSubscriptionDialog()
{
    delete ui;
}
