//
// Created by kida on 3/27/21.
//

#include <iostream>
#include <fstream>
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
    GET_COST = 'n',
    WRITE_TO_FILE = 'o',
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
    cout << "n. Get the cost of an existing edge.\n";
    cout << "o. Write to file.\n";
    cout << "x. Exit the application.\n";
}

bool Console::read_options() {
    unsigned char option;
    print_menu();
    cout <<"Please input your option: ";
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
    std::pair<std::vector<node>::iterator, std::vector<node>::iterator> inbound_iterator;
    std::pair<std::vector<node>::iterator, std::vector<node>::iterator> outbound_iterator;
    Graph h;
    std::string name_of_file;
    std::string file_name;
    switch (option) {
        case EXIT:
            //graph.write_to_file("/home/kida/year-1/Semester 2/Graph Algorithms/Homework-1/cpp_graph/graph1k_modif.txt");
            return false;
        case GET_NR_OF_VERTICES:
            print_graph(graph);
            cout << "\nThe number of vertices is: " << this->graph.get_nr_of_vertices();
            return true;
        case PARSE_SET_OF_VERTICES:
            for (; vertices_iterator.first != vertices_iterator.second;) {
                cout << vertices_iterator.first->first << " ";
                ++vertices_iterator.first;
            }
            return true;
        case PARSE_INBOUND_EDGES:
            node vertex;
            cout << "What is the node you wish to parse?\n";
            cin >> vertex;
            if(!graph.is_vertex(vertex)){
                cout << "The vertex is invalid.\n";
                return true;
            }
            try{
                inbound_iterator = graph.get_dict_in_iterator(vertex);
                for(; inbound_iterator.first != inbound_iterator.second;){
                    cout << *inbound_iterator.first << " " << vertex << "\n";
                    ++inbound_iterator.first;
                }
            }
            catch(std::out_of_range){
                cout << "The vertex doesn't have inbound neighbors.\n";
                return true;
            }
            return true;
        case PARSE_OUTBOUND_EDGES:
            cout << "What is the node you wish to parse?\n";
            cin >> vertex;
            if(!graph.is_vertex(vertex)){
                cout << "The vertex is invalid.\n";
                return true;
            }
            try{
                outbound_iterator = graph.get_dict_out_iterator(vertex);
                for(; outbound_iterator.first != outbound_iterator.second;){
                    cout << vertex << " " << *outbound_iterator.first << "\n";
                    ++outbound_iterator.first;
                }
            }
            catch(std::out_of_range){
                cout << "The vertex doesn't have outbound edges.\n";
                return true;
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
                cout << "\nThis is an edge!\n";
            } else {
                cout << "\nThis is not an edge!";
            }
            return true;
        case GET_COST:
            cout << "What is the first vertex of the edge?\n";
            cin >> node_1;
            cout << "What is the second vertex of the edge?\n";
            cin >> node_2;
            print_graph(graph);
            try{
                cout << "\nThe cost of the edge is: " << graph.get_cost(node_1, node_2) << "\n";
            }
            catch(std::runtime_error){
                cout << "The edge doesn't exist.\n";
                return true;
            }
            return true;
        case GET_DEGREE:
            cout << "What is the vertex?\n";
            cin >> vertex;
            if (!graph.is_vertex(vertex)) {
                cout << "The node doesn't exist.";
                return true;
            } else {
                print_graph(graph);
                cout << "\nThe in-degree is: " << graph.in_degree(vertex) << " and the out-degree is "
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
            cout << "What is the cost of the new edge?\n";
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
            cout << "What is the index of the node you wish to add?\n";
            cin >> vertex;
            try{
                graph.add_node(vertex);
                cout << "An additional node was successfully added!\n";
            }
            catch(std::runtime_error){
                cout << "The vertex you wish to add already exists, or is invalid. Please try again.\n";
                return true;
            }

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
            cout << "What will the new file be called?\n";
            cin >> file_name;
            try{
                h = Graph::random_graph(n, m);
                h.write_to_file("/home/kida/year-1/Semester 2/Graph Algorithms/Homework-1/cpp_graph/" + file_name);
            }
            catch(std::runtime_error){
                cout << "This graph cannot be created.\n";
                std::fstream file;
                file.open(("/home/kida/year-1/Semester 2/Graph Algorithms/Homework-1/cpp_graph/" + file_name).c_str(), std::ios::out);
                if (file.is_open()) {
                    file << "This graph cannot be created.\n";
                }
                return true;
            }
            print_graph(h);
            return true;
        case WRITE_TO_FILE:
            cout << "What file do you wish to read the graph from?\n";
            cin >> file_name;
            this->graph.write_to_file("../" + file_name);
            return true;
        default:
            printf("Option is incorrect. PLease try again!\n");
            return true;
    }
}

void Console::start() {
    string file_name;
    cout << "What file do you wish to read the graph from?\n";
    //this->graph.read_from_file("../graph.txt");
    cin >> file_name;
    this->graph.read_from_file("../" + file_name);
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
    for (std::pair<node, node> v : h.get_vertices()) {
        cout << v.first << " ";
    }
}
