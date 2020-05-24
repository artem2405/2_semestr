#include "stdio.h"
#include "struct.h"
#include "stdlib.h"

//iter
List *end(List *current) {
    while (current -> next != NULL) {
        current = current -> next;
    }
    return current;
}

List *next(List *current) {
    if(current -> next != NULL) {
        current = current -> next;
    }
    return current;
}

List *list_create(enum Footballers value) {
    List *list = (List *)malloc(sizeof(List));
    list -> football = value;
    list -> next = NULL;
    return list;
}

int list_size(List *l, int count) {
    if(l -> next != NULL) {
        return list_size(l -> next, count + 1);
    } 
    return count;
}

struct List *list_add(List *root) {
  struct List *temp, *p;
  temp = (struct List*)malloc(sizeof(List));
  root = end(root);
  p = root->next; // сохранение указателя на следующий узел
  root->next = temp; // предыдущий узел указывает на создаваемый
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = root; // созданный узел указывает на предыдущий узел
  p->prev = temp;
  return(root);
}

struct List *list_delete(List *root) {
    struct list *prev, *next;
    prev = root->prev; // узел, предшествующий lst
    next = root->next; // узел, следующий за lst
    prev -> next = root -> next; // переставляем указатель
    next -> prev = root -> prev; // переставляем указатель
    free(root); // освобождаем память удаляемого элемента
    return(root);
}

void FootballerToString(enum Footballers value) {
    switch (value) {
    case Messi:
        printf("Messi ");
        break;
    case Ronaldo:
        printf("Ronaldo ");
        break;
    case Neymar:
        printf("Neymar ");
        break;
    case Mbappe:
        printf("Mbappe ");
        break;
    case Hazard:
        printf("Hazard ");
        break;
    default:
        break;
    }
}

void list_print(List *l) {
    FootballerToString(l -> football);
    if(l -> next != NULL) {
        list_print(l -> next);
    }
}

List *list_change(List *l) {
    enum Footballers second, penult;
    int size = list_size(l, 0) + 1;
    if(size == 2) {
        List *ans = l -> next;
        l -> next -> next = l;
        l -> next = NULL;
        return ans;
    }
    else {
        List *root = l -> next;
        for(int i = 0; i < size; ++i) {
            l = l -> next;
            if (i==2) {
                second = chooseFootballer(i);
            }
            if (i==(size-1)) {
                penult = chooseFootballer(i);
            }
        }
        l -> next = NULL;
        for(int i = 0; i < size; ++i) {
            l = l -> next;
            if (i==2) {
                *l = chooseFootballer(penult);
            }
            if (i==(size-1)) {
                *l = chooseFootballer(second);
            }
        }
        return root;
    }
}