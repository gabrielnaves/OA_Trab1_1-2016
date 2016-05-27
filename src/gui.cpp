#include "gui.h"

using namespace std;
using namespace io;

bool GUI::RunMainMenu() {
    ShowMainMenu();
    string op = ReadLine();
    if (op == "1")
        CreateNewIndexFile();
    else if (op == "2")
        PrintLine("Opcao ainda nao implementada!");
    else if (op == "3")
        PrintLine("Opcao ainda nao implementada!");
    else if (op == "4")
        PrintLine("Opcao ainda nao implementada!");
    else if (op == "5")
        PrintLine("Opcao ainda nao implementada!");
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
