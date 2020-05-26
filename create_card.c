//
// Created by Thinkpad on 2019/6/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"

void create_card(int num_deck, card** deck) {
    int i;
    *deck = (card*)calloc(num_deck*52+2,sizeof(card));
    for (i = 0; i < 52*num_deck; i++) {
        (*deck+i)->num = ((i % 52) / 4) + 2;
        if (i % 4 == 0)
            strcpy((*deck+i)->kind, "spade");
        if (i % 4 == 1)
            strcpy((*deck+i)->kind, "heart");
        if (i % 4 == 2)
            strcpy((*deck+i)->kind, "diamond");
        if (i % 4 == 3)
            strcpy((*deck+i)->kind, "club");
    }
}