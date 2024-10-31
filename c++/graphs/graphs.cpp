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

    bool removeEdge(std::string vertex1, std::string vertex2)
    {
        if (adjacencyList.count(vertex1) != 0 && adjacencyList.count(vertex2) != 0)
        {
            adjacencyList.at(vertex1).erase(vertex2);
            adjacencyList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }

    bool removeVertex(std::string vertex)
    {
        if (adjacencyList.count(vertex) == 0)
            return false;
        for (auto otherVertex : adjacencyList.at(vertex))
        {
            adjacencyList.at(otherVertex).erase(vertex);
        }
        adjacencyList.erase(vertex);
        return true;
    }
};

int main()
{
    Graph graph;

    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");

    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("A", "D");
    graph.addEdge("B", "D");
    graph.addEdge("C", "D");
    graph.printGraph();

    return 0;
}
