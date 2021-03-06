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

#ifndef _MAIN_H_
#define _MAIN_H_

#include <QApplication>
#include <QString>
#include <QLocale>
#include "widgets/convertdialog.h"

#if QT_VERSION >= 0x050000
bool findIconTheme();
#endif // QT_VERSION

#endif // _MAIN_H_

/** \mainpage
  * SIR (Simple Image Resizer) is a tool created for batch parallel resizing,
  * rotate and converting images with metadata support.
  *
  * This is free software distributed under
  * [GNU GPL v2](http://www.gnu.org/licenses/old-licenses/gpl-2.0.html) license.
  * Read LICENSE file for details.
  *
  * Read/write supported image formats:
  *   * BMP  - Windows Bitmap
  *   * JPEG - Joint Photographic Experts Group
  *   * PNG  - Portable Network Graphics
  *   * PPM  - Portable Pixmap
  *   * TIFF - Tagged Image File Format
  *   * XBM  - X11 Bitmap
  *   * XPM  - X11 Pixmap
  *
  * Read only supported image formats:
  *   * GIF  - Graphic Interchange Format (optional)
  *   * MNG  - Multiple-image Network Graphics
  *   * PBM  - Portable Bitmap
  *   * PGM  - Portable Graymap
  *   * SVG  - Scalable Vector Graphics
  *   * TGA  - Targa Image Format
  *
  * Supported metadata standards using exiv2:
  *   * Exif (edition supported)
  *   * IPTC (edition supported)
  *   * XMP
  *
  * Dependences:
  *   * [Qt 4.6+](http://qt-project.org/)
  *
  * Optional dependences:
  *   * [libexiv2](http://exiv2.org/)
  *   * [dcraw](http://www.cybercom.net/~dcoffin/dcraw/)
  *
  * SIR documentation was created using Doxygen.
  */
