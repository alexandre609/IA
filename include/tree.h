#ifndef __TREE_H_
#define __TREE_H_

#include <stdlib.h>
#include <time.h>

typedef struct str_tree{
	char op;
	struct str_tree *left;
	struct str_tree *right;
}StrTree, *Tree;

Tree newTree(void);

Tree addAnd(Tree left, Tree right);

Tree addOr(Tree left, Tree right);

Tree addNot(Tree left);

Tree randomGenerate(void);

#endif
