#include <stdio.h>
#include "deck.h"
#define DECK_NUMBER 30
void init(deck_t *y) 
{ 
//	int i;
//	for (i=0;i<30;i++)
//	y->card[i]=1;
	y->top=0;	
}

void push(deck_t *myDeck, card_t card)
{
	if(myDeck->top==30)
	{
		printf("Error! Deck is full!");
	} else 
		{
		myDeck->card[myDeck->top]=card;
		myDeck->top++;
		}
}

void print_deck(deck_t *myDeck)
{
	int i;
	printf("%d",myDeck->top);
	for (i=0;i<myDeck->top;i++)
	{
		printf("card number: %d, card name: %s, card attack: %d, card defence: %d, card mana: %d\n",i,myDeck->card[i].name, 
																									myDeck->card[i].attackPower, 
																									myDeck->card[i].defencePower,
																									myDeck->card[i].mana );
	}
}
