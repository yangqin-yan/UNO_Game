//
// Created by Thinkpad on 2019/7/11.
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

int larger_than(card a, card b){
    int score_a=0,score_b=0;
    if(a.kind[0] == 's'){
        score_a = 1;
    }
    if(a.kind[0] == 'h'){
        score_a = 2;
    }
    if(a.kind[0] == 'd'){
        score_a = 3;
    }
    if(a.kind[0] == 'c'){
        score_a = 4;
    }
    if(b.kind[0] == 's'){
        score_b = 1;
    }
    if(b.kind[0] == 'h'){
        score_b = 2;
    }
    if(b.kind[0] == 'd'){
        score_b = 3;
    }
    if(b.kind[0] == 'c'){
        score_b = 4;
    }
    if(score_a > score_b){
        return 1;
    }
    else if(score_a < score_b){
        return 0;
    }
    else{
        if(a.num > b.num)
            return 1;
        else
            return 0;
    }
}

void swap(card *a, card *b){
    card temp;
    temp.num = a->num;
    strcpy(temp.kind,a->kind);
    a->num = b->num;
    strcpy(a->kind,b->kind);
    b->num = temp.num;
    strcpy(b->kind,temp.kind);

}

void sort_card(card hand[]){
    int i=0,j=0;
    if(hand == NULL){
        printf("NULL player NULL card\n");
        exit(238);
    }
    while(hand[i].num != 0 ){///!!!
        j = i;
        while(hand[j].num != 0){
            if(larger_than(hand[i],hand[j]) == 1){
                swap(&hand[i],&hand[j]);
            }
            j++;
        }
        i++;
    }
}

