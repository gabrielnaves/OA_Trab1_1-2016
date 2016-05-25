#ifndef INDEX_H
#define INDEX_H

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "io_operations.h"

namespace ind {

typedef std::pair<std::string, std::pair<int, int> > IndexReg;
typedef std::vector<IndexReg> Index;

Index LoadIndex(std::string index_fname);
void SaveIndex(std::string index_fname, const Index& index);
void ShowIndex(const Index& index);

void ShowSecondaryIndex(const std::vector<std::pair<std::string, int> >& secondary_index);
void SaveSecondaryIndex(std::string fname, const std::vector<std::pair<std::string, int> >& secondary_index);

};

#endif /* INDEX_H */
