//Poker Program
//COP3503 Spring 2017

#include <iostream>
#include <string>
#include <chrono>
#include <unistd.h>

using namespace std::chrono;
using namespace std;

class Card{
public:
    int rank; //13 ranks 1-13
    int suit; //4 suits, 1-4
};

class Deck{
public:
    void Deck();
    void shuffle();
private:
    Card cards[52];
    
    Deck(){
        
    }
    
    shuffle(){
        
    }
};

class Player{
public:
    string name;
private:
    int money;
    int playing;
    Card cards[2];
};

class Poker{
public:
    void game(string name);
    void deal();
    void flop();
    void turnRiver();
    void bets();
    int handRanking();
    int tieBreaker();
    void winner;
    void printTable();
private:
    int pot;
    int playersLeft();
    Player players[6];

    void game(name){
        
    }
    
    void deal(){
        printTable();
        bets();
        flop();
    }
    
    void flop(){
        printTable();
        bets();
    }
    
    void turnRiver(){
        printTable();
        bets();
    }
    
    void bets(){
        
    }
    
    //Assuming objects are (#, suit) and # goes from 0 (Ace) to 13 (King), and Suit goes from 1 to 4.
    int handRanking(/*Array Length 7*/){
        for(int i = 0; i < array.length; i++){
            
        }
        tiebreaker();
        winner();
    }
    
    int tieBreaker(){
        
    }
    
    void winner(){
        
    }
    
    void printTable(){
        
    }
    
    int playersLeft(){
        int count = 0;
        for (int i = 0; i < 6; i++)
            if (players[i].money>0)
                count++;
        return count;
    }
};

int main(){
    string name;
    cout << "Please type your name: ";
    cin >> name;
    cout << "Welcome " << name << ", good luck on the poker game!\n\n;
    usleep(1000000);
    game(name);
}

for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
    }
}
