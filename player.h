#ifndef PLAYER_H
#define PLAYER_H
#define HAND_NUMBER 5
#include "deck.h"
#include "card.h"
typedef struct{
    char name[128];
    int lifePoints;
    int mana;
    int turn;
    deck_t deck;
    deck_t hand;
}player_t;



void change_lifePoints(player_t *player,int value);
void turn_begin(player_t *player);
#endif // PLAYER_H_INCLUDED
