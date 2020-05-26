//
// Created by Thinkpad on 2019/6/23.
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


po distribute(int num_player,int hand_card,card **deck,create **member,\
int num_deck,card **discard,po p, FILE* fp){
    int i,j;
    for(i=0;i<hand_card;i++){
        for(j=0;j<num_player;j++){
            p = draw_card(&member,i,&deck,\
            p, &discard);
            (*member) = (*member)->next;
        }
    }
    printf("\n");
    fprintf(fp,"\n");
    return p;

}
