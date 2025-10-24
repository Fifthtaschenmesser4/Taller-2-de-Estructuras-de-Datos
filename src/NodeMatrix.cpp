#include "../include/NodeMatrix.h"
#include <iostream>
NodeMatrix::NodeMatrix(int id,SparseMatrix* mt){
    this->id=id;
    this->mt=mt;
    right=nullptr;
}
void NodeMatrix::setRight(NodeMatrix* node){
    right=node;
}
NodeMatrix* NodeMatrix::getRight(){
    return right;
}
int NodeMatrix::getID(){
    return id;
}
SparseMatrix* NodeMatrix::getMatrix(){
    return mt;
}
NodeMatrix::~NodeMatrix(){
    delete mt;
}