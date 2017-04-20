//Poker Program .h file
//COP3503 Spring 2017
//Group 12
//Contributors: Tal Eden, Joshua Jackson, Daniel Ruales
//Contributors: Andrew Carney, Kassandra Byler, Alejandro Ruiz

#include "stdio.h"
#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std::chrono;
using namespace std;

//class initializations
class Card {
public:
	int rank; //13 ranks 1-13
	string suit; //4 suits, 1-4


};

class Player {
public:
	string name;
	int money;
private:



};


//Item Initializations
void shuffle();
vector<Card> deckConstructor();
vector<Card> mainDeck;
vector<Card> tableCardSet;
vector<Card> userHand;
vector<Card> dealerHand;
int userMoney = 10000;
int dealerMoney = 10000;
int userRankValue = 0;
int dealerRankValue = 0;
int pot;
int x = -1;
string flushSuit;
int highUserCard;
int highDealerCard;
int secondUserCard;
int secondDealerCard;

//Method Initializations

//int deal();
int flop(Player Dealer, Player User);
int turn(vector<Card>, Player Dealer, Player User);
int river(vector<Card>, Player Dealer, Player User);
bool intChecker(string x);
int bets(Player x, Player b);
//int handRanking();
int tieBreaker(int userRankValue, vector<int> dealerPair, vector<int> userPair, vector<int>dealerThreeKind, vector<int>userThreeKind);
void winner(vector<Card>, vector<Card>);
void printTable();


