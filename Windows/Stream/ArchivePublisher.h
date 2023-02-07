#ifndef ARCHIVEPUBLISHER_H
#define ARCHIVEPUBLISHER_H

#include "BufferData.h"
#include <QString>
#include <cstdint>

class ArchivePublisher
{
    public:
        ArchivePublisher();
        QString key();
        void addData(const BufferData &bufferData);
        QString countPrintedPagesInPublisher();
        QString countPrintedEssayInPublisher();

    private:
        void setNamePublisher(const QString& newNamePublisher);
        void changeCountPrintedPages(uint64_t newCountPrintedPages);
        void changeCountEssay();
        QString namePublisher;
        uint64_t countPrintedPages;
        uint64_t countEssays;
};

#endif // DATAPUBLISHER_H
