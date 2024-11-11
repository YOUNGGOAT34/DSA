//This uses an array.
#include <iostream>
#include <vector>
#include<stdbool.h>

using namespace std;

template <typename T>
class Stack{
    private:
    vector<T> array;
    
    int maxSize;

    public:
    //constructor
    Stack():maxSize(10){
        array.reserve(maxSize);
    }
    //Empty check
    bool isEmpty(){
        return array.empty();

    }

    //adding elements(push  method)

     void push(T value){

        if(array.size()==maxSize){
            cout<<"Stack overflow"<<endl;

            return;
        }
        
        array.push_back(value);//adds an element at the end
      
        
     }

     //remeoving the top element.
     T pop(){
        T t=array.back();
        array.pop_back();
        return t;
     }

     //top
     T top(){
        if(isEmpty()){
            cout<<"Empty stack"<<endl;
             throw out_of_range("Stack is empty!");
        }
        return array.back();
     }



     //size of the stack
     int size(){
        return array.size();
     }


    
     
     //print the stack
     void display(){
        for(auto i=array.begin();i!=array.end();i++){
            if(isEmpty()){
                cout<<"Empty array"<<endl;
            }
            cout<<"    "<<*i<<endl;
            cout<<"----------"<<endl;
        }
     }

};