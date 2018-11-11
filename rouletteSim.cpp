#include "Player.h"
#include <string>
#include <iostream>
#include <stdlib.h>

int main(){
    std::string budget, spins, american;

    std::cout<<"Enter your budget"<<std::endl;
    std::cin>>budget;
    int budgetInt = std::stoi(budget);
    std::cout<<"Enter the number of spins you want to play"<<std::endl;
    std::cin>>spins;
    int spinsInt = std::stoi(spins);
    std::cout<<"Enter 1 for American roulette, 0 for European roulette"<<std::endl;
    std::cin>>american;
    bool americanBool = std::stoi(american);
    Player gambler(budgetInt, spinsInt, americanBool);
    gambler.startPlaying();
    std::cout<<"Final balance was: ";
    std::cout<< gambler.balance <<std::endl;
    std::cout<<"Total spins not used: ";
    std::cout<< gambler.spins <<std::endl;



    return 1;
}
