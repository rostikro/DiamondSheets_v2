#include <QApplication>
#include <QSslSocket>

#include "DiamondSheets.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    DiamondSheets window;
    window.show();
    return QApplication::exec();
}
