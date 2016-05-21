#ifndef GUI_H
#define GUI_H

#include <string>

using namespace std;

void GUI_RunMainMenu();
void GUI_ShowMainMenu();

void GUI_RunMainMenu() {
    GUI_ShowMainMenu();
    string op;
    getline(cin, op);
    if (op == "1")
        cout << "Opcao 1 esta invalida no momento." << endl;
    else
        cout << "Erro! Opcao inexistente!" << endl;
}

void GUI_ShowMainMenu() {
    cout << endl;
    cout << "Digite uma opcao: " << endl;
    cout << "[1]: Criar um arquivo de indices a partir de um arquivo de dados;" << endl;
}

#endif /* GUI_H */
