// Criar uma matriz de forma dinamica no HEAP
inline int** matriz(int lin, int col) {
    int** mat = new int*[lin];
    int* data = new int[lin * col];

    for (int i = 0; i < lin; i++) {
        mat[i] = data + (i * col);
    }

    return mat;
}

// Liberar o espaco de memoria utilizado pela matriz no HEAP
inline void freeMat(int** mat) {
    delete mat[0];
    delete mat;
}

// Criar array dinamico no HEAP, evitando assim o uso de VLA
inline int* array(int size) {
    int* arr = new int[size];
    return arr;
}

// Liberar espaco de memoria utilizado pelo array no HEAP
inline void freeArr(int* arr) {
    delete arr;
}