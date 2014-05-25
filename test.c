#include <stdio.h>
#include <stdlib.h>

#include <time.h>

/*void load_deck(deck_t *deck)
{
 FILE *fp;
 fp = fopen("cards.csv","r");
 if(!fp)
 {
  printf("Error - can not read file");
  return;
 }
}*/

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

    FILE *fname;
 fname = fopen("names.csv","r");
 char *names[30];
 for(i=0; i<30; i++)
    {
        names[i] = fscanf(fname,"%s");
    }
}
