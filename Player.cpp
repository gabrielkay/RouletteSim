#include <string>
#include <stdlib.h>
#include <stdexcept>
#include "Player.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

Player::Player(){
    budget = 1000;
    balance = budget;
    positive = true;
    spins = 100;
    american = true;
    odds = americanOdds;
}

Player::Player(int budg, int spin, bool amer){
    budget = budg;
    balance = budget;
    positive = true;
    spins = spin;
    american = amer;
    if (american){
        odds = americanOdds;
    }
    else {
        odds = europeanOdds;
    }
}

Player::startPlaying(){
    srand (time ( NULL));
    int bet = 1;
    while (spins > 0 && positive){
        int bet = spinTheWheel(bet);
    }
}

int Player::spinTheWheel(int bet){
    spins--;
    float spinResult = randmm(0, 1);
    if (spinResult <= .4737){
        balance += bet;
        return 1;
    }
    else {
        balance -= bet;
        if (balance <= 0){
            noDebt = false;
            if (bet == 1){
                return 1;
            }
            else {
                return bet * 2;
            }
        }
    }
}


float randmm(float min, float max){
     static int first = -1;
     if((first = (first<0))){
         srand(time(NULL)+getpid());
     }
     if(min>=max){
         return errno=EDOM, NAN;
     }
     return min + (float)rand() / ((float)RAND_MAX / (max - min));
}
