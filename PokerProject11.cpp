// pokerProject.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
//Poker Program
//COP3503 Spring 2017

#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>


//#include <unistd.h>

using namespace std::chrono;
using namespace std;

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



void shuffle();
vector<Card> someshit();
vector<Card> mainDeck;
vector<Card> tableCardSet;
vector<Card> userHand;
vector<Card> dealerHand;
int pot;
void game(string name);
int deal();
int flop(Player Dealer , Player User);
int turn(vector<Card>, Player Dealer, Player User);
int river(vector<Card>, Player Dealer, Player User);
bool intChecker(string x);
int bets(Player x, Player b);
//int handRanking();
int tieBreaker();
void winner(vector<Card>, vector<Card>);
void printTable();

/*void getUserCard(int i) {
 cout << "Player's Hand:\n";
 cout << userHand[i].rank << " " << userHand[i].suit << "\n\n";
 }
 void addUserCard(Card u) {
 userHand.push_back(u);
 }
 void getDealerCard(int j) {
 cout << "Dealer's Hand:\n";
 cout << dealerHand[j].rank << " " << dealerHand[j].suit << "\n\n";
 }
 void addDealerCard(Card d) {
 dealerHand.push_back(d);
 }*/










void game(string name) {
    //while () {}
    //deal(vector<Card> mainDeck);
    //turnRiver();
    //turnRiver();
    
    
}

int deal(Player Dealer, Player User) {
    
    userHand.push_back(mainDeck[mainDeck.size() - 1]);
    
    dealerHand.push_back(mainDeck[mainDeck.size() - 2]);
    
    userHand.push_back(mainDeck[mainDeck.size() - 3]);
    
    dealerHand.push_back(mainDeck[mainDeck.size() - 4]);
    
    cout << "Player  |  Dealer\n\n";
    
    cout << userHand[0].rank << " " << userHand[0].suit << "  |  ";
    
    cout << dealerHand[0].rank << " " << dealerHand[0].suit << "\n";
    
    cout << userHand[1].rank << " " << userHand[1].suit << "  |  ";
    
    cout << dealerHand[1].rank << " " << dealerHand[1].suit << "\n";
    
    
    
    printTable();
    return bets(Dealer, User);
    
}

int flop(Player Dealer, Player User) {
    
    
    userHand.push_back(mainDeck[47]);
    
    userHand.push_back(mainDeck[46]);
    
    userHand.push_back(mainDeck[45]);
    
    dealerHand.push_back(mainDeck[47]);
    
    dealerHand.push_back(mainDeck[46]);
    
    dealerHand.push_back(mainDeck[45]);
    
    cout << "\n";
    
    cout << dealerHand[2].rank << " " << dealerHand[2].suit << "\n\n";
    
    cout << dealerHand[3].rank << " " << dealerHand[3].suit << "\n\n";
    
    cout << dealerHand[4].rank << " " << dealerHand[4].suit << "\n";
    return bets(Dealer, User);
}

int turn(vector<Card> mainDeck, Player Dealer, Player User) {
    
    
    dealerHand.push_back(mainDeck[44]);
    
    userHand.push_back(mainDeck[44]);
    
    cout << "\n";
    
    cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
    return bets(Dealer, User);
    
}

int river(vector<Card> mainDeck, Player Dealer, Player User) {
    
    
    
    dealerHand.push_back(mainDeck[43]);
    
    userHand.push_back(mainDeck[43]);
    
    cout << "\n";
    
    cout << dealerHand[2].rank << " " << dealerHand[2].suit << "\n\n";
    
    cout << dealerHand[3].rank << " " << dealerHand[3].suit << "\n\n";
    
    cout << dealerHand[4].rank << " " << dealerHand[4].suit << "\n\n";
    
    cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
    
    cout << dealerHand[6].rank << " " << dealerHand[5].suit << "\n";
    
    printTable();
    return bets(Dealer, User);
}

//REFERENCE
bool intChecker(string g) {
    bool v = (g.find_first_not_of("0123456789") == string::npos);
    return v;
}

int bets(Player Dealer, Player User) {
    //Initializations
    string decision;
    int dealerBet = 0;
    int playerBet = 0;
    
    //Random amount of checks and bets
    int ran = rand() % 1000;
    
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
                Dealer.money += pot;
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
                        User.money -= value;
                        pot += value;
                        break;
                    }
                    else {
                        cout << "A bet must be a positive number. Please try again.\n";
                    }
                }
                int z = rand() % 100;
                if(z % 5 == 0){
                    cout << "The dealer has folded.\n";
                    User.money += pot;
                    pot = 0;
                    return 0;
                }
                else{
                    cout << "The dealer has called.\n";
                    Dealer.money -= value;
                    pot += value;
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
        cout << "The dealer has bet " << ran << ".\n";
        Dealer.money -= ran;
        pot += ran;
        while (true) {
            cout << "Enter r for raise, c for call, f for fold.\n";
            cin >> decision;
            if (decision == "c") {
                cout << "You have called the dealer's bet of " << ran << ".\n";
                User.money -= ran;
                pot += ran;
                return 1;
            }
            else if (decision == "f") {
                cout << "You have folded.\n";
                Dealer.money += pot;
                pot = 0;
                return 0;
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
                            cout << "You have raised the dealer by betting " << x << ".\n";
                            User.money -= value;
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
                if(z % 5 == 0){
                    cout << "The dealer has folded.\n";
                    User.money += pot;
                    pot = 0;
                    return 0;
                }
                else{
                    cout << "The dealer has called.\n";
                    int a = value - ran;
                    Dealer.money -= a;
                    pot += value;
                    return 1;
                }
                break;
            }
            else {
                cout << "Invalid input. Please try again.\n";
            }
        }
    }
}

/*bool isParam(string line)
 {
 char* p;
 strtol(line.c_str(), &p, 10);
 return *p == 0;
 }*/

//Assuming objects are (#, suit) and # goes from 0 (Ace) to 13 (King), and Suit goes from 1 to 4.
//	int Poker::handRanking(/*Array Length 7*/) {
//
//for (int i = 0; i < array.length; i++) {

//}
//tiebreaker();
//winner();
//}

int tieBreaker() {
    
    return 1;
}

// pokerProject.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "stdafx.h"
//Poker Program
//COP3503 Spring 2017

#include <iostream>
#include <ostream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>


//#include <unistd.h>

using namespace std::chrono;
using namespace std;

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



void shuffle();
vector<Card> someshit();
vector<Card> mainDeck;
vector<Card> tableCardSet;
vector<Card> userHand;
vector<Card> dealerHand;
int userMoney=10000;
int dealerMoney=10000;
int pot;
void game(string name);
//int deal();
int flop(Player Dealer, Player User);
int turn(vector<Card>, Player Dealer, Player User);
int river(vector<Card>, Player Dealer, Player User);
bool intChecker(string x);
int bets(Player x, Player b);
//int handRanking();
int tieBreaker();
void winner(vector<Card>, vector<Card>);
void printTable();

/*void getUserCard(int i) {
cout << "Player's Hand:\n";
cout << userHand[i].rank << " " << userHand[i].suit << "\n\n";
}
void addUserCard(Card u) {
userHand.push_back(u);
}
void getDealerCard(int j) {
cout << "Dealer's Hand:\n";
cout << dealerHand[j].rank << " " << dealerHand[j].suit << "\n\n";
}
void addDealerCard(Card d) {
dealerHand.push_back(d);
}*/










void game(string name) {
	//while () {}
	//deal(vector<Card> mainDeck);
	//turnRiver();
	//turnRiver();


}

int deal(Player Dealer, Player User) {

	userHand.push_back(mainDeck[mainDeck.size() - 1]);

	dealerHand.push_back(mainDeck[mainDeck.size() - 2]);

	userHand.push_back(mainDeck[mainDeck.size() - 3]);

	dealerHand.push_back(mainDeck[mainDeck.size() - 4]);

	cout << "Player  |  Dealer\n\n";

	cout << userHand[0].rank << " " << userHand[0].suit << "  |  ";

	cout << dealerHand[0].rank << " " << dealerHand[0].suit << "\n";

	cout << userHand[1].rank << " " << userHand[1].suit << "  |  ";

	cout << dealerHand[1].rank << " " << dealerHand[1].suit << "\n";



	printTable();
	return bets(Dealer, User);

}

int flop(Player Dealer, Player User) {


	userHand.push_back(mainDeck[47]);

	userHand.push_back(mainDeck[46]);

	userHand.push_back(mainDeck[45]);

	dealerHand.push_back(mainDeck[47]);

	dealerHand.push_back(mainDeck[46]);

	dealerHand.push_back(mainDeck[45]);

	cout << "\n";

	cout << dealerHand[2].rank << " " << dealerHand[2].suit << "\n\n";

	cout << dealerHand[3].rank << " " << dealerHand[3].suit << "\n\n";

	cout << dealerHand[4].rank << " " << dealerHand[4].suit << "\n";
	return bets(Dealer, User);
}

int turn(vector<Card> mainDeck, Player Dealer, Player User) {


	dealerHand.push_back(mainDeck[44]);

	userHand.push_back(mainDeck[44]);

	cout << "\n";

	cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
	return bets(Dealer, User);

}

int river(vector<Card> mainDeck, Player Dealer, Player User) {



	dealerHand.push_back(mainDeck[43]);

	userHand.push_back(mainDeck[43]);

	cout << "\n";

	cout << dealerHand[2].rank << " " << dealerHand[2].suit << "\n\n";

	cout << dealerHand[3].rank << " " << dealerHand[3].suit << "\n\n";

	cout << dealerHand[4].rank << " " << dealerHand[4].suit << "\n\n";

	cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";

	cout << dealerHand[6].rank << " " << dealerHand[5].suit << "\n";

	printTable();
	return bets(Dealer, User);
}

//REFERENCE
bool intChecker(string g) {
	bool v = (g.find_first_not_of("0123456789") == string::npos);
	return v;
}

int bets(Player Dealer, Player User) {
	//Initializations
	string decision;
	int dealerBet = 0;
	int playerBet = 0;

	//Random amount of checks and bets
	int ran = rand() % 1000;

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
				Dealer.money += pot;
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
						User.money -= value;
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
					User.money += pot;
					pot = 0;
					return 0;
				}
				else {
					cout << "The dealer has called.\n";
					Dealer.money -= value;
					dealerMoney -= value;
					pot += value;
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
		cout << "The dealer has bet " << ran << ".\n";
		Dealer.money -= ran;
		dealerMoney -= ran;
		pot += ran;
		while (true) {
			cout << "Enter r for raise, c for call, f for fold.\n";
			cin >> decision;
			if (decision == "c") {
				cout << "You have called the dealer's bet of " << ran << ".\n";
				User.money -= ran;
				userMoney -= ran;
				pot += ran;
				return 1;
			}
			else if (decision == "f") {
				cout << "You have folded.\n";
				Dealer.money += pot;
				pot = 0;
				return 0;
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
							cout << "You have raised the dealer by betting " << x << ".\n";
							User.money -= value;
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
					User.money += pot;
					pot = 0;
					return 0;
				}
				else {
					cout << "The dealer has called.\n";
					int a = value - ran;
					Dealer.money -= a;
					dealerMoney -= a;
					pot += value;
					return 1;
				}
				break;
			}
			else {
				cout << "Invalid input. Please try again.\n";
			}
		}
	}
}

/*bool isParam(string line)
{
char* p;
strtol(line.c_str(), &p, 10);
return *p == 0;
}*/

//Assuming objects are (#, suit) and # goes from 0 (Ace) to 13 (King), and Suit goes from 1 to 4.
//	int Poker::handRanking(/*Array Length 7*/) {
//
//for (int i = 0; i < array.length; i++) {

//}
//tiebreaker();
//winner();
//}

int tieBreaker() {
	/* ASSUMPTION: 1=high card, 2=pair, 3=two pair, 4= 3 of a kind, 5= straight, 6= flush, 7=fullhouse, 8= fourkind, 9=straightflush
	int userhandRank;
	int dealerhandRank;
	if (intHandrank=9)




	*/
	return 1;
}

void winner(vector<Card> userHand, vector<Card> dealerHand) {


	int userCount = 0;
	int dealerCount = 0;

	vector<int> userRank;
	vector<string> userSuit;
	vector<string> dealerSuit;
	vector<int> dealerRank;
	vector<int> userPair;
	vector<int> userThreeKind;
	vector<int> dealerPair;
	vector<int> dealerThreeKind;
	bool userFlush = false;
	bool dealerFlush = false;


	for (int i = 0; i < userHand.size(); i++) {

		userRank.push_back(userHand[i].rank);
		userSuit.push_back(userHand[i].suit);

	}

	for (int i = 0; i < dealerHand.size(); i++) {

		dealerRank.push_back(dealerHand[i].rank);
		dealerSuit.push_back(dealerHand[i].suit);

	}

	map<int, int> m;
	for (auto & i : userRank)
		m[i]++;
	userRank.clear();

	for (auto & i : m)
		if (i.second == 3) {
			userThreeKind.push_back(i.first);
		}

	for (auto & i : m)
		if (i.second == 2) {
			userPair.push_back(i.first);
		}


	//***********************************************************

	map<int, int> m2;
	for (auto & i : dealerRank)
		m2[i]++;
	dealerRank.clear();

	for (auto & i : m2)
		if (i.second == 3) {
			dealerThreeKind.push_back(i.first);
		}

	for (auto & i : m2)
		if (i.second == 2) {
			dealerPair.push_back(i.first);
		}

	//***********************************************

	map<string, int> m3;
	for (auto & i : userSuit)
		m3[i]++;
	userSuit.clear();

	for (auto & i : m3) {

		if (i.second == 5) {
			userFlush = true;
		}
	}

	//****************************************************

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

	if (!userPair.empty()) {
		cout << "Player has the following pairs: ";

		for (int i = 0; i < userPair.size(); i++) {
			cout << userPair[i] << " ";
		}
		cout << "\n";
	}

	if (!userThreeKind.empty()) {
		cout << "Player has the following three of a kind: ";

		for (int i = 0; i < userThreeKind.size(); i++) {
			cout << userThreeKind[i] << " ";
		}
		cout << "\n\n";
	}



	if (!dealerPair.empty()) {
		cout << "Dealer has the following pairs: ";

		for (int i = 0; i < dealerPair.size(); i++) {
			cout << dealerPair[i] << " ";
		}

		cout << "\n";
	}



	if (!dealerThreeKind.empty()) {

		cout << "Dealer has the following three of a kind: ";

		for (int i = 0; i < dealerThreeKind.size(); i++) {
			cout << dealerThreeKind[i] << " ";
		}

		cout << "\n";
	}

	if (userFlush == true) {

		cout << "Player has a flush";
	}

	if (dealerFlush == true) {

		cout << "Dealer has a flush";
	}



	cout << "\n";



}

void printTable() {

}
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
vector<Card> someshit() {
	string suitNames[4] = { "Spade", "Club", "Diamond", "Heart" };


	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			Card x;
			x.suit = suitNames[i];
			x.rank = j;
			mainDeck.push_back(x);
		}
	}
	for (int p = 0; p < mainDeck.size(); p++) {
		cout << "|" << mainDeck[p].rank << "," << mainDeck[p].suit << "| ";
		if (p == 9 || p == 18 || p == 27 || p == 36 || p == 45) {
			cout << "\n";
		}
	}

	return mainDeck;
}

int main() {
	Player user;
	user.money = 10000;
	Player Jarvis;
	Jarvis.name = "Jarvis";
	Jarvis.money = 10000;

	string name;

	cout << "Please type your name: ";
	cin >> user.name;
	cout << "Welcome " << user.name << ", good luck on the poker game!\n\n";
	//	usleep(1000000);
	//poker.game(name);
	someshit();
	while (user.money > 0 && Jarvis.money > 0) {
		shuffle();

		cout << endl;
		for (int p = 0; p < mainDeck.size(); p++) {
			cout << "|" << mainDeck[p].rank << "," << mainDeck[p].suit << "| ";
			if (p == 9 || p == 18 || p == 27 || p == 36 || p == 45) {
				cout << "\n";
			}
		}

		cout << "\n";

		cout << "\n";
		cout << "*** Hand *** \n\n";

		if (user.money > 9 && Jarvis.money > 9) {
			user.money = user.money - 10;
			Jarvis.money = Jarvis.money - 10;
			userMoney -= 10;
			dealerMoney -= 10;
			pot += 20;

			cout << user.name << " and " << Jarvis.name << " each bet 10 for ante \n";
		}


		else if (user.money<9 && Jarvis.money >9) {
			pot += user.money;
			pot += 10;
			Jarvis.money = Jarvis.money - 10;
			userMoney -= userMoney;
			dealerMoney -= 10;
			cout << user.name << " bet " << user.money << "for ante" << " and " << Jarvis.name << " bet 10 for ante\n";
			user.money = 0;
		}
		else if (user.money>9 && Jarvis.money <9) {
			pot += Jarvis.money;
			pot += 10;
			user.money = user.money - 10;
			userMoney -= 10;
			dealerMoney -= dealerMoney;
			cout << Jarvis.name << " bet " << Jarvis.money << "for ante" << " and " << user.name << " bet 10 for ante\n";
			Jarvis.money = 0;
		}
		cout << "user and dealer money: \n";
		cout << endl << userMoney;
		cout << endl << dealerMoney;
		
		if (deal(Jarvis, user) == 0) {
			userHand.pop_back();
			userHand.pop_back();
			dealerHand.pop_back();
			dealerHand.pop_back();
			continue;
		}

		cout << "user and dealer money: \n";
		cout << endl << userMoney;
		cout << endl << dealerMoney;

		cout << "*** Flop ***\n";
		if (flop(Jarvis, user) == 0) {
			userHand.pop_back();
			userHand.pop_back();
			dealerHand.pop_back();
			dealerHand.pop_back();
			continue;
		}

		cout << "user and dealer money: \n";
		cout << endl << userMoney;
		cout << endl << dealerMoney;

		cout << "*** Turn ***\n";
		if (turn(mainDeck, Jarvis, user) == 0) {
			userHand.pop_back();
			userHand.pop_back();
			dealerHand.pop_back();
			dealerHand.pop_back();
			continue;
		}

		cout << "user and dealer money: \n";
		cout << endl << userMoney;
		cout << endl << dealerMoney;

		cout << "*** River ***\n";
		if (river(mainDeck, Jarvis, user) == 0) {
			userHand.pop_back();
			userHand.pop_back();
			dealerHand.pop_back();
			dealerHand.pop_back();
			continue;
		}
		cout << "\n";

		cout << "user and dealer money: \n";
		cout << endl << userMoney;
		cout << endl << dealerMoney;

		cout << "*** rank  ***\n";
		winner(userHand, dealerHand);


		system("pause");
	}
	return 0;
}

void printTable() {
    
}
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
vector<Card> someshit() {
    string suitNames[4] = { "Spade", "Club", "Diamond", "Heart" };
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 14; j++) {
            Card x;
            x.suit = suitNames[i];
            x.rank = j;
            mainDeck.push_back(x);
        }
    }
    for (int p = 0; p < mainDeck.size(); p++) {
        cout << "|" << mainDeck[p].rank << "," << mainDeck[p].suit << "| ";
        if (p == 9 || p == 18 || p == 27 || p == 36 || p == 45) {
            cout << "\n";
        }
    }
    
    return mainDeck;
}

int main() {
    Player user;
    user.money = 10000;
    Player Jarvis;
    Jarvis.name = "Jarvis";
    Jarvis.money = 10000;
    
    string name;
    
    cout << "Please type your name: ";
    cin >> user.name;
    cout << "Welcome " << user.name << ", good luck on the poker game!\n\n";
    //	usleep(1000000);
    //poker.game(name);
    someshit();
    while(user.money > 0 && Jarvis.money > 0){
        shuffle();
        
        cout << endl;
        for (int p = 0; p < mainDeck.size(); p++) {
            cout << "|" << mainDeck[p].rank << "," << mainDeck[p].suit << "| ";
            if (p == 9 || p == 18 || p == 27 || p == 36 || p == 45) {
                cout << "\n";
            }
        }
        
        cout << "\n";
        
        cout << "\n";
        cout << "*** Hand *** \n\n";
        
        if (user.money > 9 && Jarvis.money > 9) {
            user.money = user.money - 10;
            Jarvis.money = Jarvis.money - 10;
            pot += 20;
            
            cout << user.name << " and " << Jarvis.name << " each bet 10 for ante \n";
        }
        else if (user.money<9 && Jarvis.money >9) {
            pot += user.money;
            pot += 10;
            Jarvis.money = Jarvis.money - 10;
            cout << user.name << " bet " << user.money << "for ante" << " and " << Jarvis.name << " bet 10 for ante\n";
            user.money = 0;
        }
        else if (user.money>9 && Jarvis.money <9) {
            pot += Jarvis.money;
            pot += 10;
            user.money = user.money - 10;
            cout << Jarvis.name << " bet " << Jarvis.money << "for ante" << " and " << user.name << " bet 10 for ante\n";
            Jarvis.money = 0;
        }
        
        if(deal(Jarvis, user) == 0){
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        
        cout << "*** Flop ***\n";
        if(flop(Jarvis, user) == 0){
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        
        
        cout << "*** Turn ***\n";
        if(turn(mainDeck, Jarvis, user) == 0){
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        
        cout << "*** River ***\n";
        if(river(mainDeck, Jarvis, user) == 0){
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        cout << "\n";
        
        cout << "*** rank  ***\n";
        winner(userHand, dealerHand);
        
        
        system("pause");
    }   
    return 0;
}