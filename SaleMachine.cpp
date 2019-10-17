#include "SaleMachine.h"

SaleMachine::SaleMachine() :orangeNum(5), beerNum(5), fiveNum(5) {
}

string SaleMachine::sale(string drink, int money) {
	string result = "";
	if ((beerNum < 1 && drink == type[0]) || (orangeNum < 1 && drink == type[1])) {
		result = answer[0] + drink;
	}
	else if (money == 5) {
		fiveNum++;
		result = answer[1] + drink;
		if (drink == type[0]) {
			beerNum--;
		}
		else if (drink == type[1]) {
			orangeNum--;
		}
		else {
			result = answer[4];
		}
	}
	else if (money == 10) {
		if (fiveNum < 1) {
			result = answer[3];
		}
		else {
			fiveNum--;
			result = answer[2] + drink;
			if (drink == type[0]) {
				beerNum--;
			}
			else if (drink == type[1]) {
				orangeNum--;
			}
			else {
				result = answer[4];
			}
		}
	}else{
		result = answer[4];
	}
	return result;
}