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
	Deck();
	void shuffle();
	vector<Card> someshit();
	vector<Card> mainDeck;
	vector<Card> tableCardSet;

private:
	
//	Deck() {

	//}

};

class Player {
public:
	string name;
private:
	int money;
	int playing;
	vector <Card> hand;
	
};

class Poker {
public:
	void game(string name);
	void deal();
	void flop();
	void turnRiver();
	void bets();
	int handRanking();
	int tieBreaker();
	void winner();
	void printTable();
private:
	int pot;
};
	
	void Poker::game(string name) {
		
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
			for (int j = 1; j < 14; j++) {
				Card x;
				x.suit = i;
				x.rank = j;
				mainDeck.push_back(x);
			}
		}
		cout << mainDeck[0].rank << " " << mainDeck[0].suit;
		return mainDeck;
	}

int main() {
	
	Poker poker;
	string name;
	Deck chimmy;
	cout << "Please type your name: ";
	cin >> name;
	cout << "Welcome " << name << ", good luck on the poker game!\n\n";
	//	usleep(1000000);
	//poker.game(name);
	chimmy.someshit();


return 0;
}

