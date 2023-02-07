#ifndef ESSAY_H
#define ESSAY_H

#include <QString>
#include "BufferData.h"

class Essay
{
    public:
        Essay(const BufferData& buffer);
        QString name() const;
        QString yearPrintage() const;
        QString countPage() const;
    private:
        QString _name;
        QString _yearPrintage;
        QString _countPage;
};

#endif // ESSAY_H
