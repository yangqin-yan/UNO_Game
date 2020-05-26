//
// Created by Thinkpad on 2019/7/13.
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
void file_welcome(FILE* fp, int num_round, int num_deck, int num_player){
    fprintf(fp,"*******************\n"
               "*                 *\n"
               "* Welcome to UNO! *\n"
               "*                 *\n"
               "*******************\n");
    fprintf(fp,"\n");
    fprintf(fp,"---- Initial setup ----\n"
               "-Number of rounds: %d\n"
               "-Number of decks: %d\n"
               "-Number of players: %d\n\n",num_round,num_deck,num_player);
    printf("---- Initial setup ----\n"
           "-Number of rounds: %d\n"
           "-Number of decks: %d\n"
           "-Number of players: %d\n\n",num_round,num_deck,num_player);
}