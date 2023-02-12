#ifndef ADDWORKAUTHORCOMMAND_H
#define ADDWORKAUTHORCOMMAND_H

#include "Stream/BufferData.h"
#include "UiWindows/MainWindow.h"
#include "WorkingWithDataLinker.h"
#include <QLineEdit>
#include <QVector>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

class AddWorkAuthorCommand: public WorkingWithDataLinker
{
    Q_OBJECT

    public:
        AddWorkAuthorCommand(QVector<QLineEdit*> arrayLineEdit, MainWindow* mainWin);

    private slots:
        virtual bool executeImplementationPart() final;
    private:
        void addRecord();
        void openFile(QIODevice::OpenMode mode, QFile& file);
        QDomElement createElements(QDomDocument& domDoc);
        QVector<QString> extractInputData();
        MainWindow*  mainWin;
        QVector<QLineEdit*> arrLineEdit;
        BufferData buffer;
};

#endif // ADDWORKAUTHORCOMMAND_H
