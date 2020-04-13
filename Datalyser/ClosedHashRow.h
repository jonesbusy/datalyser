/*******************************************************************
|
| File         : ClosedHashRow.h
|
| Description  : Represente les attributs supplementaires pour gerer
|                une table de hachage fermee
|
| Author       :  Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 24.12.2009
|
| C++ std      :
|
| Dependencies : -
|
| Version      : 1.0
|
*******************************************************************/

#ifndef CLOSED_HASH_ROW_H_INCLUDED
#define CLOSED_HASH_ROW_H_INCLUDED

class ClosedHashRow
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
    ClosedHashRow();

    /***************************************************************
    | Description  : Constructeur
    |
    | Visibility   : Public
    |
    | Parameters   : hash - Valeur initiale de hachage
    |
    | Return value : -
    ***************************************************************/
    ClosedHashRow(long hash);

    /***************************************************************
    | Description  : Incremente le nombre de colision pour la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void increment();

    /***************************************************************
    | Description  : Reset les attributs de la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void reset();

    /***************************************************************
    | Description  : Change la valeur de hachage de l'element
    |                present dans la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : hash - Le nouveau hash
    |
    | Return value : -
    ***************************************************************/
    void setHash(long hash);

    /***************************************************************
    | Description  : Retourne la valeur de hachage de l'element
    |
    | Visibility   : Public
    |
    | Parameters   : size      - Taille de la table
    |                iHashCode - Methode de hachage
    |
    | Return value : -
    ***************************************************************/
    long getHash() const;

    /***************************************************************
    | Description  : Change l'etat de ligne (libre/occupee)
    |
    | Visibility   : Public
    |
    | Parameters   : busy - La nouvel etat
    |
    | Return value : -
    ***************************************************************/
    void setBusy(bool busy);

    /***************************************************************
    | Description  : Indique l'etat d'une ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : true la ligne est occupee, false si elle est
    |                vide
    ***************************************************************/
    bool isBusy() const;

    /***************************************************************
    | Description  : Retourne le nombre de colision pour la ligne
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : Le nombre de collision pour la ligne
    ***************************************************************/
    int getSize() const;


    private:

    /***************************************************************
    | Description  : Valeur de hachage pour ligne donnee
    ***************************************************************/
    long hash;

    /***************************************************************
    | Description  : Etat de la ligne
    ***************************************************************/
    bool busy;

    /***************************************************************
    | Description  : Nombre de collision pour la ligne
    ***************************************************************/
    int size;
};

#endif // CLOSED_HASH_ROW_H_INCLUDED
