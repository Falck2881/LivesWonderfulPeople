#include "HistorySearch.h"
#include "ui_historysearch.h"

HistorySearch::HistorySearch(Tree* subject):
    subject(subject),
    listFoundData(std::make_unique<ListTablesWithFoundData>()),
    ui(new Ui::HistorySearch())
{
    ui->setupUi(this);
    move(300,200);
    setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    parentElement = std::make_unique<QTreeWidgetItem>(ui->treeWidget);
    parentElement->setText(0,"Авторы:");
    subject->append(this);
}

void HistorySearch::update(Author *archive)
{
    listFoundData->insertInEnd(archive);
    showFoundData(archive->key());
}


void HistorySearch::showFoundData(const QString& title)
{
    QTreeWidgetItem* newSearchData = new QTreeWidgetItem(parentElement.get());
    newSearchData->setText(0, title);
    ui->treeWidget->setItemWidget(newSearchData,1,listFoundData->getDataInTable());
    parentElement->setExpanded(true);
}

void HistorySearch::updateSubject(Tree *const updatedSubject)
{
    subject = updatedSubject;
    subject->append(this);
}
