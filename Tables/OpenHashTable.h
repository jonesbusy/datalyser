/*******************************************************************
|
| File         : OpenHashTable.h
|
| Description  : Permet de repr�senter une table de hachage ouverte.
|
| Author       : 
|
| Created      : 03.12.2009
|
| Modified     : 13.01.2010
|
| C++ std      : cstdlib
|
| Dependencies : Table.h, HashTable.h, IHash.h, Row.h, OpenRow.h,
|                TableError.h
|
| Version      : 2.0
|
*******************************************************************/

#ifndef OPEN_HASH_TABLE_H_INCLUDED
#define OPEN_HASH_TABLE_H_INCLUDED

#include <cstdlib>
#include "Table.h"
#include "HashTable.h"
#include "IHash.h"
#include "Row.h"
#include "OpenRow.h"
#include "TableError.h"

template<typename Key>
class OpenHashTable : public HashTable<Key>
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
    OpenHashTable(long size, IHash<Key>* iHash);

    /***************************************************************
    | Description  : Destructeur
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    ~OpenHashTable();

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
    OpenRow<Key>* getRow(long index) const;
};

#include "OpenHashTable.cpp"

#endif // OPEN_HASH_TABLE_H_INCLUDED
