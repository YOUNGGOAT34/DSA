#include<iostream>
using namespace std;
template<typename T>
class Node{
     public:
     T data;
     Node *next;
     Node *prev;


     Node(T data):data(data),next(nullptr),prev(nullptr) {}


};

template<typename T>
class DLL{
     public:
     Node<T> *head;

     DLL():head(nullptr){}


     void appendNode(T val){
        Node<T> *newNode=new Node(val);
        if(head==nullptr)
        { 
            head=newNode;
            return;
            
        }
        Node<T> *current=head;
        
        while(current->next!=nullptr){
            
            current=current->next;

             
        }
         
         current->next=newNode;
         newNode->prev=current;
         
     }

      void prepend(T val){
        Node<T> *newNode=new Node(val);
        if(head==nullptr){
            head=newNode;
            return;
        }
        // Node<T> *current=head;
        
        newNode->next=head;
        newNode->next->prev=newNode;
        head=newNode;



        
      
        
      }


      void deleteNode(T val){
        Node<T> *current=head;
        if(head->data==val){
            head=head->next;
            delete current;
            head->prev=nullptr;
            return;
        }
        while(current!=nullptr){
           
            if(current->data==val){

                if(current->next==nullptr){
                    
                    current->prev->next=nullptr;
                    delete current; 
                    
                  
                    
                    return;
                }
                

                current->prev->next=current->next;
                current->next->prev=current->prev;
                delete current;
                return;
                
            }
            
             current=current->next;
             
        }
        cout<<"Node not found"<<endl;
      }
      
    void updateNode(T oldValue,T newValue){
     Node<T> *current=head;
     while(current!=nullptr){
      if(current->data==oldValue){
        current->data=newValue;
        return;
      }
      current=current->next;
     }
     cout<<"Node not found"<<endl;
    }


    void insertAtIndex(int index,T val){
        Node<T> *newNode=new Node(val);
        Node<T> *current=head;
        int idx{};

        if(index==0){
          prepend(val);
          return;
        }



        //in the middle indices
        while(current!=nullptr){
            if(idx==index){
                if(current->next==nullptr){
                    current->next=newNode;
                    newNode->prev=current;
                    return;
                }
                current->prev->next=newNode;
                newNode->next=current;
                newNode->prev=current->prev;
                current->prev=newNode;

                return;
            }
            current=current->next;
            idx++;
        }

        cout<<"Index out of range"<<endl;
    }
     
     void display() const{
 
         Node<T> *current=head;
          while(current!=nullptr){
            cout<<current->data<<"->";
            current=current->next;

          }
          cout<<"null"<<endl;
          
          
     }





};