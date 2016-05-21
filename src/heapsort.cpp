#include "heapsort.h"

using namespace std;

void sort::Heapsort(vector<pair<string, int> > &index) {
    int vetsize = index.size();
    BuildHeap(index);

    for(int pos = vetsize-1; pos >= 1; --pos) {
        Swap(index, 0, pos);
        vetsize--;
        Heapify(index, 0, vetsize);
    }
}

void sort::BuildHeap(vector<pair<string, int> > &index) {
    for (int p = index.size()-1; p >= 0; p--)
        Heapify(index, p, index.size());
}

void sort::Heapify(vector<pair<string, int> > &index, const int pos, const int vetsize) {
    int l = left(pos, vetsize);
    int r = right(pos, vetsize);

    int maior = (l != -1 and index[l].first > index[pos].first) ? l : pos;
    maior = (r != -1 and index[r].first > index[maior].first) ? r : maior;

    if (maior != pos) {
        Swap(index, pos, maior);
        Heapify(index, maior, vetsize);
    }
}

int sort::left(const int pos, const int vetsize) {
    int res = (((pos + 1) * 2) - 1);
    return res < vetsize ? res : -1;
}

int sort::right(const int pos, const int vetsize) {
    int res = ((pos + 1) * 2);
    return res < vetsize ? res : -1;
}

void sort::Swap(vector<pair<string, int> > &index, const int a, const int b) {
    pair<string, int> tmp = index[a];
    index[a] = index[b];
    index[b] = tmp;
}

