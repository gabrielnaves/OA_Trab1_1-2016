#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "gui.h"

using namespace std;

// int main(int argc, char *argv[]) {
//     bool should_quit = false;
//     while (!should_quit)
//         should_quit = GUI::RunMainMenu();
//     return 0;
// }

// int main(int argc, char *argv[]) {
//     CreateIndex("indices/indicelista1.ind", "listas/lista1.txt", "indices/indicesecundariolista1.ind");
// }

// int main(int argc, char *argv[]) {
//     DeleteRegistry("listas/lista1.txt", "indices/indicelista1.ind", "indices/indicesecundariolista1.ind",
//                    "046946VitorBrunoJacinthodeAlme");
// }

int main(int argc, char *argv[]) {
    CreateIndex("indices/indicelista1.ind", "listas/lista1.txt", "indices/indicesecundariolista1.ind");
    DeleteRegistry("listas/lista1.txt", "indices/indicelista1.ind", "indices/indicesecundariolista1.ind",
                   "046946VitorBrunoJacinthodeAlme");
    CreateRegistry("listas/lista1.txt", "indices/indicelista1.ind", "indices/indicesecundariolista1.ind",
                   "123456", "Gabriel Naves da Silva", "32", "EC", "A");
}

// int main(int argc, char*argv[]) {
//     vector<int> index;
//     index.push_back(25);
//     index.push_back(57);
//     index.push_back(48);
//     index.push_back(37);
//     index.push_back(12);
//     index.push_back(92);
//     index.push_back(86);
//     index.push_back(33);
//     Sort::Heapsort<int>(index);
//     for (int i = 0; i < index.size(); ++i)
//         cout << index[i] << endl;

//     cout << endl << Search::BinarySearch<int>(index, 25) << endl;
// }

// int main() {
//     merge::MergeFiles("listas/lista1.txt", "indices/indicelista1.ind",
//                       "listas/lista2.txt", "indices/indicelista2.ind", "listas/lista12.txt");
// }
