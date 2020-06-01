#include <stdio.h>
#include <malloc.h>
#include "keys.h"
#include "element.h"
#define average1 k[(low + high) / 2].int_key
#define average2 k[(low + high) / 2].char_key

void binary_search(keys *k, element *words, int low, int high, float key) {
    if ((average1 > key && ((average1)-key) * ((average1)-key) > eps) || (average2 > key && ((average2)-key) * ((average2)-key) > eps)) {
        if ((low + high) / 2 != low) {
            binary_search(k, words, low, (low + high) / 2, key);
        }
        else {
            printf("Error\n");
        }
        return;
    }
    else if ((average1 < key && ((average1)-key) * ((average1)-key) > eps) || (average2 < key && ((average2)-key) * ((average2)-key) > eps)) {
        if ((low + high) / 2 != high) {
            binary_search(k, words, (low + high) / 2, high, key);
        }
        else {
            printf("Error\n");
        }
        return;
    }
    else if (((average1)-key) * ((average1)-key) < eps) {
        printf("%s %f %s %s\n", "Key: ", average1, "\nString: ", k[(low + high) / 2].word);
    }
    else if (((average2)-key) * ((average2)-key) < eps) {
        printf("%s %f %s %s\n", "Key: ", average2, "\nString: ", k[(low + high) / 2].word);
    }
    else {
        printf("Error\n");
    }
    return;
}