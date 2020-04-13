#ifndef CLOSED_ROW_TCC_INCLUDED
#define CLOSED_ROW_TCC_INCLUDED

template <typename Key>
ClosedRow<Key>::ClosedRow() : row(NULL), busy(false), size(0), hash(0)
{
}

template <typename Key>
Row<Key>* ClosedRow<Key>::getData()
{
    return this->row;
}

template <typename Key>
bool ClosedRow<Key>::setData(const Row<Key>& row, long hash)
{
    if (this->busy)

        return false;

    row.clone(this->row);

    this->busy = true;
    this->hash = hash;

    return true;
}

template <typename Key>
void ClosedRow<Key>::increment()
{
    this->size++;
}

template <typename Key>
void ClosedRow<Key>::clear()
{
    if (this->row != NULL)

        delete this->row;

    this->row = NULL;
    this->busy = false;
    this->size = 0;
    this->hash = 0;
}

template <typename Key>
bool ClosedRow<Key>::isBusy() const
{
    return this->busy;
}

template <typename Key>
int ClosedRow<Key>::getSize() const
{
    return this->size;
}

template <typename Key>
long ClosedRow<Key>::getHash() const
{
    return this->hash;
}

#endif // CLOSED_ROW_TCC_INCLUDED
