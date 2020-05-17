#include <stdio.h>
#include <malloc.h>

#include "Struct.c"

void search (btree *tmp, int *massive, int level, int max_level) {
    if (p->left != NULL) {
        massive[level] +=1;
        level += 1;
        if (level>max_level) {
            massive = (int**) realloc(massive, level * sizeof(int*));
            max_level=level;
        }
        search(p->left, massive, level, max_level);  
    }
    level-=1;;
    if (p->right != NULL) {
        massive[level] +=1;
        level += 1;
        if (level>max_level) {
            massive = (int**) realloc(massive, level * sizeof(int*));
            max_level=level;
        }
        search(p->right, massive, level, max_level);  
    }
}

void width_search(btree *tree){
    int level, max, max_level, *massive;
    level=0;
    max_level=0;
    massive = (int *)malloc(level * sizeof(int));
    if (p->left != NULL) {
        massive[level] +=1;
        level += 1;
        if (level>max_level) {
            massive = (int**)realloc(massive, level * sizeof(int*));
            max_level=level;
        }
        search(p->left, massive, level, max_level);  
    }
    level=0;
    if (p->right != NULL) {
        massive[level] +=1;
        level += 1;
        if (level>max_level) {
            massive = (int**) realloc(massive, level * sizeof(int*));
            max_level=level;
        }
        search(p->right, massive, level, max_level);  
    }
    max=0;
    for(int i=0; i<=level; i++) {
        if (massive[i]>max) {
            max=massive[i];
        }
    } 
    printf("%d", max);  
}
