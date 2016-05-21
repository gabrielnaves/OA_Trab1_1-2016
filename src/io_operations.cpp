#include "io_operations.h"

using namespace std;

string io::ReadLine() {
    string line;
    getline(cin, line);
    return line;
}

void io::PrintLine(string msg) {
    cout << msg << endl;
}
