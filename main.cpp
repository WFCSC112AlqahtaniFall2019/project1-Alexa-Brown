
/*Alexa Brown,
 * Project 1
 * CSC 112
 * due 9/12/19
 * */

#include <iostream>
#include <vector>
using namespace std;
#include <time.h>
#include <cstdlib>

int main() {

    int rows = 3;
    int randomCol;
    int randomRow;
    int userCol;
    int userRow;
    int numuserguesses = 0; //how many times the user has guessed a location
    bool guess = false; // if the user's guess is true or not
    vector<int> first(3, rows);
    vector<vector<int>> matrix{
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
    };
    // vector<vector<int>> matrix(3,first ); //creating the battleship field


    for (int i = 0; i < matrix.size(); i++) { //printing the original 3x3 matrix
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;

    //calculating random placement on the board
    srand(time(0));
    randomCol = rand() % 3 + 1;
    randomRow = rand() % 3 + 1;
    //the random numbers are outside of the loop so that they don't change throughout the game
    while (guess == false){ //allowing the game to continue as long as the user does not guess the correct location


    cout << "Where do you think the location is? Enter two numbers (row then column)" << endl;
    cin >> userCol; //allowing the user to guess which column
    cin >> userRow; //allowing the user to guess which row

    userCol = userCol - 1;//The matrices are in vectors from 0 to 2 so this keeps the numbers the same
    userRow = userRow - 1;
    if (userCol == randomCol) { //using a loop to see if the user's guess matches the randomly generated answers
        if (userRow == randomRow) {
            matrix[userCol][userRow] = 2;
            guess = true;
        }
    }

    cout << endl;
    cout << "Updated play board: (2 means you've selected the correct spot!)" << endl;
    for (int i = 0; i < matrix.size(); i++) { //printing the new 3x3 matrix
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
      numuserguesses = numuserguesses + 1;
}

  cout << "Number of user guesses during game: ";
    cout << numuserguesses << endl;

    return 0;
}