

#ifndef LINKEDLIST_H
#define LINKEDLIST_H    

typedef struct Node{
    int data;
   struct Node *next;

}Node;

// Define Linked List structure
typedef struct LinkedList {
    Node* Head;
    Node* Tail;
    int size;  // Track the size of the list
   
} LinkedList;

//functions
Node *constructor(int data);
Node *constructor1(int data,Node *next);
LinkedList *CreateLinkedList();
void insert(LinkedList *List,Node *node);
void printList(LinkedList *List);
void insertAtIndex(int index,LinkedList *List,int Data);
void delete(LinkedList *List,int data);
#endif