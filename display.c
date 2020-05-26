//
// Created by Thinkpad on 2019/6/24.
//
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"

int display(create ***member,int hand_position, \
card ***discard,int discard_position,int **seq,FILE* fp, int** cumu){

    //play to the discard
    discard_position++;
    if(discard_position > MAX_CARD){
        printf("discard space overloaded\n");
        exit(7);
    }
    (**discard+discard_position)->num = (**member)->hand[hand_position].num;//copy the card in the hand to the discard
    strcpy((**discard+discard_position)->kind,(**member)->hand[hand_position].kind);

    printf("\nPlayer %s play:",(**member)->name);
    fprintf(fp,"\nPlayer %s play:",(**member)->name);
    card_print(*(**discard+discard_position), fp);
    printf("\n");
    fprintf(fp,"\n");
    if(hand_position < MAX_HAND){
        for(int i=hand_position;i<MAX_HAND-1;i++){
            (**member)->hand[i].num = (**member)->hand[i+1].num;
            strcpy((**member)->hand[i].kind,(**member)->hand[i+1].kind);
        }
    }
    else{
        if(hand_position == MAX_HAND-1){
            (**member)->hand[MAX_HAND-1].num = 0;
        }
        else{
            printf("hand_position is over its boundary.\n");
            exit(888);
        }
    }
    //judge the special effect of the card
    if((**discard+discard_position)->num == 2 && **seq == 0){
        ((**member)->next)->situa += 2;
        (**cumu)++;
    }
    else if((**discard+discard_position)->num == 2 && **seq == 1){
        ((**member)->before)->situa += 2;
        (**cumu)++;
    }
    else if((**discard+discard_position)->num == 3 && **seq == 0){
        ((**member)->next)->situa += 3;
        (**cumu)++;
    }
    else if((**discard+discard_position)->num == 3 && **seq == 1){
        ((**member)->before)->situa += 3;
        (**cumu)++;
    }
    else if((**discard+discard_position)->num == 7 && **seq == 0){
        (**member)->situa = 7;
        (**cumu) = 0;
    }
    else if((**discard+discard_position)->num == 7 && **seq == 1){
        (**member)->situa = 7;
        (**cumu) = 0;
    }
    else if((**discard+discard_position)->num == 11 && **seq == 0){
        (**member)->next->next->situa = (**member)->situa;
        ((**member)->next)->situa = 11;
    }
    else if((**discard+discard_position)->num == 11 && **seq == 1){
        (**member)->before->before->situa = (**member)->situa;
        ((**member)->before)->situa = 11;
    }
    else if((**discard+discard_position)->num == 12 && **seq == 0){
        **seq = 1;
        (**member)->before->situa = (**member)->situa;
    }
    else if((**discard+discard_position)->num == 12 && **seq == 1){
        **seq = 0;
        (**member)->next->situa = (**member)->situa;
    }
    return discard_position;
}
