#include<iostream>
#include<vector>
#include<stdbool.h>
#include<cmath>
#include<functional>
#include<list>

using namespace std;

template<typename V,typename K>
class hashMap{
  public:
    vector<list<pair<V,K>>> map;
    size_t size;

    hashMap():size(0){
        map.resize(10);
    }

    void put(V key,K value){
       hash<V> hashFunction;
       size_t hash=hashFunction(key)%map.size();
       auto &index=map[hash];
       
       for(auto &pair:index){
        if(pair.first==key){
            pair.second=value;
            return;
        }
       }

       index.emplace_back(key,value);
       size++;
    }


    V get(V key){
     hash<V> hashFunction;
     size_t hash=hashFunction(key)%map.size();
     auto &index=map[hash];
       
       for(auto &pair:index){
        if(pair.first==key){
            
            return pair.second;;
        }
       }

       cout<<"Key Not found"<<endl;
       return -1;

    }


    void display(){
        for(auto &list:map){
            for(auto &pair:list){
                cout<<pair.first<<" "<<pair.second<<endl;
            }
            
        }
    }



    bool isEmpty(){
     size_t sum{};

     for(int i{};i<map.size();i++){
        sum+=map[i].size();
     }

     if(!sum) return true;
     return false;
    }
};