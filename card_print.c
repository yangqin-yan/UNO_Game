//
// Created by Thinkpad on 2019/6/30.
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

void card_print(card a, FILE* fp){
    if(a.num == JACK){
        printf("-%s Jack  ",a.kind);
        fprintf(fp,"-%s Jack  ",a.kind);
    }
    else if(a.num == QUEEN){
        printf("-%s Queen  ",a.kind);
        fprintf(fp,"-%s Queen  ",a.kind);
    }
    else if(a.num == KING){
        printf("-%s King  ",a.kind);
        fprintf(fp,"-%s King  ",a.kind);
    }
    else if(a.num == ACE){
        printf("-%s Ace  ",a.kind);
        fprintf(fp,"-%s Ace  ",a.kind);
    }
    else{
        printf("-%s %d  ",a.kind,a.num);
        fprintf(fp,"-%s %d  ",a.kind,a.num);
    }
}