#ifndef MERGE_H
#define MERGE_H

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "io_operations.h"
#include "misc_operations.h"

namespace merge {

void MergeFiles(std::string data_file_1_name, std::string index_file_1_name,
                std::string data_file_2_name, std::string index_file_2_name, std::string output_file);
void WriteLine(std::ofstream& file_out, std::string line);

}

#endif /* MERGE_H */
