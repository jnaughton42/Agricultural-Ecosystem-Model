#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "Header.h"

using namespace std;
int month = 0;
double soilQual = 1;
int profit = 0;

bool orgComp = 0; //config values for events
bool cide = 0;
bool remCide = 0;
bool covCrop = 0;
int reinBat = -1;
int reem = -1;

Coyote coyote;
Fox fox;
Deer deer;
Bird bird;
Squirrel squirrel;
Insect insect;
Bat bat;
Rabbit rabbit;
Corn corn;

void timePass(int);
void monthUpdate();
void aging();
void consume();
void birthing();
void addOrgComp();
void planting();
void addCide();
void removeCide();
void smCornConsump();
void cornConsump();
void harvest();
void addCovCrop();
void addBat();
void reemSpec();

int main() {
	int num;
	cout << "Enter the number of months to pass: ";
	cin >> num;
	timePass(num);
	cout << "end";
}

void timePass(int num) {
	for (int i = 0; i < num; i++) {
		monthUpdate();
	}
}

void monthUpdate() {
	aging();
	switch (month) {
	case 0:
		if (covCrop) { addCovCrop(); }
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		if (orgComp) { addOrgComp(); }
		break;
	case 4:
		planting();
		if (cide) { addCide(); }
		if (insect.genMort == .8) { insect.death(.2 * insect.totPop); }
		else if (remCide) { removeCide(); }
		break;
	case 5:
		squirrel.energyConsump -= squirrel.cornConsump;
		bird.energyConsump -= bird.cornConsump;
		smCornConsump();
		if (insect.genMort == .8) { insect.death(.2 * insect.totPop); }
		break;
	case 6:
		coyote.energyConsump -= coyote.cornConsump;
		fox.energyConsump -= fox.cornConsump;
		smCornConsump();
		if (insect.genMort == .8) { insect.death(.2 * insect.totPop); }
		break;
	case 7:
		cornConsump();
		if (insect.genMort == .8) { insect.death(.2 * insect.totPop); }
		break;
	case 8:
		cornConsump();
		harvest();
		if (insect.genMort == .8) { insect.death(.2 * insect.totPop); }
		insect.genMort = 1;
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	default: 
		cout << "Error, month out of index" << endl; exit(EXIT_FAILURE);
	}
	if (reinBat == month) { addBat(); }
	if (reem == month) { reemSpec(); }
	consume();
	birthing();
	cout << coyote.totPop << " " << deer.totPop << " " << fox.totPop << " " << bird.totPop << " " << squirrel.totPop << " " << insect.totPop << " " << bat.totPop << " " << rabbit.totPop << " " << corn.totPop << endl;
	month++;
	if (month == 9) {
		cout << "";
	}
	if (month > 11) { month = 0; }
}

void planting() {
	corn.totPop = 115200;
}

void addCide() {
	insect.child *= .1;
	insect.genMort = .8;
	soilQual *= .7;
	profit -= 113920;
}

void removeCide() {
	insect.child *= 10;
	insect.genMort = 1;
	soilQual *= 1.429;
}

void addOrgComp() {
	soilQual *= 1.2;
	profit -= 64000;
}

void addBat() {
	bat.pop[1] += 100;
	bat.totPop += 100;
}

void reemSpec() {
	deer.pop[1] += 10;
	deer.totPop += 10;
	rabbit.pop[1] += 100;
	rabbit.totPop += 100;
}

void smCornConsump() {
	int squirrelConsump, rabbitConsump;
	squirrelConsump = ((squirrel.cornConsump) / 50) * squirrel.totPop;
	rabbitConsump = ((rabbit.cornConsump) / 50) * rabbit.totPop;
	if (squirrelConsump > corn.totPop * corn.evadRate) { squirrelConsump = corn.totPop * corn.evadRate; }
	if (rabbitConsump > corn.totPop * corn.evadRate) { rabbitConsump = corn.totPop * corn.evadRate; }
	corn.totPop -= ((double)(insect.cornConsump) / 50) * (double)insect.totPop;
	corn.totPop -= ((bird.cornConsump) / 50) * bird.totPop;
	corn.totPop -= squirrelConsump;
	corn.totPop -= rabbitConsump;
	if (corn.totPop < 0) { corn.totPop = 0; }
}

void cornConsump() {
	int squirrelConsump, rabbitConsump, coyoteConsump, foxConsump, deerConsump;
	squirrelConsump = ((squirrel.cornConsump) / 50) * squirrel.totPop;
	rabbitConsump = ((rabbit.cornConsump) / 50) * rabbit.totPop;
	coyoteConsump = ((coyote.cornConsump) / 50) * coyote.totPop;
	foxConsump = ((fox.cornConsump) / 50) * fox.totPop;
	deerConsump = ((deer.cornConsump) / 50) * deer.totPop;
	if (squirrelConsump > corn.totPop * corn.evadRate) { squirrelConsump = corn.totPop * corn.evadRate; }
	if (rabbitConsump > corn.totPop * corn.evadRate) { rabbitConsump = corn.totPop * corn.evadRate; }
	corn.totPop -= ((double)(insect.cornConsump) / 50) * (double)insect.totPop;
	corn.totPop -= ((bird.cornConsump) / 50) * bird.totPop;
	corn.totPop -= squirrelConsump;
	corn.totPop -= rabbitConsump;
	if (corn.totPop < 0) { corn.totPop = 0; }
}

void harvest() {
	profit += (corn.totPop * 5) * soilQual;
	cout << "harvest: " << corn.totPop << " Profit: " << profit << endl;
	corn.totPop = 0;
	coyote.energyConsump += coyote.cornConsump;
	fox.energyConsump += coyote.cornConsump;
	bird.energyConsump += coyote.cornConsump;
	squirrel .energyConsump += coyote.cornConsump;
}

void addCovCrop() {
	profit -= 2560;
	insect.child *= .5;
	soilQual *= 1.1;
}

void aging() {
	coyote.age(month);
	fox.age(month);
	deer.age(month);
	bird.age(month);
	squirrel.age(month);
	insect.age(month);
	bat.age(month);
	rabbit.age(month);
}

void birthing() {
	coyote.birth(month);
	fox.birth(month);
	deer.birth(month);
	bird.birth(month);
	squirrel.birth(month);
	insect.birth(month);
	bat.birth(month);
	rabbit.birth(month);
}

void consume() {
	vector<int> indices{0, 1, 2, 3, 4};
	int index, selec, size = indices.size();
	for (int i = 0; i < size; i++) {
		srand(time(0));
		index = (rand() % indices.size());
		selec = indices[index];
		indices.erase(indices.begin() + index);
		switch (selec) {
		case 0:
			if (coyote.totPop <= 0) { break; }
			coyote.consume(fox, deer, bird, squirrel, insect, bat, rabbit);
			break;
		case 1:
			if (fox.totPop <= 0) { break; }
			fox.consume(fox, deer, bird, squirrel, insect, bat, rabbit);
			break;
		case 2:
			if (bird.totPop <= 0) { break; }
			bird.consume(fox, deer, bird, squirrel, insect, bat, rabbit);
			break;
		case 3:
			if (squirrel.totPop <= 0) { break; }
			squirrel.consume(fox, deer, bird, squirrel, insect, bat, rabbit);
			break;
		case 4:
			if (bat.totPop <= 0) { break; }
			bat.consume(fox, deer, bird, squirrel, insect, bat, rabbit);
			bat.starvation(bat.energyConsump * bat.totPop * (1-bat.genMort));
			break;
		default:
			cout << "Error, rng issue" << endl; exit(EXIT_FAILURE);
		}
	}
}