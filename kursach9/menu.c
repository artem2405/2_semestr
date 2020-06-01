#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "keys.h"
#include "element.h"
#include "ShellSort.c"
#include "search.c"

int menu(void) {
    printf("%s\n", "1. Ввод таблицы");
    printf("%s\n", "2. Сортировка таблицы");
    printf("%s\n", "3. Поиск элементов по ключу");
    printf("%s\n", "4. Выход");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main() {
    element allwords[12];
    keys keys[12];
    int size = 0;
    printf("%s\n", "Welcome!");
    int k = 0;
    while (k != 4) {
        k = menu();
        switch (k) {
        case 1: {
            size += 1;
            allwords = (element *)realloc(allwords, size * sizeof(element));
            if (!allwords) {
                size -= 1;
                printf("Out of memory\n");
                break;
            }
            printf("Enter a string: ");
            getchar();
            scanf("%s\n", &(allwords[size - 1].allwords[12]));
            printf("Enter a key: ");
            getchar();
            scanf("%f", &(allwords[size - 1].keys));
            printf("\n");
        }
        break;
        case 2: { 
            for (int i = 0; i < size; i++) {
                printf("%7f  %s\n", allwords[i].keys, allwords[i].allwords);
            }
            printf("\n");
            shellSort(keys, allwords, &size);
            for (int i = 0; i < size; i++) {
                printf("%7f  %s\n", allwords[i].keys, allwords[i].allwords);
            }
            printf("\n");
        }
        break;
        case 3: {
            getchar();
            printf("Enter a key: ");
            float key;
            scanf("%f", &key);
            binary_search(keys, allwords, 0, size - 1, key);
        }
        break;
        case 4:
            break;
        default:
            printf("%s\n", "Try again)");
            break;
        }
    }
    printf("%s", "Goodbye!");
    return 0;
}