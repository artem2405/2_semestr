#include <stdio.h> 
#include <stdlib.h>

#include "struct.h"

vector *vector_create(int findex, float fvalue) {
    vector *root = (vector *)malloc(sizeof (vector));
    root -> index = findex;
    root -> value = fvalue;
    root -> next = NULL;
    root -> prev = NULL;
    return root;
}

void vector_add(vector *root, int findex, float fvalue) {
    while (root -> next) {
        root = root -> next;
    }
    vector *tmp = vector_create(findex, fvalue);
    root -> next = tmp;
    tmp -> prev = root;
}

void vector_output(vector *root) {
    while (root) {
        printf("%d %.3f |", root -> index, root -> value);
        root = root -> next;
    }
    printf("\n");
}

int matrix_height(vector *root) {
    int height = 0;
    while (root -> next) {
        if(root -> index == 0 && root -> value != 0) {
            if(root -> value > height) {
                height = root -> value;
            }
        }
        root = root -> next;
    }
    return height;
}

int matrix_width(vector *root) {
    int width = 0;
    while (root -> next) {
        if(root -> index != 0 && root -> value != 0) {
            if(root -> index > width) {
                width = root -> index;
            }
        }
        root = root -> next;
    }
    return width;
}

void matrix_output(vector *root) {
    int height = matrix_height(root);
    int width = matrix_width(root);
    for(int i = 0; i < height; ++i){
        root = root -> next;
        for (int j = 0; j < width; ++j) {
            if(root -> index - 1 == j) {
                printf("%.3f ", root -> value);
                root = root -> next;
            } else {
                printf("0    ");
            }
        }
        printf("\n");
    }
}

vector *vector_input() {
    vector *v1 = NULL;
    int findex;
    float fvalue;
    scanf("%d", &findex);
    scanf("%f", &fvalue);
    while ((findex == 0) && (fvalue == 0)) {
        vector_add(v1, findex, fvalue);
        printf("Break time!\n");
        if(!v1) {
            v1 = vector_create(findex, fvalue);
            printf("Created!\n");
        } else {
            vector_add(v1, findex, fvalue);
            printf("Added!\n");
        }
        scanf("%d", &findex);
        scanf("%f", &fvalue);
    }
    return v1;
}

void search(vector *tmp, int *number, int *amount, int *count) {
    int kol = 0, max=0, sum=0;
    int numberI = *number;
    int amountI = *amount;
    int countI = *count;
    while (tmp) {
        if(tmp -> index != 0 && tmp -> value != 0) {
            kol += 1;
            sum += tmp -> value;
        }
        if(tmp -> index == 0 && tmp -> value != 0) {
            if (kol>max) {
                max=kol;
                numberI = tmp -> index;
                amountI = sum;
                countI = kol;
            }
            kol=0;
            sum=0;
        }
        if(tmp -> index == 0 && tmp -> value == 0) {
            break;
        }
        tmp = tmp -> next;
    }
}

void another_search(vector *tmp, int *number, int *count) {
    int kol = 0, sum=0;
    int numberI = *number;
    int countI = *count;
    while (tmp) {
        if(tmp -> index != 0 && tmp -> value != 0) {
            kol += 1;
            sum += tmp -> value;
        }
        if(tmp -> index == 0 && tmp -> value != 0) {
            if (kol==countI) {
                printf ("Number of another max amount row: %.3d ", numberI);
                printf("\n");
                printf ("Amount of elements in this row: %.3d ", sum);
                printf("\n");
            }
            kol=0;
            sum=0;
        }
        if(tmp -> index == 0 && tmp -> value == 0) {
            break;
        }
        tmp = tmp -> next;
    }

}