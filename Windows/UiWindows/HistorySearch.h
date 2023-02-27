#ifndef HISTORYSEARCH_H
#define HISTORYSEARCH_H

#include "ListTablesWithFoundData.h"
#include "Observers/Tree.h"
#include <QTableWidget>
#include <QTreeWidgetItem>
#include <QWidget>

namespace Ui {
class HistorySearch;
}

class HistorySearch : public QWidget, Tree
{
    Q_OBJECT

    public:
        explicit HistorySearch(Tree* subject);
        void updateSubject(Tree* const subject);

    private:
        virtual void update(Author *archive) final;
        void showFoundData(const QString& title);
        Tree* subject;
        std::unique_ptr<ListTablesWithFoundData> listFoundData;
        std::unique_ptr<QTreeWidgetItem> parentElement;
        Ui::HistorySearch* ui;
};

#endif // HISTORYSEARCH_H
