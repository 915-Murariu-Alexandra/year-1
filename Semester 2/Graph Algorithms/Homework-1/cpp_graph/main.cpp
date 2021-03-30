#include <iostream>
#include "Graph.h"
#include "Console.h"

int main() {
    Graph g;
    Console c = Console(g);
    c.start();
    return 0;
}
