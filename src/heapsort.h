#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

namespace sort {

void Heapsort(std::vector<std::pair<std::string, int> > &index);
void BuildHeap(std::vector<std::pair<std::string, int> > &index);
void Heapify(std::vector<std::pair<std::string, int> > &index, const int pos, const int vetsize);
int left(const int pos, const int vetsize);
int right(const int pos, const int vetsize);
void Swap(std::vector<std::pair<std::string, int> > &index, const int a, const int b);

}

#endif /* HEAPSORT_H */
