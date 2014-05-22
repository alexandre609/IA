#include "tree.h"

Tree newTree(void){
  // value must be set in random generation
	Tree t = malloc(sizeof(StrTree));
  t -> left = NULL;
  t -> right = NULL;
	return t;
}

Tree addAnd(Tree tree){
	Tree left = newTree();
	Tree right = newTree();

  tree->op = 1;
	tree->left = left;
	tree->right = right;

	return tree;
}

Tree addOr(Tree tree){
	Tree left = newTree();
	Tree right = newTree();

  tree->op = 2;
	tree->left = left;
	tree->right = right;

	return tree;
}

Tree addNot(Tree tree){
	Tree sub_tree = newTree();

	tree->op = 3;
	tree->left = sub_tree;
	tree->right = NULL;

	return tree;
}

void changeToAnd(Tree tree){
  if(tree->right == NULL){ // NOT to AND
    tree->right = newTree();
  }
  tree->op = 1;
}

void changeToOr(Tree tree){
  if(tree->right == NULL){ // NOT to OR
    tree->right = newTree();
  }
  tree->op = 2;
}

void changeToNot(Tree tree){
  tree->op = 3;
  if(tree->right != NULL){
    free(tree->right);
  }
}

Tree randomGenerate(void){
  Tree result = newTree();

  srand(time(NULL));
  int r = ((rand() % 3) + 1); // result is either 1, 2 or 3

  switch(r){
    case 1 :
      result = addAnd(result);
      fprintf(stdout,"Created AND node.\n");
      break;
    case 2 :
      result = addOr(result);
      fprintf(stdout,"Created OR node.\n");
      break;
    case 3 :
      result = addNot(result);
      fprintf(stdout,"Created NOT node.\n");
      break;
    default:
      break;
  }

	return result;
}
