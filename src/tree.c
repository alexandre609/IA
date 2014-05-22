#include "tree.h"

Tree newTree(void){
	Tree t = malloc(sizeof(StrTree));
	return t;
}

Tree addAnd(Tree left, Tree right){
	Tree t = malloc(sizeof(StrTree));
	t->op = 1;
	t->left = left;
	t->right = right;

	return t;
}

Tree addOr(Tree left, Tree right){
	Tree t = malloc(sizeof(StrTree));
	t->op = 2;
	t->left = left;
	t->right = right;

	return t;
}

Tree addNot(Tree left){
	Tree t = malloc(sizeof(StrTree));
	t->op = 3;
	t->left = left;
	t->right = NULL;

	return t;
}

void changeToAnd(Tree tree){
  tree->op = 1;
}

void changeToOr(Tree tree){
  tree->op = 2;
}

void changeToNot(Tree tree){
  tree->op = 3;
  free(tree->right);
}

Tree randomGenerate(void){
  Tree base_right = newTree();
  Tree base_left = newTree();
  Tree result = NULL;

  srand(time(NULL));
  int r = ((rand() % 3) + 1); // result is either 1, 2 or 3

  switch(r){
    case 1 :
      result = addAnd(base_left, base_right);
      break;
    case 2 :
      result = addOr(base_left, base_right);
      break;
    case 3 :
      result = addNot(base_left);
      break;
    default:
      break;
  }

	return result;
}
