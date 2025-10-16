#include "Clases/Node.h"
#include "Clases/SparseMatrix.h"
#include <iostream>

int main(){
    SparseMatrix* matriz = new SparseMatrix();
    matriz->add(1,1,1);
    matriz->add(1,2,1);
    matriz->add(1,3,1);
    matriz->add(1,4,1);
    matriz->add(1,5,1);
    matriz->add(1,2,2);
    matriz->add(1,3,2);
    matriz->add(1,1,3);
    matriz->add(1,100,2);
    matriz->printStoredValues();
    return 0;
}