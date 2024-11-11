//Using linkded list.
#include<iostream>
#include<stdbool.h>
using namespace std;

template<typename T>
class Node{

   public:
   T data;
   Node<T>* next;

   Node(T value):data(value),next(nullptr){}
};

template<typename T>
class Queue{
  public:
  Node<T> *front;
  Node<T> *back;
  int size;

  Queue():size(0),front(nullptr),back(nullptr){}
//Method to add elements
  void push(T value){
    Node<T> *node=new Node(value);
    if(isEmpty()){
        front=node;
        back=node;
        size++;
        return;
    }
    back->next=node;
    back=node;
    size++;

  }
//method to remove elements from the queue
void pop(){
  if(isEmpty()){
    cout<<"Empty queue"<<endl;
    return;
    }
  Node<T> *current=front;
  front=front->next;
  size--;
  delete current;

 
}

//get front element
T Front(){
    if(isEmpty()){
        cout<<"Empty queue"<<endl;
        return -1;
    }
    return front->data;
}
//get the last element
T Back(){
     if(isEmpty()){
        cout<<"Empty queue"<<endl;
        return -1;
    }
    return back->data;
}
//method to check if the queue is empty.
  bool isEmpty(){
    if(front==nullptr) return true;
    return false;

  }

  void display() const{
    Node<T> *current=front;
    while(current!=nullptr){
         cout<<current->data;
         cout<<" ";
         current=current->next;

    }
  }
};