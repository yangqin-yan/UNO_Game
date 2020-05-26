//
// Created by Thinkpad on 2019/7/8.
//
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"

void shuffle(card ****deck,int n){
    int i,s,t;
    char str[10];
    //adjust number of each kind of card

    //shuffle the deck
    srand((unsigned int)time(NULL));
    for(i=0;i<n;i++){
        //generate random numbers
        s = floor(rand() % CARD_NUM);
        t = (***deck+s)->num;
        strcpy(str,(***deck+s)->kind);
        (***deck+s)->num = (***deck+i)->num;
        strcpy((***deck+s)->kind, (***deck+i)->kind);
        (***deck+i)->num = t;
        strcpy((***deck+i)->kind,str);
    }
}

