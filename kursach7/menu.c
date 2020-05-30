#include <stdio.h> 
#include <stdlib.h>

#include "vector.c"
#include "struct.h"

int main() {
    int number = 0;
    int amount = 0;
    int count = 0;
    printf("Start\n");
    printf("Input matrix in vector: \n");
    vector *root = vector_input();
    printf("Matrix in vector: \n");
    vector_output(root);
    printf("Print matrix form: \n");
    matrix_output(root);
    printf("Find the row with the largest number of nonzero elements \n");
    search(root, &number, &amount, &count);
    printf ("Number of the row: %.3d ", number);
    printf("\n");
    printf ("Amount of elements in the row: %.3d ", amount);
    another_search(root, &number, &count);
    matrix_output(root);
    printf("Done\n");
}
