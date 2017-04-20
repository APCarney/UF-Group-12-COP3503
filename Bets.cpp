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
    //The dealer checks
    if (dealerBet == 0) {
        cout << "\nThe dealer has checked.\n";
        //User input
        while (true) {
            cout << "Enter b for bet, c for check, f for fold.\n";
            cin >> decision;
            //Check
            if (decision == "c") {
                cout << "You have checked.\n";
                return 1;
            }
            //Fold
            else if (decision == "f") {
                cout << "You have folded.\n";
                dealerMoney += pot;
                pot = 0;
                return 0;
            }
            //Bet
            else if (decision == "b") {
                string x;
                int value;
                //User input to make sure of a valid number
                while (true) {
                    cout << "How much would you like to bet?\n";
                    cin >> x;
                    //Check if number
                    if (intChecker(x) == 1) {
                        value = atoi(x.c_str());
                        //Check if larger than dealer or user money
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
                //Random response from the dealer
                int z = rand() % 100;
                
                //1 in 5 chance of folding
                if (z % 5 == 0) {
                    cout << "The dealer has folded.\n";
                    userMoney += pot;
                    pot = 0;
                    return 0;
                }
                //Otherwise the dealer bets
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
//The dealer bets, but doesn't go all in
else if (ran < dealerMoney) {
    cout << "The dealer has bet " << ran << ".\n";
    dealerMoney -= ran;
    pot += ran;
    //User input
    while (true) {
        cout << "Enter r for raise, c for call, f for fold.\n";
        cin >> decision;
        //Call
        if (decision == "c") {
            cout << "You have called the dealer's bet of " << ran << ".\n";
            userMoney -= ran;
            pot += ran;
            return 1;
        }
        //Fold
        else if (decision == "f") {
            cout << "You have folded.\n";
            dealerMoney += pot;
            pot = 0;
            return 0;
        }
        //All in
        else if (decision == "r" && ran == userMoney) {
            cout << "You have gone all in.";
            userMoney -= ran;
            pot += ran;
        }
        //Raise
        else if (decision == "r") {
            string x;
            int value;
            //User input to make sure of a valid number
            while (true) {
                cout << "How much would you like to bet?\n";
                cin >> x;
                //Checks if it's a number
                if (intChecker(x) == 1) {
                    value = atoi(x.c_str());
                    //Checks if it's actually a raise
                    if (value > ran) {
                        //Checks if it's higher than the user's money or dealer's money
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
            
            //Random dealer response
            int z = rand() % 100;
            
            //1 in 5 chance the dealer folds
            if (z % 5 == 0) {
                cout << "The dealer has folded.\n";
                userMoney += pot;
                pot = 0;
                return 0;
            }
            //Otherwise, the dealer calls 
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
    //The dealer goes all in
    else {
        cout << "The dealer has gone all in.\n";
        dealerMoney -= ran;
        pot += ran;
        //User input for call or fold
        while (true) {
            cout << "Enter c for call, f for fold.\n";
            cin >> decision;
            //Call
            if (decision == "c") {
                cout << "You have called the dealer's bet of " << ran << ".\n";
                userMoney -= ran;
                pot += ran;
                return 1;
            }
            //Fold
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
