#include "card.h"
#include "deck.h"
#include <stdio.h>
int main()
{

/*	card_t c1;
	c1.name = "Hello";
	c1.attackPower = 2;
	c1.defencePower = 1;
	c1.mana = 0;
*/
	
	//printf("Card 1: %s; %d; %d; %d\n", c1.name, c1.attackPower, c1.defencePower, c1.mana);
	
	//int resultFromFight = perform_attack(&c1, &c2);

	//printf("Result: %d\n",resultFromFight);
	deck_t d;
	init(&d);
	 d.card[0].name="kuche vurhy drakon";
	d.card[0].attackPower=3;
	d.card[0].defencePower=5;
	d.card[0].mana=2;
	return 0;
}
