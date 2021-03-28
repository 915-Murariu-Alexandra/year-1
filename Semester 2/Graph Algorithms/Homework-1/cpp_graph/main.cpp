#include <iostream>
#include "Graph.h"
#include "Console.h"

int main() {
    Graph g;
    g.read_from_file("/home/kida/year-1/Semester 2/Graph Algorithms/Homework-1/cpp_graph/graph.txt");
    Console c = Console(g);
    /*g.delete_node(2);
    Graph h = Graph(g);
    h.add_edge(1, 4, 5);
    Graph random_graph = Graph::random_graph(5, 7);
    random_graph.write_to_file("/home/kida/year-1/Semester 2/Graph Algorithms/Homework-1/cpp_graph/graphTO.txt");*/
    c.start();
    return 0;
}
