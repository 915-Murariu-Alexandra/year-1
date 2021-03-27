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
    std::map<node, std::vector<node>> dict_in;
    std::map<node, std::vector<node>> dict_out;
    std::map<edge, int> dict_cost;
public:
    Graph() = default;

    int get_nr_of_vertices() const { return this->nr_of_vertices; };

    std::map<node, std::vector<node>> get_dict_in() { return this->dict_in; };

    std::map<node, std::vector<node>> get_dict_out() { return this->dict_out; };

    std::map<edge, int> get_dict_cost() { return this->dict_cost; };

    auto get_dict_in_iterator(node vertex) {
        auto it = this->dict_in.at(vertex).begin();
        return it;
    };

    auto get_dict_out_iterator(node vertex) {
        auto it = this->dict_out.at(vertex).begin();
        return it;
    };

    std::map<edge, int>::iterator get_dict_cost_iterator() {
        auto it = this->dict_cost.begin();
        return it;
    };

    void read_from_file(const std::string &);

    void write_to_file(const std::string &);

    bool is_edge(node, node);

    int in_degree(node);

    int out_degree(node);

    void modify_cost(node, node, int);

    void delete_edge(node, node);

    void add_edge(node, node, int);

    void add_node();

    void delete_node(node);

    Graph(const Graph &g) { nr_of_vertices = g.get_nr_of_vertices(), nr_of_edges = g.nr_of_edges, dict_in = g.dict_in,
                            dict_out = g.dict_out, dict_cost = g.dict_cost; };
    static Graph random_graph(int, int);
};


#endif //CPP_GRAPH_GRAPH_H
