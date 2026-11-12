// adjacency list implementation of a graph

#include <iostream>
#define MAXVERTICES 100

using namespace std;

struct edgenode {
    int y;
    int weight;
    struct edgenode* next;

    edgenode(int weight, int y, edgenode* next) {
        this->weight = weight;
        this->y = y;
        this->next = next;
    }
};

struct graph {
    edgenode* edges[MAXVERTICES + 1]; // linked list variant of this
    int degree[MAXVERTICES + 1];      // TODO! linked list variant of this
    int nVertices;                    // number of vertices in the graph
    int nEdges;                       // number of edges in the graph
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
        int x;
        int y;

        cin >> this->nVertices;
        cin >> nEdges;

        for ( int i = 0; i < nEdges; i++ ) {
            cin >> x;
            cin >> y;

            this->insertEdge(x, y);
        }
    }

    void insertEdge(int x, int y) {
        edgenode* edge = new edgenode(0, y, this->edges[x]);
    };
};
