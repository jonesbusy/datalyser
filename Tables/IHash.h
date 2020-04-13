/*******************************************************************
|
| File         : IHash.h
|
| Description  : Interface pour le hachage.
|
| Author       : Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 06.01.2010
|
| C++ std      : -
|
| Dependencies : -
|
| Version      : 1.0
|
*******************************************************************/

#ifndef IHASH_H_INCLUDED
#define IHASH_H_INCLUDED

template <typename Key>
class IHash
{
    public:

    /***************************************************************
    | Description  : Retourne un code de hachage en fonction d'une
    |                clé et d'une taille limite. (Abstraite)
    |
    | Visibility   : Public
    |
    | Parameters   : key  - Clé pour hachage
    |                size - Taille limite
    |
    | Return value : Code de hachage
    ***************************************************************/
    virtual long generate(const Key& key, long size) = 0;

    /***************************************************************
    | Description  : Réhache un code de hachage. (Abstraite)
    |
    | Visibility   : Protected
    |
    | Parameters   : hash - Code de hachage
    |                size - Taille limite
    |
    | Return value : Nouveau code de hachage
    ***************************************************************/
    virtual long regenerate(long hash, long size) = 0;
};

#endif // IHASH_H_INCLUDED
