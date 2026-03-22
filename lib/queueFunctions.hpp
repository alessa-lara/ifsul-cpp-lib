#ifndef QUEUE_FUNCTIONS
#define QUEUE_FUNCTIONS

#include "queue.hpp"

template<typename T>
bool search(Queue<T>* queue, T value) {
    int curr = queue->head;
    for (int i = 0; i < queue->len; i++) {
        if (queue->data[curr] == value) {
            return true;
        }

        curr++;

        if (curr == queue->capacity) {
            curr = 0;
        }
    }

    return false;
}

template<typename T>
bool searchAux(Queue<T> *queue, T value) {
    Queue<T> aux(queue->capacity);

    bool found = false;
    while(!isEmpty(queue) && !found) {
        enqueue(&aux, dequeue(queue));
        if (peek(&aux) == value) {
            found = true;
        }
    }

    while (!isEmpty(&aux)) {
        enqueue(queue, dequeue(&aux));
    }
 
    return found;
}

#endif