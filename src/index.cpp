#include "index.h"

using namespace std;
using namespace io;

ind::Index ind::LoadIndex(string index_fname) {
    ifstream primary_index_file(index_fname.c_str());
    Index index;
    string line;
    while (getline(primary_index_file, line)) {
        int registry_number, pointer;
        sscanf(line.c_str(), "%*s %d %d\n", &registry_number, &pointer);
        index.push_back(make_pair(line.substr(0,30), make_pair(registry_number, pointer)));
    }
    return index;
}

void ind::SaveIndex(string index_fname, const Index& index) {
    ofstream index_file(index_fname.c_str());
    for (int i = 0; i < index.size(); ++i)
        index_file << index[i].first << " "
                   << setw(2) << index[i].second.first << " "
                   << setw(2) << index[i].second.second << endl;
}

void ind::ShowIndex(const Index& index) {
    for (int i = 0; i < index.size(); ++i) {
        cout << index[i].first << " "
             << setfill(' ') << setw(2) << index[i].second.first << " "
             << setw(2) << index[i].second.second << endl;
    }
}

ind::SecondaryIndex ind::LoadSecondaryIndex(std::string fname) {
    ifstream secondary_index_file(fname.c_str());
    SecondaryIndex secondary_index;
    string line;
    while (getline(secondary_index_file, line)) {
        int pointer;
        sscanf(line.c_str(), "%*s %d\n", &pointer);
        secondary_index.push_back(make_pair(line.substr(0,2), pointer));
    }
    return secondary_index;
}

void ind::SaveSecondaryIndex(std::string fname, const std::vector<std::pair<std::string, int> >& secondary_index) {
    ofstream secondary_index_file(fname.c_str());
    for (int i = 0; i < secondary_index.size(); ++i)
        secondary_index_file << secondary_index[i].first << " "
                             << setw(2) << secondary_index[i].second << endl;
}

void ind::ShowSecondaryIndex(const std::vector<std::pair<std::string, int> >& secondary_index) {
    for (int i = 0; i < secondary_index.size(); ++i)
        cout << secondary_index[i].first << " " << setw(2) << secondary_index[i].second << endl;
}
