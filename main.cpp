#include "Clases/Node.h"
#include "Clases/SparseMatrix.h"
#include "Clases/MatrixList.h"
#include "Clases/Sistema.h"
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
void printMenu(){
    std::cout<<"----- Menu de matrices-----"<<std::endl;
    std::cout<<"1. Crear matriz"<<std::endl;
    std::cout<<"2. Eliminar matriz"<<std::endl;
    std::cout<<"3. Insertar valor en matriz"<<std::endl;
    std::cout<<"4. Buscar valor en matriz"<<std::endl;
    std::cout<<"5. Eliminar valor en matriz"<<std::endl;
    std::cout<<"6. Multiplicar matrices"<<std::endl;
    std::cout<<"7. Mostrar matriz"<<std::endl;
    std::cout<<"8. Calcular densidad"<<std::endl;
    std::cout<<"9. Salir"<<std::endl;
    std::cout<<"Ingrese numero>> ";
}

void iniciarMenu(Sistema &systema){
    int opcion,id,valor,x,y;
    do{
        printMenu();
        std::cin>>opcion;
        if(opcion == 1){
            systema.crearMatriz();
        } else if (opcion == 2){
            std::cout<<"Ingrese ID a eliminar>>";
            std::cin>>id;
            systema.eliminarMatriz(id);
        } else if(opcion ==3){
            std::cout<<"Ingrese ID de matriz>>";
            std::cin>>id;
            std::cout<<"Ingrese valor a ingresar>>";
            std::cin>>valor;
            std::cout<<"Ingrese coordenada x>>";
            std::cin>>x;
            std::cout<<"Ingrese coordenada y>>";
            std::cin>>y;
            systema.insertarValor(id,valor,x,y);
        } else if(opcion == 4){
            std::cout<<"Ingrese ID de matriz>>";
            std::cin>>id;
            std::cout<<"Ingrese coordenada x>>";
            std::cin>>x;
            std::cout<<"Ingrese coordenada y>>";
            std::cin>>y;
           systema.buscarValor(id,x,y);
        } else if(opcion == 5){
            std::cout<<"Ingrese ID de matriz>>";
            std::cin>>id;
            std::cout<<"Ingrese coordenada x>>";
            std::cin>>x;
            std::cout<<"Ingrese coordenada y>>";
            std::cin>>y;
            systema.eliminarValor(id,x,y);
        } else if(opcion == 6){
           int id2;
           std::cout<<"Ingrese ID de matriz uno >>";
           std::cin>>id;
           std::cout<<"Ingrese ID de matriz dos >>";
           std::cin>>id2;
           systema.multiplicarMatrices(id,id2);
        } else if(opcion == 7){
            std::cout<<"Ingrese ID de matriz>>";
            std::cin>>id;
            systema.mostrarMatriz(id);
        } else if (opcion==8){
            std::cout<<"Ingrese ID de matriz>>";
            std::cin>>id;
            systema.calcularDensidad(id);
        } else if(opcion==9){
            std::cout<<"Saliendo...";
        } else {
            std::cout<<"Ingrese una opción válida."<<std::endl;
        }
    }while(opcion != 9);
}


using namespace std::chrono;

void testCTIME(int elements,int rows,int cols) {
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
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"Elemen:"<<elements<<" rows:"<<rows<<" cols:"<<cols<<std::endl;
    
    SparseMatrix* matriz1 = new SparseMatrix;
    auto start1 = std::chrono::high_resolution_clock::now();
    for (auto [x, y, value] : data1) {
        matriz1 -> add(value, x, y);
    } 
    auto fin1 = std::chrono::high_resolution_clock::now();

    std::vector<std::tuple <int, int, int>> data2; //(x, y, value)
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
    auto start2 = std::chrono::high_resolution_clock::now();
    for (auto [x, y, value] : data2) {
        matriz2 ->add(value, x, y);
    } 
    auto fin2 = std::chrono::high_resolution_clock::now();


    auto startMult = std::chrono::high_resolution_clock::now();
    matriz1 -> multiply(matriz2);
    auto endMult = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> timeAdd1 = (fin1 - start1);
    std::chrono::duration<double> timeAdd2 = (fin2 - start2);
    std::chrono::duration<double> timeMult = (endMult - startMult);
    double ms1 = timeAdd1.count() * 1000.0;
    double ms2 = timeAdd2.count() * 1000.0;
    double ms3 = timeMult.count() * 1000.0;

    std::cout << "Add1: " << ms1 << " ms" << std::endl;
    std::cout << "Add2: " << ms2 << " ms" << std::endl;
    std::cout << "Mult: " << ms3 << " ms" << std::endl;

    delete matriz1,matriz2;
}
void testADD(int elements,int rows,int cols) {
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
void testMULTIPLY(int elements,int rows,int cols) {
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
void testGET(int elements,int rows,int cols) {
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

void allTest(){

    std::vector<std::tuple<int,int,int>> values;
    values = {{50,12,12},{50,9,9},{100,16,16},{100,12,12},{250,25,25},{250,19,19},{500,36,36},{500,27,27}
,{1000,50,50},{1000,38,38}};
    for(auto [elements, rows, cols] : values){
        std::cout<<"Elements:"<<elements<<" rows:"<<rows<<" cols:"<<cols<<std::endl;
        testADD(elements,rows,cols);
        testMULTIPLY(elements,rows,cols);
        testGET(elements,rows,cols);
        std::cout<<"-----------------------"<<std::endl;
    }
}

int main() {
    allTest();
    return 0;
}

int main2(){
    Sistema systema;
    iniciarMenu(systema);

    return 0;
}