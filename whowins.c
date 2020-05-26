//
// Created by Thinkpad on 2019/7/1.
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

void whowins(create *member, FILE* fp){
    create *head,*champion;
    head = member;
    champion = calloc(1, sizeof(create));
    champion->result = -999999;
    do{
        printf("Player %s Score: %d\n",member->name,member->result);
        fprintf(fp,"Player %s Score: %d\n",member->name,member->result);
        member = (member)->next;
        if(member->result > champion->result){
            champion = member;
        }
    }
    while(head != member);

    do{
        if(member->result == champion->result){
            printf("%s WINS!\n",member->name);
            fprintf(fp,"%s WINS!\n",member->name);
        }
        member = (member)->next;
    }
    while(head != member);
}
