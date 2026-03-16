#ifndef STACK_FUNCTIONS
#define STACK_FUNCTIONS

#include "stack.hpp"

#include <string>

bool balancedParenthesesString(std::string expression) {
    Stack<char> stack;
    newStack(&stack, expression.size());

    for (char c : expression) {
        if (c == '(') {
            push(&stack, c);
            continue;
        }

        if (c == ')') {
            if(isEmpty(&stack)) {
                return false;
            }

            pop(&stack);
        }
    }

    return true;
}

template<typename T>
bool searchWithAux(Stack<T>* stack, T value) {
    Stack<T> aux;
    int size = stack->size;
    newStack(&aux, size);
    bool found = false;
    for ( int i = stack->top; i > stack->bottom; i-- ) {
        push(&aux, pop(stack));
        if (peek(&aux) == value) {
            found = true;
        }
    }
    for ( int i = stack->top; i > stack->bottom; i-- ) {
        push(stack, pop(&aux));
    }

    return found;
}

// Searches a value inside of a inner structure
bool search(Stack<Inner>* stack, Inner value) {
    for ( int i = stack->top; i > stack->bottom; i-- ) {
        if ( value.id == stack->data[i].id ) {
           return true;
       }
    }
   return false;
}

// Shows the values inside of every struct on the stack
void show(Stack<Inner>* stack) {
    for (int i = stack->top; i > stack-> bottom; i--) {
        std::cout << "id: " << stack->data[i].id << ", ";
    }
}

#endif