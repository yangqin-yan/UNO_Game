//
// Created by Thinkpad on 2019/6/16.
//

//define const
#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14
#define MAX_CARD 50000
#define MAX_HAND 300
#define CARD_NUM 52
#define MAX_MEMBER 10

//define structure of cards
typedef struct _card{
    char kind[10];
    int num;
}card;

typedef struct _member_structure{
    card hand[MAX_HAND];
    int situa;
    struct _member_structure *before,*next;
    int result;
    char name[50];
    // 0 - nothing
    // 1 - banned
    // 2 - draw 2 cards
    // 3 - draw 3 cards
    // 11 - skip the next player
    // 12 - change direction
}create;

typedef struct positions{
  int deck_position;
  int discard_position;
} po;

//define functions
#ifndef PROJECT_2_UNO_H
#define PROJECT_2_UNO_H
void file_welcome(FILE* fp, int num_round, int num_deck, int num_player);
void card_print(card a, FILE* fp);
void create_card(int num_deck, card **deck);
void shuffle_ini(card **deck, int num_deck, int aut, FILE* fp);
void who_first(create** member, int num_player);
void shuffle(card ****deck, int n);
po distribute(int num_player,int hand_card,card **deck,create **member,\
int num_deck,card **discard,po p, FILE* fp);
int display(create ***member, int hand_position, \
card ***discard, int discard_position, int **seq, FILE* fp, int**cumu);
po round_uno(po p,card **deck, create **member, card **discard, int *seq,\
FILE* fp, int* cumu);
po draw_card(create ***member, int hand_position, \
card ***deck, po p, card ***discard);
void create_member(int num_player, create **member);
int judge(create **member, FILE* fp, int *cnt_round);
po round_auto(po p, card **deck, create **member, card **discard, int *seq,\
FILE* fp, int* cumu);
void sort_card(card hand[]);
void whowins(create *member, FILE* fp);
int larger_than(card a, card b);
void free_member(create **member);
#endif //PROJECT_2_UNO_H
