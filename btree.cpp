#include "lib/btree.hpp"
#include <iostream>

using namespace std;

int main() {
    Binary_Tree<int> t = Binary_Tree<int>();
    t.insert(8, t.root);
    t.insert(2, t.root);
    t.insert(9, t.root);
    t.insert(3, t.root);
    t.insert(1, t.root);

    t.pre_order(t.root);

    t.search(1, t.root);
    t.remove(1, t.root);

    std::cout << t.nodes_in_tree(t.root) << "\n";

    std::cout << "\n";
    t.pre_order(t.root);

    cout << "\n "<< t.height_subtree(true, false);
}
