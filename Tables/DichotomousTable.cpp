#ifndef DICHOTOMOUS_TABLE_TCC_INCLUDED
#define DICHOTOMOUS_TABLE_TCC_INCLUDED

template <typename Key>
DichotomousTable<Key>::DichotomousTable(long size) : Table<Key>::Table(size), offset(0), shorted(true)
{
}

template <typename Key>
void DichotomousTable<Key>::insert(const Row<Key>& row)
{
    // Réinitialisation de la complexité
    this->resetComplexity();

    // Dépassement de la taille ?
    if (this->offset >= this->getSize())

        throw TABLE_OVERFLOW;

    // Ligne déjà existante ?
    if (this->getRowPosition(row.getKey()) != -1)

        throw TABLE_DUPLICATE_KEY;

    // Ajout de la ligne et incrémentation du curseur
    this->setRow(this->offset++, row);

    // Incrémentation de la complexité
    this->incrementComplexity();

    // Table non-triée...
    this->shorted = false;
}

template <typename Key>
Row<Key>* DichotomousTable<Key>::search(const Key& key)
{
    // Réinitialisation de la complexité
    this->resetComplexity();

    // Positionnement de la ligne
    long index = this->getRowPosition(key);

    // Pas trouvée...
    if (index == -1)

        return NULL;

    // Envoie de la ligne
    return this->getRow(index);
}

template <typename Key>
void DichotomousTable<Key>::reset()
{
    // Appel du parent
    Table<Key>::reset();

    // Réinitialisation du curseur
    this->offset = 0;

    // Table vide donc triée...
    this->shorted = true;
}

template <typename Key>
void DichotomousTable<Key>::quickSort()
{
    // Table vide...
    if (!this->offset)

        return;

    // Tri complet de la table
    this->quickSort(0, this->offset - 1);

    // Table triée...
    this->shorted = true;
}

template <typename Key>
Row<Key>* DichotomousTable<Key>::getRow(long index) const
{
    // Covariance
    return (Row<Key>*)Table<Key>::getRow(index);
}

template <typename Key>
long DichotomousTable<Key>::getRowPosition(const Key& key)
{
    // Table vide...
    if (!this->offset)

        return -1;

    // Table non-triée ?
    if (!this->shorted)
    {
        // Tri complet de la table
        this->quickSort(0, this->offset - 1);

        // Table triée...
        this->shorted = true;
    }

    // Indice du début
    long firstIndex = 0;

    // Indice de la fin
    long lastIndex = this->offset - 1;

    // Tant qu'il n'y a pas eu de croisement entre les deux indices
    while (firstIndex <= lastIndex)
    {
        // Incrémentation de la complexité
        this->incrementComplexity();

        // Médiane des deux indices
        long centerIndex = (firstIndex + lastIndex) / 2;

        // Ligne de la médiane des deux indices
        Row<Key>* centerRow = this->getRow(centerIndex);

        // Ligne trouvée
        if (*centerRow == key)

            // Envoie de l'indice
            return centerIndex;

        // Si la recherche est plus petite
        else if (*centerRow > key)

            // Continuer dans la partie inférieure
            lastIndex = centerIndex - 1;

        // Sinon (si la recherche est plus grande)
        else

            // Continuer dans la partie supérieure
            firstIndex = centerIndex + 1;
    }

    // Pas trouvée...
    return -1;
}

template <typename Key>
void DichotomousTable<Key>::quickSort(long firstIndex, long lastIndex)
{
    // Prend la valeur de l'élément central comme référence
    Row<Key>* reference = this->getRow((firstIndex + lastIndex) / 2);

    // Recherche un élément mal placé depuis la gauche
    long leftIndex = firstIndex;

    // Recherche un élément mal placé depuis la droite
    long rightIndex = lastIndex;

    // S'il reste au moins 2 éléments
    if (leftIndex < rightIndex)
    {
        // Tant que les indices ne se sont pas croisés
        while (leftIndex <= rightIndex)
        {
            // Incrémentation de la complexité
            this->incrementComplexity();

            // Recherche élément mal placé à gauche
            while (*reference > *this->getRow(leftIndex))

                leftIndex++;

            // Recherche élément mal placé à droite
            while (*this->getRow(rightIndex) > *reference)

                rightIndex--;

            // Si indices pas encore croisés
            if (leftIndex < rightIndex)
            {
                // Permute les 2 éléments mal placés
                this->reverseRows(leftIndex, rightIndex);

                // Celui de gauche est maintenant bien placé
                leftIndex++;

                // Celui de droite est maintenant bien placé
                rightIndex--;
            }
            // Si les deux indices sont égaux
            else if (leftIndex == rightIndex)
            {
                // Préparation de la sortie de la boucle :

                // Empêcher le débordement à droite de la table...
                if (leftIndex < lastIndex)

                    leftIndex++;

                // Empêcher le débordement à gauche de la table...
                if (rightIndex > firstIndex)

                    rightIndex--;
            }

            // Si les indices se sont déjà croisés on ne fait rien
        }

        // Trier le sous-tableau de bornes : premier et droite
        this->quickSort(firstIndex, rightIndex);

        // Trier le sous-tableau de bornes : gauche et dernier
        this->quickSort(leftIndex, lastIndex);
    }
}

#endif // DICHOTOMOUS_TABLE_TCC_INCLUDED
