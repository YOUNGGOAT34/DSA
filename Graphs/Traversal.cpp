#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<stdbool.h>

// using namespace std;

class Traversal{
std::unordered_map<string,vector<string>> graph;
std::unordered_set<std::string> visited;


 public:
Traversal(unordered_map<std::string,vector<std::string>> graph):graph(graph){}
//DFS
 void iterative(string start){
    std::stack<string> stack;
    stack.push(start);

    while(!stack.empty()){
        std::string current=stack.top();
        std::cout<<current<<" ";
        stack.pop();
      
        for(auto neighbor:graph[current]){
           stack.push(neighbor);

    }
    }

    std::cout<<endl;
    

 }

//recursive soln
 void recursive(string start){
     std::cout<<start<<" ";
     for(auto neighbor:graph[start]){
        recursive(neighbor);
     }
 }

 //BFS
void BFS(string start){
   std::queue<string> queue;
   queue.push(start);
   while(!queue.empty()){
      string current=queue.front();
      cout<<current<<" ";
       queue.pop();
       for(auto neighbor:graph[current]){
         queue.push(neighbor);
       }

   }
}

//has path
//1.Dfs
//1.1.Recursive soln
bool haspathR(string src,string dst){//R for recursive,src-source,dst-destination.
    if(src==dst) return true;
    for(auto neighbor:graph[src]){
        if(haspathR(neighbor,dst)) return true;
    }

    return false;
}

//1.2 iterative solution
bool haspathI(string src,string dst){//I for iterative,
   std::stack<string> stack;
   stack.push(src);
   while(!stack.empty()){
      string current=stack.top();
      stack.pop();
      if(current==dst) return true;
      for(auto neighbor:graph[current]){
         stack.push(neighbor);
      }
   }

   return false;
}

//BFS
bool bfsSolution(string src,string dst){
    std::queue<string> queue;
    queue.push(src);
    while(!queue.empty()){
      string current=queue.front();
      queue.pop();
      if(current==dst) return true;
      for(auto neighbor:graph[current]) queue.push(neighbor);
    }

    return false;
}


//Undirected path
//1. DFS
//1.1 recursive soln
bool undirectedPathRecursive(string src,string dst){
if (src==dst) return true;   
if(visited.count(src))   return false; 
visited.insert(src);
for(auto neighbor:graph[src]){
   if(undirectedPathRecursive(neighbor,dst)) return true;
}
return false;
}

//1.2 iterative solution
bool undirectedPathIterative(std::string src,std::string dst){
   std::stack<std::string> stack;
   stack.push(src);
   while(!stack.empty()){
      std::string current=stack.top();
      if(current==dst) return true;
      if(visited.count(current)) continue;
      visited.insert(current);
      stack.pop();
      for(auto neighbor:graph[current]){
         stack.push(neighbor);
      }

   }

   return false;
}



//connected component count
//1.dfs 
//1.1 recursive soln

bool connectedComponentsCount(std::string node,std::unordered_set<std::string> &visited){
   if(visited.count(node)) return false;
   visited.insert(node);
   for(auto neighbor:graph[node]){
     
      connectedComponentsCount(neighbor,visited);
   }

   return true;
}

int connectedComponent(){
int count=0;
for(auto node:graph){
   
   if(connectedComponentsCount(node.first,visited)) count++;   
}                        
   return count;                
}

//1.2 Iterative soln.
bool connected(std::string node,std::stack<std::string> stack,std::unordered_set<std::string> &visited){
    if(visited.count(node)) return false;
    stack.push(node);
    while(!stack.empty()){
       std::string current=stack.top();
       stack.pop();
       visited.insert(current);

       for(auto neighbor:graph[current]){
         if (!visited.count(neighbor))
            stack.push(neighbor);
       }

    }

    return true;

}
int connected(){
   std::unordered_set<std::string> visited;
   std::stack<std::string> stack;
   int count=0;

   for(auto node:graph){
       if(connected(node.first,stack,visited)) count++;
   }

   return count;
}

//largest component count

int largestComponent(std::string node,std::unordered_set<std::string> &visited){
    if(visited.count(node)) return 0;
    visited.insert(node);
    int count=1;
    for(auto neighbor:graph[node]){
      count +=largestComponent(neighbor,visited);
    }

    return count;
}

int largestComponent(){
  int largest=INT_MIN;
  
  std::unordered_set<std::string> visited;
  for(auto node :graph){
     int size=largestComponent(node.first,visited);
     if(size>largest) largest=size;
  }

   return largest;
}





};