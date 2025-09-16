#include "arquivo.h"
#include "clearScreen.h"

#include <fstream>
#include <iostream>
#include <string>

using std::string, std::ifstream, std::ofstream, std::cout, std::endl;

// LOCAL DOS ARQUIVOS
string ESCRITA = "arquivo.txt";
string LEITURA = "arquivo.txt";

// Captura uma palavra de uma linha com base na posicao da ocorrencia e no
// offset de palavras desejado Modificar para funcionamento com offset negativo
string capturaPalavra(string line, size_t posOcorrencia, int offsetPalavras) {
    int offsetLetras = 0;
    char delimitador = ',';
    for (int i = 0; i < offsetPalavras; i++) {
        while (line[posOcorrencia + offsetLetras] != delimitador) {
            offsetLetras++;
        }
        offsetLetras++; // Incrementamos mais uma vez para "iniciar" na proxima
                        // palavra
    }

    int posPalavra = posOcorrencia + offsetLetras;
    int lenPalavra = 0;
    while (line[posPalavra + lenPalavra] != delimitador) {
        lenPalavra++;
    }

    return line.substr(posPalavra, lenPalavra);
}

int readFile(leituraOpcoes opt, string valores[1], int valLen) {
    ifstream arq(LEITURA);

    if (!arq.is_open()) {
        cout << "erro: falha na abertura do arquivo" << endl;
        return -1;
    }

    if (!opt.padrao.empty()) {
        string line;
        int i = 0;
        while (getline(arq, line)) {
            size_t posOcorrencia = line.find(opt.padrao);
            if (posOcorrencia !=
                std::string::npos) { // encontramos uma ocorrencia do padrao
                if (valLen == 0) {
                    capturaPalavra(line, posOcorrencia, opt.offset);
                } else {
                    valores[i] = capturaPalavra(line, posOcorrencia, opt.offset);
                }
                i++;
            }
        }

        if (opt.ocorrencias) {
            return i;
        }
    }

    arq.close();
    return 0;
}

int writeFile(std::string arr[], int len) {
    ofstream arq(ESCRITA, std::ios::app); // Modo de escrita no arquivo esta como append

    if (!arq.is_open()) {
        cout << "erro: falha na abertura do arquivo";
        return -1;
    }

    for (int i = 0; i < len; i++) {
        arq << arr[i] << ',';
    }
    arq << endl;

    arq.close();
    return 0;
}