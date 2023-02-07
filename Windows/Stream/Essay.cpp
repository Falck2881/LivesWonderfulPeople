#include "Essay.h"

Essay::Essay(const BufferData& buffer)
{
    _name = std::move(buffer.fioAuthor);
    _yearPrintage = std::move(buffer.yearPublisher);
    _countPage = std::move(buffer.countPages);
}

QString Essay::name() const
{
    return _name;
}

QString Essay::yearPrintage() const
{
    return _yearPrintage;
}

QString Essay::countPage() const
{
    return _countPage;
}
