#include "XmlDomRead.h"
#include <QDebug>

XmlDomRead::XmlDomRead()
{
    Q_INIT_RESOURCE(Archive);
}

void XmlDomRead::openForRead()
{
    file.setFileName(":/NewDataRecords.xml");
    if(file.open(QIODevice::ReadOnly)){
       xmlDataAuthor.setContent(&file);
       currentElement = xmlDataAuthor.documentElement();
    }
    else{
        qDebug() << "WARNING! Puth to file - Stream/XmlDomRead.cpp. "
                    "Name file is not exists. Check name file!";
    }
}

bool XmlDomRead::isEndElement()
{
    return !currentElement.isNull()?true:false;
}

BufferData XmlDomRead::readDataBlockFromFile(BufferData buffer)
{
    currentElement = currentElement.firstChildElement();
    while(!currentElement.isNull())
    {
        if(currentElement.isElement() && currentElement.tagName() != "RecordAuthor")
        {
            if(currentElement.tagName() == "Author")
                buffer.fioAuthor = currentElement.text();
            else if(currentElement.tagName() == "Title")
                buffer.titleEssays = currentElement.text();
            else if(currentElement.tagName() == "Publisher")
                buffer.namePublisher = currentElement.text();
            else if(currentElement.tagName() == "YearPublisher")
                buffer.yearPublisher = currentElement.text();
            else if(currentElement.tagName() == "CountPage")
                buffer.countPages = currentElement.text();
        }
        buffer = readDataBlockFromFile(buffer, currentElement);
        currentElement = currentElement.nextSiblingElement();
    }
    return buffer;
}

BufferData XmlDomRead::readDataBlockFromFile(BufferData buffer, QDomElement childElement)
{
    childElement = childElement.firstChildElement();
    while(!childElement.isNull())
    {
        if(childElement.isElement() && childElement.tagName() != "RecordAuthor")
        {
            if(childElement.tagName() == "Author")
                buffer.fioAuthor = childElement.text();
            else if(childElement.tagName() == "Title")
                buffer.titleEssays = childElement.text();
            else if(childElement.tagName() == "Publisher")
                buffer.namePublisher = childElement.text();
            else if(currentElement.tagName() == "YearPublisher")
                buffer.yearPublisher = currentElement.text();
            else if(childElement.tagName() == "CountPage")
                buffer.countPages = childElement.text();
        }
        childElement = childElement.nextSiblingElement();
    }
    return buffer;
}
