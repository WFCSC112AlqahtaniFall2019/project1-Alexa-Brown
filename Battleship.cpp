
/*Alexa Brown,
 * Project 1
 * CSC 112
 * due 9/12/19
 * Using vectors and loops to create a mini game of battleship
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
    vector<vector<char>> matrix{ //creating the battleship field
            {'?' , '?', '?'},
            {'?' , '?', '?'},
            {'?' , '?', '?'}
    };


cout << "This is the game board:" << endl;
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



    cout << "Where do you think the battleship is? Enter two numbers between 1 and 3 (row then column)" << endl;
    cin >> userCol; //allowing the user to guess which column
    cin >> userRow; //allowing the user to guess which row

    if (userCol > 3 || userCol < 0 || userRow > 3 || userRow < 0){
        cout << "Please start over and enter a guess within the range." << endl;
        break; //if a user's guess is out of the range, they will have to start over the game
    }


    userCol = userCol - 1;//The matrices are in vectors from 0 to 2 so this keeps the numbers the same
    userRow = userRow - 1;


    if (userCol != randomCol || userRow != randomRow) { //using a loop to see if the user's guess matches the randomly generated answers
            matrix[userCol][userRow] = '@' ;
            guess = false;
        }


    if (userCol == randomCol) { //using a loop to see if the user's guess matches the randomly generated answers
        if (userRow == randomRow) {
            matrix[userCol][userRow] = '!';
            guess = true;
        }
    }


    cout << endl;
    cout << "Updated play board: (@ is where you've guessed and ! means you've selected the correct spot!)" << endl;
    for (int i = 0; i < matrix.size(); i++) { //printing the new 3x3 matrix since it was updated
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
      numuserguesses = numuserguesses + 1;
      //increasing the number of guesses to be outputted at the end

} //end of while loop

//this section outputs after the user guesses correctly

        cout << "Number of user guesses during game: ";
        cout << numuserguesses << endl;
        //showing the user how many times they guessed before finishing the program

    return 0;
}