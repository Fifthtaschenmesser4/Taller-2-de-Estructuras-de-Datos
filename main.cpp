#include "Clases/Node.h"
#include "Clases/SparseMatrix.h"
#include "Clases/MatrixList.h"
#include "Clases/Sistema.h"
#include <iostream>
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

int main(){
    Sistema systema;
    iniciarMenu(systema);

    SparseMatrix* matriz = new SparseMatrix();
    matriz->add(1,1,1);
    matriz->add(2,2,1);
    matriz->add(3,3,1);
    matriz->add(4,1,2);
    matriz->add(5,2,2);
    matriz->add(6,3,2);
    std::cout<<"matriz 1:"<<std::endl;
    matriz->printCabecerasX();
    matriz->printCabecerasY();
    matriz->printStoredValues();

    SparseMatrix* m2 = new SparseMatrix();
    m2->add(1,1,1);
    m2->add(2,1,2);
    m2->add(3,1,3);
    m2->add(4,2,1);
    m2->add(5,2,2);
    m2->add(6,2,3);
    std::cout<<"matriz 2:"<<std::endl;
    m2->printCabecerasX();
    m2->printCabecerasY();
    m2->printStoredValues();

    SparseMatrix* m3 = matriz->multiply2(m2);
    if(m3!=nullptr){
        std::cout<<"matriz MULTIPLICADA:"<<std::endl;
        m3->printCabecerasX();
        m3->printCabecerasY();
        m3->printStoredValues();
    } else{
        std::cout<<"NULO"<<std::endl;
    }
    return 0;
}