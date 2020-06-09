#include "stdio.h"
#include "stdlib.h"

#include "list.h"

void List_create(List *L) {
    L -> next = 0;
}

int List_check(List *L) {
    if (L -> next == NULL) return 1;
    else return 0;
}

int List_size(List *L) {
    int size=0;
    while (L) {
        L = L -> next;
        size+=1;
    }
    return size;
}

void List_push_first(List *L, int *value) {
    struct List tmp = *L;
    struct List tmp1 = *L;
    if (!L) {
        printf("\nЛинейный список заполнен\n\n");
        return;
    } else {
        for(int i = 0; i < List_size(L); ++i) {
            if (*value > L -> value) {
                L = L -> next; 
            } 
            if (*value < L -> value) {
                tmp = *L;
                L -> value = *value;
                L = L -> prev;
                while (L) {
                    tmp1 = *L;
                    *L = tmp;
                    L = L -> prev;
                }
            }
        }
    }
    printf("Элемент добавлен\n");
}

void List_push_last(List *L, int value) {
    if (!L) {
        printf("\nЛинейный список заполнен\n\n");
        return;
    }
    L = L -> next;
    L -> value = value;
    printf("Элемент добавлен\n");
}

void List_pop_first(List *L) {
    while (L) {
        L -> value = L -> next -> value;
        L -> next--;
    }
}

void List_pop_last(List *L) {
    L -> next--;
}

void List_print(List *L) {
    if(List_check(L) != 1) {
        while (L) {
            printf("%d  ", L -> value);
            L = L -> next;
        }
    }
    printf("\n");
}

void List_easy_insert(List *L, int *value) {
    int val = *value;
    struct List tmp = *L;
    struct List tmp1 = *L;
    List_create(&tmp);
    if(List_check(L) != 1) {
        for(int i = 0; i < List_size(L); ++i) {
            tmp = *L;
            while (L) {
                if (*L > tmp) {
                    tmp1 = *L; 
                    L = L -> next;
                    *L = tmp1;
                } else {
                   L = L -> next; 
                }
            }  
            *L = tmp; 
        }
        List_push_first(L, &val);
    }
}
