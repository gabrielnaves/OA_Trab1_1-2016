#include "delete_reg.h"

using namespace std;
using namespace ind;
using namespace io;

void DeleteRegistry(string data_fname, string index_fname, string secondary_fname, string primary_key) {
    /* Abre o arquivo de dados */
    ifstream data_file(data_fname.c_str());
    if (!data_file) {
        PrintLine("Erro! Arquivo de dados nao existe!");
        return;
    }

    /* Carrega os indices (primario e secundario) */
    Index index = LoadIndex(index_fname);
    SecondaryIndex secondary_index = LoadSecondaryIndex(secondary_fname);

    /* Verifica se o registro existe */
    int registry_pos_on_index = SearchPrimaryKeyOnIndex(index, primary_key);
    if (registry_pos_on_index == -1) {
        PrintLine("Erro! Registro nao existe!");
        return;
    }

     // TALVEZ EU USE ISSO
    // /* Recupera o registro do arquivo de dados (para atualizacao do indice secundario) */
    // int byte_offset = index[registry_pos_on_index].second.first*64;
    // string registry = msc::FindRegistry(data_file, byte_offset);

    /* Atualiza o indice secundario */
    for (int i = 0; i < secondary_index.size(); ++i) {
        if (secondary_index[i].second == registry_pos_on_index)
            secondary_index[i].second = index[registry_pos_on_index].second.second;
        if (secondary_index[i].second > registry_pos_on_index)
            secondary_index[i].second--;
    }

    /* Atualiza os ponteiros no indice primario */
    for (int i = 0; i < index.size(); ++i) {
        if (index[i].second.second > registry_pos_on_index)
            index[i].second.second--;
    }

    ShowIndex(index);
    ShowSecondaryIndex(secondary_index);
}
