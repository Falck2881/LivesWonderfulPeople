#ifndef BALACNCEDTREE_H
#define BALACNCEDTREE_H

#include "Tree.h"

class BinaryTree: public Tree
{
    public:
        BinaryTree();
        virtual void search(const QString &key) final;
        virtual void setData() false;
        std::unique_ptr<BalacncedTree> leftChildNode;
        std::unique_ptr<BalacncedTree> rightChildNode;
        uint64_t height();
        void changeHeight(uint64_t height);
    private:
        uint64_t _height;
};

#endif // BALACNCEDTREE_H
