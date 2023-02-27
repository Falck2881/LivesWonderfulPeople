#include "Author.h"
#include <QDebug>

Author::Author():countPrintedPages(0)
{
}

QString Author::countPrintedPagesAtAuthor()
{
    return QString::number(countPrintedPages);
}

QString Author::countPrintedPagesInPublisher()
{
    return QString::number(publisher->countPrintedPages());
}

QString Author::countPrintedEssayInPublisher()
{
    return QString::number(publisher->countPrintedEssay());
}

QString Author::bestPublisher()
{
    return publisher->name();
}

QVector<QString> Author::allNamesPublishers()
{
    return nameAllPublisher;
}

QVector<QString> Author::allNamesEssay()
{
    return allFinishedEssay;
}

Author::Author(Author&& dataAuthor)
{
    listPublisher = std::move(dataAuthor.listPublisher);
    fioAuthor = std::move(dataAuthor.fioAuthor);
    publisher = std::move(dataAuthor.publisher);
    countPrintedPages = dataAuthor.countPrintedPages;
}

QString Author::key()
{
    return fioAuthor;
}

Author& Author::operator=(Author&& dataAuthor)
{
    if(this == &dataAuthor)
        return *this;

    listPublisher = std::move(dataAuthor.listPublisher);
    fioAuthor = std::move(dataAuthor.fioAuthor);
    publisher = std::move(dataAuthor.publisher);
    countPrintedPages = dataAuthor.countPrintedPages;
    return *this;
}

void Author::addData(const BufferData &bufferData)
{
    setNameAuthor(bufferData.fioAuthor);
    addRecordAboutPublisher(bufferData);
    addNewNamePublisher(bufferData.namePublisher);
    addNewEssay(bufferData.titleEssays);
    addNewCountPrintedPages(bufferData.countPages);

    searchBestPublisher();
}

void Author::setNameAuthor(const QString& newFioAuthor)
{
    if(fioAuthor == "")
        fioAuthor = std::move(newFioAuthor);
}

void Author::addRecordAboutPublisher(const BufferData& bufferData)
{
     if(listPublisher.size() == 0)
         listPublisher.push_back(std::make_shared<Publisher>(bufferData));
     else{
         for(qint64 i = 0; i < listPublisher.size(); ++i)
         {
             if(listPublisher[i]->name() != bufferData.namePublisher && i == (listPublisher.size()-1)){
                 listPublisher.push_back(std::make_shared<Publisher>(bufferData));
                 break;
             }
             else if(listPublisher[i]->name() == bufferData.namePublisher){
                 listPublisher[i]->changeCountPrintedEssay();
                 listPublisher[i]->changeCountPrintedPages(bufferData.countPages.toUInt());
                 break;
             }
         }
     }
}

void Author::addNewNamePublisher(const QString &newNamePublisher)
{
    if(nameAllPublisher.size() == 0)
        nameAllPublisher.push_back(std::move(newNamePublisher));
    else{
        for(qint64 index = 0; index < nameAllPublisher.size(); ++index)
            if(nameAllPublisher.at(index) != newNamePublisher && index == (nameAllPublisher.size()-1)){
                nameAllPublisher.push_back(std::move(newNamePublisher));
                break;
            }
            else if(nameAllPublisher.at(index) == newNamePublisher)
                break;
    }
}

void Author::addNewEssay(const QString& newNameEssay)
{
    if(allFinishedEssay.size() == 0)
        allFinishedEssay.push_back(newNameEssay);
    else{
        for(qint64 index = 0; index < allFinishedEssay.size(); ++index)
            if(allFinishedEssay.at(index) != newNameEssay && index == (allFinishedEssay.size()-1)){
                allFinishedEssay.push_back(newNameEssay);
                break;
            }
            else if(allFinishedEssay.at(index) == newNameEssay)
                break;
    }
}

void Author::addNewCountPrintedPages(const QString& newCountPrintedPages)
{
    countPrintedPages+= newCountPrintedPages.toUInt();
}

void Author::searchBestPublisher()
{
    if(publisher == nullptr){
        publisher = std::make_shared<Publisher>();
        publisher = listPublisher.first();
    }
    else{
        for(uint8_t i = 0; i < listPublisher.size(); ++i){
            for(uint8_t j = 0; j < listPublisher.size(); ++j)
                if(listPublisher[i]->countPrintedEssay() > publisher->countPrintedEssay()){
                    publisher = listPublisher.at(i);
                    break;
                }
        }
    }
}
