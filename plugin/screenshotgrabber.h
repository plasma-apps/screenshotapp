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

#include <QObject>

class ScreenshotGrabber : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QString grabScreenshot() const;

};
