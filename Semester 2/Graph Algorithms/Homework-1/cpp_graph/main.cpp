#include <iostream>
#include "Graph.h"
#include "Console.h"

int main() {
    Graph g;
    g.read_from_file("/home/kida/year-1/Semester 2/Graph Algorithms/Homework-1/cpp_graph/graph.txt");
    Console c = Console(g);
    c.start();
    return 0;
}
