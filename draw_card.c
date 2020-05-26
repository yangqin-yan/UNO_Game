//
// Created by Thinkpad on 2019/6/25.
//
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"

po draw_card(create ***member,int hand_position, \
card ***deck,po p,card ***discard){
    //check whether the deck has cards
    if(**deck+p.deck_position == NULL){
        printf("Deck overload\n");
        exit(10);
    }
    if(strcmp((**deck+p.deck_position)->kind,"spade") != 0 && \
    strcmp((**deck+p.deck_position)->kind,"heart") != 0 && \
    strcmp((**deck+p.deck_position)->kind,"diamond") != 0 && \
    strcmp((**deck+p.deck_position)->kind,"club") != 0){
        for(int i=0;i<p.discard_position-1;i++){
            (**deck+i)->num = (**discard+i)->num;//copy the discard to the deck and clean the discard
            (**discard+i)->num = 0;
            strcpy((**deck+i)->kind,"0");
            strcpy((**deck+i)->kind,(**discard+i)->kind);
        }
        p.deck_position = 0;//point to the top of the deck
        (**discard)->num = (**discard+p.discard_position)->num;
        strcpy((**discard)->kind,(**discard+p.discard_position)->kind);//reserve the latest played card
        shuffle(&deck,p.discard_position);//p.discard_position is equal to the number of cards in deck
        p.discard_position = 0;//point to the latest card as the start of the discard
    }
    if(hand_position >= MAX_HAND){
        printf("ERROR: Player %s booms because of too many cards in hand!\n",(**member)->name);
        exit(233);
    }
    //draw
    (**member)->hand[hand_position].num = (**deck+p.deck_position)->num;
    strcpy((**member)->hand[hand_position].kind,(**deck+p.deck_position)->kind);
    p.deck_position++;
    return p;
}
