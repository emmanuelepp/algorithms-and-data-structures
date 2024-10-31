#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class Graph
{
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjacencyList;

public:
    void printGraph() const
    {
        for (const auto &[vertex, edges] : adjacencyList)
        {
            std::cout << vertex << ": [";
            for (const auto &edge : edges)
            {
                std::cout << edge << " ";
            }
            std::cout << "]" << std::endl;
        }
    }

    bool addVertex(const std::string &vertex)
    {
        if (adjacencyList.count(vertex) == 0)
        {
            adjacencyList[vertex];
            return true;
        }
        return false;
    }
};

int main()
{
    Graph graph;

    graph.addVertex("A");
    graph.printGraph();

    return 0;
}
