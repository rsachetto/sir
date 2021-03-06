/* This file is part of SIR, an open-source cross-platform Image tool
 * 2007-2010  Rafael Sachetto <rsachetto@gmail.com>
 * 2011-2014  Marek Jędryka   <jedryka89@gmail.com>
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
 * Program URL: http://marek629.github.io/sir/
 */

#include "posspinbox.h"

/** Creates the PosSpinBox object.
  * \param parent Parent widget.
  */
PosSpinBox::PosSpinBox(QWidget *parent) : QSpinBox(parent) {}

/** If \a text is \e % (percent mark) sets range of this spin box to [-100; 100].
  * Otherwise sets range to [-20000; 20000].
  */
void PosSpinBox::posUnitChanged(const QString &text) {
    if (text == "%")
        this->setRange(-100, 100);
    else
        this->setRange(-20000, 20000);
}
