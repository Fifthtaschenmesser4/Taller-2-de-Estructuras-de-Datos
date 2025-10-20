#include "SparseMatrix.h"
#include <iostream>
SparseMatrix::SparseMatrix(){
    start = new Node(0,0,0);
}
Node* SparseMatrix::getStart(){
    return start;
}
void SparseMatrix::add(int value, int xPos, int yPos){
    if(xPos<1 || yPos<1){
        return;
    }

    Node* auxX=start;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        auxX=auxX->right;
    }
    if(auxX->getX()!=xPos){
        Node* temp=auxX->right;
        auxX->setRight(new Node(-1,xPos,0));
        auxX=auxX->right;
        auxX->setRight(temp);
    }

    Node* auxY=start;
    while(auxY->down!=start and auxY->down->getY()<=yPos){
        auxY=auxY->down;
    }
    if(auxY->getY()!=yPos){
        Node* temp=auxY->down;
        auxY->setDown(new Node(-1,0,yPos));
        auxY=auxY->down;
        auxY->setDown(temp);
    } 
    Node* cabezaX = auxX;
    Node* cabezaY = auxY;
    while(cabezaX->down!=auxX and cabezaX->down->getY()<yPos){ //desde la cabeza de la columna baja fila a fila
        cabezaX=cabezaX->down;
    }
    if(cabezaX->down->getY()==yPos){
        cabezaX->down->setData(value);
        std::cout<<"Valor actualizado"<<std::endl;
        return;
    }
    Node* nuevo = new Node(value,xPos,yPos);
    Node* temp = cabezaX->down;
    cabezaX->setDown(nuevo);
    cabezaX=cabezaX->down;
    cabezaX->setDown(temp);
    
    while(cabezaY->right!=auxY and cabezaY->right->getX()<xPos){//desde la cabeza de la fila, va a la derecha columna x columna
        cabezaY=cabezaY->right;
    }
    temp = cabezaY->right;
    cabezaY->setRight(nuevo);
    cabezaY=cabezaY->right;
    cabezaY->setRight(temp);
}
void SparseMatrix::printCabecerasX(){
    Node* aux = start;
    std::cout<<"X: ";
    while(aux->right!=start){
        std::cout<<aux->getX()<<", ";
        aux=aux->right;
    }
    std::cout<<aux->getX()<<std::endl;
}
void SparseMatrix::printCabecerasY(){
    Node* aux = start;
    std::cout<<"Y: ";
    while(aux->down!=start){
        std::cout<<aux->getY()<<", ";
        aux=aux->down;
    }
    std::cout<<aux->getY()<<std::endl;
}

int SparseMatrix::get(int xPos, int yPos){
    Node* auxX=start;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        auxX=auxX->right;
    }
    if(auxX->getX()!=xPos) return 0;

    Node* cabezaX = auxX;
    while(cabezaX->down!=auxX and cabezaX->down->getY()<yPos){ //desde la cabeza de la columna baja fila a fila
        cabezaX=cabezaX->down;
    }
    if(cabezaX->down->getY()==yPos){
        return cabezaX->down->getData();
    }
    return 0;

}
void SparseMatrix::remove(int xPos, int yPos){
    if(xPos<1 || yPos<1){
        std::cout<<"Ingrese coordenadas válidas (desde el 1)"<<std::endl;
    }

    Node* auxX=start; //busca cabecera X
    Node* prevX;
    while(auxX->right!=start and auxX->right->getX()<=xPos){
        prevX=auxX; //guarda el Nodo anterior a la cabecera
        auxX=auxX->right;
    }
    Node* auxY=start; //busca cabecera Y
    Node* prevY;
    while(auxY->down!=start and auxY->down->getY()<=yPos){
        prevY=auxY;//guarda el Nodo anterior a la cabecera
        auxY=auxY->down;
    }
    if(auxX->getX()!=xPos || auxY->getY()!=yPos){ //si alguna de estas no existen, return.
        std::cout<<"No existe tal elemento 1"<<std::endl;
        return;
    }

    Node* cabezaX = auxX;
    Node* cabezaY = auxY;
    while(cabezaX->down!=auxX and cabezaX->down->getY()<yPos){ //desde la cabeza de la columna baja fila a fila hasta el nodo anterior al buscado
        cabezaX=cabezaX->down;
    }
    while(cabezaY->right!=auxY and cabezaY->right->getX()<xPos){//desde la cabeza de la fila, va a la derecha columna x columna hasta el nodo anterior al buscado
        cabezaY=cabezaY->right;
    }
    if(cabezaX->down==cabezaY->right){
        Node* deleteNode = cabezaX->down;
        cabezaX->setDown(deleteNode->down);
        cabezaY->setRight(deleteNode->right);
        delete deleteNode;
        std::cout<<"Elemento eliminado"<<std::endl;
        if(cabezaX==cabezaX->down){ //si la columna se vació
            prevX->setRight(cabezaX->right); 
            delete cabezaX;
        } //elimina la cabecera que no tiene mas nodos
        if(cabezaY==cabezaY->right){ //si la fila se vació
            prevY->setDown(cabezaY->down);
            delete cabezaY;
        }//elimina la cabecer que no tiene mas nodos
    } else {
        std::cout<<"No existe tal elemento"<<std::endl;
    }
    return;
}
void SparseMatrix::printStoredValues(){
    Node* Y = start;
    while(Y->down!=start){
        Y=Y->down;
        Node* X = Y;
        while(X->right!=Y){
            X=X->right;
            //(7, 8) --> 90 
            std::cout<<"("<<X->getX()<<", "<<X->getY()<<") --> "<<X->getData()<<std::endl;
        }
    }
    return;
}
int SparseMatrix::density(){
    int cont=0;
    Node* Y = start;
    Node* X = start;
    while(Y->down!=start){
        Y=Y->down;
        X = Y;
        while(X->right!=Y){
            X=X->right;
            cont++;
        }
    }
    int x=X->getX();
    int y=X->getY();
    std::cout<<"CONT:"<<cont<<"  x="<<x<<"  y="<<y<<std::endl;
    float density = (float(cont)/(x*y))*100;
    return (int)density;
}
SparseMatrix* SparseMatrix::multiply(SparseMatrix* second){
    //1. obtenemos orden de matriz 1
    Node* aux1 = start;
    while(aux1->down!=start){aux1=aux1->down;}
    Node* aux2=aux1;
    while(aux1->right!=aux2){aux1=aux1->right;};
    int x1=aux1->getX();
    int y1=aux1->getY();
    //2. obtenemos orden de matriz 2
    aux1=second->getStart();
    while(aux1->down!=second->getStart()){aux1=aux1->down;}
    aux2=aux1;
    while(aux1->right!=aux2){aux1=aux1->right;};
    int x2=aux1->getX();
    int y2=aux1->getY();
    if(x1!=y2 || y1!=x2) return nullptr;

    //si se puede multiplicar:
    SparseMatrix* nuevaMatriz = new SparseMatrix();
    Node* cabezaFilaA=start->down; //cabecera de filas de Matriz 1
    while(cabezaFilaA!=start){
        Node* cabezaColumnaB=second->getStart()->right; //cabecera de columnas de matriz 1
        while(cabezaColumnaB!=second->getStart()){
        Node* auxFil=cabezaFilaA->right;
        Node* auxCol=cabezaColumnaB->down;
        int suma=0;
        while(auxCol!=cabezaColumnaB and auxFil!=cabezaFilaA){
            if(auxCol->getY() == auxFil->getX()){
            suma += auxCol->getData()*auxFil->getData();
            auxCol=auxCol->down;
            auxFil=auxFil->right;
            } else if (auxCol->getY() < auxFil->getX()){
                auxCol=auxCol->down;
            } else if (auxCol->getY() > auxFil->getX()){
                auxFil=auxFil->right;
            }
        }
        if(suma!=0){
            nuevaMatriz->add(suma,cabezaColumnaB->getX(),cabezaFilaA->getY());
        }
        cabezaColumnaB=cabezaColumnaB->right;
    }
    cabezaFilaA=cabezaFilaA->down;
    }
    return nuevaMatriz;
}
SparseMatrix* SparseMatrix::multiply2(SparseMatrix* second){
    if(second==nullptr) return nullptr;
    //si la matriz1 no tiene ningún nodo(vacia) o matriz2 no tiene ningun nodo(vacia)
    if(start->right==start || second->density()==-1) {
        std::cout<<"Una o ambas matrices son vacías!"<<std::endl;    
        return nullptr;
    } 

    //1. revisar si ambas matrices son compatibles
    Node* cabezaX=start;
    Node* cabezaY=start;
    while(cabezaX->right!=start){
        cabezaX=cabezaX->right;
    }
    while (cabezaY->down!=start){
        cabezaY=cabezaY->down;
    }
    //MxN * NxM
    int filas=cabezaX->getX();
    int columnas=cabezaY->getY();
    std::cout<<"FIL:"<<filas<<" , COL:"<<columnas<<std::endl;
    std::cout<<second->get(0,filas)<<" (-1)  y  "<<second->get(0,filas+1)<<" (0)"<<std::endl;
    std::cout<<second->get(columnas,0)<<" (-1) y  "<<second->get(columnas+1,0)<<" (0)"<<std::endl;

    if(second->get(0,filas)==-1 and second->get(0,filas+1)==0 and second->get(columnas,0)==-1 
    and second->get(columnas+1,0)==0) //NO SE PUEDE HACER MULTIPLICACIÓN CON GET()
    {
        std::cout<<"Las matrices SÍ SON son compatibles!"<<std::endl;    
        return nullptr;
    }

    //ambas son compatibles
    SparseMatrix* nueva=new SparseMatrix() ;
    Node* cabezaFila=start->down; //por cada fila 
    Node* indiceCOL=start->down;

    while(cabezaFila!=start){
      int fil=cabezaFila->getY();
      for(int i = 0;i<=columnas;i++){ //por cada columna de la segunda matriz
        Node* auxX=cabezaFila->right;
        int suma=0;
        while (auxX!=cabezaFila){
            suma+=auxX->getData()*second->get(indiceCOL->getY(),auxX->getX());
            auxX=auxX->right;
        }
        if(suma!=0){
            nueva->add(suma,indiceCOL->getY(),fil);
        }
        indiceCOL=indiceCOL->down;
        }
    cabezaFila=cabezaFila->down;
    indiceCOL=start->down;
    }
    return nueva;
}

SparseMatrix::~SparseMatrix() {
    if(start==nullptr) return;
    Node* auxFila = start->down;
    while(auxFila!=start){
        Node* auxCol=auxFila->right;
        while(auxCol!=auxFila){
            Node* deleteNode=auxCol;
            auxCol=auxCol->right;
            delete deleteNode;
        }
        Node* deleteNode=auxFila;
        auxFila=auxFila->down;
        delete deleteNode;
    }
    //tras eliminar los valores de la matriz y el eje Y
    auxFila=start->right;
    while(auxFila!=start){
        Node* deleteNode = auxFila;
        auxFila=auxFila->right;
        delete deleteNode;
    }
    delete start;
}