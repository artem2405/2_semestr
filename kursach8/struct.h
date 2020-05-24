#ifndef _LIST_H_
#define _LIST_H_

enum Footballers {
    Messi = 0,
    Ronaldo = 1,
    Neymar = 2,
    Mbappe = 3,
    Hazard = 4
};

typedef struct List List;

struct List {
    enum Footballers football;
    List *next;
    List *prev;
};

#endif