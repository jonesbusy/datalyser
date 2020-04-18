#ifndef OPEN_HASH_TABLE_TCC_INCLUDED
#define OPEN_HASH_TABLE_TCC_INCLUDED

#include "OpenHashTable.h"

template<typename Key>
OpenHashTable<Key>::OpenHashTable(long size, IHash<Key>* iHash) : HashTable<Key>(size, iHash)
{
    // Création des lignes chaînées
    for (register long i = 0; i < this->getSize(); i++)

        this->setRow(i, OpenRow<Key>());
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
    // Réinitialisation de la complexité
    this->resetComplexity();

    // Liste
    OpenRow<Key>* list = this->getRow(this->hash(row.getKey()));

    // Incrémentation de la complexité
    this->incrementComplexity();

    // Recherche d'un doublon
    for (typename OpenRow<Key>::iterator rowIterator = list->begin(); rowIterator != list->end(); rowIterator++)
    {
        // Ligne déjà existante ?
        if (**rowIterator == row)

            throw TABLE_DUPLICATE_KEY;

        // Incrémentation de la complexité
        this->incrementComplexity();
    }

    // Allocation dynamique de la ligne
    Row<Key>* rowCopy;
    row.clone((IRow*&)rowCopy);

    // Ajout de la ligne au début de la liste
    list->push_back(rowCopy);
}

template<typename Key>
Row<Key>* OpenHashTable<Key>::search(const Key& key)
{
    // Réinitialisation de la complexité
    this->resetComplexity();

    // Liste
    OpenRow<Key>* list = this->getRow(this->hash(key));

    // Incrémentation de la complexité
    this->incrementComplexity();

    // Recherche de la ligne
    for (typename OpenRow<Key>::iterator rowIterator = list->begin(); rowIterator != list->end(); rowIterator++)
    {
        // Ligne trouvée ?
        if (**rowIterator == key)

            // Envoie de la ligne
            return *rowIterator;

        // Incrémentation de la complexité
        this->incrementComplexity();
    }

    // Pas trouvée...
    return NULL;
}

template<typename Key>
void OpenHashTable<Key>::reset()
{
    for (register int i = 0; i < this->getSize(); i++)
    {
        // Liste
        OpenRow<Key>* list = this->getRow(i);

        // Effacement des lignes chaînées
        for (typename OpenRow<Key>::iterator rowIterator = list->begin(); rowIterator != list->end(); rowIterator++)

            delete *rowIterator;

        // Effacement de la ligne
        list->clear();
    }
}

template <typename Key>
OpenRow<Key>* OpenHashTable<Key>::getRow(long index) const
{
    // Covariance
    return (OpenRow<Key>*)Table<Key>::getRow(index);
}

#endif // OPEN_HASH_TABLE_TCC_INCLUDED
