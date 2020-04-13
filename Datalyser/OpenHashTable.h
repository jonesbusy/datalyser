/*******************************************************************
|
| File         : OpenHashTable.h
|
| Description  : Permet de representer une table de hachage ouverte
|                Les donnees represenee sont generiques
|
| Author       : 
|
| Created      : 03.12.2009
|
| Modified     : 24.12.2009
|
| C++ std      : cstdlib
|
| Dependencies : Table.h, HashTable.h, IHash.h, Row.h, List.h
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
#include "List.h"

template<typename Key>
class OpenHashTable : public HashTable<Key, List< Row<Key>* > >
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
};

#include "OpenHashTable.cpp"

#endif // OPEN_HASH_TABLE_H_INCLUDED
