#include <iostream>

using std::string, std::getline, std::cin, std::cout;

int main() {
    string input;
    getline(cin, input);
    string provedor = "@gmail.com";
    
    if (input.size() != provedor.size() + 1) {
        cout << "Quantia de caracteres inválida para um email @gmail.com";
        return 1;
    }

    int atIndex = 0;
    while (input[atIndex] != '@' && atIndex < input.size()) {
        atIndex++;
    }
    if (atIndex == input.size()) {
        cout << "caractere '@' não encontrado";
        return 1;
    }

    int i = 0;
    bool valid = true;
    while (atIndex < input.size()) {
        if (input[atIndex] != provedor[i]) {
            valid = false;
        }
        atIndex++;
        i++;
    }

    valid ? cout << "Valido" : cout << "Nao valido";
}