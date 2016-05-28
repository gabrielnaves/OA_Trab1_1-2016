#include "gui.h"

using namespace std;
using namespace io;

bool GUI::RunMainMenu() {
    ShowMainMenu();
    string op = ReadLine();
    if (op == "1")
        CreateNewIndexFile();
    else if (op == "2")
        AddRegistryToDataFile();
    else if (op == "3")
        RemoveRegistryFromDataFile();
    else if (op == "4")
        UpdateRegistryFromDataFile();
    else if (op == "5")
        MergeDataFilesUsingTheirIndexFiles();
    else if (op == "Q" or op == "q")
        return true;
    else
        PrintLine("Erro! Opcao inexistente!");
    return false;
}

void GUI::ShowMainMenu() {
    cout << endl;
    PrintLine("Digite uma opcao: ");
    PrintLine("[1]: Criar um arquivo de indices a partir de um arquivo de dados");
    PrintLine("[2]: Inserir um registro em um arquivo de dados");
    PrintLine("[3]: Excluir um registro em um arquivo de dados");
    PrintLine("[4]: Modificar um registro em um arquivo de dados");
    PrintLine("[5]: Executar uniao de dois arquivos de dados");
    PrintLine("[Q]: Sair");
}

void GUI::CreateNewIndexFile() {
    string data_fname = ReadFileName("listas/", "Digite o nome do arquivo de dados");
    string index_fname = ReadFileName("indices/", "Digite o nome do arquivo de indices primario");
    string secondary_fname = ReadFileName("indices/", "Digite o nome do arquivo de indices secundario");

    cout << endl;
    CreateIndex(index_fname, data_fname, secondary_fname);
}

void GUI::AddRegistryToDataFile() {
    PrintLine("Opcao ainda nao implementada");
}

void GUI::RemoveRegistryFromDataFile() {
    string data_fname = ReadFileName("listas/", "Digite o nome do arquivo de dados");
    string index_fname = ReadFileName("indices/", "Digite o nome do arquivo de indices primario");
    string secondary_fname = ReadFileName("indices/", "Digite o nome do arquivo de indices secundario");

    string primary_key = msc::RemoveSpaces(ReadLine("Digite a matricula e nome completo do aluno"));
    primary_key.resize(30, ' ');

    DeleteRegistry(data_fname, index_fname, secondary_fname, primary_key);
}

void GUI::UpdateRegistryFromDataFile() {
    PrintLine("Opcao ainda nao implementada");
}

void GUI::MergeDataFilesUsingTheirIndexFiles() {
    string data_1_fname = ReadFileName("listas/", "Digite o nome do primeiro arquivo de dados");
    string index_1_fname = ReadFileName("indices/", "Digite o nome do primeiro arquivo de indices primario");

    string data_2_fname = ReadFileName("listas/", "Digite o nome do segundo arquivo de dados");
    string index_2_fname = ReadFileName("indices/", "Digite o nome do segundo arquivo de indices primario");

    string file_out = ReadFileName("listas/", "Digite o nome do arquivo de dados resultante");

    cout << endl;
    merge::MergeFiles(data_1_fname, index_1_fname, data_2_fname, index_2_fname, file_out);
}
