#include <iostream>
#include <cstdlib>
#include "MinHeap.h"


class SaveIndex {
    int data;
    int index;
public:
    SaveIndex(int d) : data(d), index(0) {};

    void setData(int i) { data = i; };

    int getData() { return data; };

    void setIndex(int i) { index = i; };

    int getIndex() { return index; };

    friend std::ostream &operator<<(std::ostream &os, SaveIndex s);

};

std::ostream &operator<<(std::ostream &os, SaveIndex *s) {
    return os << s->getData();
}

class DoNothing {
public:
    void operator()(SaveIndex *a, int j) {
        a->setIndex(j);
    }
};


void printArr(SaveIndex *arr[]) {
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i]->getData() << " ";
    }
    std::cout << std::endl;
    std::cout << "**********************" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i]->getIndex() << " ";
    }
    std::cout << std::endl;
}


int main() {

    int key[500];
    SaveIndex *data1[500];
    for (int i = 0; i < 500; i++) {
        key[i] = rand() % 500 + 1;
    }
    for (int i = 0; i < 500; i++) {
        data1[i] = new SaveIndex(key[i]);
    }

    MinHeap<SaveIndex *, int, DoNothing> h2(data1, key, 30, -1, DoNothing());

    for (int i = 30; i < 500; i++) {
        h2.insert(data1[i], key[i]);
    }
    int min = 501;
    int minIndex = -1;
    for (int j = 0; j < 500; j++) {
        for (int i = 0; i < 500; i++) {
            if (key[i] < min) {
                min = key[i];
                minIndex = i;
            }
        }
        if ((h2.getMin()->getData()!=min) || (h2.getMin()->getIndex()!=1) ) {
            std::cout << "************** FALSEEE ***********" << std::endl ;
        }
        std::cout << key[minIndex] << " " ;
        key[minIndex] = 501 ;
        min = 501 ;
        minIndex =-1 ;
        h2.delMin();
    }

    return 0;
}