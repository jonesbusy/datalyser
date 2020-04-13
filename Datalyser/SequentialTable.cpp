#ifndef SEQUENTIAL_TABLE_TCC_INCLUDED
#define SEQUENTIAL_TABLE_TCC_INCLUDED

template <typename Key>
SequentialTable<Key>::SequentialTable(long size) : Table<Key>::Table(size), offset(0)
{
}

template <typename Key>
void SequentialTable<Key>::insert(const Row<Key>& row)
{
    // Dépassement de la taille ?
    if (this->offset >= this->getSize())

        throw OVERFLOW;

    // Ligne déjà existante ?
    if (this->getRowPosition(row.getKey()) != -1)

        throw DUPLICATE_KEY;

    // Allocation dynamique de la ligne et incrémentation du curseur
    row.clone(this->getRow(this->offset++));

    // Ajout de la ligne et incrémentation du curseur
    //this->setRow(this->offset++, row);
}

template <typename Key>
Row<Key>* SequentialTable<Key>::search(const Key& key)
{
    // Positionnement de la ligne
    long index = this->getRowPosition(key);

    // Pas trouvée...
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

    // Réinitialisation du curseur
    this->offset = 0;
}

template <typename Key>
long SequentialTable<Key>::getRowPosition(const Key& key)
{
    // Recherche séquentielle jusqu'au curseur
    for (register long i = 0; i < this->offset; i++)

        // Ligne trouvée ?
        if (*this->getRow(i) == key)

            return i;

    // Pas trouvée...
    return -1;
}

#endif // SEQUENTIAL_TABLE_TCC_INCLUDED
