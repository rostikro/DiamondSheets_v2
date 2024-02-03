//
// Created by Rostik on 1/10/2024.
//

#ifndef DIAMONDSHEETS_FILEMANAGER_H
#define DIAMONDSHEETS_FILEMANAGER_H

#include <QObject>
#include <QString>

class GoogleDriveApi;

class FileManager : public QObject {
    Q_OBJECT

public:
    FileManager(QObject *parent = nullptr);

    void newFile();

    void openFile();

    bool saveFile();

    void openGoogleDriveFile();

    void saveGoogleDriveFile();

    bool ensureFileSaved();

public Q_SLOTS:
    void setFileStateEdited();

    void openDownloadedFile(const QString &name, QString content);

    void showFilesList(const QStringList& fileNames, const QStringList& fileIds);

Q_SIGNALS:
    void setAppTitle(const QString &title);

    void setDefaultTableModel();

    void serialize(QTextStream& out);

    void deserialize(QTextStream& in);

private:
    GoogleDriveApi *googleDriveApi;

    // Files
    enum FileState
    {
        NONE,
        EDITED,
        SAVED
    };

    FileState localFileState;
    FileState googleDriveFileState;
    QString fileName; // shared
    QString localFilePath;
    QString googleDriveFileId;

    const QString appName = "Diamond Sheets";
};


#endif //DIAMONDSHEETS_FILEMANAGER_H
