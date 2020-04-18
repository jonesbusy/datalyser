#ifndef CLOSED_HASH_TABLE_TCC_INCLUDED
#define CLOSED_HASH_TABLE_TCC_INCLUDED

#include "ClosedHashTable.h"

template<typename Key>
ClosedHashTable<Key>::ClosedHashTable(long size, IHash<Key>* iHash) : HashTable<Key, ClosedRow<Key> >(size, iHash), count(0)
{
    // Cr�ation des lignes
    for (register long i = 0; i < this->getSize(); i++)

        this->getRow(i) = new ClosedRow<Key>();
}

template<typename Key>
ClosedHashTable<Key>::~ClosedHashTable()
{
    // Effacement des allocation dynamiques
    this->reset();
}

template<typename Key>
void ClosedHashTable<Key>::insert(const Row<Key>& row)
{
    // D�passement de la taille ?
    if (this->count >= this->getSize())

        throw OVERFLOW;

    // Hachage de la cl�
    long hash = this->hash(row.getKey());

    // Sauvegarde de la position
    long position = hash;

    // Recherche de la bonne position
    while (this->getRow(position)->isBusy())
    {
        // Ligne d�j� existante ?
        if (*this->getRow(position)->getData() == row)

            throw DUPLICATE_KEY;

        // R�hachage
        position = this->rehash(position);
    }

    // Incr�mentation de la ligne initiale
    this->getRow(hash)->increment();

    // Ajout de la ligne dans un espace vide
    this->getRow(position)->setData(row, hash);

    // Incr�mentation...
    this->count++;
}

template<typename Key>
Row<Key>* ClosedHashTable<Key>::search(const Key& key)
{
    // Hachage de la cl�
    long position = this->hash(key);

    // Compteur d'it�rations pour �viter le bouclage infini
    long iterations = 0;

    // Recherche de la bonne position
    while (this->getRow(position)->isBusy() && iterations < this->getSize())
    {
        // Ligne trouv�e ?
        if (*this->getRow(position)->getData() == key)

            // Envoie de la ligne
            return this->getRow(position)->getData();

        // R�hachage
        position = this->rehash(position);

        iterations++;
    }

    // Pas trouv�e...
    return NULL;
}

template<typename Key>
void ClosedHashTable<Key>::reset()
{
    // R�initialisation de toutes les lignes
    for (register long i = 0; i < this->getSize(); i++)

        this->getRow(i)->clear();

    this->count = 0;
}

#endif // CLOSED_HASH_TABLE_TCC_INCLUDED
