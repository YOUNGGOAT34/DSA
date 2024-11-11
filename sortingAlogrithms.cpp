#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//bubble sort

void bubbleSort(vector<int>& v){
  int n=v.size();

  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(v[j]>v[j+1]){
            swap(v[j],v[j+1]);
        }
    }
  }
}

//selection sort
void selectionSort(vector<int>& v){
  
  
    for(int i=0;i<v.size();i++){
        int minIndex=i;
         for(int j=i+1;j<v.size();j++){
         if(v[j]<v[minIndex]){
           minIndex=j;
         }
         }
         
          swap(v[minIndex],v[i]);
         
    }

}


    //insertion sort

    void insertionSort(vector<int> &v){
          for(int i=1;i<v.size();i++){
              int temp=v[i];
              int j=i-1;
           
               while(j>=0&&v[j]>temp){
                v[j+1]=v[j];

                j--;
               }

            v[j+1]=temp;




            
          }

          
    }

      void merge(int array[],int size,int leftArray[],int leftSize,int rightArray[],int rightSize){
       

        int a=0,l=0,r=0;

        while(r<rightSize&&l<leftSize){
          if(leftArray[l]<rightArray[r]){
              array[a]=leftArray[l];
               a++;
              l++;
          }else{
            array[a]=rightArray[r];
             a++;
            r++;
        
          
          }
             

           

            
        }


        while(l<leftSize){
          array[a]=leftArray[l];
          l++;
          a++;
        }

         while(r<rightSize){
          array[a]=rightArray[r];
          r++;
          a++;
        }
        

        
        

        
    }

    void mergeSort(int array[],int size){
        
        if(size<=1) return;

        int middle=size/2;
        int leftArray[middle];
        int rightArray[size-middle];

         int i=0;//for left array
         int j=0;//for right array

        for(;i<size;i++){
           if(i<middle){
              leftArray[i]=array[i];
           }else{
              rightArray[j]=array[i];
              j++;
           }
           

        }
        mergeSort(leftArray,middle);
        mergeSort(rightArray,size-middle);
        merge(array,size,leftArray,middle,rightArray,size-middle);
        
    }


    //quicksort
    int partition(int array[],int start,int end){
    int pivot=end;
    int i=start-1;
    int j=start;

    for(;j<end;j++){
       if(array[j]<array[pivot]){
          i++;
          swap(array[i],array[j]);
       }
    }
    
   i++;
   swap(array[i],array[pivot]);

   return i;
}

void quickSort(int array[],int start,int end){
    if(start>=end) return;
    int pivot=partition(array,start,end);
    quickSort(array,start,pivot-1);
    quickSort(array,pivot+1,end);

}


   