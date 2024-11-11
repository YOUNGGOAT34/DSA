#include<iostream>
#include<unordered_map>
#include<vector>
#include<limits>

//Edge class
class Edge{
public:
    int destination;
    int weight;

    Edge(int dst,int w):destination(dst),weight(w){}
};

//graph class
class graph{
   std::unordered_map<int,std::vector<Edge>> map;

   public:
     void addEdge(int src,int dst,int weight){
       map[src].push_back(Edge(dst,weight));

       if (map.find(dst) == map.end()) {
            map[dst] = {};  // Initialize the destination node
        }
     }
    
    void BF(int start){
        // int Edges;
        int vertices=map.size();
        std::unordered_map<int,int> distance;//map to track the distance from the start node

        for(auto node:map){
            distance[node.first]=std::numeric_limits<int>::max();

        }

         distance[start]=0;

        for(auto vertex:distance){
            std::cout<<vertex.first<<" "<<vertex.second<<std::endl;
        }

        for(int i=0;i<vertices-1;i++){
            for(auto node:map){
                if(distance[node.first]!=INT_MAX){
                    for(auto edge:map[node.first]){
                        int newDistance=distance[node.first]+edge.weight;
                        if(distance[edge.destination]>newDistance){
                            distance[edge.destination]=newDistance;
                        }
                    }
                }
            }
        }
        
        for(auto node:map){
            for(auto edge:map[node.first]){
                int newDistance=distance[node.first]+edge.weight;
                if(distance[edge.destination]>newDistance) distance[edge.destination]=std::numeric_limits<int>::min();//because this is a negative cycle
            }
        }

        std::cout<<std::endl;
        for(auto vertex:distance){
            std::cout<<vertex.first<<" "<<vertex.second<<std::endl;
        }


    }

     //print the graph

     void print(){
        for(auto node:map){
            std::cout<<node.first<<":";
            for(auto edge:map[node.first]){
                std::cout<<"("<<edge.destination<<","<<edge.weight<<") ";
            }
            std::cout<<std::endl;
        }
      }

};