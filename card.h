#ifndef CARD_H
#define CARD_H
//#include "card.c"
typedef struct{
	char *name;
	int attackPower;
	int defencePower;
	int mana;
}card_t;
#endif

int perform_attack(card_t *, card_t *);
