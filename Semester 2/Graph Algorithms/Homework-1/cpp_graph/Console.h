//
// Created by kida on 3/27/21.
//

#ifndef CPP_GRAPH_CONSOLE_H
#define CPP_GRAPH_CONSOLE_H


#include "Graph.h"

class Console {
private:
    Graph graph;
public:
    Console() = default;
    explicit Console(Graph& g) : graph(g) {};
    static void print_menu();
    bool read_options();
    void start();
    bool tryParse(std::string &input, int &output);
    void print_graph(Graph);
};


#endif //CPP_GRAPH_CONSOLE_H
