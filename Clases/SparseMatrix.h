#pragma once 
#include "Node.h" 
class SparseMatrix { 
private: 
Node* start; 
public: 
SparseMatrix(); 
void printCabecerasX();
void printCabecerasY();
void add(int value, int xPos, int yPos); 
int get(int xPos, int yPos); 
void remove(int xPos, int yPos); 
void printStoredValues(); 
int density(); 
Node* getStart();
SparseMatrix* multiply(SparseMatrix* second); 
~SparseMatrix(); 
};