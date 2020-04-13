/*******************************************************************
|
| File         : List.h
|
| Description  : Permet de representer une liste d'elements.
|                Utilise pour la table de hachage ouverte du cours
|                ASD2.
|
|                La technique d'implementation est identique a celle
|                faite dans la classe Liste du cours. Les methodes
|                du TDA liste qui ne sont pas utilisees pour
|                le projet n'ont pas ete implementees.
|
| Author       : Valentin Delaye
|
| Created      : 03.12.2009
|
| Modified     : 03.12.2009
|
| C++ std      : -
|
| Dependencies : -
|
| Version      : 1.0
|
*******************************************************************/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <cstdlib>

template <typename Data>
struct Node
{
    Data data;
    Node<Data>* next;
};

template <typename Data>
class List
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
    List();

    /***************************************************************
    | Description  : Constructeur de copie
    |
    | Visibility   : Public
    |
    | Parameters   : list - Liste à copier
    |
    | Return value : -
    ***************************************************************/
    List(const List<Data>& list);

    /***************************************************************
    | Description  : Destructeur
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    ~List();

    /***************************************************************
    | Description  : Opérateur d'affectation
    |
    | Visibility   : Public
    |
    | Parameters   : list - Liste à copier
    |
    | Return value : Référence sur la liste
    ***************************************************************/
    List<Data>& operator=(const List<Data>& list);

    /***************************************************************
    | Description  : Permet d'inserer un element au debut
    |                de la liste
    |
    | Visibility   : Public
    |
    | Parameters   : data - L'element à ajouter
    |
    | Return value : Vrai si l'insertion a réussi, sinon faux
    ***************************************************************/
    bool insert(const Data& data);

    /***************************************************************
    | Description  : Permet d'effacer la liste
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : -
    ***************************************************************/
    void clear();

    /***************************************************************
    | Description  : Permet d'indiquer si la liste est vide
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : true la liste est vide, false sinon.
    ***************************************************************/
    bool isEmpty();

    /***************************************************************
    | Description  : Permet d'inserer un element au debut
    |                de la liste
    |
    | Visibility   : Public
    |
    | Parameters   : element - L'element a ajouter
    |
    | Return value : -
    ***************************************************************/
    int getLength();

    /***************************************************************
    | Description  : Permet de retourner la valeur du debut de la
    |                liste
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : L'element du debut de liste
    ***************************************************************/
    Data getData();

    /***************************************************************
    | Description  : Permet d'avancer dans la liste
    |
    | Visibility   : Public
    |
    | Parameters   : -
    |
    | Return value : L'element du debut de liste
    ***************************************************************/
    List<Data> next();

    /***************************************************************
    | Description  : Clône la liste.
    |
    | Visibility   : Public
    |
    | Parameters   : list - Liste de destination
    |
    | Return value : -
    ***************************************************************/
    void clone(List<Data>*& list);



    private:

    /***************************************************************
    | Description  : Pointeur sur le debut de la liste
    ***************************************************************/
    Node<Data>* head;

    /***************************************************************
    | Description  : Indicateur de copie
    ***************************************************************/
    bool copy;
};

#include "List.cpp"

#endif // LIST_H_INCLUDED
