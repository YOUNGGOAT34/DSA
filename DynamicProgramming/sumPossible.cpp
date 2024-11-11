#include<iostream>
#include<stdbool.h>
#include<vector>
#include<unordered_map>
#include <limits>
#include<cmath>
#include"sumPossible.h"
using namespace std;



bool sp(int amount,vector<int> numbers,unordered_map<int,bool> &map){
  if(map.count(amount)>0){
    return map[amount];
  }
  if(amount==0) return true;
  if(amount<0) return false;

  for(auto &number:numbers){
   
   if(sp(amount-number,numbers,map)){
     map[amount]=true;
     return true;
   }

   
   
  }

    map[amount]=false;

 

  

  


  return false;
 

}

 bool sp(int amount,vector<int> numbers){
   unordered_map<int,bool> map;
  

   return  sp(amount,numbers,map);
   
 }

 //min change problem
 int minimum=numeric_limits<int>::max();

 int minChange(int amount,vector<int> coins){
     if(amount==0) return 0;

     for(auto &coin:coins){
        minimum=min(minChange(amount-coin,coins),minimum);
        minimum+=1;


     }


     return minimum;

 }
