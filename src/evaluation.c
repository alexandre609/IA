#include "evaluation.h"

char evaluateNode(Tree node){
  char result;
  switch(node->value){
    case 1:
      result = (node->left->value) && (node->right->value);
      break;
    case 2:
      result = (node->left->value) || (node->right->value);
      break;
    case 3:
      result = !(node->left->value);
      break;
  }
  return result;
}

char evaluateTree(Tree tree){
  return 0;
}

