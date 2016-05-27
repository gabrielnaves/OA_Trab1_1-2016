#include "misc_operations.h"

using namespace std;

string msc::FindRegistry(ifstream& data_file, int byte_offset) {
    data_file.seekg(byte_offset);
    string registry;
    getline(data_file, registry);
    return registry;
}
