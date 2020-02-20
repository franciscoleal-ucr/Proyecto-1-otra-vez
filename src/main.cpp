#include <iostream>
#include "node.h"


int main() {
  Tree<int> tree;
  tree.insert(20);   
  tree.insert(5);
  tree.insert(8);
  tree.insert(3);
  tree.insert(40);
  tree.insert(9);	
  tree.insert(2);
  tree.insert(16);





  tree.funcPostOrden(tree.root);
}