#ifndef HASH_TABLE_TCC_INCLUDED
#define HASH_TABLE_TCC_INCLUDED

template <typename Key, typename Container>
HashTable<Key, Container>::HashTable(long size, IHash<Key>* iHash) : Table<Key, Container>(size), iHash(iHash)
{
}

template <typename Key, typename Container>
long HashTable<Key, Container>::hash(const Key& key)
{
    return this->iHash->generate(key, this->getSize());
}

template <typename Key, typename Container>
long HashTable<Key, Container>::rehash(long hash)
{
    return this->iHash->regenerate(hash, this->getSize());
}

#endif // HASH_TABLE_TCC_INCLUDED
