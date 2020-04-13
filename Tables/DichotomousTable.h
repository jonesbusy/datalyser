/*******************************************************************
|
| File         : DichotomousTable.h
|
| Description  : Classe repr�sentant une table dichotomique,
|                h�rit�e de la classe Table.
|
| Author       : 
|
| Created      : 02.12.2009
|
| Modified     : 13.01.2010
|
| C++ std      : cstdlib
|
| Dependencies : Table.h, Row.h, TableError.h
|
| Version      : 2.0
|
*******************************************************************/

#ifndef DICHOTOMOUS_TABLE_H_INCLUDED
#define DICHOTOMOUS_TABLE_H_INCLUDED

#include <cstdlib>
#include "Table.h"
#include "Row.h"
#include "TableError.h"

template <typename Key>
class DichotomousTable : public Table<Key>
{
    public:

    /***************************************************************
    | Description  : Constructeur
    |
    | Visibility   : Public
    |
    | Parameters   : size    - Taille de la table
    |                keyFunc - Pointeur sur une fonction
    |                          d'extraction de cl� primaire
    |
    | Return value : -
    ***************************************************************/
    DichotomousTable(long size);

    /***************************************************************
    | Description  : Ins�re une ligne dans la table.
    |
    | Visibility   : Public
    |
    | Parameters   : row - Ligne � ins�rer
    |
    | Return value : -
    ***************************************************************/
    void insert(const Row<Key>& row);

    /***************************************************************
    | Description  : Recherche une ligne dans la table.
    |
    | Visibility   : Public
    |
    | Parameters   : key - Cl� de recherche
    |
    | Return value : Pointeur sur la ligne
    ***************************************************************/
    Row<Key>* search(const Key& key);

    /***************************************************************
    | Description  : Efface toutes les lignes et r�initialise la
    |                table.
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void reset();

    /***************************************************************
    | Description  : Tri rapide r�cursif total. (Ajout�e uniquement
    |                pour le  projet Datalyser)
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void quickSort();



    protected:

    /***************************************************************
    | Description  : Retourne un pointeur sur une ligne de la table.
    |
    | Visibility   : Protected
    |
    | Parameters   : index - Indice de la ligne
    |
    | Return value : Pointeur sur la ligne
    ***************************************************************/
    Row<Key>* getRow(long index) const;



    private:

    /***************************************************************
    | Description  : Curseur
    ***************************************************************/
    long offset;

    /***************************************************************
    | Description  : Indique si la table est tri�e
    ***************************************************************/
    bool shorted;

    /***************************************************************
    | Description  : Retourne la position d'une ligne � partir de
    |                sa cl�.
    |
    | Visibility   : Private
    |
    | Parameters   : key - Cl� de recherche
    |
    | Return value : Indice de la ligne (-1 si aucune occurence n'a
    |                �t� trouv�e)
    ***************************************************************/
    long getRowPosition(const Key& key);

    /***************************************************************
    | Description  : Tri rapide r�cursif.
    |
    | Visibility   : Private
    |
    | Parameters   : firstIndex - Indice de gauche
    |                lastIndex  - Indice de droite
    |
    | Return value : -
    ***************************************************************/
    void quickSort(long firstIndex, long lastIndex);
};

#include "DichotomousTable.cpp"

#endif // DICHOTOMOUS_TABLE_H_INCLUDED
