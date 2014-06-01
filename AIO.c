#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "board.h"
#include "card.h"
#include "player.h"


#include <time.h>

void load_deck(deck_t *deck)
{

 FILE *fp;
 fp = fopen("cards.csv","r+");
 if(!fp)
 {
  printf("Error - can not read file");
  return;
 }
    int i;
    init_deck(deck);
    for(i=0; i<DECK_NUMBER; i++)
    {
        card_t card;
        fscanf(fp,"%d,%d,%d",&card.attackPower,&card.defencePower,&card.mana);
        //printf("%d,%d,%d\n",card.attackPower,card.defencePower,card.mana);
        push(deck, card);
    }
  fclose(fp);
}

void generate_deck()
{

    FILE *fp;
 fp = fopen("cards.csv","w+");
 if(!fp)
 {
  printf("Error - can not open file");
  return;
 }
    int i;
  srand(time(NULL));
 for(i=0; i<30; i++)
 {
 int attack_power = rand()%10;
 int defence_power = rand()%(10-attack_power);
 int mana = rand()%5 - attack_power*defence_power/5;
 if(mana<0) mana=-mana;

 fprintf(fp,"%d,%d,%d\n",attack_power+1,defence_power+1,mana+1);
 }

 fclose(fp);
}
