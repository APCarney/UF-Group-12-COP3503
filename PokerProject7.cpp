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
void deal();
void flop();
void turn(vector<Card>);
void turnRiver(vector<Card>);
void bets(Player x, Player b);
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

void deal(Player Dealer, Player User) {
    
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
    bets(Dealer, User);
    
}

void flop() {
    
    
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
    
}

void turn(vector<Card> mainDeck) {
    
    
    dealerHand.push_back(mainDeck[44]);
    
    userHand.push_back(mainDeck[44]);
    
    cout << "\n";
    
    cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
    
    
}

void turnRiver(vector<Card> mainDeck, Player Dealer, Player User) {
    
    
    
    dealerHand.push_back(mainDeck[43]);
    
    userHand.push_back(mainDeck[43]);
    
    cout << "\n";
    
    cout << dealerHand[2].rank << " " << dealerHand[2].suit << "\n\n";
    
    cout << dealerHand[3].rank << " " << dealerHand[3].suit << "\n\n";
    
    cout << dealerHand[4].rank << " " << dealerHand[4].suit << "\n\n";
    
    cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
    
    cout << dealerHand[6].rank << " " << dealerHand[5].suit << "\n";
    
    printTable();
    bets(Dealer, User);
}

//REFERENCE
bool intChecker(string g){
    bool v = (g.find_first_not_of("0123456789") == string::npos);
    return v;
}

void bets(Player Dealer, Player User) {
    //Initializations
    string decision;
    int dealerBet = 0;
    int playerBet = 0;
    
    //Random amount of checks and bets
    int ran = rand() % 1000;
    
    //Checks if divisible by 5
    int ran2 = ran % 5;
    if(ran2 % 5 == 0){
        dealerBet = 0;
    }
    //Bets that amount if not divisible by 5
    else{
        dealerBet = ran;
    }
    if(dealerBet == 0){
        cout << "\nThe dealer has checked.\n";
        while(true){
            cout << "Enter b for bet, c for check, f for fold.\n";
            cin >> decision;
            if(decision == "c"){
                cout << "You have checked.\n";
                break;
            }
            else if(decision == "f"){
                cout << "You have folded.\n";
                break;
            }
            else if(decision == "b"){
                string x;
                while(true){
                    cout << "How much would you like to bet?\n";
                    cin >> x;
                    if(intChecker(x) == 1){
                        int value = atoi(x.c_str());
                        cout << value;
                        break;
                    }
                    else{
                        cout << "A bet must be a positive number. Please try again.\n";
                    }
                }
                break;
            }
            else{
                cout << "Invalid input. Please try again.\n";
            }
        }
    }
    else{
        cout << "The dealer has bet " << ran << ".\n";
        Dealer.money -= ran;
        pot += ran;
        while(true){
            cout << "Enter r for raise, c for call, f for fold.\n";
            cin >> decision;
            if(decision == "c"){
                cout << "You have called the dealer's bet of " << ran << ".\n";
                User.money -= ran;
                pot += ran;
                break;
            }
            else if(decision == "f"){
                cout << "You have folded.\n";
                break;
            }
            else if(decision == "r"){
                string x;
                while(true){
                    cout << "How much would you like to bet?\n";
                    cin >> x;
                    if(intChecker(x) == 1){
                        int value = atoi(x.c_str());
                        cout << value;
                        if(value > ran){
                            cout << "You have raised the dealer by betting " << x << ".\n.";
                            break;
                        }
                        else{
                            cout << "A raise must be higher than the dealer's bet. Please try again.\n";
                        }
                    }
                    else{
                        cout << "A raise must be a positive number. Please try again.\n";
                    }
                }
                break;
            }
            else{
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

void winner(vector<Card> userHand, vector<Card> dealerHand) {
    
    
    int userCount = 0;
    int dealerCount = 0;
    vector<Card> userHandRank;
    vector<int> userRank;
    
    for (int i = 0; i < userHand.size(); i++) {
        
        userRank.push_back(userHand[i].rank);
        //cout << rankVect[i];
    }
    
    // singles out duplicates
    
    
    /*map<string, int> m;		// singles out duplicates
     for (auto & i : v)
     m[i]++;
     v.clear();
     for (auto & i : m)
     
     v.push_back(i.first);
     
     for (size_t j = 0; j < v.size(); j++) {
     if (j == v.size()) {
     
     j = 0;
     }
     
     cout << v[j] << " ";	//prints new vector without duplicates
     }*/
    
    map<int, int> m;
    for (auto & i : userRank)
        m[i]++;
    userRank.clear();
    for (auto & i : m)
        
        userRank.push_back(i.first);
    
    for (size_t j = 0; j < userRank.size(); j++) {
        if (j == userRank.size()) {
            
            j = 0;
        }
        
        cout << userRank[j] << " " << "\n";
    }
    
    
}

void printTable() {
    
}
void shuffle() {
    srand (time(NULL));
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
    else if(user.money<9 && Jarvis.money >9) {
        pot += user.money;
        pot += 10;
        Jarvis.money = Jarvis.money - 10;
        cout << user.name <<" bet "<< user.money<<"for ante" <<  " and " << Jarvis.name << " bet 10 for ante\n";
        user.money = 0;
    }
    else if (user.money>9 && Jarvis.money <9) {
        pot += Jarvis.money;
        pot += 10;
        user.money = user.money - 10;
        cout << Jarvis.name << " bet " << Jarvis.money << "for ante" << " and " << user.name << " bet 10 for ante\n";
        Jarvis.money = 0;
    }
    
    deal(Jarvis, user);
    
    cout << "*** Flop ***\n";
    flop();
    
    
    cout << "*** Turn ***\n";
    turn(mainDeck);
    
    cout << "*** River ***\n";
    turnRiver(mainDeck, Jarvis, user);
    cout << "\n";
    
    cout << "*** rank  ***\n";
    winner(userHand, dealerHand);
    
    
    system("pause");
    
    return 0;
}

