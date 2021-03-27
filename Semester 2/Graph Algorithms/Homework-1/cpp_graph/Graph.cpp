//
// Created by kida on 3/27/21.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <exception>

void Graph::read_from_file(const std::string &name) {
    std::ifstream new_file;
    new_file.open(name.c_str());
    if(new_file.is_open()){
        int n, m;
        new_file >> n >> m;
        this->nr_of_vertices = n;
        this->nr_of_edges = m;
        while (new_file.peek() != EOF) {
            node node_1, node_2;
            int cost;
            new_file >> node_1 >> node_2 >> cost;
            auto new_edge = std::pair<node, node>(node_1, node_2);
            this->dict_in.insert({node_2, node_1});
            this->dict_out.insert({node_1, node_2});
            this->dict_cost.insert({new_edge, cost});
        }
        new_file.close();
    }
    else {
        throw std::exception();
    }
}

void Graph::write_to_file(const std::string &name) {
    std::fstream new_file;
    new_file.open(name.c_str(), std::ios::out);
    if(new_file.is_open()){
        new_file << std::to_string(this->nr_of_vertices) << " " << std::to_string(this->nr_of_edges) << "\n";
        for(std::pair<edge, int> element : this->dict_cost) {
            new_file << element.first.first << " " << element.first.second << " " << element.second << "\n";
        }
    }
    else {
        throw std::exception();
    }
}

bool Graph::is_edge(node node_1, node node_2) {
    if(this->dict_cost.count(std::pair<node, node>(node_1, node_2)) != 0) {
        return true;
    }
    return false;
}

int Graph::in_degree(node vertex) {
    int degree = 0;
    for(std::pair<node, node> element: this->dict_in) {
        if(element.first == vertex) {
            degree++;
        }
    }
    return degree;
}

int Graph::out_degree(node vertex) {
    int degree = 0;
    for(std::pair<node, node> element: this->dict_out) {
        if(element.first == vertex) {
            degree++;
        }
    }
    return degree;
}
