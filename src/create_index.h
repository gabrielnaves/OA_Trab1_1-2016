#ifndef CREATE_INDEX_H
#define CREATE_INDEX_H

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "io_operations.h"
#include "heapsort.h"
#include "binary_search.h"
#include "index.h"

void CreateIndex(std::string index_fname, std::string data_fname, std::string secondary_index_fname);
void CreateSecondaryIndex(std::string index_fname, std::string data_fname, std::string secondary_index_fname);

std::string RemoveSpaces(std::string);

#endif /* CREATE_INDEX_H */
