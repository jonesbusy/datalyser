#ifndef HASH_TABLE_TCC_INCLUDED
#define HASH_TABLE_TCC_INCLUDED

template <typename Key>
HashTable<Key>::HashTable(long size, IHash<Key>* iHash) : Table<Key>(size), iHash(iHash)
{
}

template <typename Key>
long HashTable<Key>::hash(const Key& key)
{
    return this->iHash->generate(key, this->getSize());
}

template <typename Key>
long HashTable<Key>::rehash(long hash)
{
    return this->iHash->regenerate(hash, this->getSize());
}

#endif // HASH_TABLE_TCC_INCLUDED
