#include "tree.h"
/*
typedef struct str_tree{
	char op;
	str_tree *left;
	str_tree *right;
} Tree*;
*/
Tree newTree(){
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
	Tre t = malloc(sizeof(StrTree));
	t->op = 2;
	t->left = left;
	t->right = right;

	return t;
}

Tree addNot(Tree left){
	Tree left = malloc(sizeof(StrTree));
	Tree right = malloc(sizeof(StrTree));

	Tree t = malloc(sizeof(StrTree));
	t->op = 3;
	t->left = left;
	t->right = NULL;

	return t;
}

Tree randomGenerate(){
	return addAnd(addOr(addSimple('a'),addSimple('b')), addNot(addAnd(addSimple('c'),addSimple('d'))));
}
