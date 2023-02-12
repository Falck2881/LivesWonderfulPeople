#include "Publisher.h"

Publisher::Publisher():countPrintedPagesInPublisher(0),
                       countPrintedEssayInPublisher(0)
{

}

Publisher::Publisher(const BufferData& buffer):countPrintedPagesInPublisher(0),
                                               countPrintedEssayInPublisher(0)
{
    namePublisher = std::move(buffer.namePublisher);
    countPrintedPagesInPublisher = buffer.countPages.toUInt();
    countPrintedEssayInPublisher++;
}

void Publisher::addData(const BufferData &bufferData)
{
    setNamePublisher(bufferData.namePublisher);
    changeCountPrintedPages(bufferData.countPages.toUInt());
    changeCountPrintedEssay();
}

void Publisher::setNamePublisher(const QString &newNamePublisher)
{
    if(namePublisher == "")
        namePublisher = std::move(newNamePublisher);
}


void Publisher::changeCountPrintedEssay()
{
    countPrintedEssayInPublisher+=1;
}

void Publisher::changeCountPrintedPages(uint64_t newCountPrintedPages)
{
    countPrintedPagesInPublisher+= newCountPrintedPages;
}

QString Publisher::name() const
{
    return namePublisher;
}

uint64_t Publisher::countPrintedEssay() const
{
    return countPrintedEssayInPublisher;
}

uint64_t Publisher::countPrintedPages() const
{
    return countPrintedPagesInPublisher;
}
