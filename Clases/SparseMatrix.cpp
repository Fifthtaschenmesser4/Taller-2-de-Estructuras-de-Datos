#include "SparseMatrix.h"
#include <iostream>
SparseMatrix::SparseMatrix(){
    start = new Node(0,0,0);
}
void SparseMatrix::add(int value, int xPos, int yPos){
    if(xPos<1 || yPos<1){
        std::cout<<"Ingrese coordenadas válidas (desde el 1)"<<std::endl;
    }
    //Node* nuevo = new Node(value,xPos,yPos);
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