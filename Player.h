#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    int budget;
    bool positive;
    bool american;
    double odds;
public:
    Player();
    Player(int budg, int spin, bool amer);
    int balance;
    int spins;
    const double americanOdds = .4737;
    const double europeanOdds = .4865;
    void startPlaying();
    int spinTheWheel(int bet, bool &justLost);
    float randmm(float min, float max);
};
#endif
