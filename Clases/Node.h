#pragma once
class Node{
    private:
    int data;
    public:
    Node* right; //Avanza por la fila
    Node* down; //Avanza por la columna
    Node();
    Node(int data);
    ~Node(){};
};