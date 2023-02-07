#ifndef XMLDOMREAD_H
#define XMLDOMREAD_H

#include <QFile>
#include <QtXml/QDomNode>
#include <QtXml/QDomElement>
#include <QString>
#include "BufferData.h"

class XmlDomRead
{
    public:
        XmlDomRead();
        ~XmlDomRead(){}
        bool isEndElement();
        void openForRead();
        BufferData readDataBlockFromFile(BufferData buffer);
    private:
        BufferData readDataBlockFromFile(BufferData buffer, QDomElement currentElement);
        QFile file;
        QDomDocument xmlDataAuthor;
        QDomElement currentElement;
};

#endif // XMLDOMREAD_H
