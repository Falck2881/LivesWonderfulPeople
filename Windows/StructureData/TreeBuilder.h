#ifndef TREEBUILDER_H
#define TREEBUILDER_H

#include "Observers/Tree.h"

class TreeBuilder
{
    public:
        TreeBuilder() = default;
        virtual ~TreeBuilder() = default;
        virtual void initialize() = 0;
        virtual Tree* getReadyTree() = 0;
        virtual void insert(const BufferData& buffer) = 0;
};

#endif // TREEBUILDER_H
