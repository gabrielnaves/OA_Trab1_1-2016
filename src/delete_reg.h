#ifndef DELETE_REG_H
#define DELETE_REG_H

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "io_operations.h"
#include "misc_operations.h"
#include "binary_search.h"
#include "index.h"

void DeleteRegistry(std::string data_fname, std::string index_fname, std::string secondary_fname,
                    std::string primary_key);

#endif /* DELETE_REG_H */
