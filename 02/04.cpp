// SOLUCAO DO COLEGA

int cont = 0;
for (int i = 0; i < alfabeto.size(); i++) {
    if (texto.find(alfabeto[i]) != string::npos) {
        cont++;
    }
}

cout << "cont find 1:" << cont << endl;

cont = 0;
for (int i = 0; i < alfabeto.size(); i++)
{
    for (int j = 0; j < texto.size(); j++)
    {
        if (alfabeto[i] == texto[j]) {
            cont++;
            break;
        }
    }
    
}
