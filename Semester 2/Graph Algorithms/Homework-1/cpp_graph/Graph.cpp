//
// Created by kida on 3/27/21.
//
#define MAX_COST 20

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <random>

void Graph::read_from_file(const std::string &name) {
    std::ifstream new_file;
    new_file.open(name.c_str());
    if (new_file.is_open()) {
        int n, m;
        new_file >> n >> m;
        this->nr_of_vertices = n;
        this->nr_of_edges = m;
        while (new_file.peek() != EOF) {
            node node_1, node_2;
            int cost;
            new_file >> node_1 >> node_2 >> cost;
            auto new_edge = std::pair<node, node>(node_1, node_2);
            this->dict_in[node_2].push_back(node_1);
            this->dict_out[node_1].push_back(node_2);
            this->dict_cost.insert({new_edge, cost});
        }
        for (int i = 0; i < n; i++) {
            this->vertices.insert({i, i});
        }
        new_file.close();
    } else {
        throw std::runtime_error("The file doesn't exist");
    }
}

void Graph::write_to_file(const std::string &name) {
    std::fstream new_file;
    new_file.open(name.c_str(), std::ios::out);
    if (new_file.is_open()) {
        new_file << std::to_string(this->nr_of_vertices) << " " << std::to_string(this->nr_of_edges) << "\n";
        for (std::pair<edge, int> element : this->dict_cost) {
            new_file << element.first.first << " " << element.first.second << " " << element.second << "\n";
        }
        new_file << "Remaining vertices are: ";
        for (std::pair<node, node> vertex : this->vertices) {
            new_file << vertex.first << " ";
        }
    } else {
        throw std::runtime_error("The file couldn't be opened");
    }
}

bool Graph::is_edge(node node_1, node node_2) {
    if (this->dict_cost.count(std::pair<node, node>(node_1, node_2)) != 0) {
        return true;
    }
    return false;
}

int Graph::in_degree(node vertex) {
    if(!is_vertex(vertex)){
        throw std::runtime_error("The vertex doesn't exist.");
    }
    if (dict_in.count(vertex) != 0) {
        return dict_in.at(vertex).size();
    }
    return 0;
}

int Graph::out_degree(node vertex) {
    if(!is_vertex(vertex)){
        throw std::runtime_error("The vertex doesn't exist.");
    }
    if (dict_out.count(vertex) != 0) {
        return dict_out.at(vertex).size();
    }
    return 0;
}

void Graph::modify_cost(node node_1, node node_2, int new_cost) {
    if (!is_edge(node_1, node_2)) {
        throw std::runtime_error("The edge doesn't exist");
    } else {
        this->dict_cost[std::pair<node, node>(node_1, node_2)] = new_cost;
    }
}

void Graph::delete_edge(node node_1, node node_2) {
    if (!is_edge(node_1, node_2)) {
        throw std::runtime_error("The edge doesn't exist");
    } else {
        this->dict_cost.erase(std::pair<node, node>(node_1, node_2));
        for (auto it = this->dict_in[node_2].begin(); it != this->dict_in[node_2].end(); ++it) {
            if (*it == node_1) {
                this->dict_in[node_2].erase(it);
                it--;
            }
        }
        for (auto it = this->dict_out[node_1].begin(); it != this->dict_out[node_1].end(); ++it) {
            if (*it == node_2) {
                this->dict_out[node_1].erase(it);
                it--;
            }
        }
        this->nr_of_edges--;
    }
}

void Graph::add_edge(node node_1, node node_2, int cost) {
    if (is_edge(node_1, node_2)) {
        throw std::runtime_error("The edge already exists");
    } else if (node_1 < 0 || node_2 < 0 || !is_vertex(node_1) || !is_vertex(node_2)) {
        throw std::runtime_error("The vertices are invalid");
    } else {
        this->dict_cost.insert({std::pair<node, node>(node_1, node_2), cost});
        this->dict_in[node_2].push_back(node_1);
        this->dict_out[node_1].push_back(node_2);
    }
}

void Graph::add_node(node vertex) {
    if(!is_vertex(vertex)){
        this->vertices.insert({vertex, vertex});
        this->nr_of_vertices += 1;
    }
    else {
        throw std::runtime_error("The node already exists.\n");
    }
}

void Graph::delete_node(node vertex) {
    bool found = false;
    if(is_vertex(vertex)){
        found = true;
    }
    if (vertex < 0 || !found) {
        throw std::runtime_error("The vertex to remove is not valid.");
    } else {
        this->dict_out[vertex].clear();
        this->nr_of_vertices--;
        this->dict_in[vertex].clear();

        for (auto it = this->dict_cost.begin(); it != this->dict_cost.end();) {
            if (it->first.first == vertex || it->first.second == vertex) {
                it = this->dict_cost.erase(it);
                this->nr_of_edges--;
            } else {
                ++it;
            }
        }
        this->vertices.erase(vertex);
        }
    }


Graph Graph::random_graph(int n, int m) {
    Graph g;
    node node_1, node_2;
    unsigned int cost;
    g.nr_of_vertices = n;
    g.nr_of_edges = m;
    for(int i = 0; i < n; i++) {
        g.vertices.insert({i, i});
    }
    if (m > n * (n - 1)) {
        throw std::runtime_error("Such a graph cannot be composed.");
    }
    while (m > 0) {
        std::random_device rd;
        node_1 = rd() % n;
        node_2 = rd() % n;
        cost = rd() % MAX_COST;
        if (!g.is_edge(node_1, node_2) && node_1 != node_2)  {
            g.add_edge(node_1, node_2, cost);
            m--;
        }
    }
    return g;
}

bool Graph::is_vertex(node vertex) {
    if (this->vertices.count(vertex) != 0) {
        return true;
    }
    return false;
}

int Graph::get_cost(node node_1, node node_2) {
    if(!is_edge(node_1, node_2)){
        throw std::runtime_error("The edge doesn't exist.");
    }
    else {
        return this->dict_cost[std::pair<node, node>(node_1, node_2)];
    }
}


