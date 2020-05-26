//
// Created by Thinkpad on 2019/6/16.
//
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"

void shuffle_ini(card **deck,int num_deck,int aut, FILE* fp){
    int i,s,t;
    char str[10];
    //adjust number of each kind of card
    printf("Shuffling cards...\n");
    //shuffle the deck
    for(i=0;i<CARD_NUM*num_deck;i++){
        //generate random numbers
        s = floor(rand() % CARD_NUM*num_deck);
        t = (*deck+s)->num;
        strcpy(str,(*deck+s)->kind);
        (*deck+s)->num = (*deck+i)->num;
        strcpy((*deck+s)->kind, (*deck+i)->kind);
        (*deck+i)->num = t;
        strcpy((*deck+i)->kind,str);
    }
    fprintf(fp,"Shuffle Result:\n");
    if(aut == 1){
        printf("Shuffle Result:\n");
    }
    for(i=0;i<CARD_NUM*num_deck;i++){
            card_print(*(*deck + i), fp);
        if(i % 5 == 4){
            if(aut == 1){
                printf("\n");
            }
            fprintf(fp,"\n");
        }
    }
    if(aut == 0){
        system("cls");
        printf("\nShuffle finished...");
    }
    printf("\n");

}
