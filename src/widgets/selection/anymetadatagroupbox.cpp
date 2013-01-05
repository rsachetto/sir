/* This file is part of SIR, an open-source cross-platform Image tool
 * 2007-2010  Rafael Sachetto <rsachetto@gmail.com>
 * 2011-2013  Marek Jędryka   <jedryka89@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Program URL: http://sir.projet-libre.org/
 */

#include "anymetadatagroupbox.h"

/** Default constructor.\n
  * Sets UI and create connections.
  * \sa setupUi()
  */
AnyMetadataGroupBox::AnyMetadataGroupBox(QWidget *parent) : QGroupBox(parent) {
    // setup GUI
    setupUi(this);
    // disable widgets corresponding date and time edition
    QWidgetList widgetList;
    widgetList << createdTimeLabel1 << createdTimeLabel2
               << createdAfterDateTimeEdit << createdBeforeDateTimeEdit
               << digitizedTimeLabel1 << digitizedTimeLabel2
               << digitizedAfterDateTimeEdit << digitizedBeforeDateTimeEdit;
    foreach (QWidget *widget, widgetList)
        widget->setEnabled(false);
    // create connections
    connect(createdTimeCheckBox, SIGNAL(stateChanged(int)),
            SLOT(enableDateTimeEdits(int)));
    connect(digitizedTimeCheckBox, SIGNAL(stateChanged(int)),
            SLOT(enableDateTimeEdits(int)));
}

/** Enables or disables date time widgets depending on \a state value. */
void AnyMetadataGroupBox::enableDateTimeEdits(int state) {
    QWidgetList widgetList;
    QCheckBox *checkBox = (QCheckBox*)sender();
    if (checkBox == createdTimeCheckBox)
        widgetList << createdTimeLabel1 << createdTimeLabel2
                   << createdAfterDateTimeEdit << createdBeforeDateTimeEdit;
    else if (checkBox == digitizedTimeCheckBox)
        widgetList << digitizedTimeLabel1 << digitizedTimeLabel2
                   << digitizedAfterDateTimeEdit << digitizedBeforeDateTimeEdit;
    foreach (QWidget *widget, widgetList)
        widget->setEnabled(state);
}
