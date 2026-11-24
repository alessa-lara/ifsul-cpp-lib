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

struct DisjointSet {
    int* parent_index; // array storing the parent of a given node
    int* size_subtree; // array storing the size of each subtree
    int size_universe;

    DisjointSet(int size_universe) {
        this->parent_index = new int[size_universe];
        this->size_subtree = new int[size_universe];
        this->size_universe = size_universe;

        for ( int i = 0; i < size_universe; i++ ) {
            this->parent_index[i] = i; // each node is in a separate subtree
            this->size_subtree[i] = 1;
        };
    }

    int find(int x) {
        // go upwards until you find the root of the tree containing element x
        if ( this->parent_index[x] == x )
            return x;

        return find(this->parent_index[x]);
    }

    void merge(int element_a, int element_b) {
        int root_a;
        int root_b;

        root_a = this->find(element_a);
        root_b = this->find(element_b);

        if ( root_a == root_b )
            return; // already in the same set

        int size_subtree_a = this->size_subtree[root_a];
        int size_subtree_b = this->size_subtree[root_b];

        if ( size_subtree_a >= size_subtree_b ) { // merge set b into a
            this->size_subtree[root_a] = size_subtree_a + size_subtree_b;
            this->parent_index[root_b] = root_a;

            /*
             * size_subtree[root_b] is intentionally left stale as root_b is no longer a root
             * and therefore cannot be accessed through find(). the stale value is unreachable.
             * the same applies to size_subtree[root_a] in the else branch.
             */

        } else { // merge set a into b
            this->size_subtree[root_b] = size_subtree_a + size_subtree_b;
            this->parent_index[root_a] = root_b;
        }
    }

    bool same_set(int element_a, int element_b) {
        int root_a = find(element_a);
        int root_b = find(element_b);

        return root_a == root_b;
    }
};
