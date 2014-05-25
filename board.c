#include "board.h"
//#include "main.c"



int can_play_card(board_t board,player_t player, card_t card,int num_lane)
{
 if (!player.mana>=card.mana && !board.card[num_lane].name=="") return 0; //proverka za dostatuchna mana i proverska za svobodno mqsto
 else return 1;
}
void play_card(board_t *board,player_t *player,card_t card,int num_lane)
{
    board->card[num_lane]=card;
    player->mana-=card.mana;
}
void print_board(board_t *board,player_t first_player,player_t second_player)
{

    printf("PLAYER:%s(%d)  MANA:%d  TURN:%d\n",first_player.name,first_player.lifePoints,first_player.mana,first_player.turn);

    printf("______________________________________________________________________\n");
    printf("|   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |\n",
           first_player.hand[0].attackPower,first_player.hand[0].defencePower,first_player.hand[0].mana,
           first_player.hand[1].attackPower,first_player.hand[1].defencePower,first_player.hand[1].mana,
           first_player.hand[2].attackPower,first_player.hand[2].defencePower,first_player.hand[2].mana,
           first_player.hand[3].attackPower,first_player.hand[3].defencePower,first_player.hand[3].mana,
           first_player.hand[4].attackPower,first_player.hand[4].defencePower,first_player.hand[4].mana);

    printf("#######################################################################\n");
    printf("#   %d|%d   #   %d|%d   #   %d|%d   #   %d|%d   #   %d|%d   #\n",
           first_player.hand[0].attackPower,first_player.hand[0].defencePower,
           first_player.hand[1].attackPower,first_player.hand[1].defencePower,
           first_player.hand[2].attackPower,first_player.hand[2].defencePower,
           first_player.hand[3].attackPower,first_player.hand[3].defencePower,
           first_player.hand[4].attackPower,first_player.hand[4].defencePower);

    printf("#   %d|%d   #   %d|%d   #   %d|%d   #   %d|%d   #   %d|%d   #\n",
           second_player.hand[0].attackPower,second_player.hand[0].defencePower,
           second_player.hand[1].attackPower,second_player.hand[1].defencePower,
           second_player.hand[2].attackPower,second_player.hand[2].defencePower,
           second_player.hand[3].attackPower,second_player.hand[3].defencePower,
           second_player.hand[4].attackPower,second_player.hand[4].defencePower);
    printf("#######################################################################\n");
    printf("|   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |   %d|%d(%d)   |\n",
           second_player.hand[0].attackPower,second_player.hand[0].defencePower,second_player.hand[0].mana,
           second_player.hand[1].attackPower,second_player.hand[1].defencePower,second_player.hand[1].mana,
           second_player.hand[2].attackPower,second_player.hand[2].defencePower,second_player.hand[2].mana,
           second_player.hand[3].attackPower,second_player.hand[3].defencePower,second_player.hand[3].mana,
           second_player.hand[4].attackPower,second_player.hand[4].defencePower,second_player.hand[4].mana);
    printf("______________________________________________________________________\n");
    printf("PLAYER:%s(%d)  MANA:%d  TURN:%d",second_player.name,second_player.mana,second_player.turn);

}

