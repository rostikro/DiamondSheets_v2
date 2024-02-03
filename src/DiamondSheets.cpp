//
// Created by Rostik on 1/4/2024.
//

#include <QTableView>
#include <QMenuBar>
#include <QStatusBar>

#include <memory>
#include <QMessageBox>
#include <QCloseEvent>

#include "DiamondSheets.h"
#include "TableModel.h"
#include "FileManager.h"
#include "GoogleApi.h"

DiamondSheets::DiamondSheets(QWidget *parent)
    : QMainWindow(parent), tableModel(new TableModel(this)),
    fileManager(new FileManager()), googleApi(new GoogleApi())
{
    setWindowState(Qt::WindowMaximized);
    // UI setup
    tableView = new QTableView(this);
    tableView->setShowGrid(true);
    tableView->setModel(tableModel);
    tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    setCentralWidget(tableView);

    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // File menu setup
    fileMenu = menuBar->addMenu("File");

    newFile = new QAction("New file", fileMenu);
    newFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));

    openFile = new QAction("Open file", fileMenu);
    openFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));

    saveFile = new QAction("Save file", fileMenu);
    saveFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));

    fileMenu->addAction(newFile);
    fileMenu->addAction(openFile);
    fileMenu->addSeparator();
    fileMenu->addAction(saveFile);

    connect(newFile, &QAction::triggered, [&]()
    {
        tableView->clearFocus();
        fileManager->newFile();
    });
    connect(openFile, &QAction::triggered, fileManager, &FileManager::openFile);
    connect(saveFile, &QAction::triggered, fileManager, &FileManager::saveFile);

    // Google Drive menu setup
    googleDriveMenu = menuBar->addMenu("Google Drive");

    openGoogleDriveFile = new QAction("Open file", googleDriveMenu);
    saveGoogleDriveFile = new QAction("Save file", googleDriveMenu);
    authorizeToGoogle = new QAction(googleApi->IsAuthenticated() ? "Change account" : "Authorize", googleDriveMenu);

    googleDriveMenu->addAction(openGoogleDriveFile);
    googleDriveMenu->addAction(saveGoogleDriveFile);
    googleDriveMenu->addSeparator();
    googleDriveMenu->addAction(authorizeToGoogle);

    connect(openGoogleDriveFile, &QAction::triggered, fileManager, &FileManager::openGoogleDriveFile);
    connect(saveGoogleDriveFile, &QAction::triggered, fileManager, &FileManager::saveGoogleDriveFile);
    connect(authorizeToGoogle, &QAction::triggered, googleApi, &GoogleApi::authenticate);

    // Help menu setup
    helpMenu = menuBar->addMenu("Help");

    showAbout = new QAction("About", helpMenu);

    helpMenu->addAction(showAbout);

    connect(showAbout, &QAction::triggered, this, &DiamondSheets::showAboutDialog);

    statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    // Context menu setup
    ctxMenu = new QMenu(this);

    addRowAbove = new QAction("Add row above", ctxMenu);
    addRowBelow = new QAction("Add row below", ctxMenu);
    addColumnLeft = new QAction("Add column left", ctxMenu);
    addColumnRight = new QAction("Add column right", ctxMenu);
    deleteRow = new QAction("Delete row", ctxMenu);
    deleteColumn = new QAction("Delete column", ctxMenu);

    ctxMenu->addAction(addRowAbove);
    ctxMenu->addAction(addRowBelow);
    ctxMenu->addSeparator();
    ctxMenu->addAction(addColumnLeft);
    ctxMenu->addAction(addColumnRight);
    ctxMenu->addSeparator();
    ctxMenu->addAction(deleteRow);
    ctxMenu->addAction(deleteColumn);

    connect(tableView, &QTableView::customContextMenuRequested, this, &DiamondSheets::contextMenuRequested);
    connect(fileManager, &FileManager::setDefaultTableModel, tableModel, &TableModel::setDefaultModel);
    connect(fileManager, &FileManager::setAppTitle, this, &DiamondSheets::setWindowTitle);
    connect(tableModel, &TableModel::cellEdited, fileManager, &FileManager::setFileStateEdited);
    connect(fileManager, &FileManager::serialize, tableModel, &TableModel::serialize);
    connect(fileManager, &FileManager::deserialize, tableModel, &TableModel::deserialize);
    connect(googleApi, &GoogleApi::authenticated, [&]() { authorizeToGoogle->setText("Change account"); });

    connect(addRowAbove, &QAction::triggered, [&]() { tableModel->addRow(ctxMenuIndex); });
    connect(addRowBelow, &QAction::triggered, [&]() { tableModel->addRow(ctxMenuIndex, 1); });
    connect(addColumnLeft, &QAction::triggered, [&]() { tableModel->addColumn(ctxMenuIndex); });
    connect(addColumnRight, &QAction::triggered, [&]() { tableModel->addColumn(ctxMenuIndex, 1); });
    connect(deleteRow, &QAction::triggered, [&]() { tableModel->deleteRow(ctxMenuIndex); });
    connect(deleteColumn, &QAction::triggered, [&]() { tableModel->deleteColumn(ctxMenuIndex); });

    fileManager->newFile();
}

void DiamondSheets::closeEvent(QCloseEvent *event)
{
    if (fileManager->ensureFileSaved())
        event->accept();
    else
        event->ignore();
}

void DiamondSheets::showAboutDialog()
{
    QMessageBox::about(this, "About the app", "Diamond Sheets\nVersion 1.2\n©Diamond Company. All rights reserved.");
}

void DiamondSheets::contextMenuRequested(QPoint pos)
{
    ctxMenuIndex = tableView->indexAt(pos);
    ctxMenu->popup(tableView->viewport()->mapToGlobal(pos));
}
