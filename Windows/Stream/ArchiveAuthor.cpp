#include "ArchiveAuthor.h"
#include <QDebug>

ArchiveAuthor::ArchiveAuthor():countPrintedPages(0)
{
}

QString ArchiveAuthor::countPrintedPagesAtAuthor()
{
    return QString::number(countPrintedPages);
}

QString ArchiveAuthor::countPrintedPagesInPublisher()
{
    return QString::number(publisher->countPrintedPages());
}

QString ArchiveAuthor::countPrintedEssayInPublisher()
{
    return QString::number(publisher->countPrintedEssay());
}

QString ArchiveAuthor::bestPublisher()
{
    return publisher->name();
}

QVector<QString> ArchiveAuthor::allNamesPublishers()
{
    return nameAllPublisher;
}

QVector<QString> ArchiveAuthor::allNamesEssay()
{
    return allFinishedEssay;
}

ArchiveAuthor::ArchiveAuthor(ArchiveAuthor&& dataAuthor)
{
    listPublisher = std::move(dataAuthor.listPublisher);
    fioAuthor = std::move(dataAuthor.fioAuthor);
    publisher = std::move(dataAuthor.publisher);
    countPrintedPages = dataAuthor.countPrintedPages;
}

QString ArchiveAuthor::key()
{
    return fioAuthor;
}

ArchiveAuthor& ArchiveAuthor::operator=(ArchiveAuthor&& dataAuthor)
{
    if(this == &dataAuthor)
        return *this;

    listPublisher = std::move(dataAuthor.listPublisher);
    fioAuthor = std::move(dataAuthor.fioAuthor);
    publisher = std::move(dataAuthor.publisher);
    countPrintedPages = dataAuthor.countPrintedPages;
    return *this;
}

void ArchiveAuthor::addData(const BufferData &bufferData)
{
    setNameAuthor(bufferData.fioAuthor);
    addRecordAboutPublisher(bufferData);
    addNewNamePublisher(bufferData.namePublisher);
    addNewEssay(bufferData.titleEssays);
    addNewCountPrintedPages(bufferData.countPages);

    searchBestPublisher();
}

void ArchiveAuthor::setNameAuthor(const QString& newFioAuthor)
{
    if(fioAuthor == "")
        fioAuthor = std::move(newFioAuthor);
}

void ArchiveAuthor::addRecordAboutPublisher(const BufferData& bufferData)
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

void ArchiveAuthor::addNewNamePublisher(const QString &newNamePublisher)
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

void ArchiveAuthor::addNewEssay(const QString& newNameEssay)
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

void ArchiveAuthor::addNewCountPrintedPages(const QString& newCountPrintedPages)
{
    countPrintedPages+= newCountPrintedPages.toUInt();
}

void ArchiveAuthor::searchBestPublisher()
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
