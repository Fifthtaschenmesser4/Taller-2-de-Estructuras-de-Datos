#include "Clases/Node.h"
#include "Clases/SparseMatrix.h"
#include <iostream>

int main(){
    SparseMatrix* matriz = new SparseMatrix();
    matriz->add(1,1,1);
    matriz->add(2,2,1);
    matriz->add(3,3,1);
    matriz->add(4,1,2);
    matriz->add(5,2,2);
    matriz->add(6,3,2);
    std::cout<<"matriz 1:"<<std::endl;
    matriz->printStoredValues();

    SparseMatrix* m2 = new SparseMatrix();
    m2->add(5,1,1);
    m2->add(-1,2,1);
    m2->add(1,1,2);
    m2->add(-2,1,3);
    m2->add(3,2,3);
    std::cout<<"matriz 2:"<<std::endl;
    m2->printStoredValues();

    SparseMatrix* m3 = matriz->multiply(m2);
    if(m3!=nullptr){
        std::cout<<"matriz MULTIPLICADA:"<<std::endl;
        m3->printStoredValues();
    } else{
        std::cout<<"NULO"<<std::endl;
    }
    return 0;
}