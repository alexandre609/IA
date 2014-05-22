#ifndef __TREE_H_
#define __TREE_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX_GENERATIONS 5

static int timeout = 0;

typedef struct str_tree{
	int op;
  bool value;
	struct str_tree *left;
	struct str_tree *right;
}StrTree, *Tree;

Tree newTree(void);

Tree addAnd(Tree tree);

Tree addOr(Tree tree);

Tree addNot(Tree tree);

void changeToAnd(Tree tree);

void changeToOr(Tree tree);

void changeToNot(Tree tree);

void randomGenerate(Tree tree);

#endif
