#ifndef CREATE_REG_H
#define CREATE_REG_H

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "io_operations.h"
#include "misc_operations.h"
#include "binary_search.h"
#include "index.h"
#include "create_index.h"

void CreateRegistry(std::string data_fname, std::string index_fname, std::string secondary_fname,
                    std::string matric, std::string nome, std::string op, std::string curso, std::string turma);

#endif /* CREATE_REG_H */
