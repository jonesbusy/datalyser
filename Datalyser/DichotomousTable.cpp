#ifndef DICHOTOMOUS_TABLE_TCC_INCLUDED
#define DICHOTOMOUS_TABLE_TCC_INCLUDED

#include "DichotomousTable.h"

template <typename Key>
DichotomousTable<Key>::DichotomousTable(long size) : Table<Key>::Table(size), offset(0), shorted(true)
{
}

template <typename Key>
void DichotomousTable<Key>::insert(const Row<Key>& row)
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

    // Table non-tri�e...
    this->shorted = false;
}

template <typename Key>
Row<Key>* DichotomousTable<Key>::search(const Key& key)
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
void DichotomousTable<Key>::reset()
{
    // Appel du parent
    Table<Key>::reset();

    // R�initialisation du curseur
    this->offset = 0;

    // Table vide donc tri�e...
    this->shorted = true;
}

template <typename Key>
long DichotomousTable<Key>::getRowPosition(const Key& key)
{
    // Table vide...
    if (!this->offset)

        return -1;

    // Table non-tri�e ?
    if (!this->shorted)
    {
        // Tri complet de la table
        this->quickSort(0, this->offset - 1);

        // Table tri�e...
        this->shorted = true;
    }

    // Indice du d�but
    long firstIndex = 0;

    // Indice de la fin
    long lastIndex = this->offset - 1;

    // Tant qu'il n'y a pas eu de croisement entre les deux indices
    while (firstIndex <= lastIndex)
    {
        // M�diane des deux indices
        long centerIndex = (firstIndex + lastIndex) / 2;

        // Ligne de la m�diane des deux indices
        Row<Key>* centerRow = this->getRow(centerIndex);

        // Ligne trouv�e
        if (*centerRow == key)

            // Envoie de l'indice
            return centerIndex;

        // Si la recherche est plus petite
        else if (*centerRow > key)

            // Continuer dans la partie inf�rieure
            lastIndex = centerIndex - 1;

        // Sinon (si la recherche est plus grande)
        else

            // Continuer dans la partie sup�rieure
            firstIndex = centerIndex + 1;
    }

    // Pas trouv�e...
    return -1;
}

template <typename Key>
void DichotomousTable<Key>::quickSort(long firstIndex, long lastIndex)
{
    // Prend la valeur de l'�l�ment central comme r�f�rence
    Row<Key>* reference = this->getRow((firstIndex + lastIndex) / 2);

    // Recherche un �l�ment mal plac� depuis la gauche
    long leftIndex = firstIndex;

    // Recherche un �l�ment mal plac� depuis la droite
    long rightIndex = lastIndex;

    // S'il reste au moins 2 �l�ments
    if (leftIndex < rightIndex)
    {
        // Tant que les indices ne se sont pas crois�s
        while (leftIndex <= rightIndex)
        {
            // Recherche �l�ment mal plac� � gauche
            while (*reference > *this->getRow(leftIndex))

                leftIndex++;

            // Recherche �l�ment mal plac� � droite
            while (*this->getRow(rightIndex) > *reference)

                rightIndex--;

            // Si indices pas encore crois�s
            if (leftIndex < rightIndex)
            {
                // Permute les 2 �l�ments mal plac�s
                this->reverseRows(leftIndex, rightIndex);

                // Celui de gauche est maintenant bien plac�
                leftIndex++;

                // Celui de droite est maintenant bien plac�
                rightIndex--;
            }
            // Si les deux indices sont �gaux
            else if (leftIndex == rightIndex)
            {
                // Pr�paration de la sortie de la boucle :

                // Emp�cher le d�bordement � droite de la table...
                if (leftIndex < lastIndex)

                    leftIndex++;

                // Emp�cher le d�bordement � gauche de la table...
                if (rightIndex > firstIndex)

                    rightIndex--;
            }

            // Si les indices se sont d�j� crois�s on ne fait rien
        }

        // Trier le sous-tableau de bornes : premier et droite
        this->quickSort(firstIndex, rightIndex);

        // Trier le sous-tableau de bornes : gauche et dernier
        this->quickSort(leftIndex, lastIndex);
    }
}

#endif // DICHOTOMOUS_TABLE_TCC_INCLUDED
