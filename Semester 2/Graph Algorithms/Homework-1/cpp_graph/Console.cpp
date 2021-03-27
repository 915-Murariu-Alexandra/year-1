//
// Created by kida on 3/27/21.
//

#include <iostream>
#include "Console.h"

using namespace std;

enum option {
    GET_NR_OF_VERTICES = 'a',
    PARSE_SET_OF_VERTICES = 'b',
    FIND_IF_EDGE_EXISTS = 'c',
    GET_DEGREE = 'd',
    PARSE_OUTBOUND_EDGES = 'e',
    PARSE_INBOUND_EDGES = 'f',
    MODIFY_COST = 'g',
    ADD_EDGE = 'h',
    REMOVE_EDGE = 'i',
    ADD_NODE = 'j',
    REMOVE_NODE = 'k',
    MAKE_COPY = 'l',
    RANDOM_GRAPH = 'm',
    EXIT = 'x'
};

void Console::print_menu() {
    cout << "\na. Get the number of vertices.\n";
    cout << "b. Parse the set of vertices.\n";
    cout << "c. Find if an edge exists.\n";
    cout << "d. Get the in-degree and out-degree of a vertex.\n";
    cout << "e. Parse the set of outbound edges of a vertex.\n";
    cout << "f. Parse the set of inbound edges of a vertex.\n";
    cout << "g. Modify the cost of an edge.\n";
    cout << "h. Add an edge.\n";
    cout << "i. Remove an edge.\n";
    cout << "j. Add a node.\n";
    cout << "k. Remove a node.\n";
    cout << "l. Make a copy of the graph.\n";
    cout << "m. Create a random graph.\n";
    cout << "x. Exit the application.\n";
}

bool Console::read_options() {
    unsigned char option;
    print_menu();
    printf("Please input your option: ");
    option = getchar();

    if (option == '\n') {
        option = getchar();
    }

    if (getchar() != '\n') {
        while (getchar() != '\n');
        printf("Input should be a single character, please try again!\n");
        return true;
    }
    auto vertices_iterator = graph.get_vertices_iterator();
    Graph h;
    std::string name_of_file;
    switch (option) {
        case EXIT:
            return false;
        case GET_NR_OF_VERTICES:
            print_graph(graph);
            cout << this->graph.get_nr_of_vertices();
            return true;
        case PARSE_SET_OF_VERTICES:
            for (; vertices_iterator.first != vertices_iterator.second;) {
                cout << *vertices_iterator.first << " ";
                ++vertices_iterator.first;
            }
            return true;
        case FIND_IF_EDGE_EXISTS:
            node node_1, node_2;
            cout << "What is the first vertex of the edge?\n";
            cin >> node_1;
            cout << "What is the second vertex of the edge?\n";
            cin >> node_2;
            print_graph(graph);
            if (graph.is_edge(node_1, node_2)) {
                cout << "This is an edge!\n";
            } else {
                cout << "This is not an edge!";
            }
            return true;
        case GET_DEGREE:
            node vertex;
            cout << "What is the vertex?\n";
            cin >> vertex;
            if (!graph.is_vertex(vertex)) {
                cout << "The node doesn't exist.";
                return true;
            } else {
                print_graph(graph);
                cout << "The in-degree is: " << graph.in_degree(vertex) << " and the out-degree is "
                     << graph.out_degree(vertex);
                return true;
            }
        case MODIFY_COST:
            int cost;
            cout << "What is the first vertex of the edge?\n";
            cin >> node_1;
            cout << "What is the second vertex of the edge?\n";
            cin >> node_2;
            cout << "What is the new cost?\n";
            cin >> cost;
            try {
                graph.modify_cost(node_1, node_2, cost);
                cout << "The edge cost was successfully modified!\n";
            }
            catch(std::runtime_error){
                cout << "The edge doesn't exist";
            }
            print_graph(graph);
            return true;
        case ADD_EDGE:
            cout << "What is the first vertex of the edge?\n";
            cin >> node_1;
            cout << "What is the second vertex of the edge?\n";
            cin >> node_2;
            cout << "What is the new cost?\n";
            cin >> cost;
            try {
                graph.add_edge(node_1, node_2, cost);
                cout << "Edge was successfully added!\n";
            }
            catch(std::runtime_error){
                cout << "The edge is invalid.";
                return true;
            }
            print_graph(graph);
            return true;
        case REMOVE_EDGE:
            cout << "What is the first vertex of the edge?\n";
            cin >> node_1;
            cout << "What is the second vertex of the edge?\n";
            cin >> node_2;
            try{
                graph.delete_edge(node_1, node_2);
                cout << "The edge was successfully removed!\n";
            }
            catch(std::runtime_error){
                cout << "The edge doesn't exist.";
                return true;
            }
            print_graph(graph);
            return true;
        case ADD_NODE:
            graph.add_node();
            cout << "An additional node was successfully added!\n";
            return true;
        case REMOVE_NODE:
            cout << "What is the node you wish to remove?\n";
            cin >> vertex;
            try{
                graph.delete_node(vertex);
                cout << "Node was successfully removed!\n";
            }
            catch(std::runtime_error){
                cout << "The node doesn't exist.\n";
                return true;
            }
            print_graph(graph);
            return true;
        case MAKE_COPY:
            h = Graph(graph);
            print_graph(h);
            return true;
        case RANDOM_GRAPH:
            int n, m;
            cout << "What is the number of vertices?\n";
            cin >> n;
            cout << "What is the number of edges?\n";
            cin >> m;
            try{
                h = Graph::random_graph(n, m);
            }
            catch(std::runtime_error){
                cout << "This graph cannot be created.\n";
                return true;
            }
            print_graph(h);
            return true;
        default:
            printf("Option is incorrect. PLease try again!\n");
            return true;
    }
}

void Console::start() {
    while (this->read_options());
}


bool Console::tryParse(std::string &input, int &output) {
    try {
        output = std::stoi(input);
    } catch (std::invalid_argument) {
        return false;
    }
    return true;
}

void Console::print_graph(Graph h) {
    cout << std::to_string(h.get_nr_of_vertices()) << " " << std::to_string(h.get_nr_of_edges()) << "\n";
    for (std::pair<edge, int> element : h.get_dict_cost()) {
        cout << element.first.first << " " << element.first.second << " " << element.second << "\n";
    }
    cout << "Remaining vertices are: ";
    for (node v : h.get_vertices()) {
        cout << v << " ";
    }
}
