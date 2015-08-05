/*
 * Copyright 2015 Bhushan Shah <bshah@kde.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

import QtQuick 2.0
import QtQuick.Layouts 1.1

import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents

import org.kde.mobile.private.screenshot 1.0 as Screenshot

Rectangle {

    id: appUi

    width: 1080
    height: 1920

    color: "white"

    Screenshot.ScreenshotGrabber {
        id: grabber
    }

    ColumnLayout {

        anchors.fill: parent
        anchors.margins: units.gridUnit

        //Rectangle {
        //    color: "grey"

	Image {
            id: img
	    source: ""
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignCenter
            Component.onCompleted: source = grabber.grabScreenshot();
        }

        PlasmaComponents.Button {
            Layout.fillWidth: true
            Layout.preferredHeight: units.gridUnit * 4
            Layout.alignment: Qt.AlignCenter
            text: "Take new screenshot"
            onClicked: img.source = grabber.grabScreenshot();
        }

    }
}
