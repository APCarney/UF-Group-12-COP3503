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
int userMoney = 10000;
int dealerMoney = 10000;
int userRankValue = 0;
int dealerRankValue = 0;
int pot;
int highUserCard;
int highDealerCard;
int secondUserCard;
int secondDealerCard;
void game(string name);
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
    
    if(dealerMoney > 0 && userMoney > 0){
        return bets(Dealer, User);
    }
    else{
        return 1;
    }
    
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
    
    if(dealerMoney > 0 && userMoney > 0){
        return bets(Dealer, User);
    }
    else{
        return 1;
    }
}

int turn(vector<Card> mainDeck, Player Dealer, Player User) {
    
    
    dealerHand.push_back(mainDeck[44]);
    
    userHand.push_back(mainDeck[44]);
    
    cout << "\n";
    
    cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
    
    if(dealerMoney > 0 && userMoney > 0){
        return bets(Dealer, User);
    }
    else{
        return 1;
    }
    
}

int river(vector<Card> mainDeck, Player Dealer, Player User) {
    
    
    
    dealerHand.push_back(mainDeck[43]);
    
    userHand.push_back(mainDeck[43]);
    
    cout << "\n";
    
    cout << dealerHand[2].rank << " " << dealerHand[2].suit << "\n\n";
    
    cout << dealerHand[3].rank << " " << dealerHand[3].suit << "\n\n";
    
    cout << dealerHand[4].rank << " " << dealerHand[4].suit << "\n\n";
    
    cout << dealerHand[5].rank << " " << dealerHand[5].suit << "\n\n";
    
    cout << dealerHand[6].rank << " " << dealerHand[6].suit << "\n";
    
    printTable();
    
    if(dealerMoney > 0 && userMoney > 0){
        return bets(Dealer, User);
    }
    else{
        return 1;
    }
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
    while(ran > dealerMoney || ran > userMoney){
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
                        if(value > userMoney || value > dealerMoney){
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
                    if(value > dealerMoney){
                        
                    }
                    else{
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
    else if(ran < dealerMoney){
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
            else if (decision == "r" && ran == userMoney){
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
                            if(value > userMoney || value > dealerMoney + ran){
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
    else{
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
            else{
                cout << "Invalid input. Please try again.\n";
            }
        }
    }
}


//Assuming objects are (#, suit) and # goes from 0 (Ace) to 13 (King), and Suit goes from 1 to 4.
//	int Poker::handRanking(/*Array Length 7*/) {
//
//for (int i = 0; i < array.length; i++) {

//}
//tiebreaker();
//winner();
//}



void winner(vector<Card> userHand, vector<Card> dealerHand) {
    
    
    
    int straightCount = 0;
    vector<int> userOrder;
    vector<int> userRank;
    vector<string> userSuit;
    vector<string> dealerSuit;
    vector<int> dealerRank;
    vector<int> userPair;
    vector<int> userThreeKind;
    vector<int> userFourKind;
    vector<int> dealerPair;
    vector<int> dealerThreeKind;
    vector<int> dealerFourKind;
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
    /*vector<int>::iterator result = std::min_element(begin(dealerRank), end(dealerRank));
     cout << "***************** min element at: \n" << distance(begin(dealerRank), result);*/
    
    /*map<int, int> s;
     for (auto & i : userRank)
     s[i]++;
     userRank.clear();
     for (auto & i : s)
     userOrder.push_back(i.first);
     cout << userOrder.size() << "\n";
     for (int j = 0; j < userOrder.size(); j++) {
     cout <<"--"<< userOrder[j] <<"--"<< "\n";
     cout << " J1: " << j;
     if (j == userOrder.size() -1) {
     if ((userOrder[4] + 1) == userOrder[5]) {
     straightCount++;
     break;
     }
     break;
     }
     if ((userOrder[j] + 1) == userOrder[j + 1]) {
     while (j != (userOrder.size() - 1) && ((userOrder[j] + 1) == userOrder[j + 1])) {
     cout << "--" << userOrder[j] << "--" << "\n";
     if (j == userOrder.size() - 1) {
     if ((userOrder[4] + 1) == userOrder[5]) {
     straightCount++;
     cout << " **" << straightCount << "** ";
     break;
     }
     break;
     }
     straightCount++;
     j++;
     cout << " J2: " << j;
     cout << " **"<< straightCount << "** ";
     if (straightCount == 5) {
     break;
     }
     }
     }
     cout << " J3: " << j;
     }*/
    
    //cout << *min_element(userRank[0], userRank[userRank.size()]);
    
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
        
        if (userPair.size() == 1) {
            
            userRankValue = 1;
        }
        
        if (userPair.size() == 2) {
            
            userRankValue = 2;
        }
        
        for (int i = 0; i < userPair.size(); i++) {
            cout << userPair[i] << " ";
        }
        
        
        cout << "\n";
    }
    
    
    if (!dealerPair.empty()) {
        cout << "Dealer has the following pairs: ";
        
        dealerRankValue = dealerPair.size();
        
        for (int i = 0; i < dealerPair.size(); i++) {
            cout << dealerPair[i] << " ";
        }
        
        
        cout << "\n";
    }
    
    
    if (!userThreeKind.empty()) {
        cout << "Player has the following three of a kind: ";
        
        for (int i = 0; i < userThreeKind.size(); i++) {
            cout << userThreeKind[i] << " ";
        }
        userRankValue = 3;
        
        cout << "\n\n";
    }
    
    
    if (!dealerThreeKind.empty()) {
        
        cout << "Dealer has the following three of a kind: ";
        
        for (int i = 0; i < dealerThreeKind.size(); i++) {
            cout << dealerThreeKind[i] << " ";
        }
        
        dealerRankValue = 3;
        
        cout << "\n";
    }
    
    
    
    if (userFlush == true) {
        
        userRankValue = 5;
        cout << "Player has a flush\n";
    }
    
    if (dealerFlush == true) {
        
        dealerRankValue = 5;
        cout << "Dealer has a flush\n";
    }
    
    
    if (!userPair.empty() && !userThreeKind.empty()) {
        
        userRankValue = 6;
        cout << "Player has a full house\n";
        
        //userPair.clear();
        //userThreeKind.clear();
    }
    
    if (!dealerPair.empty() && !dealerThreeKind.empty()) {
        
        dealerRankValue = 6;
        cout << "Dealer has a full house\n";
        
        //dealerPair.clear();
        //dealerThreeKind.clear();
    }
    
    if (!userFourKind.empty()) {
        cout << "Player has the following four of a kind: ";
        
        for (int i = 0; i < userFourKind.size(); i++) {
            cout << userFourKind[i] << " ";
        }
        userRankValue = 7;
        
        userFourKind.clear();
        
        cout << "\n\n";
    }
    
    
    if (!dealerFourKind.empty()) {
        
        cout << "Dealer has the following four of a kind: ";
        
        for (int i = 0; i < dealerFourKind.size(); i++) {
            cout << dealerFourKind[i] << " ";
        }
        
        dealerRankValue = 7;
        
        dealerFourKind.clear();
        
        cout << "\n";
    }
    
    
    
    if (userRankValue > dealerRankValue) {
        
        cout << "D val: " << dealerRankValue << "\n";
        cout << "P val: " << userRankValue << "\n";
        
        cout << "D size: " << dealerPair.size() << "\n";
        cout << "P size: " << userPair.size() << "\n";
        cout << "\nPlayer has the winning hand!" << "\n";
        userMoney += pot;
        pot = 0;
    }
    
    if (userRankValue < dealerRankValue) {
        
        cout << "D val: " << dealerRankValue << "\n";
        cout << "P val: " << userRankValue << "\n";
        
        cout << "D size: " << dealerPair.size() << "\n";
        cout << "P size: " << userPair.size() << "\n";
        cout << "\nDealer has the winning hand!";
        dealerMoney += pot;
        pot = 0;
    }
    
    if (userRankValue == dealerRankValue) {
        
        cout << "D val: " << dealerRankValue << "\n";
        cout << "P val: " << userRankValue << "\n";
        
        cout << "D size: " << dealerPair.size() << "\n";
        cout << "P size: " << userPair.size() << "\n";
        cout << "\nTal where you at, you need to settle this sheit!";
        int x = tieBreaker(userRankValue, dealerPair, userPair, dealerThreeKind, userThreeKind);
        
        if (x == 0) {
            cout << "\nPlayer has the winning hand!" << "\n";
            userMoney += pot;
            pot = 0;
        }
        else if (x == 1) {
            cout << "\nDealer has the winning hand!";
            dealerMoney += pot;
            pot = 0;
        }
        else if (x == 2) {
            cout << "\n The pot is split, each player recieves half of the pot";
            int halfPot = (pot / 2);
            dealerMoney += halfPot;
            userMoney += halfPot;
            pot = 0;
            
        }
    }
    userPair.clear();
    dealerPair.clear();
    userThreeKind.clear();
    dealerThreeKind.clear();
    for (int i = 0; i < dealerPair.size(); i++) {
        cout << dealerPair[i] << endl;
        
        
        cout << "\n";
        
    }
}
int tieBreaker(int userRankValue, vector<int> dealerPair, vector<int> userPair, vector<int>dealerThreeKind, vector<int> userThreeKind) {
    
    // in main (if userhandRank==dealerhandRank){tiebreaker()}
    // ASSUMPTION: 0=high card, 1=pair, 2=two pair, 3= 3 of a kind, 4= straight, 5= flush, 6=fullhouse, 7= fourkind, 8=straightflush
    // put the deaear and user bank balance in the main at the beginning of the hand.
    //[**if int winner=0 then userHand wins,
    //if int winner=1, then dealerHand wins**]
    int winner = 2;
    
    if (userPair.empty() || dealerPair.empty() || userThreeKind.empty() || dealerThreeKind.empty() ){
        userRankValue = 30;
        winner = 1;
    }
    
    
    
    
    //if(intHandrank==dealerhandRank){}
    int maxRank = 0;
    
    for (int i = 0; i< userHand.size(); i++) {
        if (userHand[i].rank > maxRank) {
            maxRank = userHand[i].rank;
        }
    }
    
    
    if (userHand[0].rank > userHand[1].rank) {
        highUserCard = userHand[0].rank;
        secondUserCard = userHand[1].rank;
    }
    else {
        highUserCard = userHand[1].rank;
        secondUserCard = userHand[0].rank;
    }
    
    if (dealerHand[0].rank > dealerHand[1].rank) {
        highDealerCard = dealerHand[0].rank;
        secondDealerCard = dealerHand[1].rank;
    }
    else {
        highDealerCard = dealerHand[1].rank;
        secondDealerCard = dealerHand[0].rank;
    }
    
    //***********************************************
    if (userRankValue == 8) {
        if (highDealerCard > highUserCard) {
            winner = 1;
        }
        else {
            winner = 0;
        }
    }
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
    if (userRankValue == 6) {
        if (userThreeKind[0] = dealerThreeKind[0]) {
            //if ()
            //}
            
            if (highDealerCard > highUserCard) {
                winner = 1;
            }
            else {
                winner = 0;
            }
        }
    }
    //for 6, flush, if the hand ranks equal each other here, then the flush is of a different
    if (userRankValue == 5) {
        if (highDealerCard > highUserCard) {
            winner = 1;
        }
        else {
            winner = 0;
        }
    }
    //for 5, straight, the highest card in the last node of the straight is whats relevant, thats not necessarily a card in somebodys 2 cards.
    if (userRankValue == 4) {
        if (highDealerCard > highUserCard) {
            winner = 1;
        }
        else {
            winner = 0;
        }
    }
    
    
    if (userRankValue == 3) {
        if (highDealerCard > highUserCard) {
            winner = 1;
        }
        else {
            winner = 0;
        }
    }
    
    if (userRankValue == 2) {
        
        if (highDealerCard > highUserCard) {
            winner = 1;
        }
        else {
            winner = 0;
        }
    }
    
    
    if (userRankValue == 1) {
        if (dealerPair[0] > userPair[0]) {
            winner = 1;
        }
        if (userPair[0] > dealerPair[0]) {
            winner = 0;
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
    
    if (userRankValue == 0) {
        if (highDealerCard > highUserCard) {
            winner = 1;
        }
        else if (highDealerCard < highUserCard) {
            winner = 0;
        }
        
        else if (highDealerCard == highUserCard) {
            
        }
        
    }
    
    cout << "\nhighest Dealer card:" << highDealerCard;
    cout << "\n2nd highest Dealer card:" << secondDealerCard;
    cout << "\nhighest User card:" << highUserCard;
    cout << "\n2ndhighest User card:" << secondUserCard;
    
    return winner;
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
    someshit();
    while (userMoney > 0 && userMoney < 20000) {
        
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
        
        if (userMoney > 9 && dealerMoney > 9) {
            userMoney -= 10;
            dealerMoney -= 10;
            pot += 20;
            
            cout << user.name << " and " << Jarvis.name << " each bet 10 for ante \n";
        }
        
        
        else if (userMoney<9 && dealerMoney >9) {
            pot += userMoney;
            userMoney = 0;
            pot += 10;
            dealerMoney -= 10;
            cout << user.name << " bet " << userMoney << "for ante" << " and " << Jarvis.name << " bet 10 for ante\n";
        }
        else if (userMoney>9 && dealerMoney <9) {
            pot += dealerMoney;
            dealerMoney = 0;
            pot += 10;
            userMoney -= 10;
            cout << Jarvis.name << " bet " << dealerMoney << "for ante" << " and " << user.name << " bet 10 for ante\n";
        }
        
        cout << endl << user.name << "'s money: " << userMoney << endl;
        cout << "Dealer's money: " << dealerMoney << endl;
        cout << "Pot: " << pot << endl << endl;
        
        cout << "*** Hand *** \n\n";
        
        if (deal(Jarvis, user) == 0) {
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        
        cout << endl << user.name << "'s money: " << userMoney << endl;
        cout << "Dealer's money: " << dealerMoney << endl;
        cout << "Pot: " << pot << endl << endl;
        
        cout << "*** Flop ***\n";
        if (flop(Jarvis, user) == 0) {
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        
        cout << endl << user.name << "'s money: " << userMoney << endl;
        cout << "Dealer's money: " << dealerMoney << endl;
        cout << "Pot: " << pot << endl << endl;
        
        cout << "*** Turn ***\n";
        if (turn(mainDeck, Jarvis, user) == 0) {
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        
        cout << endl << user.name << "'s money: " << userMoney << endl;
        cout << "Dealer's money: " << dealerMoney << endl;
        cout << "Pot: " << pot << endl << endl;
        
        cout << "*** River ***\n";
        if (river(mainDeck, Jarvis, user) == 0) {
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            userHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            dealerHand.pop_back();
            continue;
        }
        cout << "\n";
        
        cout << endl << user.name << "'s money: " << userMoney << endl;
        cout << "Dealer's money: " << dealerMoney << endl;
        cout << "Pot: " << pot << endl << endl;
        
        cout << "*** rank  ***\n";
        
        winner(userHand, dealerHand);
        userHand.pop_back();
        userHand.pop_back();
        userHand.pop_back();
        userHand.pop_back();
        userHand.pop_back();
        userHand.pop_back();
        userHand.pop_back();
        dealerHand.pop_back();
        dealerHand.pop_back();
        dealerHand.pop_back();
        dealerHand.pop_back();
        dealerHand.pop_back();
        dealerHand.pop_back();
        dealerHand.pop_back();
        
        if (userMoney == 200000) {
            cout << "User has won! Goodnight San Francicso!";
            
        }
        
        if (userMoney == 0) {
            cout << "Dealer has won! Goodmorning Chicago!";
            
        }
        
    }
    
    cout << "good game";
    system("pause");
    
    return 0;
}
