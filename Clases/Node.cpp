#include "Node.h"
Node::Node(int data,int x,int y){
    this->data=data;
    right=down=this;
    this->x=x;
    this->y=y;
}

void Node::setRight(Node* nodo){
    right=nodo;
}
void Node::setDown(Node* nodo){
    down=nodo;
}
int Node::getX(){
    return x;
}
int Node::getY(){
    return y;
}