#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

bool checkWin(char XorO, char array[4][4]);
bool checkTie(char array[4][4]);
void clearBoard(char array[4][4]);
void printBoard(char array[4][4]);

int main () {
  char board[4][4];
  board [0][0] = ' ';
  board [0][1] = '1';
  board [0][2] = '2';
  board [0][3] = '3';
  board [1][0] = 'a';
  board [2][0] = 'b';
  board [3][0] = 'c';
  int xWinCount = 0;
  int oWinCount = 0;
  bool stillPlaying = true;
  char playerTurn;
  char playAgain;
  int turn = 0;
  clearBoard(board);
  cout << "Welcome to TicTacToe! X moves first, please enter a coordinate value (Ex: a1, b2, c3)";
  while (stillPlaying == true) { 
    char input[2];
      cin >> input; 
    if ((input[0] >= 97 && input[0] <= 99) && (input[1] >= 49 && input[1] <= 51)) {
      int row = input[0] - 96;
      int column = input[1] - 48;
      if (turn % 2 == 0 && board[row][column] == ' ') {
      board[row][column] = 'X';
      playerTurn = 'X';
      turn++;
      }
      else if (turn % 2 == 1 && board[row][column] == ' ') {
	board[row][column] = 'O';
	playerTurn = 'O';
	turn++;
      }
      else {
	    cout << "You have entered a coordinate where an X or an O already exists. Please Enter a Valid Coordinate.";	    
      }	      
      printBoard(board);
      if (checkWin(playerTurn, board) == true) {
	if (playerTurn == 'X') {
	  xWinCount++;
	  cout << playerTurn << " wins! " << playerTurn << " has " << xWinCount << " wins. O has " << oWinCount << " wins. Play Again? Enter y or n.";
	  cin >> playAgain;
	  if (playAgain == 'y') {
	    turn = 0;
	    clearBoard(board);
	  }
	  else {
	    break;
	  }
	}
	else {
	 oWinCount++;
	 cout << playerTurn << " wins! " << playerTurn << " has " << oWinCount << " wins. X has" << xWinCount << " wins. Play Again? Enter y or n."; 
	 cin >> playAgain;
	  if (playAgain == 'y') {
	    turn = 0;
	    clearBoard(board);
	  }
	  else {
	    break;
	  }
	}
      }
      if (checkTie(board) == true) {
	cout << "This Game is a Draw, X has " << xWinCount << " wins." << " O has " << oWinCount << " wins. Play Again? Enter y or n.";
	cin >> playAgain;
	  if (playAgain == 'y') {
	    turn = 0;
	    clearBoard(board);
	  }
	  else {
	    break;
	  }
      }
    }
    else {
      cout << "Please Enter A Valid Input. Ex: a1, b2, c3 \n";
      board [0][0] = ' ';
      board [0][1] = '1';
      board [0][2] = '2';
      board [0][3] = '3';
      board [1][0] = 'a';
      board [2][0] = 'b';
      board [3][0] = 'c';
    }
  } 
  
  
  return 0;
}

bool checkWin(char XorO, char array[4][4]) {
  if (array[1][1] == XorO && array[1][2] == XorO && array[1][3] == XorO) {
    return true; 
  }
  if (array[2][1] == XorO && array[2][2] == XorO && array[2][3] == XorO) {
    return true; 
  }
  if (array[3][1] == XorO && array[3][2] == XorO && array[3][3] == XorO) {
    return true; 
  }
  if (array[1][1] == XorO && array[2][1] == XorO && array[3][1] == XorO) {
    return true; 
  }
  if (array[1][2] == XorO && array[2][2] == XorO && array[3][2] == XorO) {
    return true; 
  }
  if (array[1][3] == XorO && array[2][3] == XorO && array[3][3] == XorO) {
    return true; 
  }
  if (array[1][1] == XorO && array[2][2] == XorO && array[3][3] == XorO) {
    return true; 
  }
  if (array[1][3] == XorO && array[2][2] == XorO && array[3][1] == XorO) {
    return true; 
  }
  
  return false; 
    
}

void clearBoard(char array[4][4]) {
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      array[i][j] = ' '; 
  }
}
}

void printBoard(char array[4][4]) {
  cout << endl << array[0][0] << array[0][1] << array[0][2] << array[0][3] << endl;
  cout << array[1][0] << array[1][1] << array[1][2] << array[1][3] << endl;
  cout << array[2][0] << array[2][1] << array[2][2] << array[2][3] << endl;
  cout << array[3][0] << array[3][1] << array[3][2] << array[3][3] << endl;
}

bool checkTie(char array[4][4]) {
   for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if (array[i][j] == ' ') {
      return false;
      }
  }
}
   return true; 
}
