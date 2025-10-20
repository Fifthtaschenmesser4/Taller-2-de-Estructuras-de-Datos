#include "MatrixList.h"
#include <iostream>
MatrixList::MatrixList(){
    head=nullptr;
}
void MatrixList::addMatrix(int id){
    if(head==nullptr){ 
    head = new NodeMatrix(id,new SparseMatrix());
    return;
    }
    NodeMatrix* aux = head;
    while(aux->getRight()!=nullptr){
        aux=aux->getRight();
    }
    aux->setRight(new NodeMatrix(id,new SparseMatrix()));
}
void MatrixList::deleteMatrix(int id){
    if(head==nullptr){
    std::cout<<"No hay matrices que eliminar"<<std::endl;    
    return;
    }

    NodeMatrix* prev=nullptr;
    NodeMatrix* curr = head;

    if(curr->getID()==id){
        head=nullptr;
        delete curr;
        std::cout<<"Matriz eliminada con exito"<<std::endl;
        return;
    }
    prev=curr;
    curr=curr->getRight();
    while(curr!=nullptr){
        if(curr->getID()==id){
            prev->setRight(curr->getRight());
            delete curr;
            std::cout<<"Matriz eliminada con exito"<<std::endl;
            return;
        }
        prev=curr;
        curr=curr->getRight();
    }
    std::cout<<"No existe matriz con tal ID"<<std::endl;   
}
SparseMatrix* MatrixList::getMatrix(int id){
    if(head==nullptr){
    std::cout<<"No hay matrices en la lista"<<std::endl;    
    return nullptr;
    }
    NodeMatrix* aux = head;
    while(aux!=nullptr){
        if(aux->getID()==id){
            return aux->getMatrix();
        }
        aux=aux->getRight();
    }
    std::cout<<"No se ha encontrado esa matriz esa matriz"<<std::endl;
    return nullptr;
}
void MatrixList::showList(){
    NodeMatrix* aux = head;
    std::cout<<"Listado ID: ";
    while(aux!=nullptr){
        std::cout<<aux->getID()<<" | ";
        aux=aux->getRight();
    }
}