#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

class Sort {
  public:
    /**
     * Ordena vetores de qualquer tipo (desde que o tipo suporte os operadores `<` e `>`)
     * Exemplo de uso: `Sort::Heapsort<int>(Vetor);`
     * Onde "Vetor" é um `std::vector<int>`
     */
    template<typename T>
    static void Heapsort(std::vector<T>& index) {
        int vetsize = index.size();
        BuildHeap(index);

        for(int pos = vetsize-1; pos >= 1; --pos) {
            Swap(index, 0, pos);
            vetsize--;
            Heapify(index, 0, vetsize);
        }
    }

  private:
    template<typename T>
    static void BuildHeap(std::vector<T>& index) {
        for (int p = index.size()-1; p >= 0; p--)
        Heapify(index, p, index.size());
    }

    template<typename T>
    static void Heapify(std::vector<T>& index, const int pos, const int vetsize) {
        int l = left(pos, vetsize);
        int r = right(pos, vetsize);

        int maior = (l != -1 and index[l] > index[pos]) ? l : pos;
        maior = (r != -1 and index[r] > index[maior]) ? r : maior;

        if (maior != pos) {
            Swap(index, pos, maior);
            Heapify(index, maior, vetsize);
        }
    }

    template<typename T>
    static void Swap(std::vector<T>& index, const int a, const int b) {
        T tmp = index[a];
        index[a] = index[b];
        index[b] = tmp;
    }

    static int left(const int pos, const int vetsize) {
        int res = (((pos + 1) * 2) - 1);
        return res < vetsize ? res : -1;
    }

    static int right(const int pos, const int vetsize) {
        int res = ((pos + 1) * 2);
        return res < vetsize ? res : -1;
    }
};

#endif /* HEAPSORT_H */
