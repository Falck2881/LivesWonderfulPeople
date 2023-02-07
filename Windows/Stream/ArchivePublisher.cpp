#include "ArchivePublisher.h"

ArchivePublisher::ArchivePublisher():countPrintedPages(0),countEssays(0)
{
}

QString ArchivePublisher::countPrintedEssayInPublisher()
{
    return QString::number(countEssays);
}

QString ArchivePublisher::countPrintedPagesInPublisher()
{
    return QString::number(countPrintedPages);
}

QString ArchivePublisher::key()
{
    return namePublisher;
}

void ArchivePublisher::addData(const BufferData &bufferData)
{
    setNamePublisher(bufferData.namePublisher);
    changeCountPrintedPages(bufferData.countPages.toUInt());
    changeCountEssay();
}

void ArchivePublisher::setNamePublisher(const QString &newNamePublisher)
{
    if(namePublisher == "")
        namePublisher = std::move(newNamePublisher);
}

void ArchivePublisher::changeCountPrintedPages(uint64_t newCountPrintedPages)
{
    countPrintedPages+=newCountPrintedPages;
}

void ArchivePublisher::changeCountEssay()
{
    countEssays+=1;
}
