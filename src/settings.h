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

#ifndef SETTINGS_H
#define SETTINGS_H

#ifndef SIR_CMAKE
#define SIR_METADATA_SUPPORT
#endif // SIR_CMAKE

#include <QSettings>
#include <QPoint>
#include <QSize>

typedef QMap<QString,QVariant>  HistoryMap;
typedef QList<QVariant>         HistoryList;

/** \brief Settings manipulation class implemented as singleton.
  *
  * All settings groups in settings file are represented by public structs with
  * \e Group suffix.
  *
  * Access to settings object is available by instance() method only because
  * this class is implemented using singleton design pattern.
  */
class Settings : public QSettings {
    Q_OBJECT

public:
    // singletons pattern instance
    static Settings *instance();
    // I/O operations
    void readSettings();
    void writeSettings();
    // fields
    struct MainWindowGroup {
        bool    maximized;
        QPoint  possition;
        QSize   size;
        QByteArray horizontalSplitter;
        QByteArray verticalSplitter;
    } mainWindow;
    struct SettingsGroup {
        bool alreadySent;
        QString targetFolder;
        QString targetFormat;
        QString targetPrefix;
        QString targetSuffix;
        QString languageNiceName;
        QString languageFileName;
        QString dateDisplayFormat;
        QString timeDisplayFormat;
        QString lastDir;
        int quality;
        int cores;
        int maxHistoryCount;
    } settings;
    struct SizeGroup {
        int     widthPx;
        float   widthPercent;
        int     heightPx;
        float   heightPercent;
        float   fileSizeValue;
        int     fileSizeUnit;
        int     sizeUnit;
        bool    keepAspectRatio;
    } size;
    struct TreeWidgetGroup {
        int columns;
    } treeWidget;
#ifdef SIR_METADATA_SUPPORT
    struct MetadataGroup {
        bool enabled;
        bool saveMetadata;
        bool realRotate;
        bool updateThumbnail;
        bool rotateThumbnail;
    } metadata;
    struct ExifGroup {
        HistoryMap  cameraManufacturerMap;
        HistoryList cameraManufacturerList;
        HistoryMap  cameraModelMap;
        HistoryList cameraModelList;
        bool artistOverwrite;
        HistoryMap  artistMap;
        HistoryList artistList;
        bool copyrightOverwrite;
        HistoryMap  copyrightMap;
        HistoryList copyrightList;
        bool userCommentOverwrite;
        HistoryMap  userCommentMap;
        HistoryList userCommentList;
    } exif;
    struct IPTCGroup {
        HistoryMap  editStatusMap;
        HistoryList editStatusList;
    } iptc;
    struct DetailsGroup {
        int exifImage;
        int exifPhoto;
        int exifCamera;
        int exifAuthor;
        int iptc;
    } details;
#endif // SIR_METADATA_SUPPORT
    struct SelectionGroup {
        bool subdirs;
        bool clearSelection;
        bool selectImported;
        QString fileSizeSymbol;
        QString imageWidthSymbol;
        QString imageHeightSymbol;
    } selection;
    struct SelectionDialogGroup {
        HistoryMap  fileNameMap;
        HistoryList fileNameList;
        HistoryMap  fileSizeMap;
        HistoryList fileSizeList;
        HistoryMap  imageSizeMap;
        HistoryList imageSizeList;
        HistoryMap  anyAuthorMap;
        HistoryList anyAuthorList;
        HistoryMap  anyCopyrightMap;
        HistoryList anyCopyrightList;
        HistoryMap  exifSoftMap;
        HistoryList exifSoftList;
        HistoryMap  exifCameraManufacturerMap;
        HistoryList exifCameraManufacturerList;
        HistoryMap  exifCameraModelMap;
        HistoryList exifCameraModelList;
        HistoryMap  iptcObjectNameMap;
        HistoryList iptcObjectNameList;
        HistoryMap  iptcKeywordsMap;
        HistoryList iptcKeywordsList;
        HistoryMap  iptcDescriptionMap;
        HistoryList iptcDescriptionList;
        HistoryMap  iptcCountryNameMap;
        HistoryList iptcCountryNameList;
        HistoryMap  iptcCityMap;
        HistoryList iptcCityList;
        HistoryMap  iptcEditStatusMap;
        HistoryList iptcEditStatusList;
    } selectionDialog;
    struct RawGroup {
        bool enabled;
        QString dcrawPath;
        QString dcrawOptions;
    } raw;

private:
    // constructors
    explicit Settings(QObject *parent = 0);
    explicit Settings(const QString &organization,
                      const QString &application = QString(), QObject *parent = 0);
    // destructor
    ~Settings();
    // methods
    void migrateFrom_2_1();
    void migrateFrom_2_2();
    void migrateFrom_2_3();
    void migrateFrom_2_4();
};

#endif // SETTINGS_H
