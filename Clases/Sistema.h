#pragma once
#include "MatrixList.h"
class Sistema{
    private:
    int idGlobal;
    MatrixList listaMatrices;
    SparseMatrix* buscarMatriz(int id);
    public:
    Sistema();
    void crearMatriz();
    void eliminarMatriz(int id);
    void insertarValor(int id, int valor, int x, int y);
    void buscarValor(int id, int x, int y);
    void eliminarValor(int id, int x, int y);
    void multiplicarMatrices(int id1, int id2);
    void mostrarMatriz(int id);
    void calcularDensidad(int id);
    void mostrarLista();
};