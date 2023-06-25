#include <iostream>
#include <vector>
#include <string>

class Graph {
private:
    std::vector<std::string> vertices;
    std::vector<std::vector<std::string>> adjacencyList;

public:
    Graph() {}

    void addVertex(const std::string& vertex) {
        vertices.push_back(vertex);
        adjacencyList.push_back(std::vector<std::string>());
    }

    void addEdge(const std::string& src, const std::string& dest) {
        int srcIndex = getIndex(src);
        int destIndex = getIndex(dest);

        if (srcIndex != -1 && destIndex != -1) {
            adjacencyList[srcIndex].push_back(dest);
            adjacencyList[destIndex].push_back(src); // Si el grafo es no dirigido
        }
    }

    int getIndex(const std::string& vertex) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] == vertex) {
                return i;
            }
        }
        return -1; // Si el vértice no existe en el grafo
    }

    void printGraph() {
        for (int i = 0; i < vertices.size(); i++) {
            std::cout << "Conexiones de " << vertices[i] << ": ";
            for (const std::string& neighbor : adjacencyList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};