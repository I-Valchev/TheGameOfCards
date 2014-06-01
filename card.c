#include "card.h"

int perform_attack(card_t *attacker, card_t *defender)
{
	defender->defencePower-=attacker->attackPower;
	attacker->defencePower-=defender->attackPower;

	if(defender->defencePower<=0 && attacker->defencePower<=0) return 0; //both destructed
	else if(defender->defencePower<=0 && attacker->defencePower>=0) return 1; //attacker won
	else if(defender->defencePower>=0 && attacker->defencePower<=0) return 2; //defender won
	else if(defender->defencePower>=0 && attacker->defencePower>=0) return 3; //both survived

	return 0;
}
