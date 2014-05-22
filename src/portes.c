#include <stdlib.h>

#include "portes.h"

bool logical_and(bool entry_1, bool entry_2){
  return (entry_1 && entry_2);
}

bool logical_or(bool entry_1, bool entry_2){
  return (entry_1 || entry_2);
}

bool logical_not(bool entry){
  return (!entry);
}

