#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>
class Plant;

class Iterator
{
public:
    Iterator();
    virtual ~Iterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual Plant *currentItem() = 0;
};

#endif // ITERATOR_H
