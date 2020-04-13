#ifndef TABLE_TCC_INCLUDED
#define TABLE_TCC_INCLUDED

template <typename Key, typename Container>
Table<Key, Container>::Table(long size) : size(size)
{
    // Test de cohérence de la taille
    if (this->size < 0)

        throw SIZE_UNDER_ZERO;

    // Allocation dynamique pour les pointeurs de ligne
    this->rows = new Container*[this->size];

    // Initialisation des pointeurs sur NULL (ligne vide)
    for (register long i = 0; i < this->size; i++)

        this->rows[i] = NULL;
}

template <typename Key, typename Container>
Table<Key, Container>::~Table()
{
    // Effacement des lignes
    this->reset();

    delete[] this->rows;
}

template <typename Key, typename Container>
void Table<Key, Container>::reset()
{
    // Désallocation et réinitialisation des lignes
    for (register long i = 0; i < this->size; i++)

        if (this->rows[i] != NULL)
        {
            // Désallocation de la ligne
            delete this->rows[i];

            // Réinitialisation du pointeur (ligne vide)
            this->rows[i] = NULL;
        }
}

template <typename Key, typename Container>
long Table<Key, Container>::getSize() const
{
    return this->size;
}

template <typename Key, typename Container>
Container*& Table<Key, Container>::getRow(long index)
{
    // Indice dans le domaine de la table ?
    if (!this->inRange(index))

        throw OUT_OF_RANGE;

    // Envoie de la ligne
    return this->rows[index];
}

template <typename Key, typename Container>
void Table<Key, Container>::reverseRows(long index1, long index2)
{
    // Indices dans le domaine de la table ?
    if (!this->inRange(index1) || !this->inRange(index2))

        throw OUT_OF_RANGE;

    // Pointeur sur la première ligne
    Container* rowTemp = this->rows[index1];

    // Remplacement de la première par la seconde
    this->rows[index1] = this->rows[index2];

    // Placement de la première dans la seconde
    this->rows[index2] = rowTemp;
}

template <typename Key, typename Container>
bool Table<Key, Container>::inRange(long index) const
{
    // Domaine de la table
    return (index >= 0 && index < this->size);
}

#endif // TABLE_TCC_INCLUDED
