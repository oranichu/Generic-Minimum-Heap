#include <iostream>
#include "MinHeap.h"


class SaveIndex {
    int data ;
    int index ;
public:
    SaveIndex(int d) : data(d), index(0) {} ;
    void setData(int i) {data = i ;};
    int getData() {return data ;} ;

    void setIndex(int i) {index = i ;};
    int getIndex() {return index ;} ;

    friend std::ostream& operator<<(std::ostream& os,SaveIndex s);

};

std::ostream& operator<<(std::ostream &os,SaveIndex* s) {
    return os<<s->getData() ;
}

class DoNothing {
public:
    void operator()(SaveIndex *a, int j) {
        a->setIndex(j);
    }
};


void printArr(SaveIndex *arr[])  {
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i]->getData() << " ";
    }
    std::cout << std::endl;
    std::cout << "**********************"<< std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i]->getIndex() << " ";
    }
    std::cout << std::endl;
}



int main() {

    int key[10] = {6,8,12,17,0,3,10,4,5,2};
    SaveIndex *data1[10] ;
    for (int i=0 ; i< 10 ; i++) {
        data1[i]=new SaveIndex(key[i]);
    }

    SaveIndex *data2[10] ;
    for (int i=0 ; i< 10 ; i++) {
        data2[i]=new SaveIndex(key[i]);
    }

    MinHeap<SaveIndex*,int,DoNothing> h2 (data2,key,10,-1,DoNothing()) ;

    printArr(data2);

    h2.delMin();
    h2.delNode(8);
    h2.delNode(8);
    h2.delNode(8);
    h2.delNode(8);
    h2.delNode(8);
    h2.delNode(2);


    printArr(data2);

    h2.printHeap();




    return 0;
}