#ifndef SEQUENTIAL_TABLE_TCC_INCLUDED
#define SEQUENTIAL_TABLE_TCC_INCLUDED

#include "SequentialTable.h"

template <typename Key>
SequentialTable<Key>::SequentialTable(long size) : Table<Key>::Table(size), offset(0)
{
}

template <typename Key>
void SequentialTable<Key>::insert(const Row<Key>& row)
{
    // D�passement de la taille ?
    if (this->offset >= this->getSize())

        throw OVERFLOW;

    // Ligne d�j� existante ?
    if (this->getRowPosition(row.getKey()) != -1)

        throw DUPLICATE_KEY;

    // Allocation dynamique de la ligne et incr�mentation du curseur
    row.clone(this->getRow(this->offset++));

    // Ajout de la ligne et incr�mentation du curseur
    //this->setRow(this->offset++, row);
}

template <typename Key>
Row<Key>* SequentialTable<Key>::search(const Key& key)
{
    // Positionnement de la ligne
    long index = this->getRowPosition(key);

    // Pas trouv�e...
    if (index == -1)

        return NULL;

    // Envoie de la ligne
    return this->getRow(index);
}

template <typename Key>
void SequentialTable<Key>::reset()
{
    // Appel du parent
    Table<Key>::reset();

    // R�initialisation du curseur
    this->offset = 0;
}

template <typename Key>
long SequentialTable<Key>::getRowPosition(const Key& key)
{
    // Recherche s�quentielle jusqu'au curseur
    for (register long i = 0; i < this->offset; i++)

        // Ligne trouv�e ?
        if (*this->getRow(i) == key)

            return i;

    // Pas trouv�e...
    return -1;
}

#endif // SEQUENTIAL_TABLE_TCC_INCLUDED
