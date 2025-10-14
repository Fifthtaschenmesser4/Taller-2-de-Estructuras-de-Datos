#pragma once
class Node{
    private:
    int data;
    int x;
    int y;
    public:
    Node* right; //Avanza por la fila
    Node* down; //Avanza por la columna
    Node(int data,int x,int y);
    ~Node(){};
    int getX();
    int getY();
    void setRight(Node* nodo);
    void setDown(Node* nodo);
};