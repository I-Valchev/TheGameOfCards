#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#define HAND_NUMBER 5
#include "deck.h"
#include "card.h"
typedef struct{
    char *name;
    int lifePoints;
    int mana;
    int turn;
    deck_t deck;
    card_t hand[HAND_NUMBER];
}player_t;



void change_lifePoints(player_t *player,int value);
int play_card_from_hand(player_t *player,int i,int l);
void turn_begin(player_t *player);
#endif // PLAYER_H_INCLUDED
