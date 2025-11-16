#include <iostream>

using std::cout, std::string;

int diagonais(int** mat, int* lin, int* col, int* princ, int* secund, int* abaixoDP, int* acimaDP, int* abaixoDS, int* acimaDS) {
    if (*lin != *col) {
        cout << "matriz não é quadrada";
        return 1;
    }

    int* indexBaixoDP = new int(0);
    int* indexCimaDP = new int(0);
    int* indexBaixoDS = new int(0);
    int* indexCimaDS = new int(0);

    for (int i = 0; i < *lin; i++) {
        for (int j = 0; j < *col; j++) {
            if (i == j) {
                princ[i] = mat[i][j];
            }
            if (i + j == *lin - 1) {
                secund[i] = mat[i][j];
            }
            if (i > j) {
                abaixoDP[*indexBaixoDP] = mat[i][j];
                *indexBaixoDP += 1;
            }
            if (i < j) {
                acimaDP[*indexCimaDP] = mat[i][j];
                *indexCimaDP += 1;
            }
            if (i + j > *lin - 1) {
                abaixoDS[*indexBaixoDS] = mat[i][j];
                *indexBaixoDS += 1;
            }
            if (i + j < *lin - 1) {
                acimaDS[*indexCimaDS] = mat[i][j];
                *indexCimaDS += 1;
            }
        }
    }

    return 0;
}