#include "ListTablesWithFoundData.h"
#include <QHeaderView>

ListTablesWithFoundData::ListTablesWithFoundData():foundData(nullptr),nextNode(nullptr),
                                                   saveLastNode(nullptr)
{

}

ListTablesWithFoundData& ListTablesWithFoundData::operator=(ListTablesWithFoundData &&object)
{
    if(this == &object)
        return *this;

    foundData = object.foundData;
    nextNode = object.nextNode;
    saveLastNode = object.saveLastNode;
    return *this;
}

void ListTablesWithFoundData::insertInEnd(ArchiveAuthor *&data)
{
    if(this->foundData == nullptr){
        this->foundData = data;
        addFoundDataInVector();
        saveLastNode = this;
    }
    else
        insertInEnd(data,this->saveLastNode->nextNode);
}

void ListTablesWithFoundData::insertInEnd(ArchiveAuthor *&data, ListTablesWithFoundData*& currentNode)
{
    if(currentNode == nullptr){
        currentNode = new ListTablesWithFoundData;
        foundData = data;
        addFoundDataInVector();
        saveLastNode = currentNode;
    }
}

void ListTablesWithFoundData::addFoundDataInVector()
{
    addNameAuthor(foundData->key());
    addCountPrintedPagesAtAuthor(foundData->countPrintedPagesAtAuthor());
    addBestPublisher(foundData->bestPublisher());
    addCountPrintedPagesInPublisher(foundData->countPrintedPagesInPublisher());
    addCountPrintedEssayInPublisher(foundData->countPrintedEssayInPublisher());
}

void ListTablesWithFoundData::addNameAuthor(const QString &nameAuthor)
{
    arrayFoundData.push_back(nameAuthor);
}


void ListTablesWithFoundData::addCountPrintedPagesAtAuthor(const QString &countPages)
{
    arrayFoundData.push_back(countPages);
}

void ListTablesWithFoundData::addBestPublisher(const QString &bestPublisher)
{
    arrayFoundData.push_back(bestPublisher);
}

void ListTablesWithFoundData::addCountPrintedPagesInPublisher(const QString &countPages)
{
    arrayFoundData.push_back(countPages);
}

void ListTablesWithFoundData::addCountPrintedEssayInPublisher(const QString &countEssay)
{
    arrayFoundData.push_back(countEssay);
}

QTableWidget* ListTablesWithFoundData::getDataInTable()
{
    QTableWidget* tableWgd = createTable();
    placeArrayFoundDataInTable(tableWgd);
    clearArrayFoundDataForFollowingData();

    return tableWgd;
}

QTableWidget* ListTablesWithFoundData::createTable()
{
    QTableWidget* tableWgd = new QTableWidget(new QWidget);
    tableWgd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWgd->setDropIndicatorShown(false);
    tableWgd->setTabKeyNavigation(false);
    tableWgd->setDragEnabled(false);
    tableWgd->setDragDropOverwriteMode(false);
    tableWgd->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableWgd->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tableWgd->setDragDropMode(QAbstractItemView::NoDragDrop);
    tableWgd->setDefaultDropAction(Qt::DropAction::IgnoreAction);
    tableWgd->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
    tableWgd->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
    tableWgd->setGridStyle(Qt::PenStyle::SolidLine);
    tableWgd->setSortingEnabled(false);
    tableWgd->setCornerButtonEnabled(false);
    tableWgd->setRowCount(5);
    tableWgd->setColumnCount(1);
    tableWgd->setHorizontalHeaderItem(0, new QTableWidgetItem(QString("Общая Информация")));

    QStringList listVerticalNames{"ФИО Автора","Колл. напечатннаых страниц", "<Любимое издательство>",
                                 "Колл. напечатанных страниц в Изд.", "Колл. напечатанных сочинений в Изд."};
    tableWgd->setVerticalHeaderLabels(listVerticalNames);
    tableWgd->horizontalHeader()->setStretchLastSection(true);
    tableWgd->verticalHeader()->setStretchLastSection(true);
    return tableWgd;
}

void ListTablesWithFoundData::placeArrayFoundDataInTable(QTableWidget*& table)
{
    for(uint8_t currentRow = 0; currentRow != table->rowCount(); ++currentRow)
        table->setItem(currentRow, 0, new QTableWidgetItem(arrayFoundData.at(currentRow)));
}

void ListTablesWithFoundData::clearArrayFoundDataForFollowingData()
{
    while(!arrayFoundData.empty())
        arrayFoundData.pop_back();
}
