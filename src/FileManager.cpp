//
// Created by Rostik on 1/10/2024.
//

#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QListWidget>

#include "FileManager.h"
#include "GoogleDriveApi.h"

FileManager::FileManager(QObject *parent)
    : QObject(parent), googleDriveApi(new GoogleDriveApi(this))
{
    connect(googleDriveApi, &GoogleDriveApi::setGoogleDriveFileId, [&](const QString &id) { googleDriveFileId = id; });
    connect(googleDriveApi, &GoogleDriveApi::fileDownloaded, this, &FileManager::openDownloadedFile);
    connect(googleDriveApi, &GoogleDriveApi::filesListReceived, this, &FileManager::showFilesList);
}

void FileManager::newFile()
{
    if (!ensureFileSaved())
        return;

    localFileState = NONE;
    googleDriveFileState = NONE;
    fileName = "";
    localFilePath = "";
    googleDriveFileId = "";

    Q_EMIT setDefaultTableModel();
    Q_EMIT setAppTitle("Untitled - " + appName);
}

void FileManager::openFile()
{
    if (!ensureFileSaved())
        return;

    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open file", "/", "Spreadsheet files (*.csv)");

    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    QFileInfo fileInfo(file);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(nullptr, "Error", "An error occurred while opening the file: " + file.errorString());
        return;
    }

    QTextStream in(&file);
    Q_EMIT deserialize(in);
    file.close();

    localFileState = SAVED;
    googleDriveFileState = NONE;
    fileName = fileInfo.baseName();
    localFilePath = filePath;
    googleDriveFileId = "";

    Q_EMIT setAppTitle(fileName + " - " + appName);
}

bool FileManager::saveFile()
{
    if (localFileState == SAVED)
        return true;

    QString filePath = localFilePath;
    if (localFilePath.isEmpty())
    {
        filePath = QFileDialog::getSaveFileName(nullptr, "Save file", "/", "Spreadsheet files (*.csv)");

        if (filePath.isEmpty())
            return false;
    }

    QFile file(filePath);
    QFileInfo fileInfo(file);

    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(nullptr, "Error", "An error occurred while saving the file: " + file.errorString());
        return false;
    }

    QTextStream out(&file);
    Q_EMIT serialize(out);
    file.close();

    localFileState = SAVED;
    fileName = fileInfo.baseName();
    localFilePath = filePath;

    Q_EMIT setAppTitle(fileName + " - " + appName);

    return true;
}

bool FileManager::ensureFileSaved()
{
    // If file is not edited
    if (localFileState != EDITED)
        return true;

    QMessageBox saveFileDialog;
    saveFileDialog.setWindowTitle(appName);
    saveFileDialog.setText("Do you want to save file?");
    saveFileDialog.addButton("Yes", QMessageBox::YesRole);
    saveFileDialog.addButton("No", QMessageBox::NoRole);
    saveFileDialog.addButton("Cancel", QMessageBox::RejectRole);

    int response = saveFileDialog.exec();

    if (response == 2) // Cancel
        return false;

    if (response == 0) // Save the file
        return saveFile();

    return true; // Don't save the file
}

void FileManager::setFileStateEdited()
{
    if (localFileState == EDITED || (googleDriveFileState != NONE && googleDriveFileState != SAVED))
        return;

    localFileState = EDITED;
    if (googleDriveFileState != NONE)
        googleDriveFileState = EDITED;

    Q_EMIT setAppTitle("*" + (fileName.isEmpty() ? "Untitled" : fileName) + " - " + appName);
}

void FileManager::openGoogleDriveFile()
{
    if (!googleDriveApi->IsAuthenticated())
        return;

    googleDriveApi->getFiles();
}

void FileManager::showFilesList(const QStringList &fileNames, const QStringList &fileIds)
{
    QListWidget* listWidget = new QListWidget();
    listWidget->addItems(fileNames);
    connect(listWidget, &QListWidget::doubleClicked, [=](const QModelIndex& index)
    {
        googleDriveApi->openFile(fileIds[index.row()]);
        listWidget->close();
        listWidget->deleteLater();
    });

    listWidget->show();
}

void FileManager::openDownloadedFile(const QString &name, QString content)
{
    QTextStream in(&content);
    Q_EMIT deserialize(in);

    localFileState = NONE;
    googleDriveFileState = SAVED;

    fileName = name;

    Q_EMIT setAppTitle(fileName + " - " + appName);
}

void FileManager::saveGoogleDriveFile()
{
    if (!googleDriveApi->IsAuthenticated())
        return;

    if (googleDriveFileState == SAVED)
        return;

    if (fileName.isEmpty())
    {
        QString name = QInputDialog::getText(nullptr, "Diamond Sheets", "Enter file name");
        if (name.isEmpty())
            return;

        fileName = name;
    }

    QString buff;
    QTextStream out(&buff);
    Q_EMIT serialize(out);

    if (googleDriveFileId.isEmpty())
        googleDriveApi->uploadFile(fileName, buff);
    else
        googleDriveApi->updateFile(googleDriveFileId, fileName, buff);

    googleDriveFileState = SAVED;

    Q_EMIT setAppTitle(fileName + " - " + appName);
}
