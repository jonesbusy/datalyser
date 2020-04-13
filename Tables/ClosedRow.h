/*******************************************************************
|
| File         : ClosedRow.h
|
| Description  : Classe repr�sentant une ligne d'une table de
|                hachage ferm�e.
|
| Author       :  Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 06.01.2010
|
| C++ std      : cstdlib
|
| Dependencies : IRow.h, Row.h
|
| Version      : 2.0
|
*******************************************************************/

#ifndef CLOSED_ROW_H_INCLUDED
#define CLOSED_ROW_H_INCLUDED

#include <cstdlib>
#include "IRow.h"
#include "Row.h"

template <typename Key>
class ClosedRow : public IRow
{
    public:

    /***************************************************************
    | Description  : Creer une nouvelle instance de Closed Row avec
	|				 des valeurs par defaut
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    ClosedRow();

	/***************************************************************
    | Description  : Permet de recuperer la ligne generique d'une
	|				 table
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : La ligne generique d'une table
    ***************************************************************/
    Row<Key>* getData();

	/***************************************************************
    | Description  : Permet de d'ajouter une ligne d'une table dans
	|				 une ligne d'un table ferm�e.
    |
    | Visibility   : Public
    |
    | Parameters   : row  - La nouvelle ligne de la table
	|				 hash - Le code hachage
    |
    | Return value : True l'insertion est correcte, False si la
	|			     ligne est deja occupee
    ***************************************************************/
    bool setData(const Row<Key>& row, long hash);

	/***************************************************************
    | Description  : Permet d'incrementer le nombre de colision de
	|				 la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void increment();

	/***************************************************************
    | Description  : Permet de reinitialiser la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void clear();

	/***************************************************************
    | Description  : Indique si la ligne est occupee ou non
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : True la ligne est occupee, False sinon
    ***************************************************************/
    bool isBusy() const;

	/***************************************************************
    | Description  : Indique le nombre de colision pour la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : Le nombre de colision pour la ligne
    ***************************************************************/
    int getSize() const;

	/***************************************************************
    | Description  : Retourne le code de hachage pour la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : Le code de hachage
    ***************************************************************/
    long getHash() const;

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



    private:

    /***************************************************************
    | Description  : Pointeur sur les lignes generique d'une table
    ***************************************************************/
    Row<Key>* row;

    /***************************************************************
    | Description  : Occupation
    ***************************************************************/
    bool busy;

    /***************************************************************
    | Description  : Nombre de colision pour la ligne
    ***************************************************************/
    int size;

    /***************************************************************
    | Description  : Code de hachage de la ligne
    ***************************************************************/
    long hash;
};

#include "ClosedRow.cpp"

#endif // CLOSED_ROW_H_INCLUDED
