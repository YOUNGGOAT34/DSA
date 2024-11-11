#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include <climits>

class Edge{
    public:
    std::string destination;
    int weight;
    Edge(std::string destination,int weight):destination(destination),weight(weight) {}

};


class Graph{
   std::unordered_map<std::string,std::vector<Edge>> map;

   public:
   Graph(){}
    void addEdge(std::string src,std::string destination,int weight){
        map[src].push_back(Edge(destination,weight));
    }
    
    void print(){
        for(auto node:map){
            std::cout<<node.first<<": ";
            for(auto edge:map[node.first]){
                std::cout<<"("<<edge.destination<<","<<edge.weight<<") ";
            }

            std::cout<<std::endl;
        }
    }


     //sort the graph using kahn's algorithm
 std::queue<std::string> sort(){//kahn's algorith is BFS+QUEUE

    //a queue for traversal
     std::queue<std::string> queue;
     std::queue<std::string> q;
    //Array to store the indegree of the edges
     std::unordered_map<std::string,int> indegree;


     //initialize the array with 0s
    for(auto node:map){
        indegree[node.first];
    }
    //find the indegree of each node
    for(auto nodes:map){
        for(Edge neighbor:map[nodes.first]){
            indegree[neighbor.destination]++;
        }
        }

   

    //add the nodes with 0 indegree to the queue
    for (const auto& node : indegree) {
            if (node.second == 0) {
                queue.push(node.first);
                q.push(node.first);
            }
        }

     while(!queue.empty()){
         std::string current=queue.front();
         queue.pop();
         std::cout<<current<<" ";
         for(auto neighbor:map[current]){
            indegree[neighbor.destination]--;
            if(indegree[neighbor.destination]==0){
                queue.push(neighbor.destination);
                q.push(neighbor.destination);
            }
         }


     }

     std::cout<<std::endl
;

     return q;

    }



 void sssp(std::string start){
        std::unordered_map<std::string,int> path;
        std::queue<std::string> queue=sort();
        std::queue<std::string> q=sort();
       
      
        while(!queue.empty()){
            std::string current=queue.front();
            queue.pop();
            path[current]=INT_MAX;  
        }

       //Set the start node distance to 0
        path[start] = 0;

        // Get the topologically sorted nodes
       
       
        // Relax edges in topological order
         while (!q.empty()) {
        std::string current = q.front();
        q.pop();
        

        if (path[current] != INT_MAX) {
            for (const auto& edge : map[current]) {
                if (path[current] + edge.weight < path[edge.destination]) {
                    path[edge.destination] = path[current] + edge.weight;
                }
            }
        }
    }

        for (const auto& pair : path) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }


    }

};

