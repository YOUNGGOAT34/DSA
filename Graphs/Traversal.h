#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <queue>

class Traversal {
    std::unordered_map<std::string, std::vector<std::string>> graph;

public:
    Traversal(std::unordered_map<std::string, std::vector<std::string>> graph);

    // DFS Recursive solution
    bool haspathR(std::string src, std::string dst);
    // Iterative solution
    bool haspathI(std::string src, std::string dst);
    // BFS solution
    bool bfsSolution(std::string src, std::string dst);
};

#endif // TRAVERSAL_H
