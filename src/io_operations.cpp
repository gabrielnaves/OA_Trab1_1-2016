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

string io::ReadFileName(string file_prefix, string msg) {
    PrintLine(msg);
    return file_prefix + ReadLine();
}
