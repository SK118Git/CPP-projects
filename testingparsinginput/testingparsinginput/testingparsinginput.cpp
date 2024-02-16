#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void displayBoard();

int board[8][8]{
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
};


int main()
{
	std::string pieceColor, pieceType, piecePosLet, piecePosNum;
	std::cout << "Enter your pieceColor, pieceType, piecePosLet, piecePosNum separated by spaces: \n";
	//std::cin >> pieceColor >> pieceType >> piecePosLet >> piecePosNum;
	//std::cout << "Move is: " << pieceColor << " " << pieceType << " " << piecePosLet << " " << piecePosNum << '\n';
	displayBoard();
	return 0;
}


void displayBoard() {
	for (int i = 0; i < 8; i++) {
		std::cout << " \n |";
		for (int j = 0; j < 8; j++) {
			std::cout << board[i][j] << "|";
		}
	}
};