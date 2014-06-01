#ifndef SORT_H
#define SORT_H
#include "deck.h"

int pre_random(player_t *);
void random_sort(player_t *);
void sort_by_attackPower(player_t *);
void sort_by_defencePower(player_t *);
void sort_by_mana(player_t *);
#endif
