#include<iostream>
#include<stack>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>


class Topsort{
    std::stack<int> stack;
    std::unordered_set<int> visited;
    std::unordered_map<int,vector<int>> graph;

    public:
    Topsort(std::unordered_map<int,vector<int>> graph):graph(graph){}
    void dfs(int start){
        visited.insert(start);
        for(auto neighbor:graph[start]){
            if(visited.count(neighbor)) return;
            dfs(neighbor);
            stack.push(neighbor);
        }
    }


    void topsort(){
        for(auto node:graph){
            dfs(node.first);
            stack.push(node.first);

        }
    }



    void print(){
        while(!stack.empty()){
        int current=stack.top();
        std::cout<<current<<" ";
        stack.pop();
        }

    }


    //kahn's algorithm

void kahnAlgorithm(){//kahn's algorith is BFS+QUEUE

    //a queue for traversal
     std::queue<int> queue;
    //Array to store the indegree of the edges
     std::unordered_map<int,int> indegree;


     //initialize the array with 0s
    for(auto node:graph){
        indegree[node.first]=0;
    }
    //find the indegree of each node
    for(auto nodes:graph){
        for(auto neighbor:graph[nodes.first]){
            indegree[neighbor]++;
        }
        }

    for (const auto& pair : indegree) {
        std::cout << pair.first << ": "<<pair.second<<endl;
        
    }

    //add the nodes with 0 indegree to the queue
    for (const auto& node : indegree) {
            if (node.second == 0) {
                queue.push(node.first);
            }
        }

     while(!queue.empty()){
         int current=queue.front();
         queue.pop();
         std::cout<<current<<" ";
         for(auto neighbor:graph[current]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                queue.push(neighbor);
            }
         }


     }

    }


};