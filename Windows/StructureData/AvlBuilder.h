#ifndef AVLBUILDER_H
#define AVLBUILDER_H

#include <QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include "TreeBuilder.h"
#include "BinaryTree.h"
#include "Author.h"

class AvlBuilder: public TreeBuilder
{
    public:
        AvlBuilder();
        virtual void initialize() final;
        virtual Tree* getReadyTree() final;
        virtual void insert(const BufferData& newBufferData) final;
    private:
        void openFile();
        void readAllXmlDom();
        void readAllXmlDom(QDomElement childElement);
        void insert(const BufferData& newBufferData, BinaryTree*& node);
        void fixBalance(BinaryTree*& tree);
        void fixHeight(BinaryTree* const tree);
        int8_t calculateBalanced(BinaryTree*& tree);
        uint64_t height(BinaryTree* const tree);
        BinaryTree* rotateTreeOnLeft(BinaryTree*& currentNode);
        BinaryTree* rotateTreeOnRight(BinaryTree*& currentNode);
        BinaryTree* rootNode;
        QDomElement parentElement;
        QDomDocument document;
        BufferData buffer;
};
#endif // AVLBUILDER_H
