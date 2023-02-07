#ifndef TABLEABOUTAUTHOR_H
#define TABLEABOUTAUTHOR_H

#include "Observers/Tree.h"
#include <QTableWidget>
#include <QVector>
#include <QString>

class TableAboutAuthor: public Tree
{
    public:
        TableAboutAuthor(QTableWidget* uiTable, Tree* subject);
        void updateSubject(Tree* const updatedSubject);

    private:
        virtual void update(ArchiveAuthor *archive) final;
        void addArchiveInVector(ArchiveAuthor*& archive);
        void addNameAuthor(const QString& nameAuthor);
        void addAllNamesPublishers(QVector<QString> allNamesPublisher);
        void addAllTitleEssay(QVector<QString> allTitleEssay);
        void addCountPrintedPagesAtAuthor(const QString& countPages);
        void addBestPublisher(const QString& bestPublisher);
        void addCountPrintedPagesInPublisher(const QString& countPages);
        void addCountPrintedEssayInPublisher(const QString& countEssay);
        void showSearchData();
        void clearArrayFoundDataForFollowingData();
        QTableWidget* table;
        Tree* subject;
        QVector<QString> arrayFoundData;
};

#endif // TABLEABOUTAUTHOR_H
