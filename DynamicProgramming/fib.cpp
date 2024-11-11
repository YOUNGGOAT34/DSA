#include<iostream>
#include"fib.h"
#include<unordered_map>

using namespace std;


int fib(int n,unordered_map<int,int> &map){
    if(map.count(n)>0){
        return map[n];
    }
     if(n<2){
        return n;
     }
   map[n]=fib(n-1,map)+fib(n-2,map);
    return map[n];
    
}

int fib(int n){
unordered_map<int,int> map;
return fib(n-1,map)+fib(n-2,map);
}


