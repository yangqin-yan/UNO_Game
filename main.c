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

int main(int argc,char *argv[]) {
    //definition
    int num_deck = 0,hand_card = 0,num_player = 0;
    int i,num_round = 0;
    int aut=0;
    char filename[50] = "onecard.log";

    printf("*******************\n"
           "\n"
           "Welcome to UNO!\n"
           "\n"
           "*******************\n");
    printf("\n");

    //command
    for(i=0;i<argc;++i){
        if(strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"--help") == 0){
            printf("-h|--help print this help message\n"
                   "--log filename write the logs in filename (default: onecard.log)\n"
                   "-n n|--player-number=n n players, n must be larger than 2 (default: 4)\n"
                   "-c c|--initial-cards=c deal c cards per player, c must be at least 2 (default: 5)\n"
                   "-d d|--decks=d use d decks 52 cards each, d must be at least 2 (default: 2)\n"
                   "-r r|--rounds=r play r rounds, r must be at least 1 (default: 1)\n"
                   "-a|--auto run in demo mode\n");
        }
        //if --log
        if(strcmp(argv[i],"--log") == 0){
            strcpy(filename,argv[i+1]);
        }
        if(strcmp(argv[i],"-n") == 0){
            num_player = atoi(argv[i+1]);
        }
        if(memcmp(argv[i],"--player-number=", sizeof("--player-number")) == 0){
            num_player = atoi(&argv[i][16]);
        }
        if(strcmp(argv[i],"-c") == 0){
            hand_card = atoi(argv[i+1]);
        }
        if(strcmp(argv[i],"-d") == 0){
            num_deck = atoi(argv[i+1]);
        }
        if(memcmp(argv[i],"--decks=", sizeof("--decks=")) == 0){
            num_deck = atoi(&argv[i][8]);
        }
        if(strcmp(argv[i],"-r") == 0){
            num_round = atoi(argv[i+1]);
        }
        if(memcmp(argv[i],"--rounds=",sizeof("--rounds=")) == 0){
            num_round = atoi(&argv[i][9]);
        }
        //-a auto
        if(strcmp(argv[i],"-a") == 0 || strcmp(argv[i],"--auto") == 0){
            aut = 1;
        }
    }

    FILE* fp = fopen(filename,"w+");
    if(fp == NULL){
        printf("File cannot open\n");
        exit(8);
    }
    //rename("onecard.txt",filename);
    //default
    if(num_player == 0)
        num_player = 4;
    if(num_deck == 0)
        num_deck = 2;
    if(num_round == 0)
        num_round = 1;
    if(hand_card == 0)
        hand_card = 5;

    //initialize
    po p;
    create *member;
    int cnt_round = 1;
    create_member(num_player,&member);
    file_welcome(fp,num_round,num_deck,num_player);
    srand((unsigned int)time(NULL));
    for(i=0;i<num_round;i++) {
        card *deck, *discard;
        int cumu = 0;
        p.deck_position = 0;
        p.discard_position = 0;
        //closed circle
        create_card(num_deck, &deck);
        shuffle_ini(&deck, num_deck, aut, fp);
        //distribute
        p = distribute(num_player,hand_card,&deck,&member,\
        num_deck,&discard,p,fp);
        //rounds
        discard = (card *) calloc(MAX_CARD, sizeof(card));
        int seq = 0;
        int ju = 0;
        who_first(&member, num_player);
        while (1) {
            if (aut == 0){
              p = round_uno(p, &deck, &member, &discard, &seq, fp, &cumu);
              system("cls");
            }
            if (aut == 1){
            p = round_auto(p, &deck, &member, &discard, &seq, fp, &cumu);
            }
            ju = judge(&member,fp, &cnt_round);
            if (ju == 1) {
                break;
            }
            if (seq == 0) {
                member = member->next;
            }//judge the direction
            else {
                member = member->before;
            }
        }
            //free the memory
            free(deck);
            free(discard);
    }
    whowins(member, fp);
    printf("\n****GAME OVER****\n");
    fprintf(fp,"\n****GAME OVER****\n");

    free_member(&member);
    fclose(fp);

    getchar();getchar();
    return 0;
}