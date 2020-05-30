#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef struct vector vector;

struct vector {
    vector *prev;
    vector *next;
    int index;
    float value;
};

#endif