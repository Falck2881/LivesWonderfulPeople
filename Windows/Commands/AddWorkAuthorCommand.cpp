#include "AddWorkAuthorCommand.h"
#include "Warning.h"
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>
#include <QVector>
#include <QString>
#include <vector>

AddWorkAuthorCommand::AddWorkAuthorCommand
(QVector<QLineEdit*> arrayLineEdit, MainWindow* const mainWin):mainWin(mainWin),
                                                               arrLineEdit(arrayLineEdit)
{

}

bool AddWorkAuthorCommand::executeImplementationPart()
{
    bool value;
    try {
        addRecordsInXmlFile();
        mainWin->updateDataInApplication(std::move(buffer));
        value = true;
    }  catch (Warning* warning) {
        warning->show();
        value = false;
    }

    return value;
}

void AddWorkAuthorCommand::addRecordsInXmlFile()
{
    createChildRecords();
}

void AddWorkAuthorCommand::createChildRecords()
{
    QDomDocument domDoc;
    QFile file;
    openFileForAddRecording(file);
    domDoc.setContent(&file);
    QDomElement mainRootNode;
    mainRootNode = domDoc.documentElement();
    QDomElement parentForChildNode =  createElementsForParentNode(domDoc);
    mainRootNode.appendChild(parentForChildNode);
    saveRecordsInFile(file, parentForChildNode);
}

void AddWorkAuthorCommand::openFileForAddRecording(QFile& file)
{
    QString nameFile("Archive.xml");
    file.setFileName(nameFile);
    if(file.exists())
    {
        if(file.open(QIODevice::ReadWrite | QIODevice::Text))
            qDebug() << "File with name '" + nameFile + "' successfully opened!";
        else
            qDebug() << "File with name '" + nameFile + "' not open!";
    }
    else
        throw new Warning("Warning: File with this name'" + nameFile + "' not exists");
}

QDomElement AddWorkAuthorCommand::createElementsForParentNode(QDomDocument& domDoc)
{
    QVector<QString> userInputData{extractInputData()};
    QVector<QString> nameElements;
    nameElements << "Author" << "Title" << "Publisher" << "YearPublisher" << "CountPage";
    QDomElement parentNode = domDoc.createElement("RecordAuthor");
    QDomElement childNode;
    QTextCodec* codec{QTextCodec::codecForName("UTF-8")};
    for(uint8_t i = 0; i < userInputData.size(); ++i)
    {
        if(nameElements.at(i) == "Author")
           buffer.fioAuthor = userInputData.at(i);
        else if(nameElements.at(i) == "Title")
            buffer.titleEssays = userInputData.at(i);
        else if(nameElements.at(i) == "Publisher")
            buffer.namePublisher = userInputData.at(i);
        else if(nameElements.at(i) == "YearPublisher")
            buffer.yearPublisher = userInputData.at(i);
        else if(nameElements.at(i) == "CountPage")
            buffer.countPages = userInputData.at(i);

        childNode = domDoc.createElement(nameElements.at(i));
        childNode.appendChild(domDoc.createTextNode(codec->toUnicode(userInputData.at(i).toUtf8())));
        parentNode.appendChild(childNode);
    }
    return parentNode;
}

QVector<QString> AddWorkAuthorCommand::extractInputData()
{
    QVector<QString> data;

    foreach(auto lineEdit, arrLineEdit)
        data.push_back(lineEdit->text());

    return data;
}

void AddWorkAuthorCommand::saveRecordsInFile(QFile &file, QDomElement &parentForChildNode)
{
    QTextStream streamXml(&file);
    parentForChildNode.save(streamXml,4,QDomNode::EncodingFromTextStream);
    file.close();
}
