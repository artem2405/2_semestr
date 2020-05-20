#include "marks.h"
#include "offset.h"

#ifndef _student_h_
#define _student_h_
typedef struct {
        int primary_key;
        char name[15];
        char initials[2];
        char group[15];
        enum SEX {
                SEX_F = 'F',
                SEX_M = 'M'
        } SEX;
        marks m;
        offset of;
} student;

#endif 

