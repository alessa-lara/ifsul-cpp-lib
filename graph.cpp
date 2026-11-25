#include "lib/graph.hpp"
#include "lib/kruskal.hpp"

int main() {
    Graph g(false, true);
    g.insert();
    g.print_graph();

    Kruskal_Answer answer = kruskal(g);

    for ( int i = 0; i < answer.length; i++ ) {
        cout << "weight: " << answer.edges[i]->weight << ", ";
        cout << "u: " << char(answer.edges[i]->u + 'A') << ", ";
        cout << "v: " << char(answer.edges[i]->v + 'A') << "\n";
    }

    return 0;
}
