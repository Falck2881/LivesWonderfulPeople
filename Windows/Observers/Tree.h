#ifndef TREE_H
#define TREE_H

#include <QList>
#include <cstdint>
#include <memory>
#include <QString>
#include "Stream/BufferData.h"
#include "Stream/Author.h"

class Tree
{
    public:
        virtual ~Tree(){}
        virtual QString key(){return "";}
        virtual void addData(const BufferData& buffer){}
        virtual void update(Author* archive){}
        virtual void search(const QString &key){}
        void append(Tree* observers);
        void notifyAllObservers(Author* foundArchive);
    private:
        QList<Tree*> observers;
    protected:
        Tree(){}
};

#endif // TREE_H
