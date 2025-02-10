//Programmer: Timothy Wacker
//This program will simulate a game of Rock, Paper, Scissors

#include <random>
#include <iostream>
using namespace std;

char playerchoice()
{ 
  char player;
cout << "Type r for Rock, p for Paper, or s for Scissors. Type q to end game.";
cin >> player; 
  return player;
}


char computerchoice()
{ 
  random_device random;
  uniform_int_distribution<int> computerdis(1, 3);
  if (computerdis(random) == 1) {
    return 'r'; }
  else if (computerdis(random) == 2) {
    return 'p'; } 
  else if (computerdis(random) == 3) {
    return 's'; } 
  



char determineWinner(char player, char computer) 
  {
    if (player == computer) 
      return 'd';} 
    if (player == 'r' && computer == 's')
      return 'h'; }
        (player == 's' && computer == 'p')  
        (player == 'p' && computer == 'r')) {
        return 'h'; }
    else
      return 'c';
  }

//int displayresults()


int main()
{ 
char player=playerchoice();
char computer=computerchoice();
determineWinner(player, computer);
}