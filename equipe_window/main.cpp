#include <QApplication>
#include "equipe_window.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    equipe_window w;
    w.show();
    return a.exec();
}
