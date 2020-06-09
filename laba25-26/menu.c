#include "stdio.h"
#include "stdlib.h"

#include "list.h"

int main() {
    printf("Start: \n");
    struct List *l = NULL;
    List_create(&l);
    printf("1. Добавить элелмент в начало\n");
    printf("2. Добавить элемент в конец\n");
    printf("3. Удалить первый элемент\n");
    printf("4. Удалить последний элемент\n");
    printf("5. Вывести содержимое линейного списка\n");
    printf("6. Сортировка линейного списка простой вставкой и вставка нового элемента в список\n");
    printf("7. Выход\n");
    int flag = 0;
    int value;
    while (flag != 7) {
        printf("Выбор функции:\n");
        scanf("%d", &flag);
        switch (flag) {
        case 1:
            printf("Введите число: ");
            scanf("%d", &value);
            List_push_first(l, value);
            printf("\n");
            break;
        case 2:
            printf("Введите число: ");
            scanf("%d", &value);
            List_push_last(l, value);
            break;
        case 3:
            List_pop_first(&l);
            break;
        case 4:
            List_pop_last(&l);
            break;
        case 5:
            List_print(&l);
            break;
        case 6:
            printf("Введите значение нового элемента: ");
            scanf("%d", &value);
            List_easy_insert(&l, &value);
            break;
        case 7:
            break;
        default:
            printf("\nОшибка!\n");
            break;
        }
    }
    printf("Done\n");
}