/* This file is part of SIR, an open-source cross-platform Image tool
 * 2007-2010  Rafael Sachetto <rsachetto@gmail.com>
 * 2011-2012  Marek Jędryka   <jedryka89@gmail.com>
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

#ifndef CONVERTDIALOG_H
#define CONVERTDIALOG_H

#include "ui_convertdialog.h"
#include "convertthread.h"
#include "settings.h"

class PreviewDialog;
class QTranslator;
class NetworkUtils;
class MetadataDialog;

//! Main window class provides images convertion dialog.
class ConvertDialog : public QMainWindow, public Ui::ConvertDialog {
    Q_OBJECT
    friend class Selection;
    friend class SelectionDialog;

public:
    ConvertDialog(QWidget *parent = 0, QString args = 0);
    ~ConvertDialog();
    void retranslateStrings();

private:
    // fields
    QList<ConvertThread*> convertThreads;
    QString args;
    QStringList argsList;
    QImage *image;
    QString targetFile;
    QString fileFilters;
    QStringList rawFormats;
    QString lastDir;
    PreviewDialog  *previewForm;
    MetadataDialog *metadataForm;
    quint8 numThreads;
    QTranslator *qtTranslator;
    QTranslator *appTranslator;
    QMap<QString, int>  *statusList;
    int convertedImages;
    int numImages;
    QList<QTreeWidgetItem *> itemsToConvert;
    bool converting;
    bool rawEnabled;
    bool alreadySent;
    NetworkUtils *net;
    QPoint windowPossition;
    QSize windowSize;
    QAction *removeAction;
    QAction *convertAction;
    QAction *previewAction;
    QAction *metadataAction;
    QTreeWidgetItem *treeMenuItem;
    QString sizeWidthString;
    QString sizeHeightString;
    int exifAuthor;
    int exifCamera;
    int exifPhoto;
    int exifImage;
    int iptcPrint;
    QString dateFormat;
    QString timeFormat;
    QString dateTimeFormat;
    // methods
    void initList();
    void init();
    void createConnections();
    inline void connectSizeLinesEdit();
    inline void disconnectSizeLinesEdit();
    void createActions();
    void createRawFilesList();
    inline void writeWindowProperties();
    inline void resetAnswers();
    QStringList *makeList();
    QString makeImagePath(QTreeWidgetItem *item);
    void convert();

protected:
    virtual void changeEvent(QEvent *e);

public slots:
    void browseDestination();
    void convertAll();
    void convertSelected();
    void addDir();
    void addFile();
    void loadFiles(const QStringList &files);
    void loadFiles(const QList<QFileInfo> &files);
    void enableConvertButtons(bool enable = true);
    void resizeColumnsToContents(myQTreeWidget *tree);
    void removeAll();
    void removeSelectedFromList();
    void showMenu( const QPoint & point);
    void previewAct();
    void showPreview(QTreeWidgetItem *item, int col);
    void showMetadata();
    void verifyRotate(int status);
    void about();
    void setOptions();
    void loadSettings();
    void updateTree();
    void setImageStatus(const QStringList& imageData, const QString& status, int statusNum);
    void query(const QString& targetFile, Question whatToDo);
    void giveNextImage(int tid);
    void setupThreads(int numThreads);
    void closeOrCancel();
    void updateInterface();
    void setCanceled();
    void stopConvertThreads();
    void checkUpdates();
    void showUpdateResult(QString *result, bool error);
    void sendInstall();
    void showSendInstallResult(QString *result, bool error);
    void showDetails();
    void showSelectionDialog();

private slots:
    void setSizeUnit(int index);
    void sizeChanged(const QString &value);
};

/** Saves window maximized status, possition on screen and size and last
  * choosed directory by the user in settings file.\n
  * If window is maximized this function will save last possition and size
  * of normal size mode (before maximizing).
  */
void ConvertDialog::writeWindowProperties() {
    Settings &s = Settings::instance();
    if (this->isMaximized()) {
        s.mainWindow.maximized      = true;
        s.mainWindow.possition      = windowPossition;
        s.mainWindow.size           = windowSize;
    }
    else {
        s.mainWindow.maximized      = false;
        s.mainWindow.possition      = this->pos();
        s.mainWindow.size           = this->size();
    }
    s.mainWindow.horizontalSplitter = horizontalSplitter->saveState();
    s.mainWindow.verticalSplitter   = verticalSplitter->saveState();
    s.settings.lastDir = lastDir;
}

/** Resets user ansers about overwrite file, enlarge image and abort convertion
  * variables. This function is useful when convertion is starting for reset
  * user-anser data after last convertion.
  */
void ConvertDialog::resetAnswers() {
    ConvertThread::shared->overwriteResult = 1;
    ConvertThread::shared->overwriteAll = false;
    ConvertThread::shared->noOverwriteAll = false;
    ConvertThread::shared->abort = false;
    ConvertThread::shared->enlargeResult = 1;
    ConvertThread::shared->enlargeAll = false;
    ConvertThread::shared->noEnlargeAll = false;
}

/** Connects width and height lines edit's textChanged() signal to sizeChanged()
  * slot.
  * \sa disconnectSizeLinesEdit
  */
void ConvertDialog::connectSizeLinesEdit() {
    connect(widthLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(sizeChanged(QString)));
    connect(heightLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(sizeChanged(QString)));
}

/** Disconnects sizeChanged() slot.
  * \sa connectSizeLinesEdit
  */
void ConvertDialog::disconnectSizeLinesEdit() {
    widthLineEdit->disconnect(this,SLOT(sizeChanged(QString)));
    heightLineEdit->disconnect(this, SLOT(sizeChanged(QString)));
}

#endif // CONVERTDIALOG_H
