#ifndef IO_OPERATIONS_H
#define IO_OPERATIONS_H

#include <iostream>
#include <string>

namespace io {

void PrintLine(std::string msg);
std::string ReadLine();
std::string ReadLine(std::string msg);
std::string ReadFileName(std::string file_prefix, std::string msg);

}

#endif /* IO_OPERATIONS_H */
