#ifndef OPEN_ROW_TCC_INCLUDED
#define OPEN_ROW_TCC_INCLUDED

#include "OpenRow.h"

template <typename Key>
OpenRow<Key>::OpenRow() : std::vector<Row<Key>*>()
{
}

template <typename Key>
OpenRow<Key>::~OpenRow()
{
}

template <typename Key>
void OpenRow<Key>::clone(IRow*& row) const
{
    row = new OpenRow<Key>(*this);
}

#endif // OPEN_ROW_TCC_INCLUDED
