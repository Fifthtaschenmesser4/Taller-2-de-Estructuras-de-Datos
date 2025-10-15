#include "SparseMatrix.h"
#include <iostream>
SparseMatrix::SparseMatrix(){
    start = new Node(0,0,0);
}
void SparseMatrix::add(int value, int xPos, int yPos){
    if(xPos<1 || yPos<1){
        std::cout<<"Ingrese coordenadas válidas (desde el 1)"<<std::endl;
    }

    Node* auxX=start;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        auxX=auxX->right;
    }
    if(auxX->getX()!=xPos){
        Node* temp=auxX->right;
        auxX->setRight(new Node(0,xPos,0));
        auxX=auxX->right;
        auxX->setRight(temp);
    }

    Node* auxY=start;
    while(auxY->down!=start and auxY->down->getY()<=yPos){
        auxY=auxY->down;
    }
    if(auxY->getY()!=yPos){
        Node* temp=auxY->down;
        auxY->setDown(new Node(0,0,yPos));
        auxY=auxY->down;
        auxY->setDown(temp);
    } 
    Node* cabezaX = auxX;
    Node* cabezaY = auxY;
    while(cabezaX->down!=auxX and cabezaX->down->getY()<yPos){ //desde la cabeza de la columna baja fila a fila
        cabezaX=cabezaX->down;
    }
    if(cabezaX->down->getY()==yPos){
        cabezaX->down->setData(value);
        std::cout<<"Valor actualizado"<<std::endl;
        return;
    }
    Node* nuevo = new Node(value,xPos,yPos);
    Node* temp = cabezaX->down;
    cabezaX->setDown(nuevo);
    cabezaX=cabezaX->down;
    cabezaX->setDown(temp);
    
    while(cabezaY->right!=auxY and cabezaY->right->getX()<xPos){//desde la cabeza de la fila, va a la derecha columna x columna
        cabezaY=cabezaY->right;
    }
    temp = cabezaY->right;
    cabezaY->setRight(nuevo);
    cabezaY=cabezaY->right;
    cabezaY->setRight(temp);
}
void SparseMatrix::printCabecerasX(){
    Node* aux = start;
    std::cout<<"X: ";
    while(aux->right!=start){
        std::cout<<aux->getX()<<", ";
        aux=aux->right;
    }
    std::cout<<aux->getX()<<std::endl;
}
void SparseMatrix::printCabecerasY(){
    Node* aux = start;
    std::cout<<"Y: ";
    while(aux->down!=start){
        std::cout<<aux->getY()<<", ";
        aux=aux->down;
    }
    std::cout<<aux->getY()<<std::endl;
}
void SparseMatrix::printMatrix(){
    Node* Y = start;
    while(Y->down!=start){
        Y=Y->down;
        Node* X = Y;
        while(X->right!=Y){
            X=X->right;
            std::cout<<X->getData()<<" ";
        }
        std::cout<<std::endl;
    }

}
int SparseMatrix::get(int xPos, int yPos){
    if(xPos<1 || yPos<1){
        std::cout<<"Ingrese coordenadas válidas (desde el 1)"<<std::endl;
    }

    Node* auxX=start;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        auxX=auxX->right;
    }
    if(auxX->getX()!=xPos){
        Node* temp=auxX->right;
        auxX->setRight(new Node(0,xPos,0));
        auxX=auxX->right;
        auxX->setRight(temp);
    }

    Node* cabezaX = auxX;
    while(cabezaX->down!=auxX and cabezaX->down->getY()<yPos){ //desde la cabeza de la columna baja fila a fila
        cabezaX=cabezaX->down;
    }
    if(cabezaX->down->getY()==yPos){
        std::cout<<"¡Encontrado!"<<std::endl;
        return cabezaX->down->getData();
    }
    return 0;
}
void SparseMatrix::remove(int xPos, int yPos){
    if(xPos<1 || yPos<1){
        std::cout<<"Ingrese coordenadas válidas (desde el 1)"<<std::endl;
    }

    Node* auxX=start; //busca cabecera X
    Node* prevX;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        prevX=auxX; //guarda el Nodo anterior a la cabecera
        auxX=auxX->right;
    }
    Node* auxY=start; //busca cabecera Y
    Node* prevY;
    while(auxY->down!=start and auxY->down->getY()<=yPos){
        prevY=auxY;//guarda el Nodo anterior a la cabecera
        auxY=auxY->down;
    }
    if(auxX->getX()!=xPos || auxY->getY()!=yPos){ //si alguna de estas no existen, return.
        std::cout<<"No existe tal elemento 1"<<std::endl;
        return;
    }

    Node* cabezaX = auxX;
    Node* cabezaY = auxY;
    while(cabezaX->down!=auxX and cabezaX->down->getY()<yPos){ //desde la cabeza de la columna baja fila a fila hasta el nodo anterior al buscado
        cabezaX=cabezaX->down;
    }
    while(cabezaY->right!=auxY and cabezaY->right->getX()<xPos){//desde la cabeza de la fila, va a la derecha columna x columna hasta el nodo anterior al buscado
        cabezaY=cabezaY->right;
    }
    if(cabezaX->down==cabezaY->right){
        Node* deleteNode = cabezaX->down;
        cabezaX->setDown(deleteNode->down);
        cabezaY->setRight(deleteNode->right);
        delete deleteNode;
        std::cout<<"Elemento eliminado"<<std::endl;
        if(cabezaX==cabezaX->down){ //si la columna se vació
            prevX->setRight(cabezaX->right); 
            delete cabezaX;
        } //elimina la cabecera que no tiene mas nodos
        if(cabezaY==cabezaY->right){ //si la fila se vació
            prevY->setDown(cabezaY->down);
            delete cabezaY;
        }//elimina la cabecer que no tiene mas nodos
    } else {
        std::cout<<"No existe tal elemento"<<std::endl;
    }
    return;
}
void SparseMatrix::printStoredValues(){
    Node* Y = start;
    while(Y->down!=start){
        Y=Y->down;
        Node* X = Y;
        while(X->right!=Y){
            X=X->right;
            //(7, 8) --> 90 
            std::cout<<"("<<X->getX()<<", "<<X->getY()<<") --> "<<X->getData()<<std::endl;
        }
    }
    return;
}
int SparseMatrix::density(){
    return 0;
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    return nullptr;
}
SparseMatrix::~SparseMatrix(){}