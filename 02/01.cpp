// 6 – Escreva um programa que receba um texto qualquer do teclado, em seguida
// apresente:
// - O texto com todos os caracteres em maiúsculo
// - O texto com todos os caracteres em minúsculo
// - O Total de caracteres do texto
// - O Total de vogais
// - O Total de consoantes
// - O Total de números
// - O Total de espaços em branco

#include <cstring> // strlen
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::strlen;

int main() {
    char input[30];
    cin.getline(input, sizeof(input));
    int arrLen = strlen(input);

    cout << "Letras maiúsculas: ";
    for (int i = 0; i < arrLen; i++) {
        input[i] = toupper(input[i]);
        cout << input[i];
    }
    cout << endl;

    cout << "Letras minúsculas: ";
    for (int i = 0; i < arrLen; i++) {
        input[i] = tolower(input[i]);
        cout << input[i];
    }
    cout << endl;

    cout << "total de caracteres, excluindo o NULL: " << arrLen << endl;

    // Total de vogais
    int total = 0;
    for (int i = 0; i < arrLen; i++) {
        switch (input[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                total += 1;
                break;
            default:
                break;
        }
    }
    cout << "total de vogais: " << total << endl;

    // Total de consoantes;
    total = 0;
    for (int i = 0; i < arrLen; i++) {
        switch (input[i]) {
            case 'b':
            case 'c':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                total += 1;
                break;
            default:
                break;
        }
    }
    cout << "total de consoantes: " << total << endl;

    // Total de numeros
    total = 0;
    for (int i = 0; i < arrLen; i++) {
        if (input[i] >= 48 && input[i] <= 57) { // valor ASCII dos digitos decimais
            total += 1;
        }
    }
    cout << "total de números: " << total << endl;

    // Total de espacos
    total = 0;
    for (int i = 0; i < arrLen; i++) {
        if (input[i] == ' ') {
            total += 1;
        }
    }
    cout << "total de espacos: " << total << endl;

    return 0;
}