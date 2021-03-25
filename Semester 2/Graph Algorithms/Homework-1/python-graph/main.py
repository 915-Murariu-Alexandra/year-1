class Graph:
    def __init__(self, n=0, m=0):
        self._nr_of_vertices = n
        self._nr_of_edges = m
        self._dict_in = {}
        self._dict_out = {}
        self._dict_cost = {}

    def parse_vertices(self):
        return range(self._nr_of_vertices)

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
        return [i for i in self._dict_out[vertex]]

    def parse_inbound_edges(self, vertex):
        return [i for i in self._dict_in[vertex]]

    def modify_cost(self, node_in, node_out, new_cost):
        self._dict_cost[(node_in, node_out)] = new_cost

    def add_edge(self, node_in, node_out, cost):
        if (node_in, node_out) in self._dict_cost.keys():
            raise Exception("This edge already exists.")
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

    def remove_edge(self, node_in, node_out):
        if (node_in, node_out) not in self._dict_cost.keys():
            raise Exception("This edge can't be removed, it doesn't exist.")
        self._dict_in[node_out].remove(node_in)
        self._dict_out[node_in].remove(node_out)
        del self._dict_cost[(node_in, node_out)]

    def add_node(self, vertex):
        if vertex in self._dict_in.keys() or vertex in self._dict_out.keys():
            raise Exception("Vertex already exists.")


    def read_from_file(self, file_name):
        with open(file_name) as f:
            content = f.read().splitlines()

        self._nr_of_vertices = content[0].split()[0]
        self._nr_of_edges = content[0].split()[1]

        for index in range(1, len(content)):
            node_1 = content[index].split()[0]
            node_2 = content[index].split()[1]
            cost = content[index].split()[2]
            if node_2 not in self._dict_in.keys():
                self._dict_in[node_2] = [node_1]
            else:
                self._dict_in[node_2].append(node_1)

            if node_1 not in self._dict_out.keys():
                self._dict_out[node_1] = [node_2]
            else:
                self._dict_out[node_1].append(node_2)

            self._dict_cost[(node_1, node_2)] = cost

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


if __name__ == "__main__":
    g = Graph()
    g.read_from_file("graph.txt")
    g.add_edge("0", "3", 5)
    g.remove_edge("0", "3")
    g.remove_edge("0", "0")
    g.remove_edge("0", "1")
    g.add_edge("0", "3", 4)
    g.write_to_file("new_file.txt")
