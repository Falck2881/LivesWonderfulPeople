#ifndef LISTFOUNDDATA_H
#define LISTFOUNDDATA_H

#include "Stream/ArchiveAuthor.h"
#include <QTableWidget>

class ListTablesWithFoundData
{
    public:
        ListTablesWithFoundData();
        void insertInEnd(ArchiveAuthor*& data);
        QTableWidget* getDataInTable();
        ListTablesWithFoundData& operator=(ListTablesWithFoundData&& object);
    private:
        void insertInEnd(ArchiveAuthor*& data, ListTablesWithFoundData*& currentNode);
        void addFoundDataInVector();
        void addNameAuthor(const QString& nameAuthor);
        void addCountPrintedPagesAtAuthor(const QString& countPages);
        void addBestPublisher(const QString& bestPublisher);
        void addCountPrintedPagesInPublisher(const QString& countPages);
        void addCountPrintedEssayInPublisher(const QString& countEssay);
        QTableWidget* createTable();
        void placeArrayFoundDataInTable(QTableWidget*& table);
        void clearArrayFoundDataForFollowingData();
        ArchiveAuthor* foundData;
        ListTablesWithFoundData* nextNode;
        ListTablesWithFoundData* saveLastNode;
        QVector<QString> arrayFoundData;
};

#endif // LISTFOUNDDATA_H
