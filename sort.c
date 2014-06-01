#include "sort.h"
#include "player.h"
#include <time.h>
#include <stdio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int pre_random(player_t *player)
{
	int i, top;
	
	top = player->hand.top;
	for(i=0; i<player->hand.top; i++)
	{
	push(&player->deck, pop(&player->hand));
	}
	return top;
}

void random_sort(player_t *player)
{
	
	if(player->mana<1) 
	{
		printf(ANSI_COLOR_RED "Error! Not enough mana!\n" ANSI_COLOR_RESET);
		return;
	}
	player->mana-=1;
	
	int top = pre_random(player);
	srand(time(NULL));
	int i,j, randomizer;
	card_t card;
	for(i=0,j=0; i<DECK_NUMBER*3; i++,j++)
	{
		if(j==DECK_NUMBER) j=0;
		randomizer = rand()%DECK_NUMBER;
		card=player->deck.card[j];
		player->deck.card[j]=player->deck.card[randomizer];
		player->deck.card[randomizer]=card;
	}
	///
	
	for(i=0; i<top-1; i++)
	{
		push(&player->hand, pop(&player->deck));
	}
}

void sort_by_attackPower(player_t *player)
{
	
	if(player->mana<10)
	{
		printf(ANSI_COLOR_RED "Error! Not enough mana!\n" ANSI_COLOR_RESET);
		return;
	}
	
	player->mana-=10;
	
	int top = pre_random(player);
	int i,j;
	card_t card;
	
	for(i=0; i<player->deck.top; i++)
	{
		for(j=0; j<i-1; j++)
		{
			if(player->deck.card[j].attackPower<player->deck.card[j+1].attackPower)
			{
				card=player->deck.card[j+1];
				player->deck.card[j+1]=player->deck.card[j];
				player->deck.card[j]=card;
			}
		}
	}
	
	for(i=0; i<top-1; i++)
	{
		push(&player->hand, pop(&player->deck));
	}
	
}

void sort_by_defencePower(player_t *player)
{
	
	if(player->mana<5)
	{
		printf(ANSI_COLOR_RED "Error! Not enough mana!\n" ANSI_COLOR_RESET);
		return;
	}
	
	player->mana-=5;
	
	int top = pre_random(player);
	int i,j;
	card_t card;
	
	for(i=0; i<player->deck.top; i++)
	{
		for(j=0; j<i-1; j++)
		{
			if(player->deck.card[j].defencePower<player->deck.card[j+1].defencePower)
			{
				card=player->deck.card[j+1];
				player->deck.card[j+1]=player->deck.card[j];
				player->deck.card[j]=card;
			}
		}
	}
	
	for(i=0; i<top-1; i++)
	{
		push(&player->hand, pop(&player->deck));
	}
}

void sort_by_mana(player_t *player)
{
	if(player->mana<2)
	{
		printf(ANSI_COLOR_RED "Error! Not enough mana!\n" ANSI_COLOR_RESET);
		return;
	}
	
	player->mana-=2;
	
	int top = pre_random(player);
	int i,j;
	card_t card;
	
	for(i=0; i<player->deck.top; i++)
	{
		for(j=0; j<i-1; j++)
		{
			if(player->deck.card[j].mana<player->deck.card[j+1].mana)
			{
				card=player->deck.card[j+1];
				player->deck.card[j+1]=player->deck.card[j];
				player->deck.card[j]=card;
			}
		}
	}
	
	for(i=0; i<top-1; i++)
	{
		push(&player->hand, pop(&player->deck));
	}
}
