#include "card.h"
#include "player.h"
#include "board.c"
#include "deck.c"
#include "AIO.c"
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
/*	deck_t d;
	init_deck(&d);
	d.card[0].name="drakoni";
	d.card[0].attackPower=3;
	d.card[0].defencePower=5;
	d.card[0].mana=2;
	d.card[1].name="Dinowa=drakon";
	d.card[1].attackPower=6;
	d.card[1].defencePower=1;
	d.card[1].mana=56;
	printf("%s %d %d %d\n", d.card[0].name, d.card[0].attackPower, d.card[0].defencePower, d.card[0].mana);
	printf("%s %d %d %d\n", d.card[1].name, d.card[1].attackPower, d.card[1].defencePower, d.card[1].mana);
    */
    /*char *name;
    int lifePoints;
    int mana;
    int turn;
    deck_t deck;
    card_t hand[HAND_NUMBER];*/
    board_t s;
    player_t first_player;
    player_t second_player;
    card_t test;
    test.attackPower=1;
    test.defencePower=2;
    test.mana=4;
    test.name="afd";
    deck_t d;

    first_player.lifePoints=12;
    first_player.mana=4;
    first_player.turn=0;
    first_player.deck=d;
    first_player.hand[0]=test;
    first_player.hand[1]=test;
    first_player.hand[2]=test;
    first_player.hand[3]=test;
    first_player.hand[4]=test;
    first_player.name="SPINDERMAN";

    second_player.lifePoints=15;
    second_player.mana=1;
    second_player.turn=3;
    second_player.deck=d;
    second_player.hand[0]=test;
    second_player.hand[1]=test;
    second_player.hand[2]=test;
    second_player.hand[3]=test;
    second_player.hand[4]=test;
    second_player.name="Harley";
    /*board_t d;
    player_t first;
    player_t second;
    first.mana=5;
    first.name="DRAKONA";
    first.lifePoints=8; */

    //load_deck(&first.deck);
	print_board(&d,first_player,second_player);



	return 0;

}
