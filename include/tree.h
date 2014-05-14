#ifndef __TREE_H_
#define __TREE_H_

typedef struct str_tree{
	char op;
	str_tree *left;
	str_tree *right;
}StrTree, Tree*;

Tree newTree();

Tree addAnd(Tree t);

Tree addOr(Tree t);

Tree addNot(Tree t);

#endif
