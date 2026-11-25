#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include "graph.hpp"
#include "disjointSet.hpp"

inline int partition(Edgenode* arr[], int low, int high) {
    int pivot = arr[high]->weight;

    int i = low - 1;

    for ( int j = low; j < high; j++ ) {

        if ( arr[j]->weight <= pivot ) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

inline void quickSort(Edgenode* arr[], int low, int high) {
    if ( low < high ) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}

struct Kruskal_Answer {
    Edgenode** edges;
    int length;

    ~Kruskal_Answer() {
        delete[] this->edges;
    }
};

inline Kruskal_Answer kruskal(Graph& graph) {
    int n_edges = graph.n_edges;
    int n_vert = graph.n_vertices;

    Edgenode* flat_edges[n_edges];

    Edgenode* edge;
    int i = 0;
    int j = 0;
    while ( i < graph.n_edges ) {
        edge = graph.edges[j];

        while ( edge != nullptr ) {
            flat_edges[i++] = edge;
            edge = edge->next;
        }

        j++;
    }

    int qs_high = n_edges - 1;
    int qs_low = 0;
    quickSort(flat_edges, qs_low, qs_high);

    DisjointSet set(n_vert);

    int ans_size = n_vert - 1;
    // We malloc so we don't return a stack pointer and Kruskal_Answer later frees this array
    Edgenode** edges_answer = new Edgenode*[ans_size];

    j = 0;
    for ( int i = 0; i < n_edges; i++ ) {
        if ( set.same_set(flat_edges[i]->u, flat_edges[i]->v) )
            continue;

        set.merge(flat_edges[i]->u, flat_edges[i]->v);
        edges_answer[j++] = flat_edges[i];
    }

    Kruskal_Answer answer;
    answer.edges = edges_answer;
    answer.length = j;

    return answer;
}

#endif
