#include "Node.h"
Node::Node(){
    data = 0;
    right = nullptr;
    down = nullptr;
}
Node::Node(int data){
    this->data = data;
    right = nullptr;
    down = nullptr;
}