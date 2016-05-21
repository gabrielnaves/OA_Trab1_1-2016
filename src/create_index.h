#ifndef CREATE_INDEX_H
#define CREATE_INDEX_H

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "io_operations.h"
#include "heapsort.h"

void CreateIndex(std::string index_fname, std::string data_fname);

std::string RemoveSpaces(std::string);

#endif /* CREATE_INDEX_H */
