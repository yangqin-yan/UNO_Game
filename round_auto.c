//
// Created by Thinkpad on 2019/7/8.
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
po round_auto(po p,card **deck,create **member,card **discard,int *seq, FILE* fp,int *cumu) {
    int hand_position = 0, i;
    //tips for players
    //sort the card
    sort_card((*member)->hand);
    printf("-%s cards: ", (*member)->name);
    fprintf(fp,"-%s cards: ", (*member)->name);
    printf("\n");
    fprintf(fp,"\n");

    while ((*member)->hand[hand_position].kind[0] == 's' || \
    (*member)->hand[hand_position].kind[0] == 'h' || \
    (*member)->hand[hand_position].kind[0] == 'd' || \
    (*member)->hand[hand_position].kind[0] == 'c') {
        card_print((*member)->hand[hand_position], fp);
        hand_position++;
    }
    //judge situation
    //rank 2: next player draw 2 cards
    //rank 3: next player draw 3 cards
    //rank 7: cancel an attack
    //Queen: change round order
    //Jack: skip the next player
    if ((*member)->situa == *cumu * 2 && (*member)->situa > 0) {
        //stupid robot algorithm
        for (i = 0; i < hand_position; i++) {
            if ((*member)->hand[i].num == (*discard+p.discard_position)->num || \
            (*member)->hand[i].kind[0] == (*discard+p.discard_position)->kind[0]) {
                (*member)->situa = 0;
                if((*member)->hand[i].num == 2){
                    if(*seq == 0){
                        (*member)->next->situa+=2;
                    }
                    else{
                        (*member)->before->situa+=2;
                    }
                    (*cumu)++;
                }
                p.discard_position = display(&member, i, &discard, p.discard_position,\
                &seq, fp, &cumu);
                return p;
            }
        }
        //draw a card
        printf("Player %s draw %d cards: ",(*member)->name,(*member)->situa);
        fprintf(fp,"Player %s draw %d cards: ",(*member)->name,(*member)->situa);
        for(int a=0; a<(*member)->situa; a++){
            p = draw_card(&member, hand_position, &deck, \
                p, &discard);
            printf("-%s %d ",(*member)->hand[hand_position].kind,(*member)->hand[hand_position].num);
            fprintf(fp,"-%s %d ",(*member)->hand[hand_position].kind,(*member)->hand[hand_position].num);
            hand_position++;
        }
        printf("\n");
        fprintf(fp,"\n");
        (*member)->situa = 0;
        *cumu = 0;
    }
    else if ((*member)->situa == *cumu * 3 && (*member)->situa > 0) {
        for (i = 0; i < hand_position; i++) {
            if ((*member)->hand[i].num == (*discard+p.discard_position)->num || \
            (*member)->hand[i].kind[0] == (*discard+p.discard_position)->kind[0]) {
                if((*member)->hand[i].num == 3){
                    if(*seq == 0){
                        (*member)->next->situa+=3;
                    }
                    else{
                        (*member)->before->situa+=3;
                    }
                    (*cumu)+=3;
                }
                p.discard_position = display(&member, i, &discard, p.discard_position,\
                &seq, fp, &cumu);
                (*member)->situa = 0;
                return p;
            }
        }
        //draw a card
        printf("Player %s:DRAW %d cards:",(*member)->name,(*member)->situa);
        for(int a=0; a<(*member)->situa; a++){
            p = draw_card(&member, hand_position, &deck, \
                p, &discard);
            printf("-%s %d ",(*member)->hand[hand_position].kind,(*member)->hand[hand_position].num);
            fprintf(fp,"-%s %d ",(*member)->hand[hand_position].kind,(*member)->hand[hand_position].num);
            hand_position++;
        }
        printf("\n");
        fprintf(fp,"\n");
        (*member)->situa = 0;
        *cumu = 0;
    }
    else if ((*member)->situa == JACK) {
        (*member)->situa = 0;
        return p;
    }
    else {//default
        //judge whether the card can be played
        for (i = 0; i < hand_position; i++) {
            if ((*member)->hand[i].num == (*discard+p.discard_position)->num || \
            (*member)->hand[i].kind[0] == (*discard+p.discard_position)->kind[0] \
            || (*discard+p.discard_position)->num == 0 ) {
                //display the card
                p.discard_position = display(&member, i, &discard, p.discard_position, &seq, fp, &cumu);
                return p;
            }
        }
        //draw a card
        printf("Player %s draw one card: ",(*member)->name);
        fprintf(fp,"Player %s draw one card: ",(*member)->name);
        p = draw_card(&member, hand_position, &deck, \
                p, &discard);
        printf("-%s %d",(*member)->hand[hand_position].kind,(*member)->hand[hand_position].num);
        fprintf(fp,"-%s %d",(*member)->hand[hand_position].kind,(*member)->hand[hand_position].num);
        printf("\n");
        fprintf(fp,"\n");
    }
    return p;
}

