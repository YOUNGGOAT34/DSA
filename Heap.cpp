#include<iostream>
#include <algorithm>
using namespace std;

class Heap{
    private:
      int capacity;
      int *array;
      int size;

      //parent of a node
      int parent(int index){
        return (index-1)/2;
      }
      
      //left child of a node
      int left(int index){
        return (2*index)+1;
      }

      //right child of a node

      int right(int index){
        return (2*index)+2;
      }

    public:
      Heap(int cap):capacity(cap),size(0) {
        array=new int[capacity];
      }

      void insert(int val){
         if(size==capacity){
             cout<<"Heap overflow"<<endl;
             return;
         }

        
         int index=size;
         array[index]=val;
         while(index!=0&&array[parent(index)]<array[index]){
               swap(array[parent(index)],array[index]);
               index=parent(index);
         }

          size++;
         
      }

      int extractMin(){
        if(size==0){
            cout<<"Empty heap"<<endl;
            return -1;
        }
        if(size==1){
            size--;
            return array[0];
        }

        //if the heap has more than one element
        int root=array[0];
        array[0]=array[size-1];
        size--;
        //heapify it
        heapify(0);

        return root;
      }


      void deleteKey(int index){
        decreaseKey(index,INT_MIN);
        extractMin();
      }

      void decreaseKey(int index,int min){
            array[index]=min;
            while(index!=0&&array[parent(index)]>array[index]){
                swap(array[index],array[parent(index)]);
                index=parent(index);
            }

      }

      //heapify method
       
      void heapify(int index){
        int Left=left(index);
        int Right=right(index);
        int largest=index;
        if(Left<size&&array[index]<array[Left]){
           largest=Left;

        }

        if(Right<size&&array[largest]<array[Right]){
          largest=Right;

        }

        if(largest!=index){
            swap(array[largest],array[index]);
            heapify(largest);
        }

      





      }

  
      void display() const{
         for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
      }

};