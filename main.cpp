#include <iostream>
#include "MinHeap.h"

class DoNothing {
public:
    void operator()(int i,int j){
        return ;
    }
};

int main() {

    int key[10] = {6,8,12,17,0,3,10,4,5,2};
    int data1[10] = {1,2,3,4,5,6,7,8,9,10};
    int data2[10] = {6,8,12,17,0,3,10,4,5,2} ;
    MinHeap<int,int,DoNothing> h (data2,key,10,DoNothing()) ;
    h.printHeap();

    return 0;
}