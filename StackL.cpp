//Linked list is gonna be used

#include <iostream>
#include <stdbool.h>

using namespace std;

template <typename T>
class Node{
  
   
    

     public:
     T data;
     Node<T> *next;
     Node(T d):data(d),next(nullptr){}
    

};

template<typename T>
class Stack{
   private:
   Node<T> *top;
   int size;


   public:
   Stack():top(nullptr),size(0){}


   void push(T data){
    Node<T> *node=new Node(data);
 
    //check if it is empty
    if(isEmpty()){
        top=node;
      

        return;
    }
    node->next=top;
    top=node;

   
    size++;

   }

   //Top

   T Top(){
    Node<T> *TopNode=top;
    // top=top->next;
    // delete(TopNode);
    return TopNode->data;
   }

   T pop(){
    Node<T> *TopNode=top;
    T data=TopNode->data;
    top=top->next;
    delete TopNode;
    size--;
    return data;
   }

   bool isEmpty(){
    if(top==nullptr) return true;

    return false;
   }

   void display(){
    if(isEmpty()){
        cout<<"Empty stack"<<endl;
        return;
    }
    Node<T> *current=top;
    while(current!=nullptr){
       cout<<"-------"<<endl;
       cout<<current->data<<endl;
       

       current=current->next;
    }

    cout<<"-------"<<endl;
   }
   
    

};