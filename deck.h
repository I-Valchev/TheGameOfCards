#ifndef DECK_H
#define DECK_H
#define DECK_NUMBER 30
#include "card.h"

typedef struct
{
	int top;
	card_t card[DECK_NUMBER];
}deck_t;



void init_deck(deck_t *);
void push(deck_t *, card_t);
void print_deck(deck_t *);
card_t pop(deck_t *);
#endif

