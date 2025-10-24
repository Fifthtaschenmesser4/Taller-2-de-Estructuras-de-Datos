#include "../include/Node.h"
#include "../include/SparseMatrix.h"
#include "../include/MatrixList.h"
#include "../include/Sistema.h"
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
    std::cout<<"9. Hacer todas las pruebas de tiempo"<<std::endl;
    std::cout<<"10. Salir"<<std::endl;
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
            systema.allTest();
        } else if(opcion==10){
            std::cout<<"Saliendo..."<<std::endl;
        } else {
            std::cout<<"Ingrese una opción válida."<<std::endl;
        }
    }while(opcion != 10);
}


int main() {
    Sistema systema;
    iniciarMenu(systema);
    return 0;
}