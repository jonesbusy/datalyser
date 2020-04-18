#ifndef OPEN_HASH_TABLE_TCC_INCLUDED
#define OPEN_HASH_TABLE_TCC_INCLUDED

#include "OpenHashTable.h"

template<typename Key>
OpenHashTable<Key>::OpenHashTable(long size, IHash<Key>* iHash) : HashTable<Key, List< Row<Key>* > >(size, iHash)
{
    // Cr�ation des lignes cha�n�es
    for (register long i = 0; i < this->getSize(); i++)

        this->getRow(i) = new List< Row<Key>* >();
}

template<typename Key>
OpenHashTable<Key>::~OpenHashTable()
{
    // Effacement des allocation dynamiques
    this->reset();
}

template<typename Key>
void OpenHashTable<Key>::insert(const Row<Key>& row)
{
    // T�te de la liste
    List< Row<Key>* >*& rowListHead = this->getRow(this->hash(row.getKey()));

    // Copie (non-profonde) de la t�te
    List< Row<Key>* > rowList = *rowListHead;

    // Recherche d'un doublon
    while (!rowList.isEmpty())
    {
        if (*rowList.getData() == row)

            throw DUPLICATE_KEY;

        rowList = rowList.next();
    }

    // Allocation dynamique de la ligne
    Row<Key>* rowCopy;
    row.clone(rowCopy);

    // Ajout de la ligne au d�but de la liste
    rowListHead->insert(rowCopy);
}

template<typename Key>
Row<Key>* OpenHashTable<Key>::search(const Key& key)
{
    List< Row<Key>* > rowList = *this->getRow(this->hash(key));

    // Recherche tant que la liste n'est pas termin�e
    while (!rowList.isEmpty())
    {
        // Ligne courante
        Row<Key>* currentRow = rowList.getData();

        // Ligne trouv�e ?
        if (*currentRow == key)

            return currentRow;

        rowList = rowList.next();
    }

    // Pas trouv�e...
    return NULL;
}

template<typename Key>
void OpenHashTable<Key>::reset()
{
    for (register long i = 0; i < this->getSize(); i++)
    {
        List< Row<Key>* > rowList = *this->getRow(i);

        // Effacement des lignes de la liste
        while (!rowList.isEmpty())
        {
            delete rowList.getData();

            rowList = rowList.next();
        }

        // R�initialisation de la liste
        this->getRow(i)->clear();
    }
}

#endif // OPEN_HASH_TABLE_TCC_INCLUDED
