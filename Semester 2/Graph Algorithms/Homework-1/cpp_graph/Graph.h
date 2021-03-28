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
    std::vector<node> vertices;
public:
    Graph() = default;

    int get_nr_of_vertices() const { return this->nr_of_vertices; };
    int get_nr_of_edges() const { return this->nr_of_edges;};

    std::map<node, std::vector<node>> get_dict_in() { return this->dict_in; };

    std::map<node, std::vector<node>> get_dict_out() { return this->dict_out; };

    std::vector<node> get_vertices() { return this->vertices;};

    std::map<edge, int> get_dict_cost() { return this->dict_cost; };

    auto get_dict_in_iterator(node vertex) {
        auto it_begin = this->dict_in.at(vertex).begin();
        auto it_end = this->dict_in.at(vertex).end();
        return std::pair<std::vector<node>::iterator, std::vector<node>::iterator>(it_begin, it_end);
    };

    auto get_dict_out_iterator(node vertex) {

        auto it_begin = this->dict_out.at(vertex).begin();
        auto it_end = this->dict_out.at(vertex).end();
        return std::pair<std::vector<node>::iterator, std::vector<node>::iterator>(it_begin, it_end);

    };

    std::map<edge, int>::iterator get_dict_cost_iterator() {
        auto it = this->dict_cost.begin();
        return it;
    };

    auto get_vertices_iterator() {
        auto it_begin = this->vertices.begin();
        auto it_end = this->vertices.end();
        return std::pair<std::vector<node>::iterator, std::vector<node>::iterator>(it_begin, it_end);
    }

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
                            dict_out = g.dict_out, dict_cost = g.dict_cost, vertices = g.vertices; };
    static Graph random_graph(int, int);
    bool is_vertex(node);
};


#endif //CPP_GRAPH_GRAPH_H
