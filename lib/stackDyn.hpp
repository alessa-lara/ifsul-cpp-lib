#ifndef DYN_STACK
#define DYN_STACK

#include <iostream>
template<typename T>
struct Node{
    T data;
    Node<T> *next;
};

template<typename T>
struct Stack{
    Node<T> *top;

    Stack() {
        top = nullptr;
    }
};


template<typename T>
void deleteStack(Stack<T> *stack) {
    while (! isEmpty(&stack)) {
        pop(&stack);
    }
}

template<typename T>
bool isEmpty(Stack<T> *stack) {
    if (stack->top == nullptr) {
        return true;
    }

    return false;
}

template<typename T>
void push(Stack<T> *stack, T val) {
    Node<T> *node = new Node<T>;
    node->data = val;
    node->next = stack->top;
    stack->top = node;
}

template<typename T>
T pop(Stack<T> *stack) {
    T data = nullptr;
    
    if (isEmpty(&stack)) {
        return data;
    }

    data = stack->top->data;
    Node<T>* temp = stack->top;
    stack->top = stack->top->next;
    delete temp;

    return data;
}

template<typename T>
T peek(Stack<T> *stack) {
    T data = nullptr;

    if (isEmpty(&stack)) {
        return data;
    }

    data = stack->top->data;

    return data;
}

template<typename T>
bool search(Stack<T> *stack, T value) {
    Node<T> *node = stack->top;
    
    while(node != nullptr) {
        if (node->data == value) {
            return true;
        }

        node = node->next;
    }

    return false;
}

template<typename T>
void show(Stack<T> *stack) {
    Node<T> *node = stack->top;
    
    while(node != nullptr) {
        std::cout << node->data << ", ";
        node = node->next;
    }
}

#endif