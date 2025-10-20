#include "Sistema.h"
#include "MatrixList.h"
#include <iostream>
Sistema::Sistema() : listaMatrices(){idGlobal=0;}
SparseMatrix* Sistema::buscarMatriz(int id){
    SparseMatrix* mt = listaMatrices.getMatrix(id);
    return mt;
}
void Sistema::crearMatriz(){
    listaMatrices.addMatrix(idGlobal);
    std::cout<<"Nueva matriz vacia creada!: ID:"<<idGlobal<<std::endl;
    idGlobal++;
}
void Sistema::eliminarMatriz(int id){
    listaMatrices.deleteMatrix(id);
}
void Sistema::insertarValor(int id, int valor, int x, int y){
    if(x<1 || y<1){
       std::cout<<"Ingrese coordenadas validas (desde el 1)"<<std::endl;
       return;
    }
    SparseMatrix* mt = buscarMatriz(id);
    if(mt!=nullptr){
        mt->add(valor,x,y);
    }
}
void Sistema::buscarValor(int id, int x, int y){
    if(x<1 || y<1){
       std::cout<<"Ingrese coordenadas validas (desde el 1)"<<std::endl;
       return;
    }
    SparseMatrix* mt = buscarMatriz(id);
    if(mt!=nullptr){
        int v=mt->get(x,y);
        std::cout<<"Encontrado! -> "<<v<<std::endl;
        return;
    }
}
void Sistema::eliminarValor(int id, int x, int y){
    if(x<1 || y<1){
        std::cout<<"Ingrese coordenadas validas (desde el 1)"<<std::endl;
        return;
    }
    SparseMatrix* mt = buscarMatriz(id);
    if(mt!=nullptr){
        mt->remove(x,y);
    }
}
void Sistema::multiplicarMatrices(int id1, int id2){
    SparseMatrix* mt1 = buscarMatriz(id1);
    SparseMatrix* mt2 = buscarMatriz(id2);
    if(mt1==nullptr||mt2==nullptr) return;
    
    SparseMatrix* mt3 = mt1->multiply2(mt2);
    if(mt3!=nullptr){
        std::cout<<"MATRIZ MULTIPLICADA:"<<std::endl;
        mt3->printStoredValues();
        delete mt3;
    }
}
void Sistema::mostrarMatriz(int id){
    SparseMatrix* mt = buscarMatriz(id);
    if(mt!=nullptr){
        mt->printStoredValues();
    }
}
void Sistema::calcularDensidad(int id){
    SparseMatrix* mt = buscarMatriz(id);
    if(mt!=nullptr){
        std::cout<<"La densidad de la matriz es: "<<mt->density()<<std::endl;
        return;
    }
    std::cout<<"La matriz no existe!"<<std::endl;
}
void Sistema::mostrarLista(){
    listaMatrices.showList();
}