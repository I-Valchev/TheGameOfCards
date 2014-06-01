#include "deck.h"
#include <stdio.h>
#define DECK_NUMBER 30
void init_deck(deck_t *y)
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

card_t pop(deck_t *myDeck)
{
	card_t card;
	if(myDeck->top==0)
	{
		printf("Error! You can't pop cards when your deck is empty!!!");
	}	else
		{
				card=myDeck->card[myDeck->top--];
				myDeck->top--;
		}
	return card;
}

void print_deck(deck_t myDeck)
{
	int i;
	printf("%d",myDeck.top);
	for (i=0;i<myDeck.top;i++)
	{
		printf("card number: %d, card attack: %d, card defence: %d, card mana: %d\n",i, myDeck.card[i].attackPower,
																						myDeck.card[i].defencePower,
																						myDeck.card[i].mana );
	}
}

