/*******************************************************************
|
| File         : ClosedHashTable.h
|
| Description  : Permet de representer une table de hachage fermee
|                dont les donnees sont generiques.
|
| Author       : Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 24.12.2009
|
| C++ std      : cstdlib
|
| Dependencies : Table.h, HashTable.h, IHash.h, Row.h, ClosedRow.h
|
| Version      : 1.0
|
*******************************************************************/

#ifndef CLOSED_HASH_TABLE_H_INCLUDED
#define CLOSED_HASH_TABLE_H_INCLUDED

#include <cstdlib>
#include "Table.h"
#include "HashTable.h"
#include "IHash.h"
#include "Row.h"
#include "ClosedRow.h"

template <typename Key>
class ClosedHashTable : public HashTable<Key, ClosedRow<Key> >
{
    public:

    /***************************************************************
    | Description  : Constructeur
    |
    | Visibility   : Public
    |
    | Parameters   : size  - Taille de la table
    |                iHash - Instance d'une classe de hachage
    |
    | Return value : -
    ***************************************************************/
    ClosedHashTable(long size, IHash<Key>* iHash);

    /***************************************************************
    | Description  : Destructeur
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    ~ClosedHashTable();

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
    | Description  : Permet de remettre a zero la table
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void reset();



    private:

    /***************************************************************
    | Description  : Nombre d'entr�es
    ***************************************************************/
    long count;
};

#include "ClosedHashTable.cpp"

#endif // CLOSED_HASH_TABLE_H_INCLUDED
