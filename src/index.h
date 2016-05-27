#ifndef INDEX_H
#define INDEX_H

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "io_operations.h"
#include "binary_search.h"

namespace ind {
/* INDICE PRIMARIO */
/**
 * IndexReg.first = indice primario
 * IndexReg.second.first = numero do registro
 * IndexReg.second.second = ponteiro para o proximo indice secundario
 */
typedef std::pair<std::string, std::pair<int, int> > IndexReg;
typedef std::vector<IndexReg> Index;

Index LoadIndex(std::string index_fname);
void SaveIndex(std::string index_fname, const Index& index);
void ShowIndex(const Index& index);

IndexReg MakeIndexReg(std::string primary_key, int registry_number, int secondary_index_pointer);
void AddRegToIndex(Index& index, IndexReg index_reg);
void DeleteRegFromIndex(Index& index, IndexReg index_reg);

/* Retorna o indice no Index onde o registro foi encontrado, -1 se nao encontrar */
int SearchPrimaryKeyOnIndex(Index index, std::string primary_key);

/* INDICE SECUNDARIO */
/**
 * IndexReg.first = indice secundario
 * IndexReg.second = ponteiro para o primeiro registro no indice primario
 *                   que faz parte da categoria do indice secundario
 */
typedef std::vector<std::pair<std::string, int> > SecondaryIndex;

SecondaryIndex LoadSecondaryIndex(std::string fname);
void SaveSecondaryIndex(std::string fname, const std::vector<std::pair<std::string, int> >& secondary_index);
void ShowSecondaryIndex(const std::vector<std::pair<std::string, int> >& secondary_index);

};

#endif /* INDEX_H */
