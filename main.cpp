#include "MainWindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void translation(QApplication& app);
void readStyleSheet(QApplication& app);
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    readStyleSheet(app);

    MainWindow w;
    w.open();
    return app.exec();
}

void readStyleSheet(QApplication& app)
{
    QFile file;
    file.setFileName(":/MyStyle/EasyCode.qss");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    app.setStyleSheet(stream.readAll());
    file.close();
}

