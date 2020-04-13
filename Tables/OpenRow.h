/*******************************************************************
|
| File         : OpenRow.h
|
| Description  : Classe repr�sentant une ligne d'une table de
|                hachage ouverte.
|
| Author       : 
|
| Created      : 06.01.2010
|
| Modified     : 06.01.2010
|
| C++ std      : cstdlib, vector
|
| Dependencies : IRow.h, Row.h
|
| Version      : 1.0
|
*******************************************************************/

#ifndef OPEN_ROW_H_INCLUDED
#define OPEN_ROW_H_INCLUDED

#include <cstdlib>
#include <vector>
#include "IRow.h"
#include "Row.h"

template <typename Key>
class OpenRow : public std::vector<Row<Key>*>, public IRow
{
    public:

    /***************************************************************
    | Description  : Constructeur
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    OpenRow();

    /***************************************************************
    | Description  : Destructeur
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    virtual ~OpenRow();

    /***************************************************************
    | Description  : Copie dynamiquement l'instance et place son
    |                adresse dans le pointeur pass� en param�tre.
    |                (Abstraite)
    |
    | Visibility   : Public
    |
    | Parameters   : row - Pointeur de ligne � instancier
    |
    | Return value : -
    ***************************************************************/
    void clone(IRow*& row) const;
};

#include "OpenRow.cpp"

#endif // OPEN_ROW_H_INCLUDED
