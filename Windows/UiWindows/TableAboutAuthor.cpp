#include "TableAboutAuthor.h"
#include <QTableWidgetItem>

TableAboutAuthor::TableAboutAuthor(QTableWidget* uiTable, Tree* subject):table(uiTable),subject(subject)
{
    subject->append(this);
}

void TableAboutAuthor::update(Author *archive)
{
    addArchiveInVector(archive);
    showSearchData();
    clearArrayFoundDataForFollowingData();
}

void TableAboutAuthor::addArchiveInVector(Author *&archive)
{
    addNameAuthor(archive->key());
    addAllNamesPublishers(archive->allNamesPublishers());
    addAllTitleEssay(archive->allNamesEssay());
    addCountPrintedPagesAtAuthor(archive->countPrintedPagesAtAuthor());
    addBestPublisher(archive->bestPublisher());
    addCountPrintedPagesInPublisher(archive->countPrintedPagesInPublisher());
    addCountPrintedEssayInPublisher(archive->countPrintedEssayInPublisher());
}

void TableAboutAuthor::addNameAuthor(const QString &nameAuthor)
{
    arrayFoundData.push_back(nameAuthor);
}

void TableAboutAuthor::addAllNamesPublishers(QVector<QString> allNamesPublisher)
{
    QString namesAllPublishers;

    foreach(auto& namePublisher, allNamesPublisher)
        namesAllPublishers+= namePublisher + "\n";
    arrayFoundData.push_back(namesAllPublishers);
}

void TableAboutAuthor::addAllTitleEssay(QVector<QString> allTitleEssay)
{
    QString allNamesTitle;

    foreach(auto& nameTitleEssay, allTitleEssay)
        allNamesTitle+= nameTitleEssay + "\n";
    arrayFoundData.push_back(allNamesTitle);
}

void TableAboutAuthor::addCountPrintedPagesAtAuthor(const QString &countPages)
{
    arrayFoundData.push_back(countPages);
}

void TableAboutAuthor::addBestPublisher(const QString &bestPublisher)
{
    arrayFoundData.push_back(bestPublisher);
}

void TableAboutAuthor::addCountPrintedPagesInPublisher(const QString &countPages)
{
    arrayFoundData.push_back(countPages);
}

void TableAboutAuthor::addCountPrintedEssayInPublisher(const QString &countEssay)
{
    arrayFoundData.push_back(countEssay);
}

void TableAboutAuthor::showSearchData()
{
    for(uint8_t currentRow = 0; currentRow != table->rowCount(); ++currentRow)
        table->setItem(currentRow, 0, new QTableWidgetItem(arrayFoundData.at(currentRow)));
}

void TableAboutAuthor::clearArrayFoundDataForFollowingData()
{
    while(!arrayFoundData.empty())
        arrayFoundData.pop_back();
}

void TableAboutAuthor::updateSubject(Tree *const updatedSubject)
{
    subject = updatedSubject;
    subject->append(this);
}
