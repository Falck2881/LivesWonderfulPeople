#ifndef DATAAUTHOR_H
#define DATAAUTHOR_H

#include <QTextStream>
#include <QByteArray>
#include <QVector>
#include "Publisher.h"
#include "BufferData.h"

class ArchiveAuthor
{
    public:
        ArchiveAuthor();
        ArchiveAuthor(ArchiveAuthor&& dataAuthor);
        QString key();
        void addData(const BufferData& bufferData) ;
        QString countPrintedPagesAtAuthor();
        QVector<QString> allNamesPublishers();
        QVector<QString> allNamesEssay();
        QString countPrintedEssayInPublisher();
        QString countPrintedPagesInPublisher();
        QString bestPublisher();
        ArchiveAuthor& operator=(ArchiveAuthor&& dataAuthor);

    private:
        void setNameAuthor(const QString& fioAuthor);
        void addRecordAboutPublisher(const BufferData& bufferData);
        void addNewNamePublisher(const QString& newNamePublisher);
        void addNewEssay(const QString& newNameEssay);
        void addNewCountPrintedPages(const QString& newCountPrintedPages);
        void searchBestPublisher();
        uint64_t changeCountPrintedPages(const BufferData& bufferData);
        QVector<std::shared_ptr<Publisher>> listPublisher;
        QString fioAuthor;
        QVector<QString> nameAllPublisher;
        QVector<QString> allFinishedEssay;
        uint64_t countPrintedPages;
        std::shared_ptr<Publisher> publisher;
};

#endif // DATAAUTHOR_H
