//Poker Program
//COP3503 Spring 2017
//Group 12
//Contributors: Tal Eden, Joshua Jackson, Daniel Ruales
//Contributors: Andrew Carney, Kassandra Byler, Alejandro Ruiz 

//#include "stdio.h"
//#include "stdafx.h"


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





int count_cards(int num_cards) {

	return num_cards;

}

string convert_r(int input_rank) {

	string rank = "";


	if (input_rank == 2)
		rank = "2";

	else if (input_rank == 3)
		rank = "3";

	else if (input_rank == 4)
		rank = "4";

	else if (input_rank == 5)
		rank = "5";

	else if (input_rank == 6)
		rank = "6";

	else if (input_rank == 7)
		rank = "7";

	else if (input_rank == 8)
		rank = "8";

	else if (input_rank == 9)
		rank = "9";

	else if (input_rank == 10)
		rank = "10";

	else if (input_rank == 11)
		rank = "J";

	else if (input_rank == 12)
		rank = "Q";

	else if (input_rank == 13)
		rank = "K";

	else
		rank = "A";


	return rank;

}

string convert_s(string suit) {

	if (suit == "Heart")
		suit = "hearts";


	else if (suit == "Diamond")
		suit = "diamonds";


	else if (suit == "Spade")
		suit = "spades";


	else if (suit == "Club")
		suit = "clubs";


	return suit;

}






//class initializations
class Card {

public:

	int rank; //13 ranks 1-13
	string suit; //4 suits, 1-4

};


//Pretty Cards makes individual cards look pretty
class PrettyCards {

	friend Card;

private:

	int i = 0;
	int j = 0;


public:

	string prettyface;
	string prettyrank;

	bool check;

	string prettyCard[6][10];


	PrettyCards::PrettyCards() {



	}



	PrettyCards::PrettyCards(string prettyface, string prettyrank);

	string PrettyCards::pretty_face(string prettyface);

	bool PrettyCards::pretty_rank(string prettyrank);



	string print_pretty() {

		string print;

		for (int i = 0; i < 6; i++) {

			for (int j = 0; j<10; j++) {

				print += prettyCard[i][j];

			}

			print += "\n";
		}

		return print;
	}


	bool PrettyCards::update_bool(bool check) {

		return check;

	}


};


PrettyCards::PrettyCards(string prettyrank, string prettyface) {

	bool rank_size;

	int shift = 0;

	rank_size = pretty_rank(prettyrank);

	update_bool(rank_size);

	/*Make blank card*/
	for (int i = 0; i < 6; i++) {

		for (int j = 0; j < 10; j++) {

			prettyCard[0][0] = " ";

			if (i == 0 || i == 5) {

				prettyCard[i][j] = "_";

				if (i == 0 && j == 9) {

					prettyCard[i][j] = " ";

				}

			}

			prettyCard[0][9] = " ";


			/*Insert Rank*/
			if (i > 0) {


				prettyCard[i][j] = " ";


				if (i == 1 && j == 1) {

					prettyCard[i][j] = prettyrank;

				}

				if (!rank_size) {

					prettyCard[1][3] = "";

				}

				else {

					prettyCard[1][3] = " ";

				}


				/*Insert face of suit*/
				if (i == 3 && j == 4) {

					prettyCard[3][4] = pretty_face(prettyface);


					if (prettyCard[3][4] == "<3") { /*heart*/

						prettyCard[3][3] = "";

					}

					else if (prettyCard[3][4] == "|") {/*diamond*/

						shift = 2;

						prettyCard[2][3] = "/ \\";
						prettyCard[3][4] = "\\ /";

					}


					else if (prettyCard[3][4] == " ^") { /*spade*/

						prettyCard[3][3] = "";
						prettyCard[1][4] = "_";
						prettyCard[2][4] = "{ }";
						prettyCard[2][3] = "";
						prettyCard[2][5] = "";

					}

					else {									/*club*/

						shift = 1;

						prettyCard[2][5] = "O";
						prettyCard[3][4] = " O O";
						prettyCard[3][5] = "";
						prettyCard[3][6] = "";
						prettyCard[3][7] = "";
						prettyCard[3][3] = "";

					}

				}

			}

			/*Bottom of each card*/
			if (i == 5 && j > 0 && j < 9) {

				prettyCard[i][j] = "_";

			}

			if (j == 0) {

				prettyCard[i][j] = "|";

			}

			if (j == 9) {

				prettyCard[i][j] = "|";

			}

		}

	}

	if (shift == 1) {

		prettyCard[3][1] = "  ";
		prettyCard[3][2] = "";
		prettyCard[3][5] = "";
		prettyCard[3][6] = "";
		prettyCard[4][4] = "";
		prettyCard[4][6] = "^ ";

	}

	if (shift == 2) {

		prettyCard[2][1] = " ";
		prettyCard[2][2] = " ";
		prettyCard[2][6] = "";
		prettyCard[2][7] = "";
		prettyCard[3][1] = "";
		prettyCard[3][5] = "";

	}




}


string PrettyCards::pretty_face(string prettyface) {

	string prettytemp = "";

	if (prettyface == "hearts") {

		prettytemp = "<3";

	}

	if (prettyface == "diamonds") {

		prettytemp = "|";

	}

	if (prettyface == "clubs") {

		prettytemp = " ";
	}


	if (prettyface == "spades") {

		prettytemp = " ^";
	}

	return prettytemp;

}

bool PrettyCards::pretty_rank(string prettyrank) {

	if (prettyrank == "10") {

		check = false;

	}

	else {

		check = true;

	}

	return check;

}

//Pretty Array - for printing
class PrettyArray {

	friend PrettyCards;

public:

	PrettyArray::PrettyArray(string a) {


		string pretty_array[1][1] = { a };

		cout << pretty_array[0][0];
	}

	PrettyArray::PrettyArray(string a, string b) {


		string pretty_array[1][2] = { a , b };

		cout << pretty_array[0][0] << pretty_array[0][1];
	}


	PrettyArray::PrettyArray(string a, string b, string c) {


		string pretty_array[1][5] = { a , b, c };

		cout << pretty_array[0][0] << pretty_array[0][1] << pretty_array[0][2];

	}

	PrettyArray::PrettyArray(string a, string b, string c, string d, string e) {


		string pretty_array[1][5] = { a , b, c, d, e };

		cout << pretty_array[0][0] << pretty_array[0][1] << pretty_array[0][2] << pretty_array[0][3] << pretty_array[0][4];

	}

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







//Deal method at the beginning of each hand
int deal(Player Dealer, Player User) {

	//Give dealer and user two cards each
	userHand.push_back(mainDeck[mainDeck.size() - 1]);

	dealerHand.push_back(mainDeck[mainDeck.size() - 2]);

	userHand.push_back(mainDeck[mainDeck.size() - 3]);

	dealerHand.push_back(mainDeck[mainDeck.size() - 4]);


	//Output user and dealer hand
	//cout << "Player  |  Dealer" << "\n\n";

	string s1 = convert_r(userHand[0].rank);

	string s2 = convert_s(userHand[0].suit);

	PrettyCards card1(s1, s2);

	string c1;

	c1 = card1.print_pretty();



	//cout << userHand[1].rank << " " << userHand[1].suit << "  |  ";

	string s3 = convert_r(userHand[1].rank);

	string s4 = convert_s(userHand[1].suit);

	PrettyCards card2(s3, s4);

	string c2;

	c2 = card2.print_pretty();

	PrettyArray a1(c1, c2);


	//	cout << dealerHand[1].rank << " " << dealerHand[1].suit << "\n";


	//Print the table of cards
	//Otherwise, continue
	//djkhfaskjdfhaskdjfh();

	return bets(Dealer, User);

}

//After the deal and bets method, gives the 3-card flop
int flop(Player Dealer, Player User) {

	//Input the cards to dealer and user hands
	userHand.push_back(mainDeck[47]);

	userHand.push_back(mainDeck[46]);

	userHand.push_back(mainDeck[45]);

	dealerHand.push_back(mainDeck[47]);

	dealerHand.push_back(mainDeck[46]);

	dealerHand.push_back(mainDeck[45]);

	cout << "\n";

	string s1 = convert_r(dealerHand[2].rank);

	string s2 = convert_s(dealerHand[2].suit);


	string s3 = convert_r(dealerHand[3].rank);

	string s4 = convert_s(dealerHand[3].suit);


	string s5 = convert_r(dealerHand[4].rank);

	string s6 = convert_s(dealerHand[4].suit);


	PrettyCards card1(s1, s2);

	string c1;

	c1 = card1.print_pretty();


	PrettyCards card2(s3, s4);

	string c2;

	c2 = card2.print_pretty();


	PrettyCards card3(s5, s6);

	string c3;

	c3 = card3.print_pretty();

	PrettyArray a3(c1, c2, c3);


	//If nobody is all in, go to bets
	//otherwise, continue
	if (dealerMoney > 0 && userMoney > 0) {
		return bets(Dealer, User);
	}
	else {
		return 1;
	}
}




//after the flop method, gives 1 card
int turn(vector<Card> mainDeck, Player Dealer, Player User) {

	//inputs the card of the turn to the dealer and user hands
	dealerHand.push_back(mainDeck[44]);

	userHand.push_back(mainDeck[44]);

	cout << "\n";

	//outputs the card of the turn
	//cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
	string s1 = convert_r(dealerHand[5].rank);

	string s2 = convert_s(dealerHand[5].suit);

	PrettyCards card1(s1, s2);

	string c1;

	c1 = card1.print_pretty();

	PrettyArray a1(c1);

	//If nobody is all in, go to bets
	//otherwise, continue
	if (dealerMoney > 0 && userMoney > 0) {
		return bets(Dealer, User);
	}
	else {
		return 1;
	}
}
//after the turn method, gives one card river
int river(vector<Card> mainDeck, Player Dealer, Player User) {


	//input the card of the river into the user and dealer hands
	dealerHand.push_back(mainDeck[43]);

	userHand.push_back(mainDeck[43]);

	cout << "\n";


	//print the table of cards
	string s1 = convert_r(dealerHand[2].rank);

	string s2 = convert_s(dealerHand[2].suit);


	string s3 = convert_r(dealerHand[3].rank);

	string s4 = convert_s(dealerHand[3].suit);


	string s5 = convert_r(dealerHand[4].rank);

	string s6 = convert_s(dealerHand[4].suit);


	string s7 = convert_r(dealerHand[5].rank);

	string s8 = convert_s(dealerHand[5].suit);


	string s9 = convert_r(dealerHand[6].rank);

	string s10 = convert_s(dealerHand[6].suit);



	PrettyCards card1(s1, s2);

	string c1;

	c1 = card1.print_pretty();


	PrettyCards card2(s3, s4);

	string c2;

	c2 = card2.print_pretty();


	PrettyCards card3(s5, s6);

	string c3;

	c3 = card3.print_pretty();


	PrettyCards card4(s7, s8);

	string c4;

	c4 = card4.print_pretty();


	PrettyCards card5(s9, s10);

	string c5;

	c5 = card5.print_pretty();


	PrettyArray a5(c1, c2, c3, c4, c5);



	//If nobody is all in, go to bets
	//otherwise, continue
	if (dealerMoney > 0 && userMoney > 0) {
		return bets(Dealer, User);
	}
	else {
		return 1;
	}

}

//REFERENCE:
//checks whether there is a type integer is inputted
bool intChecker(string g) {
	bool v = (g.find_first_not_of("0123456789") == string::npos);
	return v;
}

//takes care of all bets of dealer and player
int bets(Player Dealer, Player User) {
	//Initializations
	string decision;
	int dealerBet = 0;

	//Random amount of checks and bets
	int ran = rand() % 1000;
	while (ran > dealerMoney || ran > userMoney) {
		ran = rand() % 1000;
	}

	//Checks if divisible by 5
	int ran2 = ran % 5;
	if (ran2 % 5 == 0) {
		dealerBet = 0;
	}
	//Bets that amount if not divisible by 5
	else {
		dealerBet = ran;
	}
	if (dealerBet == 0) {
		cout << "\nThe dealer has checked.\n";
		while (true) {
			cout << "Enter b for bet, c for check, f for fold.\n";
			cin >> decision;
			if (decision == "c") {
				cout << "You have checked.\n";
				return 1;
			}
			else if (decision == "f") {
				cout << "You have folded.\n";
				dealerMoney += pot;
				pot = 0;
				return 0;
			}
			else if (decision == "b") {
				string x;
				int value;
				while (true) {
					cout << "How much would you like to bet?\n";
					cin >> x;
					if (intChecker(x) == 1) {
						value = atoi(x.c_str());
						if (value > userMoney || value > dealerMoney) {
							cout << "You can't bet more than you or the dealer has.\n";
							continue;
						}
						userMoney -= value;
						pot += value;
						break;
					}
					else {
						cout << "A bet must be a positive number. Please try again.\n";
					}
				}
				int z = rand() % 100;

				if (z % 5 == 0) {
					cout << "The dealer has folded.\n";
					userMoney += pot;
					pot = 0;
					return 0;
				}
				else {
					if (value > dealerMoney) {

					}
					else {
						cout << "The dealer has called.\n";
						dealerMoney -= value;
						pot += value;
						return 1;
					}
				}
				break;
			}
			else {
				cout << "Invalid input. Please try again.\n";
			}
		}
	}
	else if (ran < dealerMoney) {
		cout << "The dealer has bet " << ran << ".\n";
		dealerMoney -= ran;
		pot += ran;
		while (true) {
			cout << "Enter r for raise, c for call, f for fold.\n";
			cin >> decision;
			if (decision == "c") {
				cout << "You have called the dealer's bet of " << ran << ".\n";
				userMoney -= ran;
				pot += ran;
				return 1;
			}
			else if (decision == "f") {
				cout << "You have folded.\n";
				dealerMoney += pot;
				pot = 0;
				return 0;
			}
			else if (decision == "r" && ran == userMoney) {
				cout << "You have gone all in.";
				userMoney -= ran;
				pot += ran;
			}
			else if (decision == "r") {
				string x;
				int value;
				while (true) {
					cout << "How much would you like to bet?\n";
					cin >> x;
					if (intChecker(x) == 1) {
						value = atoi(x.c_str());
						if (value > ran) {
							if (value > userMoney || value > dealerMoney + ran) {
								cout << "You can't bet more than you or the dealer has.\n";
								continue;
							}
							cout << "You have raised the dealer by betting " << x << ".\n";
							userMoney -= value;
							pot += value;
							break;
						}
						else {
							cout << "A raise must be higher than the dealer's bet. Please try again.\n";
						}
					}
					else {
						cout << "A raise must be a positive number. Please try again.\n";
					}
				}
				int z = rand() % 100;
				if (z % 5 == 0) {
					cout << "The dealer has folded.\n";
					userMoney += pot;
					pot = 0;
					return 0;
				}
				else {
					cout << "The dealer has called.\n";
					int a = value - ran;
					dealerMoney -= a;
					pot += a;
					return 1;
				}
				break;
			}
			else {
				cout << "Invalid input. Please try again.\n";
			}
		}
	}
	else {
		cout << "The dealer has gone all in.\n";
		dealerMoney -= ran;
		pot += ran;
		while (true) {
			cout << "Enter c for call, f for fold.\n";
			cin >> decision;
			if (decision == "c") {
				cout << "You have called the dealer's bet of " << ran << ".\n";
				userMoney -= ran;
				pot += ran;
				return 1;
			}
			else if (decision == "f") {
				cout << "You have folded.\n";
				dealerMoney += pot;
				pot = 0;
				return 0;
			}
			else {
				cout << "Invalid input. Please try again.\n";
			}
		}
	}
}



//Hand Ranking algorithm and determiner
void winner(vector<Card> userHand, vector<Card> dealerHand) {

	//initializing all relevant objects
	int userRankValue = 0;
	int dealerRankValue = 0;
	int userStrtCount = 0;
	int dealerStrtCount = 0;
	vector<int> userOrder;
	vector<int> dealerOrder;
	vector<int> userRank;
	vector<int> userSRank;
	vector<int> dealerSRank;
	vector<string> userSuit;
	vector<string> dealerSuit;
	vector<int> dealerRank;
	vector<int> userPair;
	vector<int> dealerPair;
	vector<int> userThreeKind;
	vector<int> userFourKind;
	vector<int> dealerThreeKind;
	vector<int> dealerFourKind;
	bool userFlush = false;
	bool dealerFlush = false;

	//vector of user card objects
	for (int i = 0; i < userHand.size(); i++) {

		userSRank.push_back(userHand[i].rank);
		dealerSRank.push_back(userHand[i].rank);
		userRank.push_back(userHand[i].rank);
		userSuit.push_back(userHand[i].suit);

	}

	//vector of dealer card objects
	for (int i = 0; i < dealerHand.size(); i++) {

		dealerRank.push_back(dealerHand[i].rank);
		dealerSuit.push_back(dealerHand[i].suit);

	}



	//map to capture values for a straight
	map<int, int> s;
	for (auto & i : userSRank)
		s[i]++;
	userSRank.clear();

	for (auto & i : s)
		userOrder.push_back(i.first);

	int j = 0;

	for (j; j < userOrder.size(); ++j) {


		if (j == userOrder.size() - 1) {

			break;
		}

		userStrtCount = 0;

		if ((userOrder[j] + 1) == userOrder[j + 1]) {

			while ((j == userOrder.size() - 1) || ((userOrder[j] + 1) == userOrder[j + 1])) {

				if (j == userOrder.size() - 1) {

					break;
				}

				userStrtCount++;
				j++;

				if (userStrtCount >= 5) {
					break;
				}

			}
		}

	}

	if (j < userOrder.size() - 1) {
		if (userOrder[j] + 1 == (userOrder[j + 1])) {

			userStrtCount++;

		}
	}

	//********************************************************************************************


	map<int, int> s2;
	for (auto & i : dealerSRank)
		s2[i]++;
	dealerSRank.clear();

	for (auto & i : s2)
		dealerOrder.push_back(i.first);

	int k = 0;
	for (k; k < dealerOrder.size(); ++k) {

		if (k == dealerOrder.size() - 1) {

			break;
		}

		dealerStrtCount = 0;

		if ((dealerOrder[k] + 1) == dealerOrder[k + 1]) {

			while ((k == dealerOrder.size() - 1) || ((dealerOrder[k] + 1) == userOrder[k + 1])) {

				if (k == dealerOrder.size() - 1) {

					break;
				}

				dealerStrtCount++;
				k++;

				if (dealerStrtCount >= 5) {
					break;
				}

			}
		}

	}

	if (k < dealerOrder.size() - 1) {

		if (dealerOrder[k] + 1 == (dealerOrder[k + 1])) {
			dealerStrtCount++;
		}
	}

	//map for three and four of a kind for user
	map<int, int> m;
	for (auto & i : userRank)
		m[i]++;
	userRank.clear();

	for (auto & i : m)
		if (i.second == 4) {
			userFourKind.push_back(i.first);
		}

	for (auto & i : m)
		if (i.second == 3) {
			userThreeKind.push_back(i.first);
		}

	for (auto & i : m)
		if (i.second == 2) {
			userPair.push_back(i.first);
		}


	//***********************************************************
	//map for three and four of a kind for dealer
	map<int, int> m2;
	for (auto & i : dealerRank)
		m2[i]++;
	dealerRank.clear();

	for (auto & i : m2)
		if (i.second == 4) {
			dealerFourKind.push_back(i.first);
		}


	for (auto & i : m2)
		if (i.second == 3) {
			dealerThreeKind.push_back(i.first);
		}

	for (auto & i : m2)
		if (i.second == 2) {
			dealerPair.push_back(i.first);
		}

	//***********************************************
	//map for flush capturer, user
	map<string, int> m3;
	for (auto & i : userSuit)
		m3[i]++;
	userSuit.clear();

	for (auto & i : m3) {

		if (i.second == 5) {
			cout << i.first;
			userFlush = true;
		}
	}

	//****************************************************

	//map for flush capturer, dealer
	map<string, int> m4;
	for (auto & i : dealerSuit)
		m4[i]++;
	dealerSuit.clear();

	for (auto & i : m4) {

		if (i.second == 5) {
			dealerFlush = true;
		}
	}

	//************************************************

	//if pairs exist for user
	if (!userPair.empty()) {
		cout << "Player has the following pairs: ";

		if (userPair.size() == 1) {

			userRankValue = 1;
		}

		if (userPair.size() == 2) {

			userRankValue = 2;
		}

		if (userPair.size() == 3) {

			userRankValue = 2;
		}
		for (int i = 0; i < userPair.size(); i++) {
			cout << userPair[i] << " ";
		}


		cout << "\n";
	}

	//if dealer pairs exist
	if (!dealerPair.empty()) {
		cout << "Dealer has the following pairs: ";

		if (dealerPair.size() == 1) {

			dealerRankValue = 1;
		}

		if (dealerPair.size() == 2) {

			dealerRankValue = 2;
		}

		if (dealerPair.size() == 3) {

			dealerRankValue = 2;
		}

		for (int i = 0; i < dealerPair.size(); i++) {
			cout << dealerPair[i] << " ";
		}


		cout << "\n";
	}

	//if three of a kind exists for user
	if (!userThreeKind.empty()) {
		cout << "Player has the following three of a kind: ";

		for (int i = 0; i < userThreeKind.size(); i++) {
			cout << userThreeKind[i] << " ";
		}
		userRankValue = 3;

		cout << "\n\n";
	}

	//if three of a kind exists for dealer
	if (!dealerThreeKind.empty()) {

		cout << "Dealer has the following three of a kind: ";

		for (int i = 0; i < dealerThreeKind.size(); i++) {
			cout << dealerThreeKind[i] << " ";
		}

		dealerRankValue = 3;
		//dealerThreeKind.clear();
		cout << "\n";
	}

	//if straight exists
	if (userStrtCount >= 5) {

		userRankValue = 4;
		cout << "Player has a straight\n";
	}

	if (dealerStrtCount >= 5) {

		dealerRankValue = 4;
		cout << "Dealer has a straight\n";
	}



	//if flush exists for user
	if (userFlush == true) {

		userRankValue = 5;
		cout << "Player has a flush\n";
	}

	//if flush exists for dealer
	if (dealerFlush == true) {

		dealerRankValue = 5;
		cout << "Dealer has a flush\n";
	}

	//if full house exists for user
	if (!userPair.empty() && !userThreeKind.empty()) {

		userRankValue = 6;
		cout << "Player has a full house\n";

	}

	//if full house exists for dealer
	if (!dealerPair.empty() && !dealerThreeKind.empty()) {

		dealerRankValue = 6;
		cout << "Dealer has a full house\n";
	}

	//if four of a kind exists for user
	if (!userFourKind.empty()) {
		cout << "Player has the following four of a kind: ";

		for (int i = 0; i < userFourKind.size(); i++) {
			cout << userFourKind[i] << " ";
		}
		userRankValue = 7;

		userFourKind.clear();

		cout << "\n\n";
	}

	//if four of a kind exists for dealer
	if (!dealerFourKind.empty()) {

		cout << "Dealer has the following four of a kind: ";

		for (int i = 0; i < dealerFourKind.size(); i++) {
			cout << dealerFourKind[i] << " ";
		}

		dealerRankValue = 7;

		dealerFourKind.clear();

		cout << "\n";
	}

	if (userStrtCount >= 5 && userFlush == true) {

		cout << "Player has a straight flush";

		userRankValue = 8;
	}

	if (dealerStrtCount >= 5 && dealerFlush == true) {

		cout << "Dealer has a straight flush";

		dealerRankValue = 8;
	}

	// if users hand is better than dealers, he wins
	if (userRankValue > dealerRankValue) {

		//cout << "D val: " << dealerRankValue << "\n";
		//cout << "P val: " << userRankValue << "\n";

		//		cout << "D size: " << dealerPair.size() << "\n";
		//	cout << "P size: " << userPair.size() << "\n";
		cout << "\nPlayer has the winning hand!" << "\n";
		userMoney += pot;
		pot = 0;
	}

	//if dealers hand is better than users , he wins
	if (userRankValue < dealerRankValue) {

		//	cout << "D val: " << dealerRankValue << "\n";
		//	cout << "P val: " << userRankValue << "\n";

		//	cout << "D size: " << dealerPair.size() << "\n";
		//	cout << "P size: " << userPair.size() << "\n";
		cout << "\nDealer has the winning hand!";

		dealerMoney += pot;
		pot = 0;
	}
	// if hand is equivalent, then tiebreaker must commence to determine the winner or if the pot will be split i.e. a tie occurs
	if (userRankValue == dealerRankValue) {

		//cout << "D val: " << dealerRankValue << "\n";
		//cout << "P val: " << userRankValue << "\n";

		//cout << "D size: " << dealerPair.size() << "\n";
		//cout << "P size: " << userPair.size() << "\n";
		x = tieBreaker(userRankValue, dealerPair, userPair, dealerThreeKind, userThreeKind);
	}

	cout << "\n";



	// if tiebreaker geos to user
	if (x == 0) {
		cout << "\nPlayer has the winning hand!" << "\n";
		userMoney += pot;
		pot = 0;
	}

	//if tiebreaker goes to dealer
	else if (x == 1) {
		cout << "\nDealer has the winning hand!";
		dealerMoney += pot;
		pot = 0;
	}
	//if pot must be split
	else if (x == 2) {
		cout << "\n The pot is split, each player recieves half of the pot";
		int halfPot = (pot / 2);
		dealerMoney += halfPot;
		userMoney += halfPot;
		pot = 0;

	}
	x = -1;

	//vectors are cleared for re-usage in the next hand
	userOrder.clear();
	dealerOrder.clear();
	userPair.clear();
	dealerPair.clear();
	userThreeKind.clear();
	dealerThreeKind.clear();

}
int tieBreaker(int userRankValue, vector<int> dealerPair, vector<int> userPair, vector<int>dealerThreeKind, vector<int> userThreeKind) {


	// ASSUMPTION: 0=high card, 1=pair, 2=two pair, 3= 3 of a kind, 4= straight, 5= flush, 6=fullhouse, 7= fourkind, 8=straightflush

	//if int winner=0 then userHand wins, 
	//if int winner=1, then dealerHand wins
	//first initialize it to a non-acting value
	int winner = 3;

	//error catching methods for the appropriate hand types. (1,2,3,6)


	if (userRankValue == 1 && (userPair.empty()) || (dealerPair.empty())) {
		userRankValue = 10;
		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else {
			winner = 0;
		}
	}
	if (userRankValue == 2 && (userPair.empty() || dealerPair.empty())) {
		userRankValue = 20;
		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else {
			winner = 0;
		}
	}

	if (userRankValue == 3 && (userThreeKind.empty() || dealerThreeKind.empty())) {
		userRankValue = 30;
		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else {
			winner = 0;
		}
	}


	if (userRankValue == 6 && (userThreeKind.empty() || dealerThreeKind.empty()) || userPair.empty() || dealerPair.empty()) {
		userRankValue = 60;
		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else {
			winner = 0;
		}
	}



	//max card numerical value
	int maxRank = 0;
	int isthereAce = 0;
	for (int i = 0; i< userHand.size(); i++) {

		if (userHand[i].rank > maxRank) {
			maxRank = userHand[i].rank;
			if (userHand[i].rank == 1) {
				isthereAce = 1;
			}
		}
	}
	if (isthereAce == 1) {
		maxRank = 1;
	}

	//finding the highest card of the two
	if (userHand[0].rank == 1 && userHand[1].rank == 1) {
		highUserCard = userHand[0].rank;
		secondUserCard = userHand[1].rank;
	}
	else if (userHand[0].rank > userHand[1].rank || (userHand[0].rank == 1 && userHand[1].rank != 1)) {
		highUserCard = userHand[0].rank;
		secondUserCard = userHand[1].rank;
	}
	else if (userHand[1].rank > userHand[0].rank || (userHand[1].rank == 1 && userHand[0].rank != 1)) {
		highUserCard = userHand[1].rank;
		secondUserCard = userHand[0].rank;
	}
	else {
		highUserCard = userHand[1].rank;
		secondUserCard = userHand[0].rank;
	}

	if (dealerHand[0].rank == 1 && dealerHand[1].rank == 1) {
		highDealerCard = dealerHand[0].rank;
		secondDealerCard = dealerHand[1].rank;
	}
	else if (dealerHand[0].rank > dealerHand[1].rank || (dealerHand[0].rank == 1 && dealerHand[1].rank != 1)) {
		highDealerCard = dealerHand[0].rank;
		secondDealerCard = dealerHand[1].rank;
	}
	else if (dealerHand[1].rank > dealerHand[0].rank || (dealerHand[1].rank == 1 && dealerHand[0].rank != 1)) {
		highDealerCard = dealerHand[1].rank;
		secondDealerCard = dealerHand[0].rank;
	}
	else {
		highDealerCard = dealerHand[1].rank;
		secondDealerCard = dealerHand[0].rank;
	}




	//***********************************************
	//reconicliation of tiebreaker between a straightflush
	if (userRankValue == 8) {
		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else {
			winner = 0;
		}
	}

	//reconcilation of tiebreaker between 4 of a kind
	if (userRankValue == 7) {
		if ((userHand[0].rank == userHand[1].rank)) {
			if (highDealerCard > highUserCard) {
				winner = 1;
			}
			else {
				winner = 0;
			}
		}
		else if (((userHand[0].rank == maxRank) || (userHand[1].rank == maxRank)) && (dealerHand[1].rank != maxRank) && (dealerHand[2].rank != maxRank)) {

			winner = 0;
		}
		else {
			winner = 1;
		}

	}
	//reconcilation of tiebreaker between 2 full houses
	if (userRankValue == 6) {
		int maxUserPair = 0;
		int maxDealerPair = 0;
		for (int i = 0; i < userPair.size(); i++) {
			if (userPair[i] > maxUserPair) {
				maxUserPair = userPair[i];
			}
		}
		for (int i = 0; i < dealerPair.size(); i++) {
			if (dealerPair[i] > maxDealerPair) {
				maxDealerPair = userPair[i];
			}

		}

		if (userThreeKind[0] > dealerThreeKind[0]) {
			winner = 0;
		}
		else if (userThreeKind[0] < dealerThreeKind[0]) {
			winner = 1;
		}

		if (userThreeKind[0] = dealerThreeKind[0]) {
			if (maxDealerPair> maxUserPair) {
				winner = 1;
			}
			else if (maxDealerPair < maxUserPair) {
				winner = 0;
			}
			else winner = 2;
		}

	}

	//reconcilation of tiebreaker flushes 
	if (userRankValue == 5) {

		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else {
			winner = 0;
		}



	}

	//reconcilation for 2 straights
	if (userRankValue == 4) {

		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else {
			winner = 0;
		}



	}

	//reconciliation for 2 three of a kinds
	if (userRankValue == 3) {


		int secondHighest = 35;
		int secondHighestDealer = 30;
		if (dealerThreeKind[0] > userThreeKind[0]) {
			winner = 1;
		}
		else if (dealerThreeKind[0] < userThreeKind[0]) {
			winner = 0;
		}

		else if (dealerThreeKind[0] == userThreeKind[0]) {
			if (userHand[0].rank == userThreeKind[0]) {
				secondHighest = userHand[1].rank;

			}

			else if (userHand[1].rank == userThreeKind[0]) {
				secondHighest = userHand[0].rank;
			}


			if (dealerHand[0].rank == dealerThreeKind[0]) {
				secondHighestDealer = dealerHand[1].rank;

			}

			else if (dealerHand[1].rank == dealerThreeKind[0]) {
				secondHighestDealer = dealerHand[0].rank;
			}

			if (secondHighestDealer > secondHighest) {
				winner = 1;
			}
			else if (secondHighestDealer < secondHighest) {
				winner = 0;
			}
			else winner = 2;

		}


	}

	//reconcilation for a tiebreaker between 2 two-pairs
	if (userRankValue == 2) {
		int maxUserPair = 0;
		int maxDealerPair = 0;
		for (int i = 0; i < userPair.size(); i++) {
			if (userPair[i] > maxUserPair) {
				maxUserPair = userPair[i];
			}
		}



		for (int i = 0; i < dealerPair.size(); i++) {
			if (dealerPair[i] > maxDealerPair) {
				maxDealerPair = userPair[i];
			}

		}

		if (maxUserPair > maxDealerPair) {
			winner = 0;
		}
		else if (maxUserPair < maxDealerPair) {
			winner = 1;
		}

		else if (maxUserPair == maxDealerPair) {
			sort(dealerPair.begin(), dealerPair.end());
			int secondHighest = userPair[userPair.size() - 2];
			int secondHighestDealer = dealerPair[dealerPair.size() - 2];

			if (secondHighest> secondHighestDealer) {
				winner = 0;
			}
			else if (secondHighest < secondHighestDealer) {
				winner = 1;
			}
			else winner = 2;
		}


		if (highDealerCard > highUserCard) {
			winner = 1;
		}

		else {
			winner = 0;
		}
	}

	//reconciliation for tiebreaker between two pairs
	if (userRankValue == 1) {
		if (dealerPair[0] > userPair[0] && (userPair[0] != 1)) {
			winner = 1;
		}
		if (userPair[0] > dealerPair[0] && (dealerPair[0]) != 1) {
			winner = 0;
		}
		if (userPair[0] == 1 && dealerPair[0] != 1) {
			winner = 0;
		}
		if (dealerPair[0] == 1 && userPair[0] != 1) {
			winner = 1;
		}
		if (dealerPair[0] == userPair[0]) {
			if (highDealerCard > highUserCard) {
				winner = 1;
			}
			else {
				winner = 0;
			}
		}
	}

	//	reconciliation for tiebreaker between two high cards
	if (userRankValue == 0) {
		if (highDealerCard > highUserCard) {
			winner = 1;
		}
		else if (highDealerCard < highUserCard) {
			winner = 0;
		}

		else if (highDealerCard == highUserCard) {
			if (secondDealerCard > secondUserCard) {
				winner = 1;
			}
			else if (secondDealerCard < secondUserCard)
			{
				winner = 0;
			}
			else winner = 2;
		}

	}

	//	cout << "\nhighest Dealer card:" << highDealerCard;
	//	cout << "\n2nd highest Dealer card:" << secondDealerCard;
	//	cout << "\nhighest User card:" << highUserCard;
	//	cout << "\n2ndhighest User card:" << secondUserCard;

	return winner;
}



void djkhfaskjdfhaskdjfh() {

}

//shuffles the deck, randomizes the location of its elements
void shuffle() {
	srand(time(NULL));
	for (int i = 0; i<500; i++) {
		int x = rand() % 52;
		int y = rand() % 52;
		Card tempCard = mainDeck[y];
		mainDeck[y] = mainDeck[x];
		mainDeck[x] = tempCard;
	}

}
//deck of 52 cards of a rank and suit constructed here
vector<Card>  deckConstructor() {

	string suitNames[4] = { "Spade", "Club", "Diamond", "Heart" };


	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			Card x;
			x.suit = suitNames[i];
			x.rank = j;
			mainDeck.push_back(x);
		}
	}

	//printing out the deck
	for (int p = 0; p < mainDeck.size(); p++) {
		cout << "|" << mainDeck[p].rank << "," << mainDeck[p].suit << "| ";
		if (p == 9 || p == 18 || p == 27 || p == 36 || p == 45) {
			cout << "\n";
		}
	}

	return mainDeck;
}
//main method, where it all comes together
int main() {
	//initialization of user and dealer Players.
	Player user;
	user.money = 10000;
	Player Jarvis;
	Jarvis.name = "Jarvis";
	Jarvis.money = 10000;

	string name;

	cout << "Please type your name: ";
	cin >> user.name;
	cout << "Welcome " << user.name << ", good luck on the poker game!\n\n";

	deckConstructor();

	//while the game is active, nobody has 0 dollars in their "money" account, while loop goes as long as the game is active
	while (userMoney > 0 && userMoney < 20000) {
		//shuffle the deck after every hand
		shuffle();

		cout << "\n";
		cout << "\n";
		cout << "*** Hand *** \n\n";
		//sorting out the ante in different scenarios,
		//1) one where 
		if (userMoney > 9 && dealerMoney > 9) {
			user.money = user.money - 10;
			Jarvis.money = Jarvis.money - 10;
			userMoney -= 10;
			dealerMoney -= 10;
			pot += 20;

			cout << user.name << " and " << Jarvis.name << " each bet 10 for ante \n";
		}

		//2) one were user has less than 10 dollars but dealer doesnt
		else if (userMoney<9 && dealerMoney >9) {
			pot += user.money;
			pot += 10;
			Jarvis.money = Jarvis.money - 10;
			dealerMoney -= 10;
			cout << user.name << " bet " << userMoney << "for ante" << " and " << Jarvis.name << " bet 10 for ante\n";
			user.money = 0;
			userMoney -= userMoney;
		}
		//3) one were dealer has less than 10 dollars but user doesnt 
		else if (userMoney>9 && dealerMoney <9) {
			pot += Jarvis.money;
			pot += 10;
			user.money = user.money - 10;
			userMoney -= 10;

			cout << Jarvis.name << " bet " << dealerMoney << "for ante" << " and " << user.name << " bet 10 for ante\n";
			Jarvis.money = 0;
			dealerMoney -= dealerMoney;
		}
		//print out of the players bank balance and the pot
		cout << endl << user.name << "'s money: " << userMoney << endl;
		cout << "Dealer's money: " << dealerMoney << endl;
		cout << "Pot: " << pot << endl << endl;


		if (deal(Jarvis, user) == 0) {
			userHand.clear();
			dealerHand.clear();
			continue;
		}

		cout << endl << user.name << "'s money: " << userMoney << endl;
		cout << "Dealer's money: " << dealerMoney << endl;
		cout << "Pot: " << pot << endl << endl;

		//flop method call
		cout << "*** Flop ***\n";
		if (flop(Jarvis, user) == 0) {
			userHand.clear();
			dealerHand.clear();
			continue;
		}

		cout << endl << user.name << "'s money: " << userMoney << endl;
		cout << "Dealer's money: " << dealerMoney << endl;
		cout << "Pot: " << pot << endl << endl;

		//turn method call
		cout << "*** Turn ***\n";
		if (turn(mainDeck, Jarvis, user) == 0) {
			userHand.clear();
			dealerHand.clear();
			continue;
		}

		cout << endl << user.name << "'s money: " << userMoney << endl;
		cout << "Dealer's money: " << dealerMoney << endl;
		cout << "Pot: " << pot << endl << endl;

		//river method call
		cout << "*** River ***\n";
		if (river(mainDeck, Jarvis, user) == 0) {
			userHand.clear();
			dealerHand.clear();
			continue;
		}
		cout << "\n";

		cout << endl << user.name << "'s money: " << userMoney << endl;
		cout << "Dealer's money: " << dealerMoney << endl;
		cout << "Pot: " << pot << endl << endl;

		cout << "*** rank  ***\n";

		//hand ranking algorithm method call
		winner(userHand, dealerHand);
		userHand.clear();
		dealerHand.clear();
		//declaration of the wnning of the gamee
		if (userMoney == 20000) {
			cout << "\nUser has won! Goodnight San Francicso!";
			return 0;
		}

		if (userMoney == 0) {
			cout << "\nDealer has won! Goodmorning Chicago!";
			return 0;
		}


	}

	cout << "\n The Game has Ended. Thanks for Playing!";
	//system("pause");

	return 0;
}
