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
    void operator()(SaveIndex* a,int j){
        a->setIndex(j) ;
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
    printArr(data1);
    MinHeap<SaveIndex*,int,DoNothing> h (data1,key,10,DoNothing()) ;
    h.printHeap();

    std::cout << "**********************" << std::endl ;

    printArr(data1);

    return 0;
}