#include <iostream>
using namespace std;
class LinkedList{
    
   class Node{
    public:
    int data;
   
    Node *next;

    Node(int data):data(data), next(nullptr){}
   };

   public:

   Node *head;
  
   int size;
    
    LinkedList():head(nullptr),size(0){}

    
    void prependNode(int data){
      Node *node=new Node(data);
      
        
      
      
        node->next=head;
            
         head=node;
        
         size++;
       
        
        
    }

    //what if you do not use the tail
    void appendNode(int data){
    Node *node=new Node(data);
    Node *current=head;
    
    if(current==nullptr){
      head=node;
        
        size++;
     
      
      
    }else{
      while(current->next!=nullptr){
         current=current->next;
      }
      current->next=node;
     
      
      size++;
    }
    }


    void insertAfter(int nodeToinsertAfter,int nodeToinsert){
     if(size==0){
      cout<<"List is empty"<<endl;
      return;
     }
     Node *node=new Node(nodeToinsert);
     Node *current=head;
     
     while(current){
      
      if(current->data==nodeToinsertAfter){

         
         node->next=current->next;
         current->next=node;
         
         size++;
         return;

      }
      
      current=current->next;

     }
     cout<<nodeToinsertAfter<<" is not in the list"<<endl;
    }


  
   void deleteNode(int index){
      int key=0;
      
     
      if(index>=size){
         cout<<"out of bounds"<<endl;
         return;
      }

      
      
      
      Node *current=head;
      Node *prev=nullptr;

      if(index==0){
            head=head->next;
            delete current;
            size--;
            return;
          }
      
      while(current){
       
        
          
          
         if(key==index){
            
           
           prev->next=current->next;
           delete current;
            size--;
            return;
      
            
         }
         prev=current;
         current=current->next;
         key++;
         
        
        
         
      }
      


     

   }

    void display(){
      Node *current;
      current=head;
      if(current==nullptr){
         cout<<"Empty list"<<endl;
         return;
        
      }
      while(current!=nullptr){
         cout<<current->data<<"->";
         current=current->next;
          
      }
      cout<<"NULL"<<endl;
    }
};