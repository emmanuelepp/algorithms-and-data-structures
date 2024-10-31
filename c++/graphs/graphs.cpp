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

    bool addEdge(std::string vertex1, std::string vertex2)
    {
        if (adjacencyList.count(vertex1) != 0 && adjacencyList.count(vertex2) != 0)
        {
            adjacencyList.at(vertex1).insert(vertex2);
            adjacencyList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }
};

int main()
{
    Graph graph;

    graph.addVertex("A");
    graph.addVertex("B");
    graph.printGraph();
    graph.addEdge("A", "B");
    graph.printGraph();

    return 0;
}
