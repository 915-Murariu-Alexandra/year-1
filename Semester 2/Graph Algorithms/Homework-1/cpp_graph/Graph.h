//
// Created by kida on 3/27/21.
//

#ifndef CPP_GRAPH_GRAPH_H
#define CPP_GRAPH_GRAPH_H

#include <utility>
#include <vector>
#include <map>
#include <string>

typedef int node;
typedef std::pair<node, node> edge;
class Graph {
private:
    int nr_of_vertices{};
    int nr_of_edges{};
    std::multimap<node, node> dict_in;
    std::multimap<node, node> dict_out;
    std::map<edge, int> dict_cost;
public:
    Graph() = default;
    int get_nr_of_vertices() const {return this->nr_of_vertices;};
    std::multimap<node, node> get_dict_in() {return this->dict_in;};
    std::multimap<node, node> get_dict_out() {return this->dict_out;};
    std::map<edge, int> get_dict_cost() {return this->dict_cost;};
    std::map<node, node>::iterator get_dict_in_iterator(){auto it = this->dict_in.begin();return it;};
    std::map<node, node>::iterator get_dict_out_iterator(){auto it = this->dict_out.begin();return it;};
    std::map<edge, int>::iterator get_dict_cost_iterator(){auto it = this->dict_cost.begin();return it;};
    void read_from_file(const std::string&);
    void write_to_file(const std::string&);
    bool is_edge(node, node);
    int in_degree(node);
    int out_degree(node);
};


#endif //CPP_GRAPH_GRAPH_H
