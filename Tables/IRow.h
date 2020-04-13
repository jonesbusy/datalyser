/*******************************************************************
|
| File         : IRow.h
|
| Description  : Interface pour tout type de ligne de table.
|
| Author       : 
|
| Created      : 06.01.2010
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

#ifndef IROW_H_INCLUDED
#define IROW_H_INCLUDED

class IRow
{
    public:

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
    virtual void clone(IRow*& row) const = 0;
};

#endif // IROW_H_INCLUDED
