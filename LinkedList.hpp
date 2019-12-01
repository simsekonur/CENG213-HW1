#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
    public: // DO NOT CHANGE THIS PART.
        LinkedList();
        LinkedList(const LinkedList &obj);

        ~LinkedList();

        Node<T> *getFirstNode() const; //
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        int getNumberOfNodes();
        bool isEmpty(); //

        void insertAtTheFront(const T &data); //
        void insertAtTheEnd(const T &data); //
        void insertAfterGivenNode(const T &data, Node<T> *prev); //

        void removeNode(Node<T> *node);
        void removeAllNodes();

        Node<T> *findNode(const T &data); //

        void printAllNodes();
        void printReversed();

        LinkedList &operator=(const LinkedList &rhs);


    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

    private: // DO NOT CHANGE THIS PART.
        Node<T> *head;
        Node<T> *tail;
};



template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head ;

}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    /* TODO */
    head = new Node<T>();
    tail = new Node<T>();
    head->next = tail;
    tail->prev = head ;
    *this = obj ;

}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    removeAllNodes();
    delete head;
    delete tail;

}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    /* TODO */
    // first node dummy tail olmamalı
    if (head->next == tail){
        return NULL;

    }
    else {
        return head->next;
    }


}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    /* TODO */
    return head;
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    /* TODO */
    return tail;
}

template<class T>
int LinkedList<T>::getNumberOfNodes()
{
    /* TODO */
    Node<T> *p = head->next;
    int result = 0 ;
    while(p && p != getTail()){
        p = p->next ;
        result++;

    }
    return result;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    /* TODO */
    // head -> next == NULL
    // tail -> prev == NULL
    if (head->next == tail) // bos
    {
        return 1;
    }


    else {
        return 0;
    }



}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    /* TODO */
    insertAfterGivenNode(data,head);
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    /* TODO */
    insertAfterGivenNode(data,tail->prev);
}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{
    /* TODO */

    
    Node<T> *temp = prev->next ;
    Node<T> *n = new Node<T>();
    prev->next = n ;
    n->prev = prev ;
    n->next = temp ;
    temp->prev = n ;
    n->element = data ;



   
   

}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    Node<T> *ptr1 = node->prev == NULL ?NULL : node->prev;
    Node<T> *ptr2 = node->next == NULL ? NULL : node->next;
    if(head->next != tail){
        if(node->prev && node->next) {
            ptr1->next = ptr2;
            ptr2->prev = ptr1;
            node->prev = NULL;
            node->next = NULL;
            delete node;
        }
    }
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */

    while (tail->prev != head){
        Node<T> *p = tail->prev;
        removeNode(p);


    }


}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    /* TODO */
    Node<T> * p = head->next  ;
    Node<T> * result = NULL;
    while(p && p != tail){
        if (p->element == data){

            result = p ;
            return result;
        }
        p= p->next ;
    }
    return result ;

}

template<class T>
void LinkedList<T>::printAllNodes()
{
    /* TODO */
    Node<T> * p = head->next;
    while(p && p != getTail()){

        std::cout << p->element << std::endl ;
        p = p->next ;
    }
}

template<class T>
void LinkedList<T>::printReversed()
{
    /* TODO */
    Node<T> *p = tail->prev ;
    while(p && p!= getHead()){

        std::cout << p->element << std::endl ;
        p = p->prev;
    }

}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    /* TODO */
    removeAllNodes();
    if (this != &rhs){

        Node<T> * p = rhs.getFirstNode();
        while(p->next != NULL){
            insertAtTheEnd(p->element);
            if (p!= rhs.getTail()){
                p = p->next ;
            }

        }
    }
    return *this;
}

#endif //LINKED_LIST_HPP
