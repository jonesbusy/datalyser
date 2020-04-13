#ifndef TABLE_TCC_INCLUDED
#define TABLE_TCC_INCLUDED

template <typename Key>
Table<Key>::Table(long size) : size(size), complexity(NULL)
{
    // Test de cohérence de la taille
    if (this->size < 0)

        throw TABLE_SIZE_UNDER_ZERO;

    // Allocation dynamique pour les pointeurs de ligne
    this->rows = new IRow*[this->size];

    // Initialisation des pointeurs sur NULL (ligne vide)
    for (register long i = 0; i < this->size; i++)

        this->rows[i] = NULL;
}

template <typename Key>
Table<Key>::~Table()
{
    // Effacement des lignes
    this->reset();

    delete[] this->rows;
}

template <typename Key>
void Table<Key>::reset()
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

template <typename Key>
long Table<Key>::getSize() const
{
    return this->size;
}

template <typename Key>
long* Table<Key>::getComplexityPointer() const
{
    return this->complexity;
}

template <typename Key>
void Table<Key>::setComplexityPointer(long* complexityPointer)
{
    this->complexity = complexityPointer;
}

template <typename Key>
IRow* Table<Key>::getRow(long index) const
{
    // Indice dans le domaine de la table ?
    if (!this->inRange(index))

        throw TABLE_OUT_OF_RANGE;

    // Envoie de la ligne
    return this->rows[index];
}

template <typename Key>
void Table<Key>::setRow(long index, const IRow& row)
{
    // Indice dans le domaine de la table ?
    if (!this->inRange(index))

        throw TABLE_OUT_OF_RANGE;

    // Allocation dynamique de la ligne
    row.clone(this->rows[index]);
}

template <typename Key>
bool Table<Key>::inRange(long index) const
{
    // Domaine de la table
    return (index >= 0 && index < this->size);
}

template <typename Key>
void Table<Key>::reverseRows(long index1, long index2)
{
    // Indices dans le domaine de la table ?
    if (!this->inRange(index1) || !this->inRange(index2))

        throw TABLE_OUT_OF_RANGE;

    // Pointeur sur la première ligne
    IRow* rowTemp = this->rows[index1];

    // Remplacement de la première par la seconde
    this->rows[index1] = this->rows[index2];

    // Placement de la première dans la seconde
    this->rows[index2] = rowTemp;
}

template <typename Key>
void Table<Key>::incrementComplexity()
{
    if (this->complexity != NULL)

        (*this->complexity)++;
}

template <typename Key>
void Table<Key>::resetComplexity()
{
    if (this->complexity != NULL)

        *this->complexity = 0;
}

#endif // TABLE_TCC_INCLUDED
