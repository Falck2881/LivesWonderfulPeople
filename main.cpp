#include "MainWindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void readStyleSheet(QApplication& app);
void writeAllRecordsInXmlFile();
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    readStyleSheet(app);
    writeAllRecordsInXmlFile();
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

void writeAllRecordsInXmlFile()
{
    QFile qrcfile(":/Data/Archive.xml");
    if(qrcfile.open(QIODevice::ReadOnly)){
        QFile newFile("Archive.xml");
        if(newFile.open(QIODevice::WriteOnly)){
            newFile.write(qrcfile.readAll());
            qrcfile.close();
            newFile.close();
        }
    }

}
