# RouletteSim

This is simulation program attempting to make a long-term profit from repeatedly placing outside/even bets on a roulette wheel. This program utilizes a doubling down strategy (sometimes called the [Martingale system](https://en.wikipedia.org/wiki/Martingale_(betting_system))) in an attempt to beat the house.


## How to use

In order to run this program, you can must clone this repository to a command line environment.  
The program can be compiled with the following command: `g++ -std=c++11 -g rouletteSim.cpp Player.cpp Player.h -o roulette.exe`  
Then the program is run by executing `./roulette.exe`  
The program will prompt for the gambler's budget, intended number of spins, and desired version of roulette. The program will repeatedly bet following the strategy detailed below until
```
1. The gambler falls into any amount of debt 
(will almost always occur from a very high stakes bet that totals more than the player's budget)
2. The gambler completes their intended number of spins
```  
The program will then output the player's final account balance and number of inteneded spins not played.

## The Strategy

* The gambler will start by placing the minimum bet of $1 on an even bet (red/black, high/low, even/odd).  
* All of these bets have a 47.37% to win in American roulette or 48.65% chance in European roulette, thus the option to choose your rules. (American roulette has one extra green 00 space, altering its odds)  
* If the gambler wins a spin, they keep the winnings and place a $1 even bet.  
* If the gambler loses a spin, they will place a $1 bet in an attempt to regain that immediate loss.  
* If the gambler loses more than one spin in a row, the gambler will double their bet each spin, so the next spin they win will recoup all losses from that losing streak.  

The gambler will only lose money if they lose n spins in a row in which `2^n >= budget`  
Therefore, a high enough starting budget should make the odds of suffering any losses increasingly unlikely.
