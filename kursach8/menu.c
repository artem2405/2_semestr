#include "stdio.h"
#include "stdlib.h"

#include "functions.c"

enum Footballers chooseFootballer(int v) {
    switch (v) {
    case 0:
        return Messi;
        break;
    case 1:
        return Ronaldo;
        break;
    case 2:
        return Neymar;
        break;
    case 3:
        return Mbappe;
        break;
    case 4:
        return Hazard;
        break;
    default:
        break;
    }
}

int main() {
    printf("Start: \n");
    List *node = NULL;
    printf("1. Добавление элемента\n");
    printf("2. Удаление элемента\n");
    printf("3. Длина списка\n");
    printf("4. Печать списка\n");
    printf("5. Обмен элементов местами\n");
    printf("6. Завершить\n");
    int flag = 0;
    int value;
    while (flag != 6) {
        printf("\nNumber of func:\n");
        scanf("%d", &flag);
        switch (flag) {
        case 1:
            printf("Footballer to add: ");
            scanf("%d", &value);
            if(!node) {
                printf("\nCreated!\n");
                node = list_create(chooseFootballer(value));
                break;
            } else {
                list_add(chooseFootballer(value));
                printf("Another one in squad\n");
            }
            break;
        case 2:
            printf("Footballer to delete: ");
            scanf("%d", &value);
            if(node == NULL) {
                printf("\nNo list yet!\n");
                break;
            }
            list_delete(chooseFootballer(value));
            printf("Deleted\n");
            break;
        case 3:
            if(node) {
                printf("%d ", list_size(node, 0) + 1);
                break;
            }
            printf("\nNo list yet!\n");
            break;
        case 4:
            if(node) {
                list_print(node);
                break;
            }
            printf("\nNo list yet!\n");
            break;
        case 5:
            if(node) {
                node = list_change(node);
                break;
            }
            printf("\nNo list yet!\n");
            break;
        case 6:
            break;
        default:
            printf("\nERROR!\n");
            break;
        }
    }
    printf("Done\n");
}