// adjacency list implementation of a graph

#include <iostream>
#define MAXVERTICES 100

using namespace std;

struct Edgenode {
    int value;
    int weight;
    struct Edgenode* next;

    Edgenode(int weight, int value, Edgenode* next) {
        this->weight = weight;
        this->value = value;
        this->next = next;
    }
};

struct Graph {
    Edgenode* edges[MAXVERTICES];
    int degree[MAXVERTICES];
    int n_vertices;
    int n_edges;
    bool directed;

    Graph(bool directed) {
        this->n_vertices = 0;
        this->n_edges = 0;
        this->directed = directed;

        for ( int i = 0; i < MAXVERTICES; i++ )
            this->degree[i] = 0;

        for ( int i = 0; i < MAXVERTICES; i++ )
            this->edges[i] = nullptr;
    }

    ~Graph() {}

    void insert() {
        int n_edges;
        int u;
        int v;

        cin >> this->n_vertices;
        cin >> n_edges;

        for ( int i = 0; i < n_edges; i++ ) {
            cin >> u;
            cin >> v;

            this->insert_edge(u, v, this->directed);
        }
    }

    void insert_edge(int u, int v, bool directed) {
        Edgenode* edge = new Edgenode(0, v, this->edges[u]);

        this->edges[u] = edge;
        this->degree[u]++;

        if ( !directed )
            this->insert_edge(v, u, true);
        else
            this->n_edges++;
    };

    void print_graph() {
        Edgenode* edge;

        for ( int i = 0; i < this->n_vertices + 1; i++ ) {
            cout << i << ":";
            edge = this->edges[i];

            while ( edge != nullptr ) {
                cout << edge->value;
                edge = edge->next;
            }

            cout << "\n";
        }
    }

    void remove_vertex() {
        Edgenode* edge;

        // go to edges[u] and for each node v we check edges[v], remove u from the list and subtract the degree, subtract nedges, nvertices is a problem so we can do a tombstone in the degree[u]
        // this would only work for undirected graphs, which is what we're making this so its ok
    }
};

    }
};
