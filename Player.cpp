#include <string>
#include <stdlib.h>
#include <stdexcept>
#include "Player.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>


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

void Player::startPlaying(){
    int bet = 1;
    bool justLost = false;
    while (spins > 0 && positive){
        bet = spinTheWheel(bet, justLost);
    }
}

float Player::randmm(float min, float max){
     static int first = -1;
     if((first = (first<0))){
         srand(time(NULL)+getpid());
     }
     if(min>=max){
         return errno=EDOM, NAN;
     }
     return min + (float)rand() / ((float)RAND_MAX / (max - min));
}

int Player::spinTheWheel(int bet, bool &justLost){
    spins--;
    float spinResult = randmm(0, 1);
    if (spinResult <= .4737){
        balance += bet;
        return 1;
    }
    else {
        balance -= bet;
        if (balance <= 0){
            positive = false;
        }
        if (justLost == false){
            justLost = true;
            return 1;
        }
        else {
            return (bet * 2);
        }
    }
}
