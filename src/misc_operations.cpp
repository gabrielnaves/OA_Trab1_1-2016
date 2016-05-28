#include "misc_operations.h"

using namespace std;

string msc::FindRegistry(ifstream& data_file, int byte_offset) {
    data_file.seekg(byte_offset);
    string registry;
    getline(data_file, registry);
    return registry;
}

int msc::GetTopOfPed(std::fstream& data_file) {
    int top_of_ped;
    data_file.seekg(0);
    string str;
    getline(data_file, str);
    sscanf(str.c_str(), ". %d", &top_of_ped);
    return top_of_ped;
}
