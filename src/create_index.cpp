#include "create_index.h"

using namespace std;
using namespace io;
using namespace ind;

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
        if (data_line[0] != '.') {
            string primary_key = msc::RemoveSpaces(data_line.substr(0,48));
            primary_key.resize(30, ' ');
            index.push_back(make_pair(primary_key, make_pair(registry_number, -1)));
        }
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
        if (line[0] == '.')
            continue;
        string primary_key = msc::RemoveSpaces(line.substr(0,48));
        primary_key.resize(30, ' ');
        string secondary_key = line.substr(52, 2);
        intermediate.push_back(make_pair(secondary_key, primary_key));
    }

    Sort::Heapsort<pair<string, string> >(intermediate);

    /* Constroi o indice secundario a partir do intermediario, e guarda os ponteiros no indice primario */
    SecondaryIndex secondary_index;
    // Processa o primeiro
    int last_ind = SearchPrimaryKeyOnIndex(index, intermediate[0].second);
    secondary_index.push_back(make_pair(intermediate[0].first, last_ind));
    // Processa o restante
    for (int i = 1; i < intermediate.size(); ++i) {
        int new_ind = SearchPrimaryKeyOnIndex(index, intermediate[i].second);
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
