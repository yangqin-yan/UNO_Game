//
// Created by Thinkpad on 2019/7/14.
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

void who_first(create** member, int num_player){
    for(int j=0; j<num_player; j++){
        sort_card((*member)->hand);
        (*member) = (*member)->next;
    }
    create* head = *member;
    for(int i=0; i<num_player; i++){
        (*member) = (*member)->next;
        if(larger_than(head->hand[0],(*member)->hand[0]) == 1){
            head = (*member);
        }
        i++;
    }
    *member = head;
}
