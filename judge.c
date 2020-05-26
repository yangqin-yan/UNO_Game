//
// Created by Thinkpad on 2019/6/30.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14

int judge(create **member, FILE* fp, int *cnt_round){
    for(int i=0;i<20;i++){
        if((*member)->hand[i].num >= 2 && (*member)->hand[i].num <= 14){
            return 0;
        }
    }
    create *head;
    head = *member;
    printf("\n---- Stats ----\n");
    fprintf(fp,"\n---- Stats ----\n");
    printf("Round %d result:\n",*cnt_round);
    fprintf(fp,"Round %d result:\n",*cnt_round);
    (*cnt_round)++;
    int cnt;
    do{
        cnt = 0;
        while((*member)->hand[cnt].num != 0 ){
            (*member)->hand[cnt].num = 0;
            strcmp((*member)->hand[cnt].kind,"\0");
            cnt++;
        }
        (*member)->result -= cnt;
        printf("Player %s: %d, total: %d\n",(*member)->name, -cnt, (*member)->result);
        *member = (*member)->next;
    }
    while(head != *member);
    printf("Round %d ends.\n",*cnt_round-1);
    fprintf(fp,"Round %d ends.\n",*cnt_round-1);
    return 1;
}