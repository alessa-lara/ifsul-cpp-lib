// adjacency list implementation of a graph

#include <iostream>
#define MAXVERTICES 100

using namespace std;

struct edgenode {
    int v;
    int weight;
    struct edgenode* next;

    edgenode(int weight, int v, edgenode* next) {
        this->weight = weight;
        this->v = v;
        this->next = next;
    }
};

struct graph {
    edgenode* edges[MAXVERTICES + 1];
    int degree[MAXVERTICES + 1];
    int nVertices; // number of vertices in the graph
    int nEdges;    // number of edges in the graph
    bool directed;

    graph(bool directed) {
        int i = 0;

        this->nVertices = 0;
        this->nEdges = 0;
        this->directed = directed;

        for ( int i = 0; i < MAXVERTICES; i++ )
            this->degree[i] = 0;

        for ( int i = 0; i < MAXVERTICES; i++ )
            this->edges[i] = nullptr;
    }

    ~graph() {}

    void read_graph() {
        int nEdges;
        int u;
        int v;

        cin >> this->nVertices;
        cin >> nEdges;

        for ( int i = 0; i < nEdges; i++ ) {
            cin >> u;
            cin >> v;

            this->insert_edge(u, v);
        }
    }

    void insert_edge(int u, int v) {
        edgenode* edge = new edgenode(0, v, this->edges[u]);

        this->edges[u] = edge;
        this->degree[u]++;

        if ( !this->directed )
            this->insert_edge(v, u);
        else
            this->nEdges++;
    };

    void print_graph() {
        edgenode* edge;

        for ( int i = 0; i < this->nVertices + 1; i++ ) {
            cout << i << ":";
            edge = this->edges[i];

            while ( edge != nullptr ) {
                cout << edge->v;
                edge = edge->next;
            }

            cout << "\n";
        }
    }

    void remove_edge() {
        edgenode* edge;

        // go to edges[u] and for each node v we check edges[v], remove u from the list and subtract the degree, subtract nedges, nvertices is a problem so we can do a tombstone in the degree[u]
        // this would only work for undirected graphs, which is what we're making this so its ok

    }
};
