void aritmetica() {
    int* n = new int(10);
    int* arr = new int[*n];

    for (int* i = new int(0); *i < *n; (*i)++) {
        *(arr + (*i)) = (*i); // arr[i]
    }
}