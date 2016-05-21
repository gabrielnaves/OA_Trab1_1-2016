#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>

template<typename T>
class Sort {
  public:
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
    static void BuildHeap(std::vector<T>& index) {
        for (int p = index.size()-1; p >= 0; p--)
        Heapify(index, p, index.size());
    }

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
