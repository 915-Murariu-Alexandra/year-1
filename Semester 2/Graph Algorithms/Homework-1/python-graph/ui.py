import math
import random

from graph import Graph


class Console:
    def __init__(self):
        self._graph = self.read_from_file()

    def start(self):
        while self.read_option() == 0:
            pass
        return

    @staticmethod
    def print_menu():
        print("1. Get the number of vertices.")
        print("2. Parse the set of vertices.")
        print("3. Find if an edge exists.")
        print("4. Get the in-degree and out-degree of a vertex.")
        print("5. Parse the set of outbound edges of a vertex.")
        print("6. Parse the set of inbound edges of a vertex.")
        print("7. Modify the cost of an edge.")
        print("8. Get the cost of an edge.")
        print("9. Add an edge.")
        print("10. Remove an edge.")
        print("11. Add a node.")
        print("12. Remove a node.")
        print("13. Make a copy of the graph.")
        print("14. Create a random graph.")
        print("15. Write the graph to a text file.")
        print("16. Get the shortest path between two vertices.")
        print("17. Get the strongly connected components.")
        print("18. Biconnected components")
        print("19. Wolf cabbage goat")
        print("20. Floyd Warshall")
        print("21. Verify if the graph is a DAG")
        print("22. Find the highest cost path between two vertices")
        print("x. Exit the application.")

    def read_option(self):
        self.print_menu()
        option = input("Please input your option:")
        if option == "1":
            print(self._graph.get_nr_of_vertices())
            return 0
        elif option == "2":
            self.parse_vertices()
            return 0
        elif option == "3":
            self.find_edge()
            return 0
        elif option == "4":
            self.get_degree()
            return 0
        elif option == "5":
            self.parse_outbound_edges()
            return 0
        elif option == "6":
            self.parse_inbound_edges()
            return 0
        elif option == "7":
            self.modify_cost()
            return 0
        elif option == "8":
            self.get_cost()
            return 0
        elif option == "9":
            self.add_edge()
            return 0
        elif option == "10":
            self.remove_edge()
            return 0
        elif option == "11":
            self.add_node()
            return 0
        elif option == "12":
            self.remove_node()
            return 0
        elif option == "13":
            self.make_a_copy()
            return 0
        elif option == "14":
            self.create_random_graph()
            return 0
        elif option == "15":
            self.write_to_file()
            return 0
        elif option == "16":
            self.shortest_path()
            return 0
        elif option == "17":
            self.strongly_connected_components()
            return 0
        elif option == "18":
            self.biconnected_components()
            return 0
        elif option == "19":
            self.wcg()
            return 0
        elif option == "20":
            self.floyd_warshall()
            return 0
        elif option == "21":
            self.verify_dag()
            return 0
        elif option == "22":
            self.highest_cost_path()
            return 0
        elif option == "x":
            return 1
        else:
            print("Invalid option! Please try again")
            return 0

    def parse_vertices(self):
        for i in self._graph.parse_vertices():
            print(i)

    def find_edge(self):
        node_1 = input("Please input the first vertex from the edge.")
        node_2 = input("Please input the second vertex from the edge.")
        try:
            int(node_1)
            int(node_2)
        except ValueError:
            print("The nodes should be integers. Please try again!")
            return
        if self._graph.is_edge(int(node_1), int(node_2)):
            print("The edge exists!")
            return
        print("The edge doesn't exist!")
        return

    def get_degree(self):
        node = input("Please input the node to get the in-degree and out-degree from.")
        try:
            int(node)
        except ValueError:
            print("The node should be an integer. Please try again!")
            return
        if int(node) not in self._graph.parse_vertices():
            print("The node doesn't exist. Please try again!")
            return
        print("The in-degree is: " + str(self._graph.in_degree(int(node))) + " and the out-degree is: " +
              str(self._graph.out_degree(int(node))))

    def parse_outbound_edges(self):
        node = input("Please input the node to parse through its outbound edges.")
        try:
            int(node)
        except ValueError:
            print("The node should be an integer. Please try again!")
            return
        try:
            for i in self._graph.parse_outbound_edges(int(node)):
                print(node + " " + str(i))
        except Exception as ex:
            print(ex)

    def parse_inbound_edges(self):
        node = input("Please input the node to parse through its inbound edges.")
        try:
            int(node)
        except ValueError:
            print("The node should be an integer. Please try again!")
            return
        try:
            for i in self._graph.parse_inbound_edges(int(node)):
                print(str(i) + " " + node)
        except Exception as ex:
            print(ex)

    def modify_cost(self):
        node_1 = input("Please input the first vertex from the edge.")
        node_2 = input("Please input the second vertex from the edge.")
        new_cost = input("Please input the new cost for the edge.")
        try:
            int(node_1)
            int(node_2)
            int(new_cost)
        except ValueError:
            print("The nodes and cost should be integers. Please try again!")
            return
        try:
            self._graph.modify_cost(int(node_1), int(node_2), int(new_cost))
            print("The cost was successfully modified!")
        except Exception as ex:
            print(ex)
            return

    def get_cost(self):
        node_1 = input("Please input the first vertex from the edge.")
        node_2 = input("Please input the second vertex from the edge.")
        try:
            int(node_1)
            int(node_2)
        except ValueError:
            print("The nodes and cost should be integers. Please try again!")
            return
        try:
            print(self._graph.get_cost(int(node_1), int(node_2)))
        except Exception as ex:
            print(ex)
            return

    def add_edge(self):
        node_1 = input("Please input the first vertex from the edge.")
        node_2 = input("Please input the second vertex from the edge.")
        cost = input("Please input the new cost for the edge.")
        try:
            int(node_1)
            int(node_2)
            int(cost)
        except ValueError:
            print("The nodes and cost should be integers. Please try again!")
            return
        try:
            self._graph.add_edge(int(node_1), int(node_2), int(cost))
            print("The edge was successfully added!")
        except Exception as ex:
            print(ex)
            return

    def remove_edge(self):
        node_1 = input("Please input the first vertex from the edge.")
        node_2 = input("Please input the second vertex from the edge.")
        try:
            int(node_1)
            int(node_2)
        except ValueError:
            print("The nodes and cost should be integers. Please try again!")
            return
        try:
            self._graph.remove_edge(int(node_1), int(node_2))
            print("The edge was successfully removed!")
        except Exception as ex:
            print(ex)
            return

    def shortest_path(self):
        node_1 = input("Please input the start vertex from the edge.")
        node_2 = input("Please input the end vertex from the edge.")
        try:
            int(node_1)
            int(node_2)
        except ValueError:
            print("The nodes and cost should be integers. Please try again!")
            return
        try:
            result = self._graph.shortest_path(int(node_1), int(node_2))
            print("The minimum length is " + str(result[0]) + " and the path is " + str(result[1]))
        except Exception as ex:
            print(ex)

    def floyd_warshall(self):
        node_1 = input("Please input the start vertex.")
        node_2 = input("Please input the end vertex.")
        try:
            int(node_1)
            int(node_2)
        except ValueError:
            print("The nodes and cost should be integers. Please try again!")
            return
        try:
            result = self._graph.floyd_warshall(int(node_1), int(node_2))
            if result[0] == math.inf:
                print("There is no walk.")
            else:
                print("The minimum cost walk is " + str(result[0]) + " and the path is " + str(result[1]))
        except Exception as ex:
            print(ex)

    def add_node(self):
        node = input("Please input the node you wish to add.")
        try:
            int(node)
        except ValueError:
            print("The node should be an integer number. Please try again!")
            return
        try:
            self._graph.add_node(int(node))
            print("The node was successfully added!")
        except Exception as ex:
            print(ex)
            return

    def remove_node(self):
        node = input("Please input the node you wish to remove.")
        try:
            int(node)
        except ValueError:
            print("The node should be an integer number. Please try again!")
            return
        try:
            self._graph.remove_node(int(node))
            print("The node was successfully removed!")
        except Exception as ex:
            print(ex)
            return

    def make_a_copy(self):
        new_graph = self._graph.copy_graph()
        print(str(new_graph))

    def write_to_file(self):
        new_file = input("What is the name of the file you wish to write the graph to?")
        f = open(new_file, "w")
        f.write(str(self._graph))

    def read_from_file(self):
        file_to_read = input("What is the name of the file you wish to read the graph from?")
        g = Graph()
        g.read_from_file(file_to_read)
        return g

    def create_random_graph(self):
        n = input("What should be the number of vertices?")
        m = input("What should be the number of edges?")
        file_name = input("What file do you want the random graph to be written in?\n")
        try:
            int(n)
            int(m)
        except ValueError:
            print("These should be integer numbers. Please try again!")
            return
        if int(m) > int(n) * int(n):
            f = open(file_name, "w")
            f.write("We cannot construct a graph like this. Please try again!")
            print("We cannot construct a graph like this. Please try again!")
            return
        elif int(m) < 0 or int(n) < 0:
            print("The numbers should be positive.")
        h = self._graph.random_graph(int(n), int(m))
        print(str(h))
        h.write_to_file(file_name)

    def strongly_connected_components(self):
        print(self._graph.kosaraju())

    def verify_dag(self):
        print(self._graph.is_dag())

    def biconnected_components(self):
        self._graph.BCC()
        print(self._graph.count)

    def highest_cost_path(self):
        node_1 = input("Please input the start vertex.")
        node_2 = input("Please input the end vertex.")
        try:
            int(node_1)
            int(node_2)
        except ValueError:
            print("The nodes and cost should be integers. Please try again!")
            return
        print(self._graph.highest_cost_path(int(node_1), int(node_2)))

    def wcg(self):
        g = self.read_from_file()
        ans = g.shortest_path(1, 2)
        print("F -> Farmer")
        print("W -> Wolf")
        print("G -> Goat")
        print("C -> Cabbage")
        print("The shortest path is " + str(ans[0]))
        for state in ans[1]:
            if state == 1:
                print("WGCF |")
            elif state == 2:
                print("     | WGCF")
            elif state == 3:
                print("WCF  | G")
            elif state == 4:
                print("   G | WCF")
            elif state == 5:
                print("WGF  | C")
            elif state == 6:
                print("    C | WGF")
            elif state == 7:
                print(" GCF | W")
            elif state == 8:
                print("   W | GCF")
            elif state == 9:
                print("  GF | WC")
            elif state == 10:
                print("  WC | GF")
