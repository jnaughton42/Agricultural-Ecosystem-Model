#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include "Header.h"

using namespace std;

void Coyote::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop += pop[0];
	return;
}

void Coyote::age(int month) {
	if (repMonth != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0); 
	return;
}

void Coyote::starvation(int deficit) {
	int death = ceil((double)deficit / (double)energyConsump);
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

void Coyote::consume(Fox& fox, Deer& deer, Bird& bird, Squirrel& squirrel, Insect& insect, Bat& bat, Rabbit& rabbit) {
	vector<int> preyPops;
	vector<double> curDiet;
	int energyTot = 0, energyTemp;
	double sum = 0;
	for (int i = 0; i < prey.size(); i++) {
		switch (prey[i]) {
		case 1:
			energyTemp = (ceil(fox.totPop * fox.evadRate) * fox.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 2:
			energyTemp = (ceil(deer.totPop * deer.evadRate) * deer.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 3:
			energyTemp = (ceil(bird.totPop * bird.evadRate) * bird.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 4:
			energyTemp = (ceil(squirrel.totPop * squirrel.evadRate) * squirrel.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 5:
			energyTemp = (ceil(insect.totPop * insect.evadRate) * insect.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 6:
			energyTemp = (ceil(bat.totPop * bat.evadRate) * bat.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 7:
			energyTemp = (ceil(rabbit.totPop * rabbit.evadRate) * rabbit.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		default:
			cout << "Error: bad Coyote prey vector" << endl;
			exit(EXIT_FAILURE);
		}
	}
	if (energyTot == 0) { starvation(totPop * energyConsump); return; }
	for (int i = 0; i < diet.size(); i++) {
		curDiet.push_back(((double)preyPops[i] / (double)energyTot) * diet[i]);
		sum += curDiet[i];
	}
	for (int i = 0; i < diet.size(); i++) {
		curDiet[i] = curDiet[i] / sum;
	}
	int starve = fox.devour(curDiet[0] * energyConsump * totPop);
	starve += deer.devour(curDiet[1] * energyConsump * totPop);
	starve += bird.devour(curDiet[2] * energyConsump * totPop);
	starve += squirrel.devour(curDiet[3] * energyConsump * totPop);
	starve += rabbit.devour(curDiet[4] * energyConsump * totPop);
	starvation(starve);
	return;
}

void Fox::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop += pop[0];
	return;
}

void Fox::age(int month) {
	if (repMonth != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0);
	return;
}

void Fox::starvation(int deficit) {
	int death = ceil((double)deficit / (double)energyConsump);
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

void Deer::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop += pop[0];
	return;
}

void Deer::age(int month) {
	if (repMonth != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0);
	return;
}

void Deer::death(int death) {
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = ((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death;
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

void Bird::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop += pop[0];
	return;
}

void Bird::age(int month) {
	if (repMonth != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0);
	return;
}

void Bird::starvation(int deficit) {
	int death = ceil((double)deficit / (double)energyConsump);
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

void Squirrel::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop += pop[0];
	return;
}

void Squirrel::age(int month) {
	if (repMonth + 1 != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0);
	return;
}

void Squirrel::starvation(int deficit) {
	int death = ceil((double)deficit / (double)energyConsump);
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

void Insect::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop -= pop[1];
	pop[1] = 0;
	totPop += pop[0];
	return;
}

void Insect::age(int month) {
	if (repMonth - 1 != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0);
	return;
}

void Insect::death(int death) {
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = ((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death;
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

void Bat::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop += pop[0];
	return;
}

void Bat::age(int month) {
	if (repMonth != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0);
	return;
}

void Bat::starvation(int deficit) {
	int death = ceil((double)deficit / (double)energyConsump);
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

void Rabbit::birth(int month) {
	if (repMonth != month) return;
	int tot = 0;
	int curr;
	for (int i = repAge; i < pop.size(); i++) {
		tot += pop[i];
	}
	pop[0] = (child * (tot / 2));
	totPop += pop[0];
	return;
}

void Rabbit::age(int month) {
	if (repMonth != month) return;
	totPop -= pop.back();
	pop.pop_back();
	pop.push_front(0);
	return;
}

void Rabbit::death(int death) {
	int deathCount = 0, i = 1;
	int subtract;
	while (deathCount < death) {
		subtract = (((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
		if (subtract > pop[pop.size() - i]) {
			subtract = pop[pop.size() - i];
		}
		deathCount += subtract;
		if (deathCount > death) {
			subtract -= deathCount - death;
		}
		pop[pop.size() - i] -= subtract;
		i++;
	}
	totPop -= death;
	return;
}

int Fox::devour(int totEnCons) {
	if (totPop * evadRate * energy >= totEnCons) {
		int death = round((double)totEnCons / (double)energy);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return 0;
	}
	else {
		int death = round((double)totPop * (double)evadRate);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return (totEnCons - (death * energy));
	}
}

int Deer::devour(int totEnCons) {
	if (totPop * evadRate * energy >= totEnCons) {
		int death = round((double)totEnCons / (double)energy);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return 0;
	}
	else {
		int death = round((double)totPop * (double)evadRate);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return (totEnCons - (death * energy));
	}
}

int Bird::devour(int totEnCons) {
	if (totPop * evadRate * energy >= totEnCons) {
		int death = round((double)totEnCons / (double)energy);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return 0;
	}
	else {
		int death = round((double)totPop * (double)evadRate);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return (totEnCons - (death * energy));
	}
}

int Squirrel::devour(int totEnCons) {
	if (totPop * evadRate * energy >= totEnCons) {
		int death = round((double)totEnCons / (double)energy);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return 0;
	}
	else {
		int death = round((double)totPop * (double)evadRate);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return (totEnCons - (death * energy));
	}
}

int Insect::devour(int totEnCons) {
	if (totPop * evadRate * energy >= totEnCons) {
		int death = round((double)totEnCons / (double)energy);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return 0;
	}
	else {
		int death = round((double)totPop * (double)evadRate);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return (totEnCons - (death * energy));
	}
}

int Rabbit::devour(int totEnCons) {
	if (totPop * evadRate * energy >= totEnCons) {
		int death = round((double)totEnCons / (double)energy);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return 0;
	}
	else {
		int death = round((double)totPop * (double)evadRate);
		int deathCount = 0, i = 1;
		int subtract;
		while (deathCount < death) {
			subtract = ceil(((double)pop[pop.size() - i] / (double)totPop) * 1.1 * death);
			if (subtract > pop[pop.size() - i]) {
				subtract = pop[pop.size() - i];
			}
			deathCount += subtract;
			if (deathCount > death) {
				subtract -= deathCount - death;
			}
			pop[pop.size() - i] -= subtract;
			i++;
		}
		totPop -= death;
		return (totEnCons - (death * energy));
	}
}

void Fox::consume(Fox& fox, Deer& deer, Bird& bird, Squirrel& squirrel, Insect& insect, Bat& bat, Rabbit& rabbit) {
	vector<int> preyPops;
	vector<double> curDiet;
	int energyTot = 0, energyTemp;
	double sum = 0;
	for (int i = 0; i < prey.size(); i++) {
		switch (prey[i]) {
		case 1:
			energyTemp = (ceil(fox.totPop * fox.evadRate) * fox.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 2:
			energyTemp = (ceil(deer.totPop * deer.evadRate) * deer.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 3:
			energyTemp = (ceil(bird.totPop * bird.evadRate) * bird.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 4:
			energyTemp = (ceil(squirrel.totPop * squirrel.evadRate) * squirrel.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 5:
			energyTemp = (ceil(insect.totPop * insect.evadRate) * insect.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 6:
			energyTemp = (ceil(bat.totPop * bat.evadRate) * bat.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 7:
			energyTemp = (ceil(rabbit.totPop * rabbit.evadRate) * rabbit.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		default:
			cout << "Error: bad Fox prey vector" << endl;
			exit(EXIT_FAILURE);
		}
	}
	if (energyTot == 0) { starvation(totPop * energyConsump); return; }
	for (int i = 0; i < diet.size(); i++) {
		curDiet.push_back(((double)preyPops[i] / (double)energyTot) * diet[i]);
		sum += curDiet[i];
	}
	for (int i = 0; i < diet.size(); i++) {
		curDiet[i] = curDiet[i] / sum;
	}
	int starve = bird.devour(curDiet[0] * energyConsump * totPop);
	starve += squirrel.devour(curDiet[1] * energyConsump * totPop);
	starve += rabbit.devour(curDiet[2] * energyConsump * totPop);
	starvation(starve);
	return;
}

void Bird::consume(Fox& fox, Deer& deer, Bird& bird, Squirrel& squirrel, Insect& insect, Bat& bat, Rabbit& rabbit) {
	vector<int> preyPops;
	vector<double> curDiet;
	int energyTot = 0, energyTemp;
	double sum = 0;
	for (int i = 0; i < prey.size(); i++) {
		switch (prey[i]) {
		case 1:
			energyTemp = (ceil(fox.totPop * fox.evadRate) * fox.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 2:
			energyTemp = (ceil(deer.totPop * deer.evadRate) * deer.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 3:
			energyTemp = (ceil(bird.totPop * bird.evadRate) * bird.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 4:
			energyTemp = (ceil(squirrel.totPop * squirrel.evadRate) * squirrel.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 5:
			energyTemp = (ceil(insect.totPop * insect.evadRate) * insect.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 6:
			energyTemp = (ceil(bat.totPop * bat.evadRate) * bat.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 7:
			energyTemp = (ceil(rabbit.totPop * rabbit.evadRate) * rabbit.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		default:
			cout << "Error: bad Coyote prey vector" << endl;
			exit(EXIT_FAILURE);
		}
	}
	if (energyTot == 0) { starvation(totPop * energyConsump); return; }
	for (int i = 0; i < diet.size(); i++) {
		curDiet.push_back(((double)preyPops[i] / (double)energyTot) * diet[i]);
		sum += curDiet[i];
	}
	for (int i = 0; i < diet.size(); i++) {
		curDiet[i] = curDiet[i] / sum;
	}
	int starve = insect.devour(curDiet[0] * energyConsump * totPop);
	starvation(starve);
	return;
}

void Squirrel::consume(Fox& fox, Deer& deer, Bird& bird, Squirrel& squirrel, Insect& insect, Bat& bat, Rabbit& rabbit) {
	vector<int> preyPops;
	vector<double> curDiet;
	int energyTot = 0, energyTemp;
	double sum = 0;
	for (int i = 0; i < prey.size(); i++) {
		switch (prey[i]) {
		case 1:
			energyTemp = (ceil(fox.totPop * fox.evadRate) * fox.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 2:
			energyTemp = (ceil(deer.totPop * deer.evadRate) * deer.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 3:
			energyTemp = (ceil(bird.totPop * bird.evadRate) * bird.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 4:
			energyTemp = (ceil(squirrel.totPop * squirrel.evadRate) * squirrel.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 5:
			energyTemp = (ceil(insect.totPop * insect.evadRate) * insect.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 6:
			energyTemp = (ceil(bat.totPop * bat.evadRate) * bat.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 7:
			energyTemp = (ceil(rabbit.totPop * rabbit.evadRate) * rabbit.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		default:
			cout << "Error: bad Coyote prey vector" << endl;
			exit(EXIT_FAILURE);
		}
	}
	if (energyTot == 0) { starvation(totPop * energyConsump); return; }
	for (int i = 0; i < diet.size(); i++) {
		curDiet.push_back(((double)preyPops[i] / (double)energyTot) * diet[i]);
		sum += curDiet[i];
	}
	for (int i = 0; i < diet.size(); i++) {
		curDiet[i] = curDiet[i] / sum;
	}
	int starve = insect.devour(curDiet[0] * energyConsump * totPop);
	starvation(starve);
	return;
}

void Bat::consume(Fox& fox, Deer& deer, Bird& bird, Squirrel& squirrel, Insect& insect, Bat& bat, Rabbit& rabbit) {
	vector<int> preyPops;
	vector<double> curDiet;
	int energyTot = 0, energyTemp;
	double sum = 0;
	for (int i = 0; i < prey.size(); i++) {
		switch (prey[i]) {
		case 1:
			energyTemp = (ceil(fox.totPop * fox.evadRate) * fox.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 2:
			energyTemp = (ceil(deer.totPop * deer.evadRate) * deer.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 3:
			energyTemp = (ceil(bird.totPop * bird.evadRate) * bird.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 4:
			energyTemp = (ceil(squirrel.totPop * squirrel.evadRate) * squirrel.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 5:
			energyTemp = (ceil(insect.totPop * insect.evadRate) * insect.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 6:
			energyTemp = (ceil(bat.totPop * bat.evadRate) * bat.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		case 7:
			energyTemp = (ceil(rabbit.totPop * rabbit.evadRate) * rabbit.energy);
			energyTot += energyTemp;
			preyPops.push_back(energyTemp);
			break;
		default:
			cout << "Error: bad Coyote prey vector" << endl;
			exit(EXIT_FAILURE);
		}
	}
	if (energyTot == 0) { starvation(totPop * energyConsump); return; }
	for (int i = 0; i < diet.size(); i++) {
		curDiet.push_back(((double)preyPops[i] / (double)energyTot) * diet[i]);
		sum += curDiet[i];
	}
	for (int i = 0; i < diet.size(); i++) {
		curDiet[i] = curDiet[i] / sum;
	}
	int starve = insect.devour(curDiet[0] * energyConsump * totPop);
	starvation(starve);
	return;
}