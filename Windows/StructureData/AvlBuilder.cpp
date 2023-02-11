#include "AvlBuilder.h"
#include <QDebug>

AvlBuilder::AvlBuilder():rootNode(nullptr)
{
}

Tree* AvlBuilder::getReadyTree()
{
    return rootNode;
}

void AvlBuilder::initialize()
{
    openArchiveAuthorForRead();
    readBlockDataForWriteInAvlTree();
}

void AvlBuilder::openArchiveAuthorForRead()
{
    QFile file(archive.fileName());
    if(file.exists()){
        if(file.open(QIODevice::ReadOnly)){
           document.setContent(&file);
           parentElement = document.documentElement();
        }
    }
    else{
        qDebug() << "WARNING! Puth to file - Windows/StructureData/AvlBuilder.cpp "
                    "Name file is not exists. Check name file!";
    }
}

void AvlBuilder::readBlockDataForWriteInAvlTree()
{
    parentElement = parentElement.firstChildElement();
    while(!parentElement.isNull())
    {
        if(parentElement.isElement() && parentElement.tagName() == "RecordAuthor")
        {
            readBlockDataForWriteInAvlTree(parentElement);
            parentElement = parentElement.nextSiblingElement();
            insert(buffer);
        }
    }
}

void AvlBuilder::readBlockDataForWriteInAvlTree(QDomElement childElement)
{
    childElement = childElement.firstChildElement();
    while(!childElement.isNull())
    {
        if(childElement.isElement() && childElement.tagName() != "RecordAuthor")
        {
            if(childElement.tagName() == "Author")
                buffer.fioAuthor = childElement.text();
            else if(childElement.tagName() == "Title")
                buffer.titleEssays = childElement.text();
            else if(childElement.tagName() == "Publisher")
                buffer.namePublisher = childElement.text();
            else if(childElement.tagName() == "YearPublisher")
                buffer.yearPublisher = childElement.text();
            else if(childElement.tagName() == "CountPage")
                buffer.countPages = childElement.text();
        }
        childElement = childElement.nextSiblingElement();
    }
}

void AvlBuilder::insert(const BufferData& newBufferData)
{
    if(rootNode == nullptr){
        rootNode = new BinaryTree(std::make_unique<Author>());
        rootNode->addData(newBufferData);
        return;
    }
    else if(newBufferData.fioAuthor == rootNode->key())
        rootNode->addData(newBufferData);
    else if(newBufferData.fioAuthor < rootNode->key())
        insert(newBufferData, rootNode->leftChildNode);
    else if(newBufferData.fioAuthor > rootNode->key())
        insert(newBufferData, rootNode->rightChildNode);

    fixBalance(rootNode);
}

void AvlBuilder::insert(const BufferData &newBufferData, BinaryTree*& node)
{
    if(node == nullptr){
        node = new BinaryTree(std::make_unique<Author>());
        node->addData(newBufferData);
        return;
    }
    else if(newBufferData.fioAuthor == node->key())
        node->addData(newBufferData);
    else if(newBufferData.fioAuthor < node->key())
        insert(newBufferData, node->leftChildNode);
    else if(newBufferData.fioAuthor > node->key())
        insert(newBufferData, node->rightChildNode);

    fixBalance(node);
}

void AvlBuilder::fixBalance(BinaryTree*& tree)
{
    fixHeight(tree);

    if(calculateBalanced(tree) == 2)
    {
        if(calculateBalanced(tree->rightChildNode) == -1)
            tree->rightChildNode = rotateTreeOnRight(tree->rightChildNode);

        tree = rotateTreeOnLeft(tree);
    }
    else if(calculateBalanced(tree) == -2)
    {
        if(calculateBalanced(tree->leftChildNode) == 1)
            tree->leftChildNode = rotateTreeOnLeft(tree->leftChildNode);

        tree = rotateTreeOnRight(tree);
    }
}

void AvlBuilder::fixHeight(BinaryTree* const tree)
{
    uint64_t heightLeftDescendant = height(tree->leftChildNode);
    uint64_t heightRightDescendant = height(tree->rightChildNode);

    if(heightLeftDescendant ==  heightRightDescendant)
        tree->changeHeight( heightRightDescendant);
    else if(heightLeftDescendant >  heightRightDescendant)
        tree->changeHeight(heightLeftDescendant);
    else if(heightRightDescendant > heightLeftDescendant)
        tree->changeHeight(heightRightDescendant);
}

int8_t AvlBuilder::calculateBalanced(BinaryTree*& tree)
{
    uint64_t heightLeftChildNode = height(tree->leftChildNode);
    uint64_t heightRightChildNode = height(tree->rightChildNode);

    return heightRightChildNode - heightLeftChildNode;
}

uint64_t AvlBuilder::height(BinaryTree* const tree)
{
    return tree!=nullptr?tree->height():0;
}

BinaryTree* AvlBuilder::rotateTreeOnLeft(BinaryTree*& currentNode)
{
     BinaryTree* newCurrentNode = currentNode->rightChildNode;
     currentNode->rightChildNode = newCurrentNode->leftChildNode;
     newCurrentNode->leftChildNode = currentNode;

     fixHeight(currentNode);
     fixHeight(newCurrentNode);
     return newCurrentNode;
}

BinaryTree* AvlBuilder::rotateTreeOnRight(BinaryTree*& currentNode)
{
    BinaryTree* newCurrentNode = currentNode->leftChildNode;
    currentNode->leftChildNode = newCurrentNode->rightChildNode;
    newCurrentNode->rightChildNode = currentNode;

    fixHeight(currentNode);
    fixHeight(newCurrentNode);
    return newCurrentNode;
}
