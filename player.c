#include <stdio.h>
#include <stdlib.h>
#include "player.h"


void turn_begin(struct player *p){
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i){
		if(p->hand[i].name == NULL || p->hand[i].name == ""){
			if(p->deck.top <= 0){
				printf("No cards.\n");
			}
			else{
				p->hand[i] = draw_card(&p->deck);
			}
			break;
		}
	}
}

void print_health(struct player p){
	printf("%d\n", p.health);
}

void print_hand(struct player p){
	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i){
		if(p.hand[i].name != NULL && p.hand[i].name != ""){
			print_card(p.hand[i]);
		}
	}
}


void play_card_from_hand(struct player *p, char *card_name){

	int i;
	for(i = 0; i < NUM_OF_CARDS_IN_HAND; ++i){
		if(p->hand[i].name == card_name){
			p->hand[i].name = "";
			p->hand[i].life = 0;
			p->hand[i].force = 0;
			p->hand[i].cost = 0;
			break;
		}
	}
}
void init_player(struct player *p){
	p->health = 100;
	mana_init(&p->manapool);

	p->hand = (card_t*)malloc(NUM_OF_CARDS_IN_HAND * sizeof(card_t));

	int i;
	for(i = 0; i < 5; ++i){
		p->hand[i] = draw_card(&p->deck);
	}
}


void change_health(struct player *p, int hp, int modifier){
	if(modifier == INCREASE){
		p->health += hp;
	}
	else if(modifier == DECREASE){
		p->health -= hp;
	}
}
