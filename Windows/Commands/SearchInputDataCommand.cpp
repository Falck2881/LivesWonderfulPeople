#include "SearchInputDataCommand.h"
#include <QDebug>
#include "Warning.h"

SearchInputDataCommand::SearchInputDataCommand
(const QLineEdit* lineEdit, Tree* tree):lineEdit{lineEdit},tree{tree}
{

}

bool SearchInputDataCommand::executeImplementationPart()
{
    bool value;
    if(checkDataInTree())
        value = searchInputData();
    else
        value = false;

    return value;
}

bool SearchInputDataCommand::checkDataInTree()
{
    bool value = true;


    if(tree == nullptr){
        value = false;
        qDebug() << QString("Build a search tree in the class constructor - SearchPublisherWin");
    }

    return value;
}

bool SearchInputDataCommand::searchInputData()
{
    bool value;

    try{
        tree->search(lineEdit->text());
        value = true;
    }catch (Warning* warning) {
        warning->show();
        value = false;
    }
    return value;
}

void SearchInputDataCommand::updataTree(Tree *newTree)
{
    tree = newTree;
}
