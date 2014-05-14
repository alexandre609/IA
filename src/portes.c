#include <stdlib.h>

#include "portes.h"

char logical_and(char entry_1, char entry_2){
  return (entry_1 && entry_2);
}

char logical_or(char entry_1, char entry_2){
  return (entry_1 || entry_2);
}

char logical_not(char entry){
  return (!entry);
}

