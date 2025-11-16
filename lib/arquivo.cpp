#include "arquivo.hpp"
#include "clearScreen.hpp"

#include <fstream>
#include <iostream>
#include <string>

using std::string, std::ifstream, std::ofstream, std::cout, std::endl;

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

int readFile(string leitura, leituraOpcoes opt, string valores[1], int valLen) {
    ifstream arq(leitura);

    if (!arq.is_open()) {
        cout << "erro: falha na abertura do arquivo" << endl;
        return -1;
    }

    if (!opt.padrao.empty()) {
        string line;
        int i = 0;
        while (getline(arq, line)) {
            size_t posOcorrencia = line.find(opt.padrao);
            if (posOcorrencia != std::string::npos) { // encontramos uma ocorrencia do padrao
                if (valLen > 0) {
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

int writeFile(string escrita, string valores[], int len) {
    ofstream arq(escrita, std::ios::app); // Modo de escrita no arquivo esta como append
    // ofstream arq(escrita, std::ios::out); // Modo de escrita no arquivo como replace

    if (!arq.is_open()) {
        cout << "erro: falha na abertura do arquivo";
        return -1;
    }

    for (int i = 0; i < len; i++) {
        arq << valores[i] << ',';
    }
    arq << endl;

    arq.close();
    return 0;
}