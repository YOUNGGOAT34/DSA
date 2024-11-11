#include<iostream>
using namespace std;



#define GLOBALSPACE  5

template<typename T>
class Node{
public:
  T value;
  Node *left;
  Node *right;

  Node(T value):value(value),left(nullptr),right(nullptr) {}

};


template<typename T>
class Tree{
 public:
   Node<T> *root;
   int size;

   Tree():size(0),root(nullptr) {}


   

   

   



    

    // Recursive display function with indentation based on tree level
    void display(Node<T>* node,int space) {
        if(node==nullptr) return;

        space=space+GLOBALSPACE;
        display(node->right,space);
        cout<<"\n";
        for(int i=GLOBALSPACE;i<space;i++){
            cout<<" ";

        }

        cout<<node->value<<endl;
        display(node->left,space);
        
    }

   

 

};