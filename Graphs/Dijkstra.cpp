#include<iostream>
#include<vector>
#include <limits>
#include<unordered_map>
#include <utility>
#include <functional>
#include<queue>



class Edge{
     

      public:
      int weight;
      int destination;
      Edge(int dst,int weight):weight(weight),destination(dst){}
};

class graph{
      std::unordered_map<int,std::vector<Edge>> map;
      std::unordered_map<int,int> path;

     

      public:
      void addEdge(int src,int dst,int weight){
          map[src].push_back(Edge(dst,weight));
          if (map.find(dst) == map.end()) {
            map[dst] = {};  // Initialize the destination node
        }
      }

    void dijkstra(int start){
        for(auto node:map){
         path[node.first]=INT_MAX;
      }

      for(auto node:path){
        std::cout<<node.first<<":"<<node.second<<std::endl;
      }

     std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq; //pq-priority queue
     path[start]=0;
     pq.push({0,start});

     while(!pq.empty()){
        auto [currentWeight,currentNode]=pq.top();
        pq.pop();
        // std::cout<<currentNode<<" "<<currentWeight<<std::endl;
        if(path[currentNode]!=INT_MAX){
            
            for(auto edge:map[currentNode]){
                int dist=currentWeight+edge.weight;
                if(dist<path[edge.destination])  {
                    path[edge.destination]=dist;
                    pq.push({dist,edge.destination});
                }
                
            }
        }
     }

      for(auto node:path){
        std::cout<<node.first<<":"<<node.second<<std::endl;
      }
}

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




/*
movie_votes = {}

while true:
    movie = get_user_input()
    if movie == '-1':
        break
    if movie not in movie_votes:
        movie_votes[movie] = 1
    else:
        movie_votes[movie] += 1

max_votes = max(movie_votes.values())
most_popular_movies = [movie for movie, count in movie_votes.items() if count == max_votes]

print "Voting Results:"
for movie, count in movie_votes.items():
    print movie, ":", count

if len(most_popular_movies) > 1:
    print "It's a tie! Most Popular Movies:", ", ".join(most_popular_movies)
else:
    print "The most popular movie is:", most_popular_movies[0]

  

*/