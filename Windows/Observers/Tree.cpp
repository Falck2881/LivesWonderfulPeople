#include "Tree.h"

void Tree::append(Tree *observer)
{
    observers.push_back(observer);
}

void Tree::notifyAllObservers(Author* foundArchive)
{
    foreach(auto observer, observers)
        observer->update(foundArchive);
}
