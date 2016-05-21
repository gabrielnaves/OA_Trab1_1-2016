#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

class Search {
  public:
    /**
     * Exemplo de uso: `Search::BinarySearch<int>(Vetor, Objeto)`
     * Onde "Vetor" é um `std::vector<int>` e "Objeto" é do tipo `int`
     */
    template<typename T>
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

    /**
     * Para buscas em vector<pair<a, b> >, onde apenas 'a' deve ser levado em consideracao
     * Exemplo de uso: `Search::BinarySearch<int, float>(Vetor, Objeto);`
     * Onde "Vetor" é um `std::vector<std::pair<int, float> > ` e "Objeto" é do tipo `int`
     */
    template<typename T, typename U>
    static int BinarySearch(const std::vector<std::pair<T, U> >& vet, T obj) {
        int vetsize = vet.size();
        int i = 0, j = vetsize - 1;
        while (i <= j) {
            int k = floor(i + j)/2;
            if (vet[k].first < obj)
                i = k + 1;
            else if (vet[k].first > obj)
                j = k - 1;
            else
                return k;
        }
        return -1;
    }
};

#endif /* BINARY_SEARCH_H */
