/*******************************************************************
|
| File         : Table.h
|
| Description  : Classe repr�sentant une table g�n�rique compos�e
|                de lignes. (Abstraite)
|
| Author       : 
|
| Created      : 02.12.2009
|
| Modified     : 13.01.2010
|
| C++ std      : cstdlib
|
| Dependencies : IRow.h, Row.h, TableError.h
|
| Version      : 5.5
|
*******************************************************************/

#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <cstdlib>
#include "IRow.h"
#include "Row.h"
#include "TableError.h"

template <typename Key>
class Table
{
    public:

    /***************************************************************
    | Description  : Constructeur
    |
    | Visibility   : Public
    |
    | Parameters   : size - Taille de la table
    |
    | Return value : -
    ***************************************************************/
    Table(long size);

    /***************************************************************
    | Description  : Destructeur (Virtuel)
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    virtual ~Table();

    /***************************************************************
    | Description  : Ins�re une ligne dans la table. (Abstraite)
    |
    | Visibility   : Public
    |
    | Parameters   : row - Ligne � ins�rer
    |
    | Return value : -
    ***************************************************************/
    virtual void insert(const Row<Key>& row) = 0;

    /***************************************************************
    | Description  : Recherche une ligne dans la table. (Abstraite)
    |
    | Visibility   : Public
    |
    | Parameters   : key - Cl� de recherche
    |
    | Return value : Pointeur sur la ligne
    ***************************************************************/
    virtual Row<Key>* search(const Key& key) = 0;

    /***************************************************************
    | Description  : Efface toutes les lignes et r�initialise la
    |                table. (Virtuelle)
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    virtual void reset();

    /***************************************************************
    | Description  : Retourne la taille de la table.
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : Taille de la table
    ***************************************************************/
    long getSize() const;

    /***************************************************************
    | Description  : Retourne le pointeur de complexit�.
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : Pointeur de complexit�
    ***************************************************************/
    long* getComplexityPointer() const;

    /***************************************************************
    | Description  : Modifie le pointeur de complexit�.
    |
    | Visibility   : Public
    |
    | Parameters   : complexityPointer - Pointeur de complexit�
    |
    | Return value : -
    ***************************************************************/
    void setComplexityPointer(long* complexityPointer);



    protected:

    /***************************************************************
    | Description  : Retourne un pointeur sur une ligne de la table.
    |                (Virtuelle pour pouvoir utiliser la covariance)
    |
    | Visibility   : Protected
    |
    | Parameters   : index - Indice de la ligne
    |
    | Return value : Pointeur sur la ligne
    ***************************************************************/
    virtual IRow* getRow(long index) const;

    /***************************************************************
    | Description  : Modifie une ligne de la table.
    |
    | Visibility   : Protected
    |
    | Parameters   : index - Indice de la ligne
    |                row   - Ligne � ins�rer
    |
    | Return value : -
    ***************************************************************/
    void setRow(long index, const IRow& row);

    /***************************************************************
    | Description  : Indique si l'indice est dans le domaine de la
    |                table.
    |
    | Visibility   : Protected
    |
    | Parameters   : index - Indice � tester
    |
    | Return value : Vrai si l'indice est dans le domaine de la
    |                table, sinon faux
    ***************************************************************/
    bool inRange(long index) const;

    /***************************************************************
    | Description  : Inverse deux lignes de la table.
    |
    | Visibility   : Protected
    |
    | Parameters   : index1 - Indice de la premi�re ligne
    |                index2 - Indice de la seconde ligne
    |
    | Return value : -
    ***************************************************************/
    void reverseRows(long index1, long index2);

    /***************************************************************
    | Description  : Incr�mente la complexit�.
    |
    | Visibility   : Protected
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void incrementComplexity();

    /***************************************************************
    | Description  : R�initialise la complexit�.
    |
    | Visibility   : Protected
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void resetComplexity();



    private:

    /***************************************************************
    | Description  : Taille de la table
    ***************************************************************/
    long size;

    /***************************************************************
    | Description  : Complexit�
    ***************************************************************/
    long* complexity;

    /***************************************************************
    | Description  : Tableau de lignes
    ***************************************************************/
    IRow** rows;
};

#include "Table.cpp"

#endif // TABLE_H_INCLUDED
