#include "evaluation.h"

bool evaluateNode(Tree node){
  bool result;
  switch(node->op){
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

bool evaluateTree(Tree tree){
  bool result;
  if(tree->op == 0){ // we're at the bottom of the tree
    result = tree->value;
  }
  else{
    // we're at a node - we check the altitude
    // left is never NULL - except at the bottom, which is not the case
    if(tree->left->op == 0){ // we're at altitude 1 - no recursion needed
      result = evaluateNode(tree);
    }
    else{ // we're too high - recursion activated !
      bool result_left = evaluateTree(tree->left);
      bool result_right = evaluateTree(tree->right);

      switch(tree->op){
        case 1:
          result = result_left && result_right;
          break;
        case 2:
          result = result_left || result_right;
          break;
        case 3:
          result = !result_left;
          break;
      }
    }
  }
  return result;
}

