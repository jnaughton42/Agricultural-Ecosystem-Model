#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
//0-Coyote 1-Fox 2-Deer 3-Bird 4-Squirrel 5-Insect 6-Bat 7-Rabbit

class Coyote;
class Fox;
class Deer;
class Bird;
class Squirrel;
class Insect;
class Bat;
class Rabbit;

class Coyote{
public:
	deque<int> pop = {0, 0, 0, 0, 0, 2, 0};
	int totPop = 2;
	int energyConsump = 9000;
	int cornConsump = 1500;
	int repAge = 2;
	int child = 5;
	int repMonth = 4;
	double genMort = 1;
	vector<int> prey = {1, 2, 3, 4, 7};
	vector<double> diet = {.05, .65, .1, .1, .1};
	void birth(int);
	void age(int);
	void starvation(int);
	void consume(Fox&, Deer&, Bird&, Squirrel&, Insect&, Bat&, Rabbit&);
};

class Fox{
public:
	deque<int> pop = {0, 12, 0};
	int totPop = 12;
	int energyConsump = 4500;
	int cornConsump = 1500;
	int repAge = 1;
	int child = 5;
	int repMonth = 2;
	double genMort = 1;
	double evadRate = 0.2;
	int energy = 1200;
	vector<int> prey = {3, 4, 7};
	vector<int> pred = {0};
	vector<double> diet = { .33, .33, .34 };
	int devour(int);
	void birth(int);
	void age(int);
	void starvation(int);
	void consume(Fox&, Deer&, Bird&, Squirrel&, Insect&, Bat&, Rabbit&);
};

class Deer{
public:
	deque<int> pop = {0, 0, 0, 0, 0, 0, 0, 0};
	int totPop = 0;
	int cornConsump = 24000;
	int repAge = 6;
	int child = 3;
	int repMonth = 4;
	double genMort = 1;
	double evadRate = 0.2;
	int energy = 19000;
	vector<int> pred = { 0 };
	vector<double> diet;
	int devour(int);
	void birth(int);
	void age(int);
	void death(int);
};

class Bird{
public:
	deque<int> pop = {0, 1800, 0};
	int totPop = 1800;
	int energyConsump = 150;
	int cornConsump = 100;
	int repAge = 1;
	int child = 4;
	int repMonth = 2;
	double genMort = 1;
	double evadRate = 0.2;
	int energy = 100;
	vector<int> prey = {5};
	vector<int> pred = {0, 1};
	vector<double> diet = {1};
	int devour(int);
	void birth(int);
	void age(int);
	void starvation(int);
	void consume(Fox&, Deer&, Bird&, Squirrel&, Insect&, Bat&, Rabbit&);
};

class Squirrel{
public:
	deque<int> pop = {0, 2000, 0};
	int totPop = 2000;
	int energyConsump = 100;
	int cornConsump = 50;
	int repAge = 1;
	int child = 3;
	int repMonth = 2;
	double genMort = 1;
	double evadRate = 0.3;
	int energy = 100;
	vector<int> prey = {5};
	vector<int> pred = {0, 1};
	vector<double> diet = {1};
	int devour(int);
	void birth(int);
	void age(int);
	void starvation(int);
	void consume(Fox&, Deer&, Bird&, Squirrel&, Insect&, Bat&, Rabbit&);
};

class Insect{
public:
	deque<int> pop = {1700000, 0};
	int totPop = 1700000;
	int energyConsump = 15;
	int cornConsump = 1;
	int repAge = 0;
	int child = 100;
	int repMonth = 5;
	int energy = 1;
	double genMort = 1;
	double evadRate = 0.5;
	vector<int> prey;
	vector<int> pred = {3, 4, 6};
	vector<double> diet;
	int devour(int);
	void birth(int);
	void age(int);
	void death(int);
};

class Bat{
public:
	deque<int> pop = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int totPop = 0;
	int energyConsump = 165;
	int cornConsump;
	int repAge = 1;
	int child = 1;
	int repMonth = 5;
	int energy;
	double genMort = 0.97;
	double evadRate;
	vector<int> prey = {5};
	vector<int> pred;
	vector<double> diet = {1};
	void birth(int);
	void age(int);
	void starvation(int);
	void consume(Fox&, Deer&, Bird&, Squirrel&, Insect&, Bat&, Rabbit&);
};

class Rabbit{
public:
	deque<int> pop = {0, 0, 0, 0, 0, 0, 0};
	int totPop = 0;
	int cornConsump = 150;
	int repAge = 1;
	int child = 28;
	int repMonth = 5;
	int energy = 300;
	double genMort = 1;
	double evadRate = 0.4;
	vector<int> pred = {0, 1};
	vector<double> diet;
	int devour(int);
	void birth(int);
	void age(int);
	void death(int);
};

class Corn{
public:
	deque<int> pop;
	int totPop = 0;
	double evadRate = .95;
};
