#include "menu.h"
#include "clearScreen.h"

#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

void hang() {
    cout << "Pressione [enter] para continuar";
    cin.ignore();
    getchar();
}

int menu(string header, string opcoes[], size_t length) {
    int userOpcao;
    while (true) {
        clearScreen();

        if (!header.empty()) {
            cout << header << endl;
        }
        for (int i = 0; i < length; i++) {
            cout << i << ". " << opcoes[i] << endl;
        }

        cout << "Digite sua opção: ";
        cin >> userOpcao;
        cout << endl;

        if (userOpcao >= 0 && userOpcao <= length) {
            return userOpcao;
        } else {
            cout << "Opção inválida, insira um valor entre 0 e " << length;
            hang();
        }
    }
}