#include<iostream>
#include<vector>
#include<tuple>
#include<unordered_map>

using namespace std;
class Graph{


public:
unordered_map<string,vector<string>> map;
unordered_map<string,vector<string>> graph(vector<tuple<string,string>> list){


 for(auto edge:list){
    auto [a,b]=edge;
    map[a].push_back(b);
    map[b].push_back(a);
 }


 return map;
  
}


//print map 
void printGraph(){
    for (const auto& pair : map) {
        cout << pair.first << ": ";
        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }
        cout << '\n';
    }
}



};



