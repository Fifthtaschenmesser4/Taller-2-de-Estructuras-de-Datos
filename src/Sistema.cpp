#include "../include/Sistema.h"
#include "../include/MatrixList.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <cmath>
#include <random>
#include <chrono>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std::chrono;
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
    
    SparseMatrix* mt3 = mt1->multiply(mt2);
    if(mt3!=nullptr){
        std::cout<<"Matriz multiplicada:"<<std::endl;
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
void Sistema::testADD(int elements,int rows,int cols) {
    for(int i = 1;i<=2;i++){
    std::vector<std::tuple <int, int, int>> data1; //(x, y, value)
    std::set<std::pair<int,int>> used1;
    while (data1.size() < elements) {
        int x = rand() % cols + 1;
        int y = rand() % rows + 1;
        if (used1.count({x,y}) == 0) {
            int value = rand() % 100 + 1;
            data1.push_back({x,y,value});
            used1.insert({x,y});
        }
    }
    
    SparseMatrix* matriz1 = new SparseMatrix;
    auto start1 = std::chrono::high_resolution_clock::now();
    for (auto [x, y, value] : data1) {
        matriz1 -> add(value, x, y);
    } 
    auto fin1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeAdd1 = (fin1 - start1);
    double ms1 = timeAdd1.count() * 1000.0;
    std::cout << "Add test " <<i<<": "<< ms1 << " ms" << std::endl;
    delete matriz1;
    }
}
void Sistema::testMULTIPLY(int elements,int rows,int cols) {
    for(int i = 1;i<=2;i++){
    std::vector<std::tuple <int, int, int>> data1; 
    std::set<std::pair<int,int>> used1;
    while (data1.size() < elements) {
        int x = rand() % cols + 1;
        int y = rand() % rows + 1;
        if (used1.count({x,y}) == 0) {
            int value = rand() % 100 + 1;
            data1.push_back({x,y,value});
            used1.insert({x,y});
        }
    }
    SparseMatrix* matriz1 = new SparseMatrix;
    for (auto [x, y, value] : data1) {
        matriz1 -> add(value, x, y);
    } 

    std::vector<std::tuple <int, int, int>> data2; 
    std::set<std::pair<int,int>> used2;
    while (data2.size() < elements) {
        int x = rand() % cols + 1;
        int y = rand() % rows + 1;
        if (used2.count({x,y}) == 0) {
            int value = rand() % 100 + 1;
            data2.push_back({x,y,value});
            used2.insert({x,y});
        }
    }
    SparseMatrix* matriz2 = new SparseMatrix;
    for (auto [x, y, value] : data2) {
        matriz2 ->add(value, x, y);
    } 
    
    auto startMult = std::chrono::high_resolution_clock::now();
    matriz1 -> multiply(matriz2);
    auto endMult = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeMult = (endMult - startMult);
    double ms1 = timeMult.count() * 1000.0;
    std::cout << "Multiply test " <<i<<": "<< ms1 << " ms" << std::endl;
    delete matriz1, matriz2;
    }
}
void Sistema::testGET(int elements,int rows,int cols) {
    for(int i = 1;i<=2;i++){
    std::vector<std::tuple <int, int, int>> data1; 
    std::set<std::pair<int,int>> used1;
    while (data1.size() < elements) {
        int x = rand() % cols + 1;
        int y = rand() % rows + 1;
        if (used1.count({x,y}) == 0) {
            int value = rand() % 100 + 1;
            data1.push_back({x,y,value});
            used1.insert({x,y});
        }
    }
    SparseMatrix* matriz1 = new SparseMatrix;
    for (auto [x, y, value] : data1) {
        matriz1 -> add(value, x, y);
    } 

    std::vector<std::tuple <int, int>> data2; 
    std::set<std::pair<int,int>> used2;
    while (data2.size() < elements) {
        int x = rand() % cols + 1;
        int y = rand() % rows + 1;
        if (used2.count({x,y}) == 0) {
            int value = rand() % 100 + 1;
            data2.push_back({x,y});
            used2.insert({x,y});
        }
    }
   
    auto startGet = std::chrono::high_resolution_clock::now();
    for (auto [x, y] : data2) {
        matriz1 ->get(x, y);
    } 
    auto endGet = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> timeGet = (endGet - startGet);
    double ms1 = timeGet.count() * 1000.0;
    std::cout << "Get test " <<i<<": "<< ms1 << " ms" << std::endl;
    delete matriz1;
    }
}
void Sistema::allTest(){

    std::vector<std::tuple<int,int,int>> values;
    values = {{50,12,12},{50,9,9},{100,16,16},{100,12,12},{250,25,25},{250,19,19},{500,36,36},{500,27,27}
,{1000,50,50},{1000,38,38},{5000,84,84},{5000,111,113}};
    for(auto [elements, rows, cols] : values){
        std::cout<<"Elements:"<<elements<<" rows:"<<rows<<" cols:"<<cols<<std::endl;
        testADD(elements,rows,cols);
        testMULTIPLY(elements,rows,cols);
        testGET(elements,rows,cols);
        std::cout<<"-----------------------"<<std::endl;
    }
}
