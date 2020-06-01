#include <stdio.h>
#include <stdlib.h>
#include "keys.h"
#include "element.h"

void shellSort(keys *k, element *words, int *size) {
  int inc = 3;
  while (inc > 0) {
    for (int i = 0; i < *size; i++) {
      int j = i;
      keys temp = k[i];
      while ((j >= inc) && ((k[j - inc].char_key > temp.char_key) || (k[j - inc].int_key > temp.int_key))) {  
        k[j] = k[j - inc];
        j = j - inc;
      }
      k[j] = temp;
    }
    if (inc > 1) {
      inc = inc / 2;
    }
    else if (inc == 1) {
      break;
    }
  }
  return;
}