//
// Created by Rostik on 1/4/2024.
//

#ifndef DIAMONDSHEETS_DIAMONDSHEETS_H
#define DIAMONDSHEETS_DIAMONDSHEETS_H

#include <QtWidgets/QMainWindow>
#include <QModelIndex>

class QTableView;
class QMenuBar;
class QStatusBar;
class QMenu;
class QAction;

class FileManager;
class TableModel;
class GoogleApi;
class QCloseEvent;

class DiamondSheets : public QMainWindow {
    Q_OBJECT

public:
    DiamondSheets(QWidget *parent = nullptr);

    ~DiamondSheets() = default;

private:
    void closeEvent(QCloseEvent *event) override;

private Q_SLOTS:
    void showAboutDialog();

    void contextMenuRequested(QPoint pos);

private:
    FileManager *fileManager;
    TableModel *tableModel;
    GoogleApi *googleApi;

    // UI elements
    QTableView *tableView;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    // Menus
    QMenu *fileMenu;
    QMenu *googleDriveMenu;
    QMenu *helpMenu;

    // File menu actions
    QAction *newFile;
    QAction *openFile;
    QAction *saveFile;

    // Google Drive menu actions
    QAction *openGoogleDriveFile;
    QAction *saveGoogleDriveFile;
    QAction *authorizeToGoogle;

    // Help menu action
    QAction *showAbout;

    // Table context menu
    QModelIndex ctxMenuIndex;
    QMenu *ctxMenu;

    QAction *addRowAbove;
    QAction *addRowBelow;
    QAction *addColumnLeft;
    QAction *addColumnRight;
    QAction *deleteRow;
    QAction *deleteColumn;
};

#endif //DIAMONDSHEETS_DIAMONDSHEETS_H
