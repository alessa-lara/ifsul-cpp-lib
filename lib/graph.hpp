// adjacency list implementation of a graph

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#define MAXVERTICES 100

using namespace std;

struct Edgenode {
    char u;
    char v;
    int weight;
    Edgenode* next;

    Edgenode(int weight, char u, char v, Edgenode* next) {
        this->weight = weight;
        this->u = u;
        this->v = v;
        this->next = next;
    }
};

struct Graph {
    Edgenode* edges[MAXVERTICES];
    int degree[MAXVERTICES];
    int n_vertices;
    int n_edges;
    bool directed;
    bool alphabetical;

    Graph(bool directed, bool alphabetical) {
        this->n_vertices = 0;
        this->n_edges = 0;
        this->directed = directed;
        this->alphabetical = alphabetical;

        for ( int i = 0; i < MAXVERTICES; i++ )
            this->degree[i] = 0;

        for ( int i = 0; i < MAXVERTICES; i++ )
            this->edges[i] = nullptr;
    }

    ~Graph() {
        Edgenode* del;
        Edgenode* next;

        for ( int i = 0; i < n_vertices; i++ ) {
            next = this->edges[i];

            while ( next != nullptr ) {
                del = next;
                next = del->next;
                delete del;
            }
        }
    }

    void insert() {
        int n_edges;
        int weight;
        int u;
        int v;
        char char_u;
        char char_v;

        cin >> this->n_vertices;
        cin >> n_edges;

        for ( int i = 0; i < n_edges; i++ ) {
            cin >> weight;

            if ( this->alphabetical ) {
                cin >> char_u;
                cin >> char_v;
                char_u = toupper(char_u);
                char_v = toupper(char_v);
                u = char_u - 'A';
                v = char_v - 'A';

                this->insert_edge(weight, u, v, this->directed);
            } else {
                cin >> u;
                cin >> v;

                this->insert_edge(weight, u, v, this->directed);
            }
        }
    }

    void insert_edge(int weight, char u, char v, bool directed) {
        Edgenode* edge = new Edgenode(weight, u, v, this->edges[u]);

        this->edges[u] = edge;
        this->degree[u]++;

        if ( directed )
            this->n_edges++;
        else {
            this->n_edges++;
            this->insert_edge(weight, v, u, true);
        }
    };

    void print_graph() {
        Edgenode* edge;

        for ( int i = 0; i < this->n_vertices; i++ ) {
            cout << char(i + 'A') << ": ";
            edge = this->edges[i];

            while ( edge != nullptr ) {
                cout << "{ w = " << edge->weight << ", v = ";

                if ( this->alphabetical )
                    cout << char(edge->v + 'A') << "}, ";
                else
                    cout << char(edge->v) << "}, ";

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

#endif
