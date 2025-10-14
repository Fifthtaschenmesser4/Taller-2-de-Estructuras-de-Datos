#include "Clases/Node.h"
#include "Clases/SparseMatrix.h"
#include <iostream>

int main(){
    SparseMatrix* matriz = new SparseMatrix();
    matriz->add(1,1,1);
    matriz->add(1,4,1);
    matriz->add(1,3,1);
    matriz->add(1,2,1);
    matriz->add(1,100,2);
    matriz->printCabecerasX();
    matriz->printCabecerasY();
    return 0;
}