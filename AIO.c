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
 fp = fopen("cards.csv","r");
 if(!fp)
 {
  printf("Error - can not read file");
  return;
 }
    int i;
    init_deck(deck);
    for(i=0; i<30; i++)
    {
  card_t card;
        fscanf(fp,"%s,%d,%d,%d\n",card.name,&card.attackPower,&card.defencePower,&card.mana);
        printf("%s,%d,%d,%d\n",card.name,card.attackPower,card.defencePower,card.mana);
        push(deck, card);
    }
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
    char names[][30]={"Leprikona","Eldd","Enr","Issn","Dragon","Voldemort","Dumbledore","Karry","Garmione","Ort","Rom","Bat Jiorji","Dinko","Baba Gusi","Ptice4ovkata",
    "Dim4o","Big Mamma","Dushterichkata","Froggy","Shvarci","Piggy","Mumii Susuhrenov","Golqmata skumriq","Cvuk","Apostolova","Tan4etoo","MATEV","Bobi","Kra4un","Veselka"};
  srand(time(NULL));
 for(i=0; i<30; i++)
 {
 int attack_power = rand()%10;
 int defence_power = rand()%(10-attack_power);
 int mana = rand()%5 - attack_power*defence_power/5;
 if(mana<0) mana=-mana;

 fprintf(fp,"%s,%d,%d,%d\n", names[i] ,attack_power+1,defence_power+1,mana+1);
 }

 fclose(fp);
}






