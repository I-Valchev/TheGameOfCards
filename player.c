#include<stdio.h>
#include "player.h"
#include "card.h"
#include "deck.h"

void change_lifePoints(player_t *player,int value){

    player->lifePoints+=value;

}
void turn_begin(player_t *player){
    player->hand.card[player->hand.top]=pop(&player->deck);
    player->deck.top--;
    player->turn++;
    player->mana++;
}
/*int play_card_from_hand(player_t *player,int i,int l){
    player->hand[i]=player->lane[l]; //witch card on witch lane we are putting
    player->mana-=player->hand[i].mana;
    //player->hand[*i]=; // The struct is NULLed
}*/
