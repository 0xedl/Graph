#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Graph
{
   private:
      // Graph structure that supports parallel edges and self-loops
      std::map<int, std::vector<std::pair<int,int>>> graph;

    public:
      void insertEdge(int from, int to, int weight);  
      bool isEdge(int from, int to);  
      int sumEdge(int from, int to); 
      std::vector<int> getWeight(int from, int to); 
      std::vector<int> getAdjacent(int vertex); 
};

void Graph::insertEdge(int from, int to, int weight) 
{
   graph[from].push_back(std::make_pair(to, weight));
   if (graph.find(to) == graph.end())
        graph[to] = {};
}
        
bool Graph::isEdge(int from, int to) 
{
    if (graph.find(from) != graph.end()) {
        for (const auto &pair : graph[from]) {
            if (pair.first == to) {
                return true;
            }
        }
    }
    return false;
}

int Graph::sumEdge(int from, int to)
{
    int sum = 0;
    std::vector<int> weights = getWeight(from, to);
    for (auto i : weights)
        sum += i;

    return sum;
}

std::vector<int> Graph::getWeight(int from, int to)
{
    std::vector<int> weights;
    if (graph.find(from) != graph.end()) {
        for (auto &pair : graph[from]) {
            if (pair.first == to) {
                weights.push_back(pair.second);
            }
        }
    }
    std::sort(weights.begin(), weights.end());
    return weights;
}

std::vector<int> Graph::getAdjacent(int vertex) 
{
    std::vector<int> adjacent;
    if (graph.find(vertex) != graph.end()) {
        for (auto &pair : graph[vertex]) {
            adjacent.push_back(pair.first);
        }
    }
    std::sort(adjacent.begin(), adjacent.end());
    return adjacent;
}
