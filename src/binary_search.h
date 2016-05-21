#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

template<typename T>
class Search {
  public:
    static int BinarySearch(const std::vector<T>& vet, T obj) {
        int vetsize = vet.size();
        int i = 0, j = vetsize - 1;
        while (i <= j) {
            int k = floor(i + j)/2;
            if (vet[k] < obj)
                i = k + 1;
            else if (vet[k] > obj)
                j = k - 1;
            else
                return k;
        }
        return -1;
    }
};

#endif /* BINARY_SEARCH_H */
