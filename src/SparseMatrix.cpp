#include "../include/SparseMatrix.h"
#include <iostream>
SparseMatrix::SparseMatrix(){
    start = new Node(0,0,0);
}

void SparseMatrix::add(int value, int xPos, int yPos){
    if(xPos<1 || yPos<1){
        return;
    }
    Node* auxX=start;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        auxX=auxX->right;
    }
    if(auxX->getX()!=xPos){
        Node* temp=auxX->right;
        auxX->setRight(new Node(-1,xPos,0));
        auxX=auxX->right;
        auxX->setRight(temp);
    }

    Node* auxY=start;
    while(auxY->down!=start and auxY->down->getY()<=yPos){
        auxY=auxY->down;
    }
    if(auxY->getY()!=yPos){
        Node* temp=auxY->down;
        auxY->setDown(new Node(-1,0,yPos));
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

int SparseMatrix::get(int xPos, int yPos){
    Node* auxX=start;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        auxX=auxX->right;
    }
    if(auxX->getX()!=xPos) return 0;

    Node* cabezaX = auxX;
    while(cabezaX->down!=auxX and cabezaX->down->getY()<yPos){ //desde la cabeza de la columna baja fila a fila
        cabezaX=cabezaX->down;
    }
    if(cabezaX->down->getY()==yPos){
        return cabezaX->down->getData();
    }
    return 0;

}
void SparseMatrix::remove(int xPos, int yPos){
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
        std::cout<<"No existe ese elemento!"<<std::endl;
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
            std::cout<<"("<<X->getX()<<", "<<X->getY()<<") --> "<<X->getData()<<std::endl;
        }
    }
    return;
}
int SparseMatrix::density(){
    int cont=0;
    Node* Y = start;
    Node* X = start;
    while(Y->down!=start){
        Y=Y->down;
        X = Y;
        while(X->right!=Y){
            X=X->right;
            cont++;
        }
    }
    int x=X->getX();
    int y=X->getY();
    float density = (float(cont)/(x*y))*100;
    return (int)density;
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    if(start->right==start and second->start->right==start) return this; 
    if(start->right==start) return this;
    if(second->start->right==start) return second; 

    SparseMatrix* nuevaMatriz = new SparseMatrix();
    Node* cabezaFilaA=start->down; //cabecera de filas de Matriz 1
    while(cabezaFilaA!=start){
        Node* cabezaColumnaB=second->start->right; //cabecera de columnas de matriz 1
        while(cabezaColumnaB!=second->start){
        Node* auxFil=cabezaFilaA->right;
        Node* auxCol=cabezaColumnaB->down;
        int suma=0;
        while(auxCol!=cabezaColumnaB and auxFil!=cabezaFilaA){
            if(auxCol->getY() == auxFil->getX()){
            suma += auxCol->getData()*auxFil->getData();
            auxCol=auxCol->down;
            auxFil=auxFil->right;
            } else if (auxCol->getY() < auxFil->getX()){
                auxCol=auxCol->down;
            } else if (auxCol->getY() > auxFil->getX()){
                auxFil=auxFil->right;
            }
        }
        if(suma!=0){
            nuevaMatriz->add(suma,cabezaColumnaB->getX(),cabezaFilaA->getY());
        }
        cabezaColumnaB=cabezaColumnaB->right;
    }
    cabezaFilaA=cabezaFilaA->down;
    }
    return nuevaMatriz;
}
SparseMatrix::~SparseMatrix() {
if(start==nullptr) return;
    Node* auxFila = start->down;
    while(auxFila!=start){
        Node* auxCol=auxFila->right;
        while(auxCol!=auxFila){
            Node* deleteNode=auxCol;
            auxCol=auxCol->right;
            delete deleteNode;
        }
        Node* deleteNode=auxFila;
        auxFila=auxFila->down;
        delete deleteNode;
    }
    //tras eliminar los valores de la matriz y el eje Y
    auxFila=start->right;
    while(auxFila!=start){
        Node* deleteNode = auxFila;
        auxFila=auxFila->right;
        delete deleteNode;
    }
    delete start;

}