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
    PrintLine("Digite o nome do arquivo de dados");
    string data_fname = ReadLine();
    data_fname = "listas/" + data_fname;

    PrintLine("Digite o nome do arquivo de indices primario");
    string index_fname = ReadLine();
    index_fname = "indices/" + index_fname;

    PrintLine("Digite o nome do arquivo de indices secundario");
    string secondary_fname = ReadLine();
    secondary_fname = "indices/" + secondary_fname;

    cout << endl;
    CreateIndex(index_fname, data_fname, secondary_fname);
}

void GUI::AddRegistryToDataFile() {
    PrintLine("Opcao ainda nao implementada");
}

void GUI::RemoveRegistryFromDataFile() {
    PrintLine("Opcao ainda nao implementada");
}

void GUI::UpdateRegistryFromDataFile() {
    PrintLine("Opcao ainda nao implementada");
}

void GUI::MergeDataFilesUsingTheirIndexFiles() {
    PrintLine("Digite o nome do primeiro arquivo de dados");
    string data_1_fname = ReadLine();
    data_1_fname = "listas/" + data_1_fname;

    PrintLine("Digite o nome do primeiro arquivo de indices primario");
    string index_1_fname = ReadLine();
    index_1_fname = "indices/" + index_1_fname;

    PrintLine("Digite o nome do segundo arquivo de dados");
    string data_2_fname = ReadLine();
    data_2_fname = "listas/" + data_2_fname;

    PrintLine("Digite o nome do segundo arquivo de indices primario");
    string index_2_fname = ReadLine();
    index_2_fname = "indices/" + index_2_fname;

    PrintLine("Digite o nome do arquivo de dados resultante");
    string file_out = ReadLine();
    file_out = "listas/" + file_out;

    cout << endl;
    merge::MergeFiles(data_1_fname, index_1_fname, data_2_fname, index_2_fname, file_out);
}
