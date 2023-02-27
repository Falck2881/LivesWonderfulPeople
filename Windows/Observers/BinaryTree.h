#ifndef BALACNCEDTREE_H
#define BALACNCEDTREE_H

#include "Tree.h"
#include <QList>

class BinaryTree: public Tree
{
    public:
        BinaryTree(BinaryTree*&& copeTree);
        BinaryTree(std::unique_ptr<Author> newArchiveData);
        virtual void addData(const BufferData& buffer) final;
        virtual QString key() final;
        virtual void search(const QString &key);
        Author* data();
        BinaryTree& operator=(BinaryTree&& tree);
        BinaryTree* leftChildNode;
        BinaryTree* rightChildNode;
        uint64_t height();
        void changeHeight(uint64_t height);
    private:
        void search(const QString& key, BinaryTree*& currentNode);
        uint64_t _height;
        std::unique_ptr<Author> archive;
};

#endif // BALACNCEDTREE_H
