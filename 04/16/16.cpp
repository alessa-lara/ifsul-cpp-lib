#include <iostream>
#include <string>

#include "arquivo.h"
#include "menu.h"

using std::string, std::endl, std::cout, std::cin;

int totalTorcedores(string torcedor);
void venda(string torcedores[], string posicoes[]);

int main() {
    // Erros tem o valor de retorno -1

    string torcedores[4] = {
        "Proprietário",
        "Contribuinte",
        "Meia entrada",
        "Demais torcedores"
    };

    string posicoes[4] = {
        "arquibancada",
        "camarote",
        "centro",
        "lateral"
    };

    string opcoes[5] = {
            "Fechar Programa",
            "Vender Ingresso",
            "Mostrar total vendido (exibe o valor comercializado em cada parte do estádio e o total geral)",
            "Mostrar o total de torcedores (exibe o total em cada categoria, juntamente como total geral)",
            "Encerrar partida (deve zerar todas as vendas para iniciar outra partida)"
    };
    size_t length = sizeof(opcoes) / sizeof(opcoes[0]);
    int userOpt = menu("", opcoes, length);

    switch (userOpt) {
        case 0:
            return 0;
        case 1: // venda
            venda(torcedores, posicoes);
            break;
        case 2: // total estadio
            cout << "Nao implementado";
            break;
        case 3: // total torcedores
            int total = 0;
            for (int i = 0; i < 4; i++) {
                total += totalTorcedores(torcedores[i]);
            }
            cout << "Total de torcedores no geral: " << total;
            break;
    }

    return 0;
}

void venda(string torcedores[], string posicoes[]) {
    int userOpcao;
    string userOpcoes[3];

    userOpcao = menu("Selecione o tipo de Torcedor para a venda: ", torcedores, 4);
    userOpcoes[0] = torcedores[userOpcao];


    userOpcao = menu("Selecione a posição no estádio para a venda: ", posicoes, 4);
    userOpcoes[1] = posicoes[userOpcao];

    cout << "Digite a quantia de ingressos a vender: ";
    cin >> userOpcoes[2];

    writeFile(userOpcoes, 3);
}

int totalTorcedores(string torcedor) {
    leituraOpcoes opt;
    opt.padrao = torcedor;
    opt.ocorrencias = true;
    int quantidade = readFile(opt);
    cout << "Total de torcedores do tipo " << torcedor << ": " << quantidade << endl;
    return quantidade;
}