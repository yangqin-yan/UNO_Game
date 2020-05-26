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

po round_uno(po p, card **deck, create **member,\
card **discard, int *seq, FILE* fp, int *cumu){
    int hand_position,i,match,num;
    char str[10],c[10];
    match = 0;

    while(match == 0){

        //tips for players
        sort_card((**member).hand);
        card_print(*(*discard+p.discard_position), fp);
        printf("-%s. It is your turn now, little brother.(press enter)\n",(*member)->name);
        getchar();getchar();

        hand_position = 0;
        while(((*member)->hand[hand_position].kind[0] == 's'||\
        (*member)->hand[hand_position].kind[0] == 'h'|| \
        (*member)->hand[hand_position].kind[0] == 'd'|| \
        (*member)->hand[hand_position].kind[0] == 'c') && \
        (*member)->hand[hand_position].num != 0) {//hand card
            card_print((*member)->hand[hand_position], fp);
            hand_position++;
        }
        //judge situation
        //rank 2: next player draw 2 cards
        //rank 3: next player draw 3 cards
        //rank 7: cancel an attack
        //Queen: change round order
        //Jack: skip the next player
        if((*member)->situa == *cumu * 2 && (*member)->situa != 0) {
            printf("\n***If none of the cards is valid to play, input 'NaN draw'***\n");
            printf("Which card to display:");
            scanf("%s %s", str, c);
            //read the input
            if (strcmp(c, "draw") == 0) { //draw a card
                for(int a=0;a<(*member)->situa;a++){
                    p = draw_card(&member, hand_position, &deck, \
                p, &discard);
                    hand_position++;
                }//penalty
                (*member)->situa = 0;
                *cumu = 0;
                break;
            }
            else if(strcmp(c,"Jack") == 0)
                num = 11;
            else  if(strcmp(c,"Queen") == 0)
                num = 12;
            else  if(strcmp(c,"King") == 0)
                num = 13;
            else  if(strcmp(c,"Ace") == 0)
                num = 14;
            else if(strcmp(c,"10") == 0)
                num = 10;
            else{
                num = c[0]-'0';
            }
            for(i=0;i<hand_position;i++){
                if((*member)->hand[i].num == num && (*member)->hand[i].kind[0] == str[0]){
                    if((num == (*discard+p.discard_position)->num) || \
                    (num ==  7 && str[0] == (*discard+p.discard_position)->kind[0])){
                        match = 1;
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
                    }
                    p.discard_position = display(&member,i, &discard, p.discard_position, &seq, fp, &cumu);
                    break;
                }
            }
        }
        else if((*member)->situa == *cumu * 3 && (*member)->situa != 0){
            printf("\n***If none of the cards is valid to play, input 'NaN draw'***\n");
            printf("Which card to display:");
            scanf("%s %s", str, c);
            //read the input
            if (strcmp(c, "draw") == 0) { //draw a card
                for(int a=0;a<(*member)->situa;a++){
                    p = draw_card(&member, hand_position, &deck, \
                    p, &discard);
                    hand_position++;
                }
                (*member)->situa = 0;
                *cumu = 0;
                break;
            }
            else if(strcmp(c,"Jack") == 0)
                num = 11;
            else  if(strcmp(c,"Queen") == 0)
                num = 12;
            else  if(strcmp(c,"King") == 0)
                num = 13;
            else  if(strcmp(c,"Ace") == 0)
                num = 14;
            else if(strcmp(c,"10") == 0)
                num = 10;
            else{
                num = c[0]-'0';
            }
            for(i=0;i<hand_position;i++){
                if((*member)->hand[i].num == num && (*member)->hand[i].kind[0] == str[0]){
                    if((num ==  7 || num == (*discard+p.discard_position)->num) || \
                    str[0] == (*discard+p.discard_position)->kind[0]){
                        match = 1;
                        if((*member)->hand[i].num == 3){
                            if(*seq == 0){
                                (*member)->next->situa+=3;
                            }
                            else{
                                (*member)->before->situa+=3;
                            }
                            (*cumu)++;
                        }
                        p.discard_position = display(&member, i, &discard,\
                        p.discard_position, &seq, fp, &cumu);
                        break;
                    }
                }
            }
        }
        else if((*member)->situa == JACK){
            (*member)->situa = 0;
            break;
        }
        else{//default
            printf("\n***If none of the cards is valid to play, input 'NaN draw'***\n");
            printf("Which card to display:");
            scanf("%s %s",str,c);

            //read the input
            if(strcmp(c,"draw") == 0){ //draw a card
                p = draw_card(&member, hand_position, &deck, \
                p, &discard);
                for(int k=0;k<20;k++){
                    if(strcmp((*member)->hand[k].kind,"spade") !=0 && \
                strcmp((*member)->hand[k].kind,"heart") !=0 && \
                strcmp((*member)->hand[k].kind,"diamond") !=0 && \
                strcmp((*member)->hand[k].kind,"club") !=0 ){
                        break;
                    }
                    card_print((*member)->hand[k], fp);
                }
                printf("\n");
                break;
            }
            else if(strcmp(c,"Jack") == 0)
                num = 11;
            else  if(strcmp(c,"Queen") == 0)
                num = 12;
            else  if(strcmp(c,"King") == 0)
                num = 13;
            else  if(strcmp(c,"Ace") == 0)
                num = 14;
            else if(strcmp(c,"10") == 0)
                num = 10;
            else{
                num = c[0]-'0';
            }
            //judge whether the card can be played
            for(i=0;i<hand_position;i++){
                if( ((*member)->hand[i].num == num && (*member)->hand[i].kind[0] == str[0]) ||\
                (*discard+p.discard_position)->num == 0 ){
                    if(num ==  (*discard+p.discard_position)->num || \
                str[0] == (*discard+p.discard_position)->kind[0] || \
                (*discard+p.discard_position)->num == 0){
                        match = 1;
                        p.discard_position = display(&member, i, &discard,\
                        p.discard_position, &seq, fp, &cumu);
                        break;
                    }
                }
            }
            if(match == 0){
                printf("invalid display,please display again(press enter)\n");
                getchar();
            }
        }
        }

    return p;

}
