#pragma once
#include "SparseMatrix.h"
#include "NodeMatrix.h"
class MatrixList{
    private:
    NodeMatrix* head;
    public:
    MatrixList();
    ~MatrixList(){}
    void addMatrix(int id);
    void deleteMatrix(int id);
    SparseMatrix* getMatrix(int id);
    void showList();
};