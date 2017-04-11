// pokerProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Poker Program
//COP3503 Spring 2017

#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include<vector>


//#include <unistd.h>

using namespace std::chrono;
using namespace std;

class Card {
public:
	int rank; //13 ranks 1-13
	int suit; //4 suits, 1-4
	
	
};

class Deck {
public:

	void shuffle();
	vector<Card> someshit();
	vector<Card> mainDeck;
	vector<Card> tableCardSet;

private:


};

class Player {
public:
	string name;
	int money;
private:
	
	vector <Card> hand;
	
};

class Poker {
public:
	void game(string name);
	void deal();
	void flop();
	void turnRiver();
	void bets();
	//int handRanking();
	int tieBreaker();
	void winner();
	void printTable();
private:
	int pot;
};
	
	void Poker::game(string name) {
		//while () {}
			deal();
			turnRiver();
			turnRiver();

		
	}

	void Poker::deal() {
		printTable();
		bets();
		flop();
	}

	void Poker::flop() {
		printTable();
		bets();
	}

	void Poker::turnRiver() {
		printTable();
		bets();
	}

	void Poker::bets() {

	}

	//Assuming objects are (#, suit) and # goes from 0 (Ace) to 13 (King), and Suit goes from 1 to 4.
//	int Poker::handRanking(/*Array Length 7*/) {
	//	
		//for (int i = 0; i < array.length; i++) {

		//}
		//tiebreaker();
		//winner();
	//}

	int Poker::tieBreaker() {
		int j;
		return j;
	}

	void Poker::winner() {

	}

	void Poker::printTable() {

	}
	void Deck::shuffle() {
	
	}
	vector<Card> Deck::someshit() {
		for (int i = 1; i < 5; i++) {
			for (int j = 2; j < 15; j++) {
				Card x;
				x.suit = i;
				x.rank = j;
				mainDeck.push_back(x);
			}
		}
		for (int p = 0; p < mainDeck.size(); p++){
			cout <<"|"<< mainDeck[p].rank << "," << mainDeck[p].suit << "| ";
			if (p == 9 || p == 18 || p == 27 || p == 36 || p == 45) {
				cout << "\n";
			}
		}
		return mainDeck;
	}

int main() {
	Player user;
	user.money = 10, 000;
	Player Jarvis;
	Jarvis.name = "Jarvis";
	Jarvis.money = 10, 000;   
	Poker poker;
	string name;
	Deck chimmy;
	cout << "Please type your name: ";
	cin >> user.name;
	cout << "Welcome " << user.name << ", good luck on the poker game!\n\n";
	//	usleep(1000000);
	//poker.game(name);
	chimmy.someshit();


return 0;
}

