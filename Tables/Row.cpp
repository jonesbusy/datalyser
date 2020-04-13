#ifndef ROW_TCC_INCLUDED
#define ROW_TCC_INCLUDED

template <typename Key>
Row<Key>::Row(Key key) : key(key)
{
}

template <typename Key>
Key Row<Key>::getKey() const
{
    return this->key;
}

template <typename Key>
bool Row<Key>::operator==(const Row<Key>& row)
{
    return !this->compare(this->key, row.key);
}

template <typename Key>
bool Row<Key>::operator==(const Key& key)
{
    return !this->compare(this->key, key);
}

template <typename Key>
bool Row<Key>::operator>(const Row<Key>& row)
{
    return this->compare(this->key, row.key) >= 1;
}

template <typename Key>
bool Row<Key>::operator>(const Key& key)
{
    return this->compare(this->key, key) >= 1;
}

template <typename Key>
bool Row<Key>::operator<(const Row<Key>& row)
{
    return this->compare(this->key, row.key) <= -1;
}

template <typename Key>
bool Row<Key>::operator<(const Key& key)
{
    return this->compare(this->key, key) <= -1;
}

/*
template <typename Key>
int Row<Key>::compare(const Key& key1, const Key& key2)
{
    if (key1 > key2)

        return 1;

    if (key1 < key2)

        return -1;

    return 0;
}
*/

#endif // ROW_TCC_INCLUDED
