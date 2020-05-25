#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include "../data.h"
#include "function.h"

void right_move(cell *tmp) {
	tmp = tmp->right;
	return;
}

void main_change(cell *tmp) {
    if ((tmp->left->val.oper != '*') && (tmp->left->val.oper != '(') && (tmp->right->val.oper != '*') && (tmp->right->val.oper != '(')) {
		right_move(tmp->left);
		right_move(tmp->right);
	}
    else if ((tmp->left->val.oper != '*') && (tmp->left->val.oper != '(')) {
		cell *a = (cell *)malloc(sizeof(cell));
		right_move(tmp->left);
		a = tmp;
		tmp->val.oper = '$';
		free(tmp->left);
		tmp->left = NULL;
		tmp->right = a;
		free(a);
	}
    else if ((tmp->right->val.oper != '*') && (tmp->right->val.oper != '(')) {
		cell *a = (cell *)malloc(sizeof(cell));
		right_move(tmp->right);
		a = tmp;
		tmp->val.oper = '$';
		free(tmp->left);
		tmp->left = NULL;
		tmp->right = a;
		free(a);
	}
	return;
}

void both_move(cell *tmp) {
    if (tmp->val.oper != '*') {
        both_move(tmp->left);
        both_move(tmp->right);
    }
	else {
		main_change(tmp);
	}
	return;
}

void func_18(cell *tmp) {
	if (tmp->left != NULL) {
    	func_18(tmp->left);
    }
	if (tmp->right!= NULL) {
    	func_18(tmp->right);
    }
  	if (tmp->val.oper == '*') {
    	both_move(tmp->left);
    	both_move(tmp->right);
    	main_change(tmp);
    }
	return;
}