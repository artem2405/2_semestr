
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../data.h"
#include "function.h"

void func_18(cell *tmp) {
int min_numb;
	if (tmp->type == 0 && tmp->val.oper == '*' && tmp->left) {
		if (tmp->left->type == 0 && tmp->left->val.oper == '(' && tmp->left->right) {
			cell *del;
			if((tmp->val.oper >= 'A') && (tmp->val.oper <= "Z") && (!tmp->type)) {
				tmp->val.oper = (char)((int)tmp->val.oper + 32);
				
			}
			elif ((tmp->type) && (tmp->val.value < 0)) {
				tmp->val.value *= -1;
			}
		}
	}
	if (tmp->left)
    {
        func_18(tmp->left);
    }
    if (tmp->right)
    {
        func_18(tmp->right);
    }
    return;
}
