#include "card.h"
#include "player.h"
#include "board.h"
#include "deck.h"
#include "AIO.h"
#include "sort.h"
#include <stdio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int get_option(int possible_options)
{
	printf(ANSI_COLOR_BLUE "\n==================\n");
	printf("| (1)Play card   |\n");
	printf("| (2)Attack      |\n");
	printf("| (3)Sort deck   |\n");
	printf("| (4)End turn    |\n");
	printf("| (5)Exit game   |\n");
	printf("==================\n"ANSI_COLOR_RESET);
	printf("Possible actions: %d\n",possible_options);
	int option;
	do
	{
	printf("Option: ");
	scanf("%d", &option);
	if(option<1||option>5) printf(ANSI_COLOR_RED  "Error! Wrong option!\n" ANSI_COLOR_RESET );
	}while(option<1 || option>5);
	return option;
}

int play_card_option(board_t *board, player_t *player, int player_num)
{
		int num_lane;
		int card_to_play;
		
		
		do
		{
		printf("Card you want to play: ");
		scanf("%d", &card_to_play);
		card_to_play--;
		if(card_to_play<0 || player->hand.top<card_to_play) printf(ANSI_COLOR_RED "Error! Card does not exist!\n" ANSI_COLOR_RESET);
		}while(card_to_play<0 || player->hand.top<card_to_play);
		
		int board_index=0;
		if(player_num==2) board_index=5;
		
		do
		{
		printf("Position you want to put: ");
		scanf("%d", &num_lane);
		num_lane--;
		if(num_lane<0 || board->card[num_lane+board_index].attackPower!=0 || (player_num==1&&num_lane>5) || 
				(player_num==2&&num_lane+6<6)) printf(ANSI_COLOR_RED "Error! Position not available!\n" ANSI_COLOR_RESET);
				
		}while(num_lane<0 || board->card[num_lane+board_index].attackPower!=0 || (player_num==1&&num_lane>5) || 
				(player_num==2&&num_lane+6<6));
	
		card_t card = player->hand.card[card_to_play];
		
		if(player_num==2) board_index=5;
		else board_index=0;
		
		if(player->mana>=card.mana){
			play_card(board, player, card, num_lane+board_index);
			return 0;
		}else
		{
			printf(ANSI_COLOR_RED "Error! Could not play card!\n" ANSI_COLOR_RESET);
		}
		
		return 1;
}

void attack_option(board_t *board, int player_num, player_t *player_attacker, player_t *player_defender)
{
	int attack_card, defence_card, board_index;
	if(player_num==1) {board_index=0;}
	else board_index=5;

	do
	{
		printf("Your attacking card: ");
		scanf("%d",&attack_card);
		attack_card--;
		if(attack_card<0 || attack_card>5 || board->card[attack_card+board_index].attackPower==0) 
						printf(ANSI_COLOR_RED "Error! Could not pick card!\n" ANSI_COLOR_RESET);
	}while(attack_card<0 || attack_card>5 || board->card[attack_card+board_index].attackPower==0);
	
	if(player_num==1) {board_index=5;}
	else board_index=0;
	int attack_player_possible = 1;
	do
	{
		printf("[0] - attack player\n");
		printf("[1..5] - attack card\n");
		printf("Attacked card: ");
		scanf("%d",&defence_card);
		defence_card--;
		if(defence_card==-1) //ATTACK DIRECTLY
		{
			int i,m;
			if(player_num==1) {board_index=5;m=0;}
			else {board_index=0; m=5;}
			
			
			for(i=board_index; i<10-m; i++)
			{
				if(board->card[i].attackPower!=0) {attack_player_possible=0; break;}
			}
			
			if(attack_player_possible)
			{	
				if(player_num==1) {board_index=0;}
				else {board_index=5;}
				//change_lifePoints(player, -board->card[attack_card+player_num].attackPower);
				player_defender->lifePoints-=board->card[attack_card+board_index].attackPower;
			}else
			{
				printf(ANSI_COLOR_RED "Error! You could not attack directly!\n" ANSI_COLOR_RESET);
			}
			return;
		}; 
		if(defence_card<0 || defence_card>5 || board->card[defence_card+board_index].attackPower==0)
					printf(ANSI_COLOR_RED "Error! Could choose card to attack!\n" ANSI_COLOR_RESET);
	}while(defence_card<0 || defence_card>5 || board->card[defence_card+board_index].attackPower==0);
	
	int result;
	if(player_num==1) result = perform_attack(&board->card[attack_card],&board->card[defence_card+5]);
	else result = perform_attack(&board->card[attack_card+5],&board->card[defence_card]);
	
	if(player_num==1) {board_index=0;}
	else board_index=5;
	
	switch(result)
	{
		case 0: {board->card[attack_card+board_index].attackPower=0;board->card[attack_card+board_index]
											.defencePower=0;board->card[attack_card+board_index].mana=0;
				if(player_num==1) {board_index=5;}
				else board_index=0;
				board->card[defence_card+board_index].attackPower=0;board->card[defence_card+board_index]
									.defencePower=0;board->card[defence_card+board_index].mana=0; break;}
		case 1: {if(player_num==1) {board_index=5;} 
				else board_index=0; 
				board->card[defence_card+board_index].attackPower=0; board->card[defence_card+board_index]
				.defencePower=0; 
				board->card[defence_card+board_index].mana=0; 
					break;
				}
		case 2: {if(player_num==1) {board_index=0;} 
				else board_index=5;
				board->card[attack_card+board_index].attackPower=0; 
				board->card[attack_card+board_index].defencePower=0; 
				board->card[attack_card+board_index].mana=0; 
				break;
			}
	}
	
}

int get_sort_option()
{
	int option;
	printf(ANSI_COLOR_BLUE "\n=================================\n");
	printf("| SORTING BY:                   |\n");
	printf("| (1)Most attack power - %d mana|\n",10);
	printf("| (2)Most defence power - %d mana|\n", 5);
	printf("| (3)Less mana required - %d mana|\n", 2);
	printf("| (4)Randomly - %d mana          |\n", 1);
	printf("=================================\n"ANSI_COLOR_RESET);
	printf("Sort: ");
	scanf("%d", &option);
	return option;
}

void exit_program(int i)
{
	
	if(i==1) printf("Player one wins! CONGRATULATIONS!\n");
	if(i==2) printf("Player two wins! CONGRATULATIONS!\n");
	
	printf(ANSI_COLOR_CYAN "THANK YOU FOR PLAYING THE GAME OF CARDS!\nBy:Ivo Valchev, Borislav Rusinov and Dimitar Matev"ANSI_COLOR_RESET);
	exit(0);
} 

int main()
{
    board_t board;
    init_board(&board);
    player_t first;
    player_t second;
    first.mana=10;
    first.lifePoints=30;
    first.turn=0;
    second.mana=10;
    second.lifePoints=30;
    second.turn=0;
    
    printf("First player name: ");
    scanf("%s", first.name);
    
    printf("Second player name: ");
    scanf("%s", second.name);

    init_deck(&first.hand);
    init_deck(&second.hand);
    
	load_deck(&first.deck);
	generate_deck();
	load_deck(&second.deck);
	int i;
	for(i=0; i<4; i++)
	{
			push(&first.hand, first.deck.card[i]);
			push(&second.hand, second.deck.card[i]);
		
	}
	int turns = 0;
	int possible_options;
	while(1){
	if(turns%2==0)
	{
	//FIRST PLAYER TURN	
		if(first.lifePoints<=0) exit_program(2);
		if(second.lifePoints<=0) exit_program(1);
		if(first.hand.top<5) push(&first.hand, pop(&first.deck));
		turn_begin(&first);
		printf(ANSI_COLOR_YELLOW "%s's turn\n" ANSI_COLOR_RESET, first.name );
		possible_options=3;
		while(possible_options){
		print_board(board, first, second);
		int option = get_option(possible_options);
		switch(option)
		{
			case 1: if(!play_card_option(&board, &first,1))  {possible_options--;} break;
			case 2: attack_option(&board,1, &first, &second); possible_options--; break;
			case 3: switch(get_sort_option())
					{
						case 1: {sort_by_attackPower(&first); break;}
						case 2: {print_deck(first.deck); sort_by_defencePower(&first); break;}
						case 3: {sort_by_mana(&first); break;}
						case 4: {random_sort(&first); break;}
					} break;
			case 4: possible_options=0; break;
			case 5: exit_program(0); break;
		}
		}
		turns++;
		
	}else
	{
	//SECOND PLAYER TURN
		if(second.lifePoints<=0) exit_program(1);
		if(first.lifePoints<=0) exit_program(2);
		if(second.hand.top<5) push(&second.hand, pop(&second.deck));
		turn_begin(&second);
		printf(ANSI_COLOR_YELLOW "%s's turn\n" ANSI_COLOR_RESET, second.name);
		possible_options=3;
		while(possible_options){
		print_board(board, first, second);
		int option = get_option(possible_options);
		switch(option)
		{
			case 1: if(!play_card_option(&board, &second,2))  {possible_options--;} break;
			case 2: attack_option(&board,1, &second, &first); possible_options--; break;
			case 3: switch(get_sort_option())
					{
						case 1: {sort_by_attackPower(&second); break;}
						case 2: {print_deck(second.deck); sort_by_defencePower(&second); break;}
						case 3: {sort_by_mana(&second); break;}
						case 4: {random_sort(&second); break;}
					} break;
			case 4: possible_options=0; break;
			case 5: exit_program(0); break;
		}
		}
		turns++;
	}
	}
	return 0;
}
