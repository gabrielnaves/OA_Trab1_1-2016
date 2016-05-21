#include "create_index.h"

using namespace std;
using namespace io;

void CreateIndex(string index_fname, string data_fname, string secondary_index_fname) {
    /* Abre o arquivo de dados */
    ifstream data_file(data_fname.c_str());
    if (!data_file) {
        PrintLine("Erro! Arquivo de dados nao existe!");
        return;
    }

    /* Le o arquivo de dados, criando o indice */
    string data_line;
    int registry_number = 0;
    Index index;
    while (getline(data_file, data_line)) {
        string primary_key = RemoveSpaces(data_line.substr(0,48));
        primary_key.resize(30, ' ');
        index.push_back(make_pair(primary_key, make_pair(registry_number, -1)));
        registry_number++;
    }

    /* Ordena o indice com heapsort */
    Sort::Heapsort<IndexReg>(index);

    /* Salva o indice num arquivo (sem informacao do indice secundario) */
    SaveIndex(index_fname, index);

    CreateSecondaryIndex(index_fname, data_fname, secondary_index_fname);
}

void CreateSecondaryIndex(string index_fname, string data_fname, string secondary_index_fname) {
    /* Abre o arquivo de dados */
    ifstream data_file(data_fname.c_str());

    /* Carrega o arquivo de indice primario */
    Index index = LoadIndex(index_fname);

    /* Le o arquivo de dados, guardando chave secundaria e primaria em um intermediario */
    vector<pair<string, string> > intermediate;
    string line;
    while (getline(data_file, line)) {
        string primary_key = RemoveSpaces(line.substr(0,48));
        primary_key.resize(30, ' ');
        string secondary_key = line.substr(52, 2);
        intermediate.push_back(make_pair(secondary_key, primary_key));
    }

    Sort::Heapsort<pair<string, string> >(intermediate);

    /* Constroi o indice secundario a partir do intermediario, e guarda os ponteiros no indice primario */
    vector<pair<string, int> > secondary_index;
    // Processa o primeiro
    int last_ind = Search::BinarySearch<string, pair<int, int> >(index, intermediate[0].second);
    secondary_index.push_back(make_pair(intermediate[0].first, last_ind));
    // Processa o restante
    for (int i = 1; i < intermediate.size(); ++i) {
        int new_ind = Search::BinarySearch<string, pair<int, int> >(index, intermediate[i].second);
        if (intermediate[i].first != secondary_index[secondary_index.size()-1].first)
            secondary_index.push_back(make_pair(intermediate[i].first, new_ind));
        else
            index[last_ind].second.second = new_ind;
        last_ind = new_ind;
    }

    /* Mostra na tela e salva o arquivo de indice primario final */
    PrintLine("Arquivo de indice primario criado: ");
    ShowIndex(index);
    SaveIndex(index_fname, index);

    /* Mostra e salva o arquivo de indice secundario criado */
    PrintLine("Arquivo de indice secundario criado: ");
    ShowSecondaryIndex(secondary_index);
    SaveSecondaryIndex(secondary_index_fname, secondary_index);
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

Index LoadIndex(string index_fname) {
    ifstream primary_index_file(index_fname.c_str());
    Index index;
    string line;
    while (getline(primary_index_file, line)) {
        int registry_number, pointer;
        sscanf(line.c_str(), "%*s %d %d\n", &registry_number, &pointer);
        index.push_back(make_pair(line.substr(0,30), make_pair(registry_number, pointer)));
    }
    return index;
}

void SaveIndex(string index_fname, const Index& index) {
    ofstream index_file(index_fname.c_str());
    for (int i = 0; i < index.size(); ++i)
        index_file << index[i].first << " "
                   << setw(2) << index[i].second.first << " "
                   << setw(2) << index[i].second.second << endl;
}

void ShowIndex(const Index& index) {
    for (int i = 0; i < index.size(); ++i) {
        cout << index[i].first << " "
             << setfill(' ') << setw(2) << index[i].second.first << " "
             << setw(2) << index[i].second.second << endl;
    }
}

void ShowSecondaryIndex(const std::vector<std::pair<std::string, int> >& secondary_index) {
    cout << endl;
    for (int i = 0; i < secondary_index.size(); ++i)
        cout << secondary_index[i].first << " " << setw(2) << secondary_index[i].second << endl;
}

void SaveSecondaryIndex(std::string fname, const std::vector<std::pair<std::string, int> >& secondary_index) {
    ofstream secondary_index_file(fname.c_str());
    for (int i = 0; i < secondary_index.size(); ++i)
        secondary_index_file << secondary_index[i].first << " "
                             << setw(2) << secondary_index[i].second << endl;
}
