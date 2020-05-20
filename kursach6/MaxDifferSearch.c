#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "student.h"
#include "iterators.h"

int check(char RAW_NAME[], char group[]) {
    double average = 0, min=5, max=0, max_differ=0, differ=0;
    char max_differ_group_number;
    FILE *file;
    file = fopen(RAW_NAME, "r");
    student *squad;
    if (file == NULL) {
        printf("Error!!!");
    } else {
        while (!feof(file)) {
            squad = malloc(sizeof(squad));
            fread(&squad, sizeof(squad), 1, file);
            if(strcmp(squad -> group, group)) {
                average=((squad -> m.disk) + (squad -> m.mat) + (squad -> m.mat) + (squad -> m.it)) / 4;
                if (average<min) {
                    min=average;
                }
                if (average>max) {
                    max=average;
                }
                differ=max-min;
                if (differ > max_differ) {
                    max_differ=differ;
                    max_differ_group_number=*group;
                } 
            }
        }
    }
    fclose(file);
    return max_differ_group_number;
}