//
// Created by Thinkpad on 2019/6/30.
//

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "uno.h"

void create_member(int num_player,create **member){
    create *node,*head;
    head = NULL;
    //member = calloc(num_player , sizeof(create));
    for(int i=0;i<num_player;i++){
        node = calloc(num_player , sizeof(create));
        //member = malloc(num_player * sizeof(create));
        if(i == 0){
            (*member) = node;
            head = node;
            (*member)->next = node;
        }
        else{
            node->next = (*member)->next;
            (*member)->next = node;
            node->before = *member;
            *member = (*member)->next;
        }

        printf("Player %d, your name is:",i+1);
        gets((*member)->name);
        system("cls");
    }
   //closed circle
   if(head == NULL){
       exit(100);
   }
    head->before = *member;
}