#include "board.h"
//#include "main.c"



int can_play_card(player_t player, card_t card)
{
	if(!player.mana>=card.mana) {printf("Not enough mana!\n"); return 0;}
	return 1;
}

void play_card(board_t *board,player_t *player,card_t card,int num_lane)
{
    board->card[num_lane]=card;
    player->mana-=card.mana;
    
    deck_t temp_deck = player->hand;
    
    init_deck(&player->hand);
	//
    int i;
	for(i=0;i<temp_deck.top;i++)
	{
		if(!(temp_deck.card[i].attackPower==card.attackPower && temp_deck.card[i].defencePower==card.defencePower
		&& temp_deck.card[i].mana==card.mana))
		{
			push(&(player->hand), temp_deck.card[i]);
		}
	}
}
void print_board(board_t board,player_t first_player,player_t second_player)
{

   printf("PLAYER:%s(%d)  MANA:%d  TURN:%d\n",first_player.name,first_player.lifePoints,first_player.mana,first_player.turn);

   printf("_______________________________________________________\n");
   int i;
   for(i=0; i<first_player.hand.top; i++)
   {
	   printf("| %d|%d (%d) |", first_player.hand.card[i].attackPower,first_player.hand.card[i].defencePower,
				first_player.hand.card[i].mana);
   }
   
   printf("\n-------------------------------------------------------\n");

   for(i=0; i<BOARD_MAX_SIZE; i++)
   {
	   if(i==BOARD_MAX_SIZE/2) printf("\n#######################################################\n");
		printf("|   %d|%d   |",board.card[i].attackPower, board.card[i].defencePower);
   }
   
   printf("\n-------------------------------------------------------\n");
   
   for(i=0; i<second_player.hand.top; i++)
   {
	   printf("| %d|%d (%d) |",second_player.hand.card[i].attackPower,second_player.hand.card[i].defencePower,
				second_player.hand.card[i].mana);
   }
   
   printf("\n_______________________________________________________\n");
   printf("PLAYER:%s(%d)  MANA:%d  TURN:%d\n",second_player.name,second_player.lifePoints,second_player.mana,second_player.turn);
   
   /*printf("|   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |\n",
           first_player.hand.card[0].attackPower,first_player.hand.card[0].defencePower,first_player.hand.card[0].mana,
           first_player.hand.card[1].attackPower,first_player.hand.card[1].defencePower,first_player.hand.card[1].mana,
           first_player.hand.card[2].attackPower,first_player.hand.card[2].defencePower,first_player.hand.card[2].mana,
           first_player.hand.card[3].attackPower,first_player.hand.card[3].defencePower,first_player.hand.card[3].mana,
           first_player.hand.card[4].attackPower,first_player.hand.card[4].defencePower,first_player.hand.card[4].mana);

    printf("#######################################################################\n");
    printf("______________________________________________________________________\n"); */
    //printf("PLAYER:%s(%d)  MANA:%d  TURN:%d",second_player.name,second_player.mana,second_player.turn);

}

void init_board(board_t *board)
{
	int i;
	for(i=0; i<BOARD_MAX_SIZE; i++)
	{
		board->card[i].attackPower=0;
		board->card[i].defencePower=0;
	}
}

