#ifndef _HEAD_H_
#define _HEAD_H_

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct polynom{
    double coeff;
    int degree;
    struct polynom* next;
};

struct polynom* get_list(void);
struct polynom* make_polynom(struct polynom*, struct polynom*);
void put_list(struct polynom*);
void clear_list(struct polynom**);

char* s_gets(char*, int);
void check_num(char*, char*);

#endif 