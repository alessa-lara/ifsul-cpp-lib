#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <stdexcept>
using std::cout;

// circular queue
template <typename T>
struct Queue {
    int capacity;
    int len;
    int head;
    int tail;
    T* data; // arr

    Queue(int size) {
        capacity = size;
        len = 0;
        head = 0;
        tail = 0;
        data = new T[size];
    }
};

template <typename T>
bool isInit(Queue<T>* queue) {
    if (queue->data == nullptr) {
        return false;
    }

    return true;
}

// responsabilidade do dev: nao remover a fila se nao tiver sido inicializada
template <typename T>
void deleteQueue(Queue<T>* queue) {
    queue->capacity = 0;
    queue->len = 0;
    queue->head = 0;
    queue->tail = 0;

    if (isInit(queue)) {
        delete[] queue->data;
        queue->data = nullptr;
    }
}

template <typename T>
bool isEmpty(Queue<T>* queue) {
    if (queue->len != 0) {
        return false;
    }

    return true;
}

template <typename T>
bool isFull(Queue<T>* queue) {
    if (queue->len != queue->capacity) {
        return false;
    }

    return true;
}

// verificacao se a fila esta cheia ou inicializada e responsabilidade do dev
template <typename T>
void enqueue(Queue<T>* queue, T val) {
    if (!isInit(queue)) {
        throw std::logic_error("Queue nao inicializada");
    }

    if (isFull(queue)) {
        throw std::logic_error("Queue sem espacos disponiveis");
    }

    queue->data[queue->tail] = val;
    queue->len++;
    queue->tail++;

    if (queue->tail == queue->capacity) {
        queue->tail = 0;
    }
}

template <typename T>
T dequeue(Queue<T>* queue) {
    if (!isInit(queue)) {
        throw std::logic_error("Queue nao inicializada");
    }

    if (isEmpty(queue)) {
        throw std::logic_error("Queue vazia");
    }

    T data = queue->data[queue->head];
    queue->len--;
    queue->head++;

    if (queue->head == queue->capacity) {
        queue->head = 0;
    }

    return data;
}

template <typename T>
T peek(Queue<T>* queue) {
    T data = queue->data[queue->head];
    return data;
}

template <typename T>
void show(Queue<T>* queue) {
    if (isEmpty(queue)) {
        throw std::logic_error("Queue Vazia");
    }

    int curr = queue->head;
    for (int i = 0; i < queue->len; i++) {
        cout << queue->data[curr] << ", ";
        curr++;

        if (curr == queue->capacity) {
            curr = 0;
        }
    }
}

#endif