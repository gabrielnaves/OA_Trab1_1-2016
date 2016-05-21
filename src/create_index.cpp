#include "create_index.h"

using namespace std;
using namespace io;

void CreateIndex(std::string index_fname, std::string data_fname) {
    /* Abre o arquivo de dados */
    ifstream data_file(data_fname.c_str());
    if (!data_file) {
        PrintLine("Erro! Arquivo de dados nao existe!");
        return;
    }

    /* Le o arquivo de dados, criando o indice */
    string data_line;
    int registry_number = 0;
    vector<pair<string,int> > index;
    while (getline(data_file, data_line)) {
        string primary_key = RemoveSpaces(data_line.substr(0,48));
        primary_key.resize(30, ' ');
        index.push_back(make_pair(primary_key, registry_number));
        registry_number++;
    }

    /* Ordena o indice com heapsort */
    //###### Falta essa parte ######

    /* Salva o indice num arquivo */
    ofstream index_file(index_fname.c_str());
    for (int i = 0; i < index.size(); ++i)
        index_file << index[i].first << " " << setfill('0') << setw(2) << index[i].second << endl;
}

string RemoveSpaces(string str) {
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            str.erase(str.begin() + i);
            i--;
        }
    }
    return str;
}
