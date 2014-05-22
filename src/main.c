#include <stdlib.h>
#include <stdio.h>

#include "table.h"
#include "portes.h"
#include "tree.h"

/**
* \file main.c
* \brief Démarrage du programme et gestion des arguments
*/

int main(int argc, char** argv){
  srand(time(NULL));
  Tree test_tree = newTree();

  randomGenerate(test_tree);

  free(test_tree->right);
  free(test_tree->left);
  free(test_tree);

  return 0;
}
