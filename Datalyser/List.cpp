#ifndef LIST_TCC_INCLUDED
#define LIST_TCC_INCLUDED

template <typename Data>
List<Data>::List() : head(NULL), copy(false)
{
}

template <typename Data>
List<Data>::List(const List<Data>& list)
{
    // Nouvelle tête
    this->head = list.head;

    // Copie non-profonde
    this->copy = true;
}

template <typename Data>
List<Data>::~List()
{
    this->clear();
}

template <typename Data>
List<Data>& List<Data>::operator=(const List<Data>& list)
{
    // Efface la liste
    this->clear();

    // Nouvelle tête
    this->head = list.head;

    // Copie non-profonde
    this->copy = true;

    return *this;
}

template <typename Data>
bool List<Data>::insert(const Data& data)
{
    // On ne peut pas insérer dans une copie
    if (this->copy)

        return false;

    Node<Data>* node = new Node<Data>();

    node->data = data;
    node->next = this->head;

    this->head = node;

    return true;
}

template <typename Data>
void List<Data>::clear()
{
    // On ne peut pas effacer une copie
    if (this->copy)

        return;

    while (this->head != NULL)
    {
        Node<Data>* currentNode = this->head;
        this->head = currentNode->next;

        delete currentNode;
    }

    this->head = NULL;
}

template <typename Data>
bool List<Data>::isEmpty()
{
    return this->head == NULL;
}

template <typename Data>
int List<Data>::getLength()
{
    int count = 0;

    Node<Data>* currentNode = this->head;

    while (currentNode != NULL)
    {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}

template <typename Data>
Data List<Data>::getData()
{
    return this->head->data;
}

template <typename Data>
List<Data> List<Data>::next()
{
    List<Data> list;

    list.head = this->head->next;
    list.copy = true;

    return list;
}

template <typename Data>
void List<Data>::clone(List<Data>*& list)
{
    list->head = NULL;
    list->copy = false;

    Node<Data>* reference = this->head;
    Node<Data>* lastNode = NULL;

    while (reference != NULL)
    {
        Node<Data>* newNode = new Node<Data>();

        newNode->data = reference->data;
        newNode->next = NULL;

        if (lastNode != NULL)

            lastNode->next = newNode;

        else

            list->head = newNode;

        reference = reference->next;
        lastNode = newNode;
    }
}

#endif // LIST_TCC_INCLUDED
