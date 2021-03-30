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

/**
 * Directed Graph class with 3 maps.
 */
class Graph {
private:
    int nr_of_vertices{};
    int nr_of_edges{};
    std::map<node, std::vector<node>> dict_in;
    std::map<node, std::vector<node>> dict_out;
    std::map<edge, int> dict_cost;
    std::map<node, node> vertices;
public:
    Graph() = default;

    int get_nr_of_vertices() const { return this->nr_of_vertices; };
    int get_nr_of_edges() const { return this->nr_of_edges;};

    std::map<node, std::vector<node>> get_dict_in() { return this->dict_in; };

    std::map<node, std::vector<node>> get_dict_out() { return this->dict_out; };

    std::map<node, node> get_vertices() { return this->vertices;};

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
        return std::pair<std::map<node, node>::iterator, std::map<node, node>::iterator>(it_begin, it_end);
    }

    /**
     * Function that reads a graph from a file.
     * @throw if file doesn't exist
     *
     * Theta(n)
     */
    void read_from_file(const std::string &);

    /**
     * Function that writes a graph to a given file.
     * @param file_name: file path (std::string)
     * @throw if file cannot be opened for writing
     *
     * Theta(n)
     */
    void write_to_file(const std::string & file_name);

    /**
     * Function that checks if two nodes are part of an edge.
     * @param n1: first vertex (int)
     * @param n2: second vertex (int)
     * @return true if edge exists else false
     *
     * O(logn)
     */
    bool is_edge(node n1, node n2);

    /**
     * Function that returns the in-degree of a given vertex
     * @param vertex an existing node (int)
     * @throw if vertex doesn't exist
     * @return the in-degree of the vertex (int)
     *
     * Theta(1)
     */
    int in_degree(node vertex);

    /**
     * Function that returns the out-degree of a given vertex
     * @param vertex an existing node (int)
     * @throw if vertex doesn't exist
     * @return the out-degree of the vertex (int)
     *
     * Theta(1)
     */
    int out_degree(node);

    /**
     * Function that modifies the cost of a given edge
     * @param n1: first vertex
     * @param n2: second vertex
     * @param cost: the new cost of the edge
     * @throw if edge (n1, n2) doesn't exist in the graph
     *
     * Theta(1)
     */
    void modify_cost(node n1, node n2, int cost);

    /**
     * Function that retrieves the cost of an edge
     * @param n1: the first node from the edge
     * @param n2: the second node from the edge
     * @throw if edge (n1, n2) doesn't exist
     * @return the cost of the edge (n1, n2) (int)
     *
     * Theta(1)
     */
    int get_cost(node n1, node n2);

    /**
     * Function that deletes an existing edge
     * @param n1: the first node from the edge
     * @param n2: the second node from the edge
     * @throw if edge (n1, n2) doesn't exist
     *
     * O(n)
     */
    void delete_edge(node n1, node n2);

    /**
     * Function that adds an edge to the graph
     * @param n1: the first node from the edge
     * @param n2: the second node from the edge
     * @param cost: the cost of the new edge
     * @throw if edge already exists or if nodes are invalid
     *
     * O(n)
     */
    void add_edge(node n1, node n2, int cost);

    /**
     * Function that adds a new node to the graph
     * @param n: the new node to be added
     * @throw if node already exists
     *
     * O(n)
     */
    void add_node(node n);

    /**
     * Function that deletes an existing node from the graph, along with all edges connecting it to
     * other edges
     * @param n: the node to be deleted
     * @throw if node doesn't exist
     *
     * O(n)
     */
    void delete_node(node n);

    /**
     * Copy constructor for the Graph class
     * @param g: the graph to be copied
     */
    Graph(const Graph &g) { nr_of_vertices = g.get_nr_of_vertices(), nr_of_edges = g.nr_of_edges, dict_in = g.dict_in,
                            dict_out = g.dict_out, dict_cost = g.dict_cost, vertices = g.vertices; };

    /**
     * Static function that creates a random graph
     * @param n: the number of vertices of the new graph
     * @param m: the number of edges of the new graph
     * @throw if graph cannot be composed (the number of edges is too big for how many vertices are)
     * @return the new graph
     */
    static Graph random_graph(int n, int m);

    /**
     * Function that verifies if a given node index is in the graph
     * @param n: the node to search for
     * @return true if the node exists, false otherwise
     *
     * O(n)
     */
    bool is_vertex(node n);
};


#endif //CPP_GRAPH_GRAPH_H
