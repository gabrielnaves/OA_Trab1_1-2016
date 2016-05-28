#include "create_reg.h"

using namespace std;
using namespace ind;
using namespace io;

void CreateRegistry(string data_fname, string index_fname, string secondary_fname,
                    string matric, string nome, string op, string curso, string turma) {
    /* Abre o arquivo de dados */
    fstream data_file(data_fname.c_str());
    if (!data_file) {
        PrintLine("Erro! Arquivo de dados nao existe!");
        return;
    }

    /* Carrega os indices (primario e secundario) */
    Index index = LoadIndex(index_fname);
    SecondaryIndex secondary_index = LoadSecondaryIndex(secondary_fname);

    /* Verifica se o registro ja existe */
    string primary_key = msc::RemoveSpaces(matric + nome);
    primary_key.resize(30, ' ');
    int registry_pos_on_index = SearchPrimaryKeyOnIndex(index, primary_key);
    if (registry_pos_on_index != -1) {
        PrintLine("Erro! Registro ja existe!");
        return;
    }

    /* Mostra na tela os indices antes da alteracao */
    PrintLine("Indice primario antes da insercao:");
    ShowIndex(index);
    PrintLine("Indice secundario antes da insercao:");
    ShowSecondaryIndex(secondary_index);

    /* Verifica se ha posicoes disponiveis */
    int registry_number_on_data_file;
    int top_of_ped = msc::GetTopOfPed(data_file);
    if (top_of_ped != -1) {
        registry_number_on_data_file = top_of_ped;
        // Recupera a posicao anterior da pilha
        data_file.seekg(top_of_ped*64);
        string str;
        getline(data_file, str);
        int previous_pos_on_stack;
        sscanf(str.c_str(), ". %d", &previous_pos_on_stack);
        // Atualiza o topo da pilha
        data_file.seekg(2);
        data_file << setfill(' ') << setw(2) << previous_pos_on_stack;
        // Retorna para a posicao onde sera escrito o novo registro
        data_file.seekg(registry_number_on_data_file*64);
    }
    else {
        data_file.seekg(0, data_file.end);
        registry_number_on_data_file = (int)(data_file.tellg() / 63);
    }

    /* Escreve o registro no arquivo de dados */
    string str = matric + " " + nome;
    str.resize(48, ' ');
    data_file << str << setfill(' ') << setw(2) << op;
    data_file << setfill(' ') << setw(4) << curso;
    data_file << setfill(' ') << setw(8) << turma;
    if (top_of_ped == -1 )
        data_file << endl;

    data_file.close();

    /* Recria os indices */
    CreateIndex(index_fname, data_fname, secondary_fname);
}
