#include "tree.h"

Tree newTree(void){
	Tree t = malloc(sizeof(StrTree));
  t -> left = NULL;
  t -> right = NULL;
  // value will need to be set in random generation
  t -> value = 1;
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

void randomGenerate(Tree tree){
  int r = ((rand() % 3) + 1); // result is either 1, 2 or 3

  switch(r){
    case 1 :
      tree = addAnd(tree);
      fprintf(stdout,"Created AND node.\n");
      break;
    case 2 :
      tree = addOr(tree);
      fprintf(stdout,"Created OR node.\n");
      break;
    case 3 :
      tree = addNot(tree);
      fprintf(stdout,"Created NOT node.\n");
      break;
    default:
      break;
  }

  timeout++;

  if(timeout != MAX_GENERATIONS){
    int left_or_right = (rand() % 2);
    if(left_or_right == 0){
      randomGenerate(tree->left);
    }else{
      randomGenerate(tree->right);
    }
  }
}
