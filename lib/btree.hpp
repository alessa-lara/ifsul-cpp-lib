#ifndef BTREE
#define BTREE

#include "iostream"
using namespace std;

inline int max(int a, int b) {
    if ( a >= b )
        return a;
    else
        return b;
}

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data, Node<T>* left = nullptr, Node<T>* right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    ~Node() {
        delete this->left;
        delete this->right;
    }
};

template <typename T>
struct Binary_Tree {
    Node<T>* root;

    Binary_Tree(Node<T>* root = nullptr) {
        this->root = root;
    }

    ~Binary_Tree() {
        delete this->root;
    }

    void insert(T val) {
        this->root = insert(val, this->root);
    }

    Node<T>* insert(T val, Node<T>*& current) {
        if ( current == nullptr )
            return new Node<T>(val);

        if ( val < current->data )
            current->left = insert(val, current->left);
        else if ( val >= current->data )
            current->right = insert(val, current->right);

        return balance_node(current);
    }

    void remove(T val) {
        this->root = remove(val, this->root);
    }

    Node<T>* remove(T val, Node<T>*& current) {
        if ( current == nullptr )
            return nullptr;

        if ( val < current->data )
            current->left = remove(val, current->left);
        else if ( val > current->data )
            current->right = remove(val, current->right);
        else {
            if ( current->left == nullptr && current->right == nullptr ) {
                delete current;
                return nullptr;
            }

            if ( current->left == nullptr ) {
                Node<T>* aux = current->right;
                current->right = nullptr;
                delete current;
                return aux;
            }

            if ( current->right == nullptr ) {
                Node<T>* aux = current->left;
                current->left = nullptr;
                delete current;
                return aux;
            }

            // there's two nodes below
            Node<T>* aux = current->left;
            while ( aux->left != nullptr && aux->right != nullptr )
                aux = aux->right;

            current->data = aux->data;
            current->left = remove(aux->data, current->left);
        }

        return balance_node(current);
    }

    void in_order(Node<T>* node) {
        if ( node == nullptr )
            return;

        cout << "<";
        in_order(node->left);
        cout << ">";
        cout << "<" << node->data << ">";
        cout << "<";
        in_order(node->right);
        cout << ">";
    }

    void pre_order(Node<T>*& node) {
        if ( node == nullptr )
            return;

        cout << "<" << node->data << ">";
        cout << "<";
        pre_order(node->left);
        cout << "><";
        pre_order(node->right);
        cout << ">";
    }

    void post_order(Node<T>*& node) {
        if ( node == nullptr )
            return;

        cout << "<";
        post_order(node->left);
        cout << "><";
        post_order(node->right);
        cout << ">";
        cout << "<" << node->data << ">";
    }

    bool search(T value, Node<T>* node) {
        if ( this->root == nullptr )
            return false;

        if ( node == nullptr )
            return false;

        if ( node->data == value )
            return true;

        if ( value < node->data )
            return search(value, node->left);
        else
            return search(value, node->right);
    }

    int height_subtree(bool left, bool right) {
        if ( left && right )
            return max(height_subtree(this->root->left), height_subtree(this->root->right));

        if ( left == true )
            return height_subtree(this->root->left);

        if ( right == true )
            return height_subtree(this->root->right);
    }

    int height_subtree(Node<T>* node) {
        if ( node == nullptr )
            return 0;

        if ( node->left != nullptr || node->right != nullptr )
            return 1 + max(height_subtree(node->left), height_subtree(node->right));

        return 1;
    }

    inline int balance_factor(Node<T>* node) {
        return height_subtree(node->left) - height_subtree(node->right);
    }

    Node<T>* balance_node(Node<T>*& node) {
        // LL - left left
        if ( balance_factor(node) > 1 && balance_factor(node->left) >= 0 )
            return rotate_right(node);

        // LR - left right
        if ( balance_factor(node) > 1 && balance_factor(node->left) < 0 ) {
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }

        // RR - right right
        if ( balance_factor(node) < -1 && balance_factor(node->right) <= 0 )
            return rotate_left(node);

        // RL - right left
        if ( balance_factor(node) < -1 && balance_factor(node->right) > 0 ) {
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }

        return node;
    }

    Node<T>* rotate_left(Node<T>*& node) {
        Node<T>* right = node->right;

        node->right = right->left;
        right->left = node;

        return right;
    }

    Node<T>* rotate_right(Node<T>*& node) {
        Node<T>* left = node->left;

        node->left = left->right;
        left->right = node;

        return left;
    }

    int nodes_in_tree(Node<T>* node) {
        if ( node == nullptr )
            return 0;

        int left = height_subtree(node->left);
        int right = height_subtree(node->right);

        if ( left == right )
            return (2 << left) - 1;
        else {
            return 1 + nodes_in_tree(node->left) + nodes_in_tree(node->right);
        }
    }

    int nodes_at_level(Node<T>* node, int target) {
        if ( node == nullptr )
            return 0;

        if ( target != 0 )
            return nodes_at_level(node->left, target - 1) + nodes_at_level(node->right, target - 1);
        else
            return 1;
    }

    void print_per_level(Node<T>* node, int target, int level = 0) {
        if ( node == nullptr )
            return;

        if ( target != 0 ) {
            print_per_level(node->left, target - 1, level + 1);
            print_per_level(node->right, target - 1, level + 1);
        } else
            cout << "L" << level << ":" << node->data << ", ";
    }
};

#endif
