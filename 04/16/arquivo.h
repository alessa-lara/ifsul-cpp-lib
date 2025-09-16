#include <string>

struct leituraOpcoes {
    std::string padrao = ""; // Se queremos encontrar algum padrao no arquivo
    int offset = 0;     // capturar posicao X apos a ocorrencia do padrao
    bool ocorrencias = false; // Contar a quantia de ocorrencias?
};
int readFile(leituraOpcoes opt, std::string valores[1] = 0, int valLen = 0); // retorna -1 em erro
int writeFile(std::string arr[], int len);