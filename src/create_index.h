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

typedef std::pair<std::string, std::pair<int, int> > IndexReg;
typedef std::vector<IndexReg> Index;

void CreateIndex(std::string index_fname, std::string data_fname);
void CreateSecondaryIndex(std::string index_fname, std::string data_fname, std::string secondary_index_fname);

Index LoadIndex(std::string index_fname);
void SaveIndex(std::string index_fname, const Index& index);
void ShowIndex(const Index& index);

void ShowSecondaryIndex(const std::vector<std::pair<std::string, int> >& secondary_index);
void SaveSecondaryIndex(std::string fname, const std::vector<std::pair<std::string, int> >& secondary_index);

std::string RemoveSpaces(std::string);

#endif /* CREATE_INDEX_H */
