#include "gui.h"

using namespace std;

void gui::RunMainMenu() {
    ShowMainMenu();
    string op;
    getline(cin, op);
    if (op == "1")
        cout << "Opcao 1 esta invalida no momento." << endl;
    else
        cout << "Erro! Opcao inexistente!" << endl;
}

void gui::ShowMainMenu() {
    cout << endl;
    cout << "Digite uma opcao: " << endl;
    cout << "[1]: Criar um arquivo de indices a partir de um arquivo de dados;" << endl;
}
