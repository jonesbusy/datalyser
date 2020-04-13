#ifndef CLOSED_ROW_H_INCLUDED
#define CLOSED_ROW_H_INCLUDED

#include <cstdlib>
#include "Row.h"

template <typename Key>
class ClosedRow
{
    public:

    ClosedRow();

    Row<Key>* getData();

    bool setData(const Row<Key>& row, long hash);

    void increment();

    void clear();

    bool isBusy() const;

    int getSize() const;

    long getHash() const;



    private:

    Row<Key>* row;
    bool busy;
    int size;
    long hash;
};

#include "ClosedRow.cpp"

#endif // CLOSED_ROW_H_INCLUDED
