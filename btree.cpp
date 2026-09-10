#include "lib/btree.hpp"
#include <cassert>
#include <iostream>

using namespace std;

int main() {
    Binary_Tree<int> t = Binary_Tree<int>();
    t.insert(8);
    t.insert(2);
    t.insert(9);
    t.insert(3);
    t.insert(1);

    t.pre_order(t.root);

    assert(t.search(1, t.root) == true);
    t.remove(1);
    assert(t.search(1, t.root) == false);

    t.insert(1);
    t.insert(11);
    t.insert(15);
    t.insert(13);
    t.insert(12);
    assert(t.nodes_in_tree(t.root) ==  9);
    assert(t.nodes_at_level(t.root, 0) == 1);
    assert(t.nodes_at_level(t.root, 1) == 2);
    assert(t.nodes_at_level(t.root, 2) == 4);
    assert(t.nodes_at_level(t.root, 3) == 2);
    t.remove(8);
    t.remove(2);
    t.remove(9);
    t.remove(3);
    t.remove(1);
    t.remove(11);
    t.remove(15);
    t.remove(13);
    t.remove(12);

    std::cout << "\n";
    t.pre_order(t.root);

    // assert(t.height_subtree(true, false) == 2);
}
