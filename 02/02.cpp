// 7 - Escreva um programa que recebe uma string qualquer do usuário e verifique
// se a string forma um palíndromo. Palíndromo é uma palavra, frase ou número
// que permanece igual quando lida de trás para frente, sem considerar acentos,
// hífen, espaços em branco e independente de maiúsculas e minúsculas. São
// exemplos de palíndromos: radar, Renner, Roma é amor, orava o avaro,
// socorram-me subi no ônibus em Marrocos.

// remover espacos -> shift
// remover hifen -> shit
// lowercase
// remover acentos -> ascii
// comparar str[0 .. meio] com str[len .. meio];

#include <cstring> // strlen
#include <iostream>

using std::cin;
using std::cout;

int main() {
    setlocale(LC_ALL, "portuguese"); // trocar portuguese para vazio no windows

    // char input[30];
    // cin.getline(input, sizeof(input));
    // int arrLen = strlen(input);
    std::string input;
    std::getline(cin, input);
    int arrLen = input.length();

    // removendo os espacos
    for (int i = 0; i < arrLen; i++) {
        if (input[i] == ' ') {
            for (int j = i; j < arrLen; j++) {
                input[j] = input[j + 1];
            }
            arrLen--;
            input.pop_back();
        }
    }

    // removendo os hifens
    for (int i = 0; i < arrLen; i++) {
        if (input[i] == '-') {
            for (int j = i; j < arrLen; j++) {
                input[j] = input[j + 1];
            }
            arrLen--;
            input.pop_back();
        }
    }

    // trocar letras acentuadas por letras comuns
    // cpp nao consegue comparar os caracteres da extended ASCII
    // porque sao mais de uma especificacao desta. Precisaria de Unicode, mas nao faco ideia de como fazer
    // for (int i = 0; i < arrLen; i++) {
    // }

    // comparacao
    bool palindromo = true;
    int i = 0;
    int j = arrLen - 1;

    while (i < j) {
        if (input[i] != input[j]) {
            palindromo = false;
            break;
        }

        i++;
        j--;
    }

    if (palindromo) {
        cout << "A palavra é um palíndromo";
    }

    return 0;
}
