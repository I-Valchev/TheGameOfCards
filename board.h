#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include "player.h"
#include "card.h"



typedef struct
{
 card_t card[10];


}board_t;
int can_play_card(board_t board,player_t player, card_t card,int num_lane);
void play_card(board_t *board,player_t *player,card_t card,int num_lane);
void print_board(board_t *board,player_t first_player,player_t second_player);
#endif

