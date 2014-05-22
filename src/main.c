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
  Tree test_tree = NULL;
  test_tree = randomGenerate();    	
  return 0;
}
