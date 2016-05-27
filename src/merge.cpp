#include "merge.h"

using namespace std;
using namespace io;

void merge::MergeFiles(string data_file_1_name, string index_file_1_name,
                       string data_file_2_name, string index_file_2_name, string output_file) {

    /* Abre os arquivos */
    ifstream ind_file1(index_file_1_name.c_str()), ind_file2(index_file_2_name.c_str());
    ifstream data_file1(data_file_1_name.c_str()), data_file2(data_file_2_name.c_str());
    ofstream file_out(output_file.c_str());

    if (not ind_file1) {
        PrintLine("Erro! Arquivo de entrada 1 nao existe!");
        return;
    }
    if (not ind_file2) {
        PrintLine("Erro! Arquivo de entrada 2 nao existe!");
        return;
    }

    PrintLine("Arquivo de dados resultante:");

    string line1, line2;
    getline(ind_file1, line1);
    getline(ind_file2, line2);
    while (not ind_file1.eof() and not ind_file2.eof()) {
        string primary_key_1 = line1.substr(0, 30);
        string primary_key_2 = line2.substr(0, 30);

        if (primary_key_1 < primary_key_2) {
            int reg_number;
            sscanf(line1.c_str(), "%*s %d %*d\n", &reg_number);
            string registry = FindRegistry(data_file1, reg_number*64);
            WriteLine(file_out, registry);
            getline(ind_file1, line1);
        }

        else if (primary_key_1 > primary_key_2) {
            int reg_number;
            sscanf(line2.c_str(), "%*s %d %*d\n", &reg_number);
            string registry = FindRegistry(data_file2, reg_number*64);
            WriteLine(file_out, registry);
            getline(ind_file2, line2);
        }

        else {
            int reg_number;
            sscanf(line1.c_str(), "%*s %d %*d\n", &reg_number);
            string registry = FindRegistry(data_file1, reg_number*64);
            WriteLine(file_out, registry);
            getline(ind_file1, line1);
            getline(ind_file2, line2);
        }
    }

    while (not ind_file1.eof()) {
        int reg_number;
        sscanf(line1.c_str(), "%*s %d %*d\n", &reg_number);
        string registry = FindRegistry(data_file1, reg_number*64);
        WriteLine(file_out, registry);
        getline(ind_file1, line1);
    }

    while (not ind_file2.eof()) {
        int reg_number;
        sscanf(line2.c_str(), "%*s %d %*d\n", &reg_number);
        string registry = FindRegistry(data_file2, reg_number*64);
        WriteLine(file_out, registry);
        getline(ind_file2, line2);
    }
}

void merge::WriteLine(ofstream& file_out, string line) {
    PrintLine(line);
    file_out << line << endl;
}

string merge::FindRegistry(ifstream& data_file, int byte_offset) {
    data_file.seekg(byte_offset);
    string registry;
    getline(data_file, registry);
    return registry;
}
