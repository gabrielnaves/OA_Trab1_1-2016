#include "delete_reg.h"

using namespace std;
using namespace ind;
using namespace io;

void DeleteRegistry(string data_fname, string index_fname, string secondary_fname, string primary_key) {
    /* Abre o arquivo de dados */
    fstream data_file(data_fname.c_str());
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

    /* Faz a exclusão do registro no arquivo de dados, e atualiza a PED */
    int top_of_ped = msc::GetTopOfPed(data_file);
    // Deleta o registro
    int byte_offset = index[registry_pos_on_index].second.first*64;
    data_file.seekg(byte_offset);
    data_file << ". " << setfill(' ') << setw(2) << top_of_ped << " ";
    // Atualiza o topo da pilha
    data_file.seekg(2);
    data_file << setfill(' ') << setw(2) << index[registry_pos_on_index].second.first;

    /* Finalmente, exclui o registro do indice primario, mostra na tela e salva nos arquivos */
    DeleteRegFromIndex(index, index[registry_pos_on_index]);
    ShowIndex(index);
    ShowSecondaryIndex(secondary_index);
    SaveIndex(index_fname, index);
    SaveSecondaryIndex(secondary_fname, secondary_index);
}
