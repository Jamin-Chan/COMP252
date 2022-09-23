//Jamin Chan 9/22/22

#ifndef H_UnorderedDoubleLinkedList
#define H_UnorderedDoubleLinkedList
 
#include "DoubleLinkedList.h"

using namespace std; 

template <class Type>
class unorderedDoubleLinkedList: public DoubleLinkedList<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: this->first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               this->last points to the this->last node in the  
      //               list, and this->count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: this->first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               this->last points to the this->last node in the 
      //               list, and this->count is incremented by 1.
    
    void insertNode(const Type& newItem, int index);
      //Function to insert newItem to be the element at location index.
      //Postcondition: If index is valid newItem will inserted at that location and count is incremented by 1.
    
    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               this->first points to the this->first node, this->last
      //               points to the this->last node of the updated 
      //               list, and this->count is decremented by 1.
};


template <class Type>
bool unorderedDoubleLinkedList<Type>::
                   search(const Type& searchItem) const
{
    dNodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = this->first; //set current to point to the this->first 
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->next; //make current point to
                                     //the next node
    return found; 
}//end search

template <class Type>
void unorderedDoubleLinkedList<Type>::insertFirst(const Type& newItem) {
   dNodeType<Type> *newNode;
    newNode = new dNodeType<Type>;
    newNode->info = newItem;
    
    newNode->next = NULL;
    newNode->prev = NULL;

    if (this->first == NULL) { //if there are no nodes in the doubly linked list yet
        this->first = newNode;
        this->last = newNode;
        this->count++;
        return;

    } else { // uses this if there are nodes in the linked list already
        newNode->next = this->first;
        this->first->prev = newNode;
        this->first = newNode;
        this->count++;
        return;
    }
}//end insertFirst


template <class Type>
void unorderedDoubleLinkedList<Type>::insertLast(const Type& newItem) {
    dNodeType<Type> *newNode;
    newNode = new dNodeType<Type>;
    newNode->info = newItem;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (this->last == NULL) { //if there are no nodes in the doubly linked list yet
        this->last = newNode;
        this->first = newNode;

    } else {  // uses this if there are nodes in the linked list already
        newNode->prev = this->last;
        this->last->next = newNode;
        this->last = newNode;

    }
    this->count++;
}//end insertLast

template <class Type>
void unorderedDoubleLinkedList<Type>::insertNode(const Type& newItem, int index) {
    dNodeType<Type> *newNode;
    dNodeType<Type> *current;
    dNodeType<Type> *temp;
    newNode = new dNodeType<Type>;
    newNode->info = newItem;

    newNode->next = NULL;
    newNode->prev = NULL;
    current = this->first;
    int position = 0;

    while (position != index) { //find the index of the node
        current = current->next;
        position++;

        if (position == this->count - 1) {
            cout << "Could not find the index [" << index << "] to insert." << endl;
            return;
        }
    }

    temp = current->prev;

    if (index == 0) { //incase index first instead of using insertFirst
        newNode->next = this->first;
        this->first->prev = newNode;
        this->first = newNode;

    } else if (index == this->count) { //incase index last instead of using insertLast
        newNode->prev = this->last;
        this->last->next = newNode;
        this->last = newNode;

    } else { //insert the node in the middle of the linked list
        newNode->next = current;
        newNode->prev = temp;
        temp->next = newNode;
        current->prev = newNode;

    }
    this->count++;
}//end insertNode

template <class Type>
void unorderedDoubleLinkedList<Type>::deleteNode(const Type& deleteItem) {
    dNodeType<Type>* current;
    dNodeType<Type>* temp;
    dNodeType<Type>* temp2;

    current = this->first;
    int position = 0;

    while (current != NULL) {
        if (current->info == deleteItem) {
            if (current->prev == NULL) { //if at the beginning of the linked list
                temp = current->next;
                this->first = temp;
                this->first->prev = NULL;

            } else if (current->next == NULL) { // if at the end of the linked list
                temp = current->prev;
                this->last = temp;
                this->last->next = NULL;

            } else { //everything else
                temp = current->prev;
                temp2 = current->next;
                temp->next = temp2;
                temp2->prev = temp;

            }
            current = NULL; //delete all signs of the node from count to node itself
            this->count--;
            return;

        } else {
            current = current->next;
        }

    }
    cout << "Could not find the item [" << deleteItem << "] to delete." << endl; //the function will reach this if no node is deleted
}//end deleteNode


#endif
