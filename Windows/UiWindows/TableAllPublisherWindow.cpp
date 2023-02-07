#include "TableAllPublisherWindow.h"
#include "ui_tableallpublisherwindow.h"
#include "../Stream/ArchivePublisher.h"
#include <QFile>
#include <QDebug>
#include <QHeaderView>
#include <QtXml/QDomNode>

TableAllPublisherWindow::TableAllPublisherWindow():currentRow(0),ui(new Ui::TableAllPublisherWindow)
{
    ui->setupUi(this);
    move(600,200);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    openArchiveForRead();
    readAllRecordsByPublishersFromFile();
    createTable();
    placeAllRecordsAboutPublishers();
}

void TableAllPublisherWindow::openArchiveForRead()
{
    QFile file;
    file.setFileName("Archive.xml");
    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
           document.setContent(&file);
           parentElement = document.documentElement();
        }
    }
    else{
        qDebug() << "WARNING! Puth to file - Windows/UiWindows/TableAllPublisherWindow.cpp "
                    "Name file is not exists. Check name file!";
    }
}

void TableAllPublisherWindow::readAllRecordsByPublishersFromFile()
{
    parentElement = parentElement.firstChildElement();
    while(!parentElement.isNull())
    {
        if(parentElement.isElement() && parentElement.tagName() == "RecordAuthor")
        {
            readAllRecordsByPublishersFromFile(parentElement);
            parentElement = parentElement.nextSiblingElement();
            addRecordsAboutPublisher(buffer);
        }
    }
}

void TableAllPublisherWindow::readAllRecordsByPublishersFromFile(QDomElement childElement)
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
            else if(childElement.tagName() == "YearPublisher")
                buffer.yearPublisher = childElement.text();
            else if(childElement.tagName() == "CountPage")
                buffer.countPages = childElement.text();
        }
        childElement = childElement.nextSiblingElement();
    }
}

void TableAllPublisherWindow::addRecordsAboutPublisher(const BufferData &buffer)
{
    ArchivePublisher archivePublisher;
    if(dataPublishers.size() == 0){
        archivePublisher.addData(buffer);
        dataPublishers.push_back(archivePublisher);
    }
    else{
        for(uint8_t i = 0; i < dataPublishers.size(); ++i)
        {
            if(buffer.namePublisher == dataPublishers[i].key()){
                dataPublishers[i].addData(buffer);
                break;
            }
            else if(i == (dataPublishers.size()-1))
            {
                archivePublisher.addData(buffer);
                dataPublishers.push_back(archivePublisher);
                break;
            }
        }
    }
}

void TableAllPublisherWindow::createTable()
{
    tableAllPublisher = std::make_unique<QTableWidget>(this);
    setMaxRowCount();
    setProperties();
}

void TableAllPublisherWindow::setMaxRowCount()
{
    tableAllPublisher->setRowCount(dataPublishers.size());
}

void TableAllPublisherWindow::setProperties()
{
    tableAllPublisher->setGeometry(QRect(10,50,511,300));
    tableAllPublisher->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableAllPublisher->setDropIndicatorShown(false);
    tableAllPublisher->setTabKeyNavigation(false);
    tableAllPublisher->setDragEnabled(false);
    tableAllPublisher->setDragDropOverwriteMode(false);
    tableAllPublisher->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    tableAllPublisher->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableAllPublisher->setDragDropMode(QAbstractItemView::NoDragDrop);
    tableAllPublisher->setDefaultDropAction(Qt::DropAction::IgnoreAction);
    tableAllPublisher->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
    tableAllPublisher->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
    tableAllPublisher->setGridStyle(Qt::PenStyle::SolidLine);
    tableAllPublisher->setSortingEnabled(false);
    tableAllPublisher->setCornerButtonEnabled(false);
    tableAllPublisher->setColumnCount(2);

    QList<QString> horizontalHeader{"Кол. Напечатанных Книг","Кол. Напечатанных Страниц"};
    tableAllPublisher->setHorizontalHeaderLabels(horizontalHeader);
    tableAllPublisher->horizontalHeader()->setStretchLastSection(true);
    tableAllPublisher->verticalHeader()->setStretchLastSection(true);
    tableAllPublisher->verticalHeader()->setStretchLastSection(true);
    tableAllPublisher->horizontalHeader()->setMaximumSectionSize(160);
    tableAllPublisher->horizontalHeader()->setMinimumSectionSize(160);
    tableAllPublisher->verticalHeader()->setMaximumSectionSize(50);
    tableAllPublisher->verticalHeader()->setMinimumSectionSize(10);
}

void TableAllPublisherWindow::placeAllRecordsAboutPublishers()
{
    while(currentRow != dataPublishers.size())
            placeDataAboutPublisherInColumn(dataPublishers.at(currentRow));
}

void TableAllPublisherWindow::placeDataAboutPublisherInColumn(ArchivePublisher dataPublisher)
{
    QList<QString> essayAndPages{dataPublisher.countPrintedEssayInPublisher(),
                                 dataPublisher.countPrintedPagesInPublisher()};

    for(uint8_t column = 0; column < tableAllPublisher->columnCount(); ++column){
        tableAllPublisher->setVerticalHeaderItem(currentRow, new QTableWidgetItem(dataPublisher.key()));
        tableAllPublisher->setItem(currentRow, column, new QTableWidgetItem(essayAndPages.at(column)));
    }

    currentRow+=1;
}

void TableAllPublisherWindow::updateWholeTable(const BufferData &buffer)
{
    addRecordsAboutPublisher(buffer);
    setMaxRowCount();
    placeAllRecordsAboutPublishers();
}
