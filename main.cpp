#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include<stack>
#include <climits>
#include <string> // For strlen
#include "Graphs/BF.cpp"
#include<cmath>
#include<list>
#include <algorithm> 
#include <sstream>



int main() {

std::vector<int> temp{73,74,75,71,69,72,76,73};
std::vector<int> result(temp.size(),0);
std::stack<std::pair<int,int>> stack;

stack.push({temp[0],0});

for(int i=1;i<temp.size();i++){
     
    while(!stack.empty()&&temp[i]>stack.top().first){
            result[stack.top().second]=i-stack.top().second;
            stack.pop();
    }
    stack.push({temp[i],i});

}
for(auto p:result){
   std::cout<<p<<std::endl;
}

return 0;
}






