#include <iostream>
using namespace std;

template<typename T>
class LinkedList
{
    private:
        int size;
        Node<T>* head;
    public:
        LinkedList();
        LinkedList(T newElem);
        LinkedList(const LinkedList<T>&listabase);
        void insertHead(T val);
        void insertTail(T val);
        void insertNthPosition(T val, int pos);
        void removeHead();
        void removeTail();
        void removeNthPosition(int pos);
        void print();
        ~LinkedList();
        class Iterator; 
        Iterator begin()
        { 
            return Iterator(head); 
        } 
        Iterator end()
        { 
            return Iterator(NULL); 
        } 
        class Iterator 
        { 
            private: 
                Node<T>* NodeActual; 
            public:
                //Constructor por defecto 
                Iterator() noexcept : NodeActual (head) {} 
                //Constructor con parámetros
                Iterator(Node<T>* Node) noexcept :  NodeActual (Node) {} 
                    
                    Iterator& operator=(Node<T>* Node) 
                    { 
                        this->NodeActual = Node; 
                        return *this; 
                    } 

                    Iterator& operator++() 
                    { 
                        if (NodeActual) 
                            NodeActual = NodeActual->getNext(); 
                        return *this; 
                    } 

                    Iterator operator++(int) 
                    { 
                        Iterator iterator = *this; 
                        ++*this; 
                        return iterator; 
                    } 

                    bool operator!=(const Iterator& iterator) 
                    { 
                        return NodeActual != iterator.NodeActual; 
                    } 

                    T operator*() 
                    { 
                        return NodeActual->getElem(); 
                    } 
            }; 

};

//constructor por defecto
template<typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    size = 0;
}

//constrcutor con parámetros
template<typename T>
LinkedList<T>::LinkedList(T val)
{
    head = new Node<T>(val);
    size = 1;
}

//constructor copia
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>&listabase)
{
    head = NULL; 
    size = 0;
    Node<T>* prev = NULL;
    Node<T>* temp = listabase.head;
    while (temp != NULL)
    {
        Node<T>* newNodeCopy = new Node<T>();
        newNodeCopy->setElem(temp->getElem());
        if(prev == NULL)
            head = newNodeCopy;
        else
            prev->setNext(newNodeCopy);
        prev = newNodeCopy;
        temp = temp->getNext();
    } 
}

//inserta elementos al comienzo de la lista enlazada
template<typename T>
void LinkedList<T>::insertHead(T val)
{
    Node<T>* newNode = new Node<T> ();
    newNode->setElem(val);
    newNode->setNext(head);
    head = newNode;
    size++;
}

//inserta elementos al final de la lista enlazada
template<typename T>
void LinkedList<T>::insertTail(T val)
{
    Node<T>* newNode = new Node<T>(); 
    newNode->setElem(val);
    newNode->setNext(NULL); 
    if(head == NULL) 
        head = newNode; 
    else
    {
        Node<T>* temp = head;
        while (temp->getNext() != NULL) 
            temp = temp->getNext(); 
        temp->setNext(newNode);
    }
    size++;
}

//inserta elementos en cualquier posición de la lista enlazada
template<typename T>
void LinkedList<T>::insertNthPosition(T val, int pos)
{
    Node<T>* newNode = new Node<T>(); 
    newNode->setElem(val);
    if (pos == 0)
        cout<<"Las posiciones empiezan en 1"<<endl;
    if (pos == 1)
    {
        newNode->setNext(head);
        head = newNode;
    }
    else
    {
        Node<T>* prev = NULL;
        Node<T>* temp = head;
        int i= 1;
        while (temp != NULL && i < pos)
        {
            prev = temp;
            temp = temp->getNext();
            i++;
        }
        newNode->setNext(prev->getNext());
        prev->setNext(newNode);
    }
}

//quita elementos del comienzo de la lista enlazada
template<typename T>
void LinkedList<T>::removeHead()
{
    if(size > 0)
    {
      Node<T>* temp = head;
      head = temp->getNext();
      delete temp;
      size--;
    }
    else if (head == NULL)
        cout<<"No hay más elementos por eliminar"<<endl;
    
}

//quita elementos del final de la lista enlazada
template<typename T>
void LinkedList<T>::removeTail()
{
    Node<T>* temp = head;
    Node<T>* prev = new Node<T>();
    while(temp->getNext() != NULL)
    {
        prev = temp;
        temp = temp->getNext();
    }
    temp->setNext(prev);
    prev->setNext(NULL);
    delete temp;
}

//quita elementos de cualquier posición de la lista enlazada 
template<typename T>
void LinkedList<T>::removeNthPosition(int pos)
{
    Node<T>* temp = head;
    if(pos < 1 || pos > size)
        cout<<"Fuera de rango "<<endl;
    else if (pos == 1)
    {
        head = temp->getNext();
        delete temp;
    }
    else
    {
        for (int i = 1; i < pos-1; i++)
            temp = temp->getNext();
        Node<T>* nextNode = temp->getNext();
        temp->setNext(nextNode->getNext());
        delete nextNode;
    }
    
}

//imprime la lista enlazada
template<typename T>
void LinkedList<T>::print()
{
    Node<T>* temp = head;
    while( temp != NULL)
    {
        cout<< temp->getElem() <<" ";
        temp = temp->getNext();
    }
    cout<<endl;
}

//destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != NULL)
    {
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}
