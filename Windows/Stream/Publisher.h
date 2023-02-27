#ifndef LISTPUBLISHER_H
#define LISTPUBLISHER_H

#include <cstdint>
#include <memory>
#include <QString>
#include "BufferData.h"

class Publisher
{
    public:
        Publisher();
        Publisher(const BufferData& buffer);
        QString name() const;
        void addData(const BufferData &bufferData);
        void setNamePublisher(const QString& newNamePublisher);
        uint64_t countPrintedPages() const;
        uint64_t countPrintedEssay() const;
        void changeCountPrintedPages(uint64_t newCountPrintedPages);
        void changeCountPrintedEssay();
   private:
        QString namePublisher;
        uint64_t countPrintedPagesInPublisher;
        uint64_t countPrintedEssayInPublisher;
};

#endif // LISTPUBLISHER_H
