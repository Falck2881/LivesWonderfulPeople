#ifndef SEARCHINPUTDATACOMMAND_H
#define SEARCHINPUTDATACOMMAND_H

#include "Observers/Tree.h"
#include "WorkingWithDataLinker.h"
#include <QLineEdit>


class SearchInputDataCommand: public WorkingWithDataLinker
{
    Q_OBJECT


    public:
        SearchInputDataCommand(const QLineEdit* lineEdit, Tree* tree);
        void updataTree(Tree* newTree);
    private slots:
        virtual bool executeImplementationPart() final;
    private:
        bool searchInputData();
        bool checkDataInTree();
        const QLineEdit* lineEdit;
        Tree* tree;
};

#endif // SEARCHINPUTDATACOMMAND_H
