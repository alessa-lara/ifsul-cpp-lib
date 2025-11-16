#include <iostream>
#include <stdlib.h> // srand(), rand(), talvez nao precise
#include <time.h>   // time, talve nao precise

// Algorithm P (Shuffling).
// Let (X1, X2, . . . , Xt) be a sequence of t numbers to be shuffled.
// P1. [Initialize.] Set j ← t.
// P2. [Generate U.] Generate a random number U, uniformly distributed between zero and one.
// P3. [Exchange.] Set k ← ⌊jU⌋ + 1. (Now k is a random integer, between 1 and j. Exercise 3.4.1–3 explains that k should not be computed by taking a remainder modulo j.) Exchange Xk ↔ Xj.
// P4. [Decrease j.] Decrease j by 1. If j > 1, return to step P2.
// fonte: Knuth, Donald E. (1969). Seminumerical algorithms. The Art of Computer Programming. Vol. 2. Reading, MA: Addison–Wesley. pp. 139–140. OCLC 85975465
void shuffle(int arr[], int len) {
    srand(time(NULL));
    for (int i = len - 1; i >= 1; i--) {
        int u = rand() % (i + 1);
        std::swap(arr[i], arr[u]);
    }
}

// Implementacao do algoritmo de floyd (F2) para sampling aleatorio com valores unicos
// initialize set S to empty
// for J := N-M + 1 to N do
//   T := RandInt(1, J)
//   if T is not in S then
// insert T in S
//   else
// insert J in S
// fonte: Bentley, J., & Floyd, B. (1987). Programming pearls: A Sample Of Brilliance. Communications of the ACM, 30(9), 754–757.
// Quanto menor for a populacao (n), mais o resultado estara ordenado
// uma solucao e utilizar fisher-yates shuffle no arranjo final
int random(int arr[], int len, int min, int max) {
    int m = len;           // unique samples
    int n = max - min + 1; // population aka range
    int* s = arr;

    if (m > n) {
        std::cout << "Tamanho do array menor do que a quantia de possíveis valores a serem inseridos";
        return 1;
    }

    bool inArr[n + 1]; // +1 para incluir o indice igual a n
    for (int i = 0; i < n + 1; i++) {
        inArr[i] = false;
    }

    int i = 0;
    srand(time(NULL));
    for (int j = n - (m) + 1; j <= n; j++) {
        int t = (rand() % j) + 1; // 1 to j

        if (!inArr[t]) {
            s[i++] = t - 1 + min;
            inArr[t] = true;
        } else {
            s[i++] = j - 1 + min;
            inArr[j] = true;
        }
    }

    shuffle(s, m);

    return 0;
}

void bubbleSort(int array[], int length, bool crescente) {
    int temp;
    bool troca;
    bool comp;

    for (int i = 0; i < length; i++) {
        troca = false;
        for (int j = 0; j < length - i - 1; j++) {
            if (crescente) {
                comp = array[j] > array[j + 1];
            } else {
                comp = array[j] < array[j + 1];
            }

            if (comp) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                troca = true;
            }
        }
        if (!troca) {
            break;
        }
    }
}

int* transporMat(int** mat, int* lin, int* col) {
    int transSize = (*lin) * (*col);
    int arr[transSize];

    for (int i = 0; i < *lin; i++) {
        for (int j = 0; j < *col; j++) {
            arr[(i * *col) + j] = mat[i][j];
        }
    }

    return arr;
}

int** sortMatrix(int** mat, int* lin, int* col) {
    int* arr = transporMat(mat, lin, col);
    bubbleSort(arr, (*lin) * (*col), true);

    for (int i = 0; i < *lin; i++) {
        for (int j = 0; j < *col; j++) {
            mat[i][j] = arr[(i * (*col)) + j];
        }
    }

    return mat;
}

// Considera que o arr esteja ordenado
int binarySearch(int* arr, int* len, int* num) {
    int* floor = new int(0);
    int* ceil = new int(*len - 1);
    int* mid;

    while (*floor <= *ceil) {
        *mid = *floor + (*ceil - *floor) / 2;

        if (arr[*mid] == *num) {
            return *mid;
        }

        if (arr[*mid] < *num) {
            *floor = *mid + 1;
        } else {
            *ceil = *mid - 1;
        }
    }

    return -1;
}