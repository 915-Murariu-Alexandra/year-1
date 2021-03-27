import copy


class Graph:
    def __init__(self, n=0, m=0, nodes=None, dict_in=None, dict_out=None, dict_cost=None):
        if dict_cost is None:
            dict_cost = {}
        if dict_out is None:
            dict_out = {}
        if dict_in is None:
            dict_in = {}
        if nodes is None:
            nodes = []
        self._nr_of_vertices = n
        self._nr_of_edges = m
        self._list_of_nodes = nodes
        self._dict_in = dict_in
        self._dict_out = dict_out
        self._dict_cost = dict_cost

    def copy_graph(self):
        return Graph(self._nr_of_vertices, self._nr_of_edges, self.parse_vertices(), copy.deepcopy(self.get_dict_in()),
                     copy.deepcopy(self.get_dict_out()), copy.deepcopy(self.get_dict_cost()))

    def parse_vertices(self):
        return iter(self._list_of_nodes)

    def is_edge(self, node_in, node_out):
        if (node_in, node_out) in self._dict_cost.keys():
            return True
        return False

    def in_degree(self, node):
        if node in self._dict_in.keys():
            return len(self._dict_in[node])
        return 0

    def out_degree(self, node):
        if node in self._dict_out.keys():
            return len(self._dict_out[node])
        return 0

    def parse_outbound_edges(self, vertex):
        if vertex not in self._dict_out.keys():
            raise Exception("No outbound edges for this vertex")
        return iter(self._dict_out[vertex])

    def parse_inbound_edges(self, vertex):
        if vertex not in self._dict_in.keys():
            raise Exception("No inbound edges for this vertex")
        return iter(self._dict_in[vertex])

    def modify_cost(self, node_in, node_out, new_cost):
        if not self.is_edge(node_in, node_out):
            raise Exception("The edge doesn't exist")
        self._dict_cost[(node_in, node_out)] = new_cost

    def add_edge(self, node_in, node_out, cost):
        if (node_in, node_out) in self._dict_cost.keys():
            raise Exception("This edge already exists.")
        elif node_in not in self.parse_vertices() or node_out not in self.parse_vertices():
            raise Exception("The nodes don't exist.")
        else:
            if node_in not in self._dict_out.keys():
                self._dict_out[node_in] = [node_out]
            else:
                self._dict_out[node_in].append(node_out)
            if node_out not in self._dict_in.keys():
                self._dict_in[node_out] = [node_in]
            else:
                self._dict_in[node_out].append(node_in)
            self._dict_cost[(node_in, node_out)] = cost
            self._nr_of_edges += 1

    def remove_edge(self, node_in, node_out):
        if (node_in, node_out) not in self._dict_cost.keys():
            raise Exception("This edge can't be removed, it doesn't exist.")
        self._dict_in[node_out].remove(node_in)
        self._dict_out[node_in].remove(node_out)
        del self._dict_cost[(node_in, node_out)]
        self._nr_of_edges -= 1

    def add_node(self, vertex):

        if vertex not in self._list_of_nodes:
            self._nr_of_vertices += 1
            self._list_of_nodes.append(vertex)
            return
        else:
            raise Exception("The vertex to add is not valid.")

    def remove_node(self, vertex):

        if vertex not in self._list_of_nodes:
            raise Exception("The vertex to remove doesn't exist.")

        else:
            if vertex in self._dict_in.keys():
                inbound_edges = [i for i in self._dict_in[vertex]]
                for node in inbound_edges:
                    print(self._dict_in[vertex])
                    self._dict_in[vertex].remove(node)
                    if node in self._dict_out.keys():
                        self._dict_out[node].remove(vertex)
                    del self._dict_cost[(node, vertex)]
                    self._nr_of_edges -= 1
            if vertex in self._dict_out.keys():
                outbound_edges = [i for i in self._dict_out[vertex]]
                for node in outbound_edges:
                    if node in self._dict_in.keys():
                        self._dict_in[node].remove(vertex)
                    self._dict_out[vertex].remove(node)
                    del self._dict_cost[(vertex, node)]
                    self._nr_of_edges -= 1
            self._nr_of_vertices -= 1
            self._list_of_nodes.remove(vertex)

    def read_from_file(self, file_name):
        with open(file_name) as f:
            content = f.read().splitlines()

        self._nr_of_vertices = int(content[0].split()[0])
        self._nr_of_edges = int(content[0].split()[1])

        for index in range(1, len(content)):
            node_1 = int(content[index].split()[0])
            node_2 = int(content[index].split()[1])
            cost = int(content[index].split()[2])
            if node_2 not in self._dict_in.keys():
                self._dict_in[node_2] = [node_1]
            else:
                self._dict_in[node_2].append(node_1)

            if node_1 not in self._dict_out.keys():
                self._dict_out[node_1] = [node_2]
            else:
                self._dict_out[node_1].append(node_2)

            self._dict_cost[(node_1, node_2)] = cost
        self._list_of_nodes = [i for i in range(self._nr_of_vertices)]

    def write_to_file(self, file_name):
        f = open(file_name, "w")
        f.write(str(self._nr_of_vertices) + " " + str(self._nr_of_edges) + "\n")

        for key, value in self._dict_out.items():
            for vertex in value:
                f.write(str(key) + " " + str(vertex) + " " + str(self._dict_cost[(key, vertex)]) + "\n")

    def get_nr_of_vertices(self):
        return self._nr_of_vertices

    def get_nr_of_edges(self):
        return self._nr_of_edges

    def set_nr_of_vertices(self, n):
        self._nr_of_vertices = n

    def set_nr_of_edges(self, m):
        self._nr_of_edges = m

    def get_dict_in(self):
        return self._dict_in

    def get_dict_out(self):
        return self._dict_out

    def get_dict_cost(self):
        return self._dict_cost

    def __str__(self):
        graph_str = str(self._nr_of_vertices) + " " + str(self._nr_of_edges) + "\n"
        for key, value in self._dict_out.items():
            for node in value:
                graph_str += str(key) + " " + str(node) + " " + str(self._dict_cost[(key, node)]) + "\n"
        return graph_str
