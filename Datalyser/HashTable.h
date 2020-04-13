/*******************************************************************
|
| File         : HashTable.h
|
| Description  : Classe parente des tables de hachage.
|
| Author       : Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 24.12.2009
|
| C++ std      : -
|
| Dependencies : Table.h, IHash.h
|
| Version      : 1.0
|
*******************************************************************/

#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

#include "Table.h"
#include "IHash.h"

template <typename Key, typename Container>
class HashTable : public Table<Key, Container>
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
    HashTable(long size, IHash<Key>* iHash);



    protected:

    /***************************************************************
    | Description  : Retourne un code de hachage en fonction d'une
    |                clé.
    |
    | Visibility   : Protected
    |
    | Parameters   : key - Clé pour hachage
    |
    | Return value : Code de hachage
    ***************************************************************/
    long hash(const Key& key);

    /***************************************************************
    | Description  : Réhache un code de hachage.
    |
    | Visibility   : Protected
    |
    | Parameters   : hash - Code de hachage
    |
    | Return value : Nouveau code de hachage
    ***************************************************************/
    long rehash(long hash);



    private:

    /***************************************************************
    | Description  : Instance d'une classe de hachage
    ***************************************************************/
    IHash<Key>* iHash;
};

#include "HashTable.cpp"

#endif // HASH_TABLE_H_INCLUDED
