
/*Alexa Brown, Project 1, CSC 112, due 9/12/19*/

#include <iostream>
#include <vector>
using namespace std;
#include <ctime>
#include <cstdlib>

int main() {

    int rows = 3;
    int randomCol;
    int randomRow;
    int userCol;
    int userRow;
    vector<int> first (3, rows);
    vector<vector<int>> matrix(3,first ); //creating the battleship field

    srand(time(0));
     randomCol = rand() % 3 + 1;
     randomRow = rand() % 3 + 1;


     cout << "Where do you think the location is? Enter two numbers (row and column)"<< endl;
     cin >> userCol;
     cin >> userRow;
     if (userCol == randomCol){
         if (userRow == randomRow){
             cout << "hi";
         }
     }
     cout << "hello";


    return 0;
}