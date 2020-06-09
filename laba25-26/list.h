#ifndef _LIST_H_
#define _LIST_H_

typedef struct List List;
struct List {
    int value;
    struct List *next;
    struct List *prev;
};

#endif
