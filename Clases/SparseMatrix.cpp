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
    while(aux->right!=start){
        std::cout<<"X:"<<aux->getX()<<"Y:"<<aux->getY()<<std::endl;
        aux=aux->right;
    }
    std::cout<<"X:"<<aux->getX()<<"Y:"<<aux->getY()<<std::endl;
}
void SparseMatrix::printCabecerasY(){
    Node* aux = start;
    while(aux->down!=start){
        std::cout<<"X:"<<aux->getX()<<"Y:"<<aux->getY()<<std::endl;
        aux=aux->down;
    }
    std::cout<<"X:"<<aux->getX()<<"Y:"<<aux->getY()<<std::endl;
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
    return 0;
}
void SparseMatrix::remove(int xPos, int yPos){
    return;
}
void SparseMatrix::printStoredValues(){
    return;
}
int SparseMatrix::density(){
    return 0;
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    return nullptr;
}
SparseMatrix::~SparseMatrix(){}