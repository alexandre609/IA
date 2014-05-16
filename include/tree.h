#ifndef __TREE_H_
#define __TREE_H_

typedef struct str_tree{
	char op;
	struct str_tree *left;
	struct str_tree *right;
}StrTree, *Tree;

Tree newTree();

Tree addAnd(Tree left, Tree right);

Tree addOr(Tree left, Tree right);

Tree addNot(Tree left, Tree right);

Tree randomGenerate();

#endif
