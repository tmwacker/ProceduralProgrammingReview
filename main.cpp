//Programmer: Timothy Wacker
//This program will simulate a game of Rock, Paper, Scissors

#include <iostream>
#include <random>

using namespace std;

//get players input
char playerChoice() { 
    char player;
    while (true) {
        cout << "Type r for Rock, p for Paper, or s for Scissors. Type q to end game: ";
        cin >> player;
        player = tolower(player); 

        if (player == 'r' || player == 'p' || player == 's' || player == 'q') {
            return player; 
        }
        cout << "Invalid input. Please enter r, p, s, or q.\n"; 
    }
}

// computers rock paper or scissors
char computerChoice() { 
    random_device random;
    uniform_int_distribution<int> computerdis(1, 3);
    int choice = computerdis(random);

    if (choice == 1) return 'r'; 
    if (choice == 2) return 'p'; 
    return 's'; 
}

//Determine who wins
char determineWinner(char player, char computer) {
    if (player == computer) {
        return 'd'; // Draw
    }
    if ((player == 'r' && computer == 's') || 
        (player == 's' && computer == 'p') || 
        (player == 'p' && computer == 'r')) {
        return 'h'; 
    }
    return 'c'; 
}

//display results after each round
void displayResults(char player, char computer, char winner, int humanScore, int computerScore) {
    cout << "You chose: " << player << "\n";
    cout << "Computer chose: " << computer << "\n";

    if (winner == 'h') {
        cout << "You win this round!\n";
    } else if (winner == 'c') {
        cout << "Computer wins this round!\n";
    } else {
        cout << "It's a draw!\n";
    }

    cout << "Current Score -> You: " << humanScore << " | Computer: " << computerScore << "\n";
}

// Function to display the final tournament results
void displayFinalResults(int humanScore, int computerScore) {
    cout << "\nFINAL SCORE - You: " << humanScore << " | Computer: " << computerScore << "\n";

    if (humanScore > computerScore) {
        cout << "Congratulations! You won the tournament!\n";
    } else if (computerScore > humanScore) {
        cout << "Computer won the tournament.\n";
    } else {
        cout << "The tournament ended in a draw!\n";
    }
}

int main() { 
    int humanScore = 0, computerScore = 0;

    while (true) {
        char player = playerChoice();
        if (player == 'q') break; // Exit loop

        char computer = computerChoice();
        char winner = determineWinner(player, computer);

        if (winner == 'h') {
            humanScore++;
        } else if (winner == 'c') {
            computerScore++;
        }
        displayResults(player, computer, winner, humanScore, computerScore);
    }
    displayFinalResults(humanScore, computerScore);

    return 0;
}