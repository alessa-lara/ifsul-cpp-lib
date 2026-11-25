#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

struct DisjointSet {
    int* parent_index; // array storing the parent of a given node
    int* size_subtree; // array storing the size of each subtree
    int size_universe;

    ~DisjointSet() {
        delete[] this->parent_index;
        delete[] this->size_subtree;
    }

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

#endif
