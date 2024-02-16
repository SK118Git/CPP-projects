// Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

int boardSize;
int difficultyVal;
int maxDiff = 5;
int bombQt;
int score = 0;
std::pair<int, int> clickCoords;
std::pair<int, int> bombCoords;


void gamend();
void checkforEmpty();
int randomnum(boardSize);


std::vector<std::vector<int>> initializeBoard() {
	std::cout << "Enter board Size";
	std::cin >> boardSize;
    std::vector<std::vector<int>> Board(boardSize, std::vector<int>(boardSize, 0));
    std::cout << "Enter difficulty value (from 1 to " << maxDiff <<  " )";
    std::cin >> difficultyVal; 
    for (int n = 1; n < maxDiff + 1; n++) {
        if (difficultyVal == n) {
            bombQt = (10*difficultyVal / n) - ((10*difficultyVal / n)%1);
            std::cout << "bomb qt is" << bombQt << std::endl;
        }
    }

    for (int n = 0; n < bombQt; n++) {
        int bombXcoord = randomnum(boardSize);
        int bombYcoord = randomnum(boardSize);
        Board[bombXcoord][bombYcoord] = 1;
        //std::cout << bombXcoord << bombYcoord << std::endl;
    }
    return Board;
}

int randomnum(boardSize) {
    return rand() % boardSize;
}

int main()
{
    int seed;
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        seed = rand();
        srand(seed);
    }
    
    //for (int i = 0; i < 20; i++) {
    //    std::cout << randomnum()<< std::endl;
    //};
  

    auto board = initializeBoard();
    for (int i = 0; i < boardSize; ++i)
    {
       for (int j = 0; j < boardSize; ++j)
        {
            std::cout << board[i][j] << "   LL   ";
        }
   
        std::cout << std::endl;
    }



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


//Player Input (Init):
//	set board size (AxA) and pick difficulty
//
//Init board:
//	initialize board (array)
//	set amount of bombs (depend on diffuclty)
//	for n in range (amount of bombs) --> pick a number between 0 and amount of rows-1, pick a numbert between 0 and amount of columns -1 --> place 1 bomb at coordinate and add coordinate to bombcoords[]
// 
//
//
//Gameplay loop:
//	player pick move type:
//	if movetype == flag: 
//		player input coordinates
//		if coordinates == bomb:
//			score ++
//		coordinates = 'F' 
//	if movetype == click:
//		player input coordinates
//		if coordinates == bomb:
//			gameend 
//		else if coordinates != bomb:
//			clickedTiles[].append(coordinates) 
//			
// 
//
//Refresh board:
//	for n in bombcoords[]:
//		a, b = bombcoords[n]
//		
// 
//  
// 
//			for j in range (2)
//				for k in range(2)
//					check coordinate[x+j-1][y+k-1]
//					if prior == 
//
//
//
//Gamend check:
//	if score == bomb number:
//		gameend 
//
//