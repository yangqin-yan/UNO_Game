//
// Created by Thinkpad on 2019/7/14.
//
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"
void free_member(create **member) {
    create *tmp = NULL;
    create *pHead = *member;
    while (pHead->next != NULL) {
        tmp = pHead;
        pHead = pHead->next;
        free(tmp);
    }
    free(pHead);
}