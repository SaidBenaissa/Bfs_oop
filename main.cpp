#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph {
public:
    // Constructor to initialize the adjacency list with the given number of vertices
    Graph(int vertices) : adjacency_list(vertices) {}

    // Function to add an undirected edge between nodes (vertices) u and v
    void add_edge(int u, int v) {
        // Add vertex v to the adjacency list of vertex u
        adjacency_list[u].push_back(v);
        // Add vertex u to the adjacency list of vertex v (since the graph is undirected)
        adjacency_list[v].push_back(u);
    }

    // Function to perform BFS traversal starting from a given node
    void bfs(int start_node) {
        // Create a visited vector to keep track of visited nodes, initially all set to false
        std::vector<bool> visited(adjacency_list.size(), false);
        // Create a queue for BFS traversal
        std::queue<int> queue;

        // Mark the starting node as visited and enqueue it
        visited[start_node] = true;
        queue.push(start_node);

        // Iterate through the queue while it's not empty
        while (!queue.empty()) {
            // Dequeue the next node from the queue
            int current_node = queue.front();
            queue.pop();

            // Print the current node as part of the BFS traversal
            std::cout << current_node << " -> ";

            // Iterate through the neighbors of the current node
            for (int neighbor : adjacency_list[current_node]) {
                // If a neighbor hasn't been visited, mark it as visited and enqueue it
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
    }

private:
    // The adjacency list representation of the graph, using a vector of lists
    std::vector<std::list<int>> adjacency_list;
};

int main() {
    // Create a graph with 7 vertices (numbered 0 through 6)
    Graph g(7);

    // Add edges to the graph
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 5);
    g.add_edge(2, 6);

    // Perform BFS traversal starting from vertex 0
    std::cout << "BFS Traversal: " << std::endl;
    g.bfs(0);  // Output: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6

    return 0;
}
