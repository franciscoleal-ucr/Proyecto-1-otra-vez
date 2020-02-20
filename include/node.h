#include <iostream>

#pragma once

template <class Datum>

class Node{
  public:
  Datum value;

  Node *left, *right;

  Node();

  ~Node();
};

template <class Datum>
class Tree{
  public:

  Tree();

  ~Tree();

  Node<Datum> *root;

  void destroySubTree(Node<Datum> *);
  
  void insertNew(Node<Datum> *&, Node<Datum> *&);

  void insert(Datum d);

  int size;

  int getSize(Node<Datum> *node);

  void remove(Datum d);

  void deleteNode(Datum d, Node<Datum> *&);

  void makeDeletion(Node<Datum> *&);

  bool find(Datum d);

  void funcPreOrden(Node<Datum> *);
  
  void funcInOrden(Node<Datum> *);

  void funcPostOrden(Node<Datum> *);

  void inOrden(){
    funcInOrden(root);
  };

  void preOrden(){
    funcPreOrden(root);
  }

  void postOrden(){
    funcPostOrden(root);
  }
};

template<class Datum>
Node<Datum>::~Node(){
  this->value = 0;
  this->left = this->right = NULL;
}


template<class Datum>
Tree<Datum>::Tree(){
  root = NULL;
}



template<class Datum>
Tree<Datum>::~Tree(){
}





template<class Datum>
Node<Datum>::Node(){
  this->left = this->right = NULL;
}



/// insertar dato solo
template<class Datum>
void Tree<Datum>::insert(Datum d){
  ///  se crea un nuevo puntero a nodo
  Node<Datum> *newNode = NULL;
  //// Creamos un nuevo nodo para asignarle valores
  Node<Datum> newTreeNode;
  
  /// se le asigna el valor
  newTreeNode.value = d;
  //// se le asignan los valores a la izquierda y a la derecha
  newTreeNode.left = newTreeNode.right = NULL;
  //// Se apunta el puntero newNode al nodo para asignarle valores
  newNode = &newTreeNode;
  //// se inserta en el arbol
  insertNew(root, newNode);
}

template<class Datum>
void Tree<Datum>::insertNew(Node<Datum> *&nodePtr, Node<Datum> *&newNode){
  /// si no hay ningun puntero root, se crea desde cero
  if(nodePtr == NULL){
    std::cout<<newNode->value<<" es el root \n";
    nodePtr = newNode;
  }
  //// si es menor que el root, se inserta a la izquierda
  else if(newNode->value < nodePtr -> value){
    std::cout<<newNode->value<<" a la izquierda \n";
    insertNew(nodePtr->left, newNode);
  }
  /// si es mayor que el root se inserta a la derecha
  else{
    std::cout<<newNode->value<<" a la derecha \n";
    insertNew(nodePtr->right,newNode);
  }
}



template<class Datum>
void Tree<Datum>::remove(Datum d){
  deleteNode(d, root);
}

template<class Datum>
void Tree<Datum>::deleteNode(Datum d, Node<Datum> *&nodePtr){
  if(d < nodePtr->value){
    deleteNode(d, nodePtr->left);
  }
  else if(d > nodePtr->value){
    deleteNode(d, nodePtr->right);
  }
  else{
    makeDeletion(nodePtr);
  }
}

template<class Datum>
void Tree<Datum>::makeDeletion(Node<Datum> *&nodePtr){
  Node<Datum> *tempNodePtr = NULL;
  if(nodePtr==NULL){
    std::cout << "No se puede eliminar un nodo vacio \n";
  }
  else if(nodePtr->right == NULL){
    tempNodePtr=nodePtr;
    nodePtr = nodePtr->left;
    delete tempNodePtr;
  }
  else if(nodePtr->left == NULL){
    tempNodePtr=nodePtr;
    tempNodePtr = nodePtr->right;
    delete tempNodePtr;
  }
  else{
    tempNodePtr = nodePtr->right;
    while(tempNodePtr->left){
      tempNodePtr=tempNodePtr->left;
    }
    tempNodePtr->left = nodePtr->left;
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->right;
    delete tempNodePtr;
  }
}

/// busca un dato, retorna true si lo encuentra, false si no
template<class Datum> 
bool Tree<Datum>::find(Datum d){
  bool status = false;
  Node<Datum> *nodePtr = root;
  while(nodePtr){
    if(nodePtr->value == d){
      status = true;
    }
    else if(d<nodePtr->value){
      nodePtr=nodePtr->left;
    }
    else{
      nodePtr=nodePtr->right;
    }
  }
  return status;
}

/// muestra los datos antes del ordenamiento transversal
template<class Datum>
void Tree<Datum>::funcPreOrden(Node<Datum> *nodePtr){
  if(nodePtr){
    std::cout << nodePtr->value << " ";
    
    funcPreOrden(nodePtr->left);

    funcPreOrden(nodePtr->right);
  }
}

//// muestra los datos durante el orden transversal
template<class Datum>
void Tree<Datum>::funcInOrden(Node<Datum> *nodePtr){
  if(nodePtr){
    funcInOrden(nodePtr->left);
    std::cout << nodePtr->value << " ";
    funcInOrden(nodePtr->right);
    
  }
}


// muestra los datos despues del orden transversal
template<class Datum>
void Tree<Datum>::funcPostOrden(Node<Datum> *nodePtr){
  if(nodePtr){
    funcPostOrden(nodePtr->left);
    funcPostOrden(nodePtr->right);
    std::cout<<nodePtr->value<<" ";
  }
}

template<class Datum>
int Tree<Datum>::getSize(Node<Datum> *node){
  if(node == NULL){
    return 0;
  }
  else{
    return(getSize(node->left)+1+size(node->right));
  }
}


