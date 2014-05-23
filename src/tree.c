#include "tree.h"

Tree newTree(void){
  Tree t = NULL;
	if((t = malloc(sizeof(StrTree))) == NULL){
    perror("malloc ");
    exit(EXIT_FAILURE);
  }

  t -> left = NULL;
  t -> right = NULL;

  // value will need to be set in random generation
  t -> value = true;
  t -> op = 0;
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
	tree->right = newTree();

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

void randomGenerateDoor(Tree node){
  if(node == NULL){
    node = newTree();
  }
  int r = ((rand() % 3) + 1); // result is either 1, 2 or 3

  switch(r){
    case 1 :
      node = addAnd(node);
      fprintf(stdout,"Created AND node.\n");
      break;
    case 2 :
      node = addOr(node);
      fprintf(stdout,"Created OR node.\n");
      break;
    case 3 :
      node = addNot(node);
      fprintf(stdout,"Created NOT node.\n");
      break;
    default:
      break;
  }
}

void randomGenerateNode(Tree node){
  randomGenerateDoor(node->left);
  randomGenerateDoor(node->right);
}

void randomGenerateTree(Tree tree){
  if(tree->left == NULL){
    tree -> left = newTree();
  }
  if(tree->right == NULL){
    tree -> right = newTree();
  }

  if(timeout < SIZE){
    randomGenerateNode(tree);
    timeout++;
    randomGenerateTree(tree->left);
    randomGenerateTree(tree->right);
  }
}
