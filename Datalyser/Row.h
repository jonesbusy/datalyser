/*******************************************************************
|
| File         : Row.h
|
| Description  : Classe repr�sentant une ligne contenant une cl�
|                g�n�rique destin�e � �tre encapsul�e dans une
|                table. (Abstraite)
|
| Author       : 
|
| Created      : 10.12.2009
|
| Modified     : 12.12.2009
|
| C++ std      : -
|
| Dependencies : -
|
| Version      : 1.0
|
*******************************************************************/

#ifndef ROW_H_INCLUDED
#define ROW_H_INCLUDED

template <typename Key>
class Row
{
    public:

    /***************************************************************
    | Description  : Constructeur
    |
    | Visibility   : Public
    |
    | Parameters   : key - Cl� de la ligne
    |
    | Return value : -
    ***************************************************************/
    Row(Key key);

    /***************************************************************
    | Description  : Retourne la cl�.
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : Cl� de la ligne
    ***************************************************************/
    Key getKey() const;

    /***************************************************************
    | Description  : Compare la cl� de l'instance avec celle d'une
    |                autre (�galit�).
    |
    | Visibility   : Public
    |
    | Parameters   : row - Instance � comparer
    |
    | Return value : Vrai si les cl�s sont identiques, sinon faux
    ***************************************************************/
    bool operator==(const Row<Key>& row);

    /***************************************************************
    | Description  : Compare la cl� de l'instance avec une cl�
    |                (�galit�).
    |
    | Visibility   : Public
    |
    | Parameters   : key - Cl� � comparer
    |
    | Return value : Vrai si les cl�s sont identiques, sinon faux
    ***************************************************************/
    bool operator==(const Key& key);

    /***************************************************************
    | Description  : Compare la cl� de l'instance avec celle d'une
    |                autre (plus grand que...).
    |
    | Visibility   : Public
    |
    | Parameters   : row - Instance � comparer
    |
    | Return value : Vrai si la cl� est plus grande, sinon faux
    ***************************************************************/
    bool operator>(const Row<Key>& row);

    /***************************************************************
    | Description  : Compare la cl� de l'instance avec une cl�
    |                (plus grand que...).
    |
    | Visibility   : Public
    |
    | Parameters   : key - Cl� � comparer
    |
    | Return value : Vrai si la cl� est plus grande, sinon faux
    ***************************************************************/
    bool operator>(const Key& key);

    /***************************************************************
    | Description  : Compare la cl� de l'instance avec celle d'une
    |                autre (plus petit que...).
    |
    | Visibility   : Public
    |
    | Parameters   : row - Instance � comparer
    |
    | Return value : Vrai si la cl� est plus petite, sinon faux
    ***************************************************************/
    bool operator<(const Row<Key>& row);

    /***************************************************************
    | Description  : Compare la cl� de l'instance avec une cl�
    |                (plus petit que...).
    |
    | Visibility   : Public
    |
    | Parameters   : key - Cl� � comparer
    |
    | Return value : Vrai si la cl� est plus petite, sinon faux
    ***************************************************************/
    bool operator<(const Key& key);

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
    virtual void clone(Row<Key>*& row) const = 0;



    protected:

    /***************************************************************
    | Description  : Retourne un nombre [-1;0;1] indiquant l'ordre
    |                de grandeur du premier arguement par rapport
    |                au second arguement. (Abstraite)
    |
    | Visibility   : Protected
    |
    | Parameters   : key1 - Premi�re cl� � comparer
    |                key2 - Seconde cl� � comparer
    |
    | Return value : Rapport de grandeur (-1 = plus petit, 0 =
    |                �gaux, 1 = plus grand)
    ***************************************************************/
    virtual int compare(const Key& key1, const Key& key2) = 0;



    private:

    /***************************************************************
    | Description  : Cl� de la ligne
    ***************************************************************/
    Key key;
};

#include "Row.cpp"

#endif // ROW_H_INCLUDED
