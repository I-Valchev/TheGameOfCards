#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include "player.h"
#include "card.h"
#define BOARD_MAX_SIZE 10


typedef struct
{
 card_t card[BOARD_MAX_SIZE];
 int top;
}board_t;

int can_play_card(player_t player, card_t card);
void play_card(board_t *board,player_t *player,card_t card,int num_lane);
void print_board(board_t board,player_t first_player,player_t second_player);
void init_board(board_t *board);
#endif

