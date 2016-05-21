#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "gui.h"
#include "binary_search.h"

using namespace std;

// int main(int argc, char *argv[]) {
//     bool should_quit = false;
//     while (!should_quit)
//         should_quit = gui::RunMainMenu();
//     return 0;
// }

// int main(int argc, char *argv[]) {
//     CreateIndex("indices/indicelista1.ind", "listas/lista1.txt");
// }

int main(int argc, char*argv[]) {
    vector<int> index;
    index.push_back(25);
    index.push_back(57);
    index.push_back(48);
    index.push_back(37);
    index.push_back(12);
    index.push_back(92);
    index.push_back(86);
    index.push_back(33);
    Sort<int>::Heapsort(index);
    for (int i = 0; i < index.size(); ++i)
        cout << index[i] << endl;

    cout << endl << Search<int>::BinarySearch(index, 12) << endl;
}
