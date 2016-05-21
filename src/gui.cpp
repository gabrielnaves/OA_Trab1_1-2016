#include "gui.h"

using namespace std;
using namespace io;

bool gui::RunMainMenu() {
    ShowMainMenu();
    string op = ReadLine();
    if (op == "1")
        CreateNewIndexFile();
    else if (op == "Q" or op == "q")
        return true;
    else
        PrintLine("Erro! Opcao inexistente!");
    return false;
}

void gui::ShowMainMenu() {
    cout << endl;
    PrintLine("Digite uma opcao: ");
    PrintLine("[1]: Criar um arquivo de indices a partir de um arquivo de dados");
    PrintLine("[Q]: Sair");
}

void gui::CreateNewIndexFile() {
    PrintLine("Digite o nome do arquivo de indices");
    string index_fname = ReadLine();
    index_fname = "indices/" + index_fname; // Para

    PrintLine("Digite o nome do arquivo de dados");
    string data_fname = ReadLine();
    data_fname = "listas/" + data_fname; // Para

    CreateIndex(index_fname, data_fname);
}
