#ifndef MISC_OPERATIONS_H
#define MISC_OPERATIONS_H

#include <iostream>
#include <string>
#include <fstream>

namespace msc {

std::string FindRegistry(std::ifstream& data_file, int byte_offset);
int GetTopOfPed(std::fstream& data_file);
std::string RemoveSpaces(std::string str);

}

#endif /* MISC_OPERATIONS_H */
