#include <iostream>
using namespace std;
template<typename T>
class Node{
     public:
      Node *next;
      T data;

      Node(T val):data(val),next(nullptr) {}
      

};

template<typename T>
class CLL{
      public:
      Node<T> *head;
      CLL():head(nullptr){}

      void appendNode(T val){
        Node<T> *newNode=new Node(val);
        if(head==nullptr){
            
            head=newNode;
            newNode->next=head;
            return;
        }
        Node<T> *current=head;
        
        while(current->next!=head){
            
            current=current->next;
            
        }

        current->next=newNode;
        newNode->next=head;

      }


      void prependNode(T val){
        Node<T> *newNode=new Node(val);
        Node<T> *current=head;

        if(head==nullptr){
          
          appendNode(val);
          return;
        }

        newNode->next=current;
        while(current->next!=head){
          current=current->next;
        }

        current->next=newNode;
        head=newNode;
        
        
        }

      void display(){
       if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

 

    Node<T> *current = head;
     do {
            cout << current->data << " -> ";
           
            current = current->next;
        } while (current != head);
        cout << "(head)" << endl; 
        
      }

};