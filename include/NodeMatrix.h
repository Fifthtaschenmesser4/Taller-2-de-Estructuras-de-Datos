#pragma once
#include "SparseMatrix.h"
class NodeMatrix{
    private:
    int id;
    SparseMatrix* mt;
    NodeMatrix* right;
    public:
    NodeMatrix(int id,SparseMatrix* mt);
    ~NodeMatrix();
    void setRight(NodeMatrix* node);
    NodeMatrix* getRight();
    SparseMatrix* getMatrix();
    int getID();
};