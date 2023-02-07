#include "BinaryTree.h"
#include "Warning.h"

BinaryTree::BinaryTree(BinaryTree*&& copyTree)
{
    this->leftChildNode = copyTree->leftChildNode;
    this->rightChildNode = copyTree->rightChildNode;
    this->_height = copyTree->_height;
    this->archive = std::move(copyTree->archive);
}

BinaryTree::BinaryTree
(std::unique_ptr<ArchiveAuthor> newArchiveData):leftChildNode(nullptr),
                                                rightChildNode(nullptr),
                                                _height(1),
                                                archive{std::move(newArchiveData)}
{
}

ArchiveAuthor* BinaryTree::data()
{
    return archive.get();
}

QString BinaryTree::key()
{
    return archive->key();
}

BinaryTree& BinaryTree::operator=(BinaryTree&& tree)
{
    if(this == &tree)
        return *this;

    if((&tree) == nullptr)
        return *this;
    else{
        this->leftChildNode = (&tree)->leftChildNode;
        this->leftChildNode = nullptr;
        this->rightChildNode = (&tree)->rightChildNode;
        this->rightChildNode = nullptr;
    }

    return *this;
}

void BinaryTree::addData(const BufferData &buffer)
{
    archive->addData(buffer);
}

void BinaryTree::changeHeight(uint64_t height)
{
    _height = height+1;
}

uint64_t BinaryTree::height()
{
    return _height;
}

void BinaryTree::search(const QString &key)
{
    if(key == this->key())
        notifyAllObservers(this->data());
    else if(this->leftChildNode != nullptr && key < this->key())
        search(key, leftChildNode);
    else if(this->rightChildNode != nullptr && key > this->key())
        search(key, this->rightChildNode);
    else
        throw new Warning("Warning!: Author with this name -" + key + " does not exist \n");
}

void BinaryTree::search(const QString &key, BinaryTree*& currentNode)
{
    if(key == currentNode->key())
        notifyAllObservers(currentNode->data());
    else if(currentNode->leftChildNode != nullptr && key < currentNode->key())
        search(key, currentNode->leftChildNode);
    else if(currentNode->rightChildNode != nullptr && key > currentNode->key())
        search(key, currentNode->rightChildNode);
    else
        throw new Warning("Warning!: Author with this name -" + key + " does not exist \n");
}
