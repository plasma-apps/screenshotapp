/*
 * Copyright 2015 Bhushan Shah <bshah@kde.org>
 *
 * this library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * license as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * this library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * mERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * lesser General Public License for more details.
 *
 * you should have received a copy of the GNU Lesser General Public
 * license along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "screenshotgrabber.h"

#include <QUrl>
#include <QFile>
#include <QDateTime>
#include <QStandardPaths>

#include <QDBusReply>
#include <QDBusInterface>

#include <QDebug>

QString ScreenshotGrabber::grabScreenshot() const
{

    QString path = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/snapshot_" + QDateTime::currentDateTime().toString(QStringLiteral("yyyyMMddhhmmss") + ".png");

    QDBusInterface kwinInterface(QStringLiteral("org.kde.KWin"),
                                 QStringLiteral("/Screenshot"),
                                 QStringLiteral("org.kde.kwin.Screenshot"));
    QDBusReply<QString> reply = kwinInterface.call("screenshotFullscreen");

    if(QFile::copy(reply.value(), path))
    {
	return QUrl::fromLocalFile(path).url();
    }

    return QString();
}
