#include<iostream>
#include <cstdlib>    //library for pause
using namespace std;
int main()
{
    setlocale(LC_ALL, ""); //for getting cs-CZ signs - compatible with CZ original
    int number_of_matches = 0;
    int player1 = 0;
    int player2 = 0;
    int x = 0;
    bool player_onround = false;   //by using true and false we can later distinguish when player 1 and player 2 are playing

    if (number_of_matches == 0) {    //if the number of matches is not entered, the program will prompt the user to enter the default number for the game
        cout << "First players, enter the default number of matches (integer): \n";
        cin >> number_of_matches;  //sets the default number of matches
        cout << "Thank you, the game can begin! \n";
    }
    while (player_onround >= 2) {   //if 2 or more matches remain, the game continues

        cout << (player_onround ? "1st player is on the round:\n" : "2nd player is on the round:\n"); //if player status is true - plays first, if false plays second
        cout << " How much do you take matches?\n";
        cin >> x;
        // write into the variable x, from which the matches will be subtracted and the number of matches taken by the player in hrac1 and player2 will be added
        if (x > number_of_matches) {
            cout << "ERROR: You are trying to remove more matches than you have :D, try again!" << endl;
            x = 0; //if the player enters the wrong value, nothing will be done with the entered value - the input will be reset

        }
        else if (x <= 0) {
            cout << "ERROR: You entered an invalid number of matches to remove :/, try again!" << endl;
            x = 0;  //if the player enters the wrong value, nothing will be done with the entered value - the input will be reset
        }
        else if (x == number_of_matches) {
            cout << "ERROR: You entered the number of matches equal to the total number of matches :P, try again!" << endl;
            x = 0;
        }
        number_of_matches -= x;  // subtract the specified number of matches from the default value
        cout << "You still have " << number_of_matches << " matches!" << endl;

        if (player_onround == false) {
            player2 += x;   //players 2 I will put the number of matches entered into the statistics
            player_onround = true;  //switch the player status so that the first player can play now (if true - the first player plays, if false the second player plays - sub operator at the beginning)
            x = 0; //zero the input for another player (not to add the value of the previous player | not to subtract the value of matches + another player)
        }
        else {
            player1 += x;                //same as player 2, only now for player 1
            player_onround = false;
            x = 0;
        }
    }
    cout << "\n Results:" << endl;
    cout << "Player1: " << player1 << " matches" << endl;   //puts the number of matches from the player variables
    cout << "Player2: " << player2 << " matches" << endl;
    cout << endl;
    if (player1 > player2) {                                      //list who won according to conditions
        cout << "The first player wins! Congratulations! ;)" << endl;   //if player 1 had a higher score, we congratulate him
    }
    else if (player1 < player2) {   //if the 2nd player had a higher score (more removed matches) - congratulations
        cout << "Second player wins! Congratulations! ;)" << endl;
    }
    else if (player1 == player2) {   //If Player 1 and Player 2 have the same number of points - Draw is declared
        cout << "Tie!" << endl;
    }
    system("pause");
}