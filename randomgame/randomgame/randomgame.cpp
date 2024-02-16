// randomgame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//P1 bot:
//look at the board
//place at the center if possible, anywhere but mids 
//


//if board empty place at 1,1
//make a list with all empty boxes
//after every placement send back to beginning of function
//For every box in list:
//  if sum of every element in a row/column/diagonal == 2 then place there #by fdoing it like this it should automatically place for the first oneif multplie
//  if sum of every element in a row/column/diagonal == -2 then place there #by fdoing it like this it should automatically place for the first oneif multplie
//  if sum of every element in a row/column/diagonal == 1 then add to new list 
//      for every element in list:
//          count amount of rows/columns/diagonals whose sum == 1 and affect it to new list with same indice
//          for every element in list -1 , if [k]<[k+1], remove([k]) #like this at the end only one left !!count rows, columns, diag then antidiag
//                
//  else place randomly 
//
//



#include <iostream>
#include <list>
#include <iterator>
#include <set>
#include <vector>

void play();
void displayBoard();
void checkVictoryP1();
void checkVictoryP2();
void checkStalemate();
void replay();
void P1Move();
void P2Move();
void initializeBoard();
void initialmove();
void botP1Move();
void botP2Move();
void botP2FirstMove();

float board[3][3]{
        {0,0,0},
        {0,0,0},
        {0,0,0}   };


int hasMoved;
int botPlayedSecondMove;

int main()
{
    play();
    return 0;
}


void play() {
    int playerChoice;
    std::cout << "Please keep in mind that you must count from 0 to 2 throughout this game \n" << std::endl;
    std::cout << "Choose the mode you wish to play" << std::endl;
    std::cout << "Enter 1 for 2 human players" << std::endl;
    std::cout << "Enter 2 to play against AI" << std::endl;
    std::cin >> playerChoice;
    switch (playerChoice) {
    case 1:
        std::cout << "You picked 2 human players" << std::endl;
        system("Pause");
        initializeBoard();
        displayBoard();
        while (1 == 1) {
            system("cls");
            displayBoard();
            P1Move();
            system("Pause");
            system("cls");
            checkVictoryP1();
            checkStalemate();

            system("cls");
            displayBoard();
            P2Move();
            system("cls");
            checkVictoryP2();
            checkStalemate();
        };
        break;
    case 2:
        int playerNumber;
        std::cout << "You chose to play against AI" << std::endl;
        system("Pause");
        system("cls");
        std::cout << "Do you want to be first or second player?" << std::endl;
        std::cout << "Enter 1 to be first player" << std::endl;
        std::cout << "Enter 2 to be second player" << std::endl;
        std::cin >> playerNumber;
        if (playerNumber == 1) {
            std::cout << "You chose to be first player" << std::endl;
            system("Pause");
            system("cls");
            initializeBoard();
            displayBoard();

            P1Move();
            system("cls");
            displayBoard();
            botP2FirstMove();
            system("cls");
            displayBoard();

            while (1 == 1) {

                system("cls");
                displayBoard();
                P1Move();
                system("cls");
                checkVictoryP1();
                checkStalemate();

                system("cls");
                displayBoard();
                botP2Move();
                system("Pause");
                system("cls");
                checkVictoryP2();
                checkStalemate();



            }
        }
        else if (playerNumber == 2) {
            std::cout << "You chose to be second player" << std::endl;
            system("Pause");
            initializeBoard();
            initialmove();
            displayBoard();
            while (1 == 1) {

                system("cls");
                displayBoard();
                P2Move();
                system("cls");
                checkVictoryP2();
                checkStalemate();

                system("cls");
                displayBoard();
                botP1Move();
                system("Pause");
                system("cls");
                checkVictoryP1();
                checkStalemate();
            };
        }
        else {
            std::cout << "Incorrect choice, returning to menu..." << std::endl;
            system("Pause");
            play();
        };
        break;

    default:
        std::cout << "Incorrect choice, returning to menu..." << std::endl;
        system("Pause");
        play();
        break;
    };
}

void checkVictoryP1() {
    displayBoard();
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += board[i][j];
        };
        if (sum == 3) {
            std::cout << "Player 1 Victory \n" <<std::endl;
            replay();
        };
    };
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += board[j][i];
        };
        if (sum == 3) {
            std::cout << "Player 1 Victory \n" << std::endl;
            replay();
        };
    };
    if ((board[0][0] + board[1][1] + board[2][2] == 3) or (board[2][0] + board[1][1] + board[0][2] == 3)) {
        std::cout << "Player 1 Victory \n" << std::endl;
        replay();
    }
}



void checkVictoryP2() {
    displayBoard();
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += board[i][j];
        };
        if (sum == -3) {
            std::cout << "Player 2 Victory \n" << std::endl;
            replay();
        };
    };
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += board[j][i];
        };
        if (sum == -3) {
            std::cout << "Player 2 Victory \n" << std::endl;
            replay();
        };
    };
    if ((board[0][0] + board[1][1] + board[2][2] == -3) or (board[2][0] + board[1][1] + board[0][2] == -3)) {
        std::cout << "Player 2 Victory \n" << std::endl;
        replay();
    }
}



void checkStalemate() {
    int emptySpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0) {
                emptySpaces--;
            }
        }
    };
    if (emptySpaces == 0) {
        std::cout << "Stalemate has been achieved." << std::endl;
        replay();
    };
}

void displayBoard() {
    std::string dispBoard[3][3]{
        {"", "", ""},
        {"", "", ""},
        {"", "", ""}
    };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 1) {
                dispBoard[i][j] = "X";
            }
            else if (board[i][j] == -1) {
                dispBoard[i][j] = "O";
            }
            else if (board[i][j] == 0) {
                dispBoard[i][j] = " ";
            };
        };
    };
    for (int i = 0; i < 3; i++) {
        std::cout << " | ";
        for (int j = 0; j < 3; j++) {
            std::cout << dispBoard[i][j] << " | ";
        };
        std::cout << "\n";
    };
}

void replay() {
    std::string choice;
    std::cout << "Do you want to play again? \nEnter 'yes' or 'no': ";
    std::cin >> choice;
    if (choice == "yes") {
        system("cls");
        play();
    }
    else if (choice == "no") {
        std::cout << "Thank you for playing! \nPress enter to EXIT" << std::endl;
        system("Pause");
        exit(0);
    }
    else {
        std::cout << "Incorrect input" << std::endl;
        replay();
    };

}


void P1Move() {
    int rown1, coln1;
    std::cout << "Player 1: ";
    std::cout << "Enter the row you wish to select: ";
    std::cin >> rown1;
    std::cout << "Enter the column you wish to select: ";
    std::cin >> coln1;
    if (board[rown1][coln1] == 0) {
        board[rown1][coln1] = 1;
    }
    else {
        std::cout << "Incorrect choice. \nPlease select a box that hasn't already been picked" << std::endl;
        P1Move();
    };
    
}


void P2Move() {
    int rown2, coln2;
    std::cout << "Player 2: ";
    std::cout << "Enter the row you wish to select: ";
    std::cin >> rown2;
    std::cout << "Enter the column you wish to select: ";
    std::cin >> coln2;
    if (board[rown2][coln2] == 0) {
        board[rown2][coln2] = -1;;
    }
    else {
        std::cout << "Incorrect choice. \nPlease select a box that hasn't already been picked" << std::endl;
        P2Move();
    };
}

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 0;
        }
    };
}



void initialmove() {
    int emptySpaces = 9;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0) {
                emptySpaces--;
            }
        }
    };


    if (emptySpaces == 9) {
        board[1][1] = 1;
        hasMoved += 1;
    }


    else {
        std::cout << "First move already played" << std::endl;
    };

}

std::list<std::pair<int,int>> checkPossibleMoves() {
    std::list<std::pair<int, int>> possibleMoves;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                std::pair<int, int> couple = { i, j };
                possibleMoves.push_front(couple);
            }
        }
    }
    return possibleMoves;
}

void botP1Move() {
    hasMoved = 0;
    while (hasMoved < 1) {
        std::list<int> rangeC;
        std::list<std::pair<int, int>> possibleMoves = checkPossibleMoves();
        std::set<std::pair<int, int>> movesWorth1;
        

        if (possibleMoves.size() == 1) {
            std::pair<int, int> onlyLeft = possibleMoves.front();
            int RowCoor = onlyLeft.first;
            int ColCoor = onlyLeft.second;
            board[RowCoor][ColCoor] = 1;
        };

        for (auto i : possibleMoves) {
            int sumR = 0;
            int sumC = 0;
            int sumD = 0;
            int sumAD = 0;
            int abzero = 0;
            int coordinateRow = i.first;
            int coordinateCol = i.second;
            for (int i_2 = 0; i_2 < 4; i_2++) {
                if (i_2 == 0) { //row sum
                    for (int i_3 = 0; i_3 < 3; i_3++) {
                        sumR += board[coordinateRow][i_3];
                    };
                    if (sumR == 2) {
                        board[coordinateRow][coordinateCol] = 1;
                        hasMoved += 1;
                        return;
                    }
                    else if (sumR == -2) {
                        board[coordinateRow][coordinateCol] = 1;
                        hasMoved += 1;
                        return;
                    }
                    else if (sumR == 1) {
                        movesWorth1.insert(i);
                    }
                    else if (sumR == 0) {
                        abzero += 1;
                        if (movesWorth1.size() > 2) {
                            if (movesWorth1.count(i) > 1) {
                                movesWorth1.erase(i);
                            };
                        };
                    }

                }
                else if (i_2 == 1) { //column sum
                    for (int i_3 = 0; i_3 < 3; i_3++) {
                        sumC += board[i_3][coordinateCol];
                    };
                    if (sumC == 2) {
                        board[coordinateRow][coordinateCol] = 1;
                        hasMoved += 1;
                        return;
                    }
                    else if (sumC == -2) {
                        board[coordinateRow][coordinateCol] = 1;
                        hasMoved += 1;
                        return;
                    }
                    else if (sumC == 1) {
                        movesWorth1.insert(i);
                    }
                    else if (sumC == 0) {
                        abzero += 1;
                        if (movesWorth1.size() > 2) {
                            if (movesWorth1.count(i) > 1) {
                                movesWorth1.erase(i);
                            };
                        };
                    }

                }
                else if (i_2 == 2) { //diag sum 
                    if (coordinateRow == coordinateCol) {
                        sumD = board[0][0] + board[1][1] + board[2][2];
                        if (sumD == 2) {
                            board[coordinateRow][coordinateCol] = 1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumD == -2) {
                            board[coordinateRow][coordinateCol] = 1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumD == 1) {
                            movesWorth1.insert(i);
                        }
                        else if (sumD == 0) {
                            abzero += 1;
                            if (movesWorth1.size() > 2) {
                                if (movesWorth1.count(i) > 1) {
                                    movesWorth1.erase(i);
                                };
                            };
                        }
                    }

                }
                else if (i_2 == 3) { //antediag sum
                    if ((coordinateCol == coordinateRow == 1) or (coordinateRow == 0 and coordinateCol == 2) or (coordinateRow == 2 and coordinateCol == 0)) {
                        sumAD = board[2][0] + board[1][1] + board[0][2];
                        if (sumAD == 2) {
                            board[coordinateRow][coordinateCol] = 1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumAD == -2) {
                            board[coordinateRow][coordinateCol] = 1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumAD == 1) {
                            movesWorth1.insert(i);
                        }
                        else if (sumAD == 0) {
                            abzero += 1;
                            if (movesWorth1.size() > 2) {
                                if (movesWorth1.count(i) > 1) {
                                    movesWorth1.erase(i);
                                };
                            };
                        }
                    }
                }

            };
            if ((abzero >= possibleMoves.size()) and (abzero >= 4)) {
                board[coordinateRow][coordinateCol] = 1;
                hasMoved += 1;
                return;
            };
        };
        std::vector<std::pair<int, int>> vectorMoves(movesWorth1.begin(), movesWorth1.end());
        if (vectorMoves.size() > 0) {
            std::pair<int, int> tempMove = vectorMoves.front();
            board[tempMove.first][tempMove.second] = 1;
            hasMoved += 1;
            return;
        }
        else {
            std::cout << "empty vector" << std::endl;
            exit(0);
        }
    }
}



void botP2FirstMove() {
    if (board[1][1] == 1) {
        board[0][0] = -1;
        botPlayedSecondMove = 1;
        hasMoved += 1;
    }
    else if ((board[0][0] == 1) or (board[0][2] == 1) or (board[2][0] == 1) or (board[2][2] == 1)) {
        board[1][1] = -1;
        botPlayedSecondMove = 1;
        hasMoved += 1;
    };
}



void botP2Move() {
    hasMoved = 0;
    if (botPlayedSecondMove == 1) {
        while (hasMoved < 1) {
            std::list<int> rangeC;
            std::list<std::pair<int, int>> possibleMoves = checkPossibleMoves();
            std::set<std::pair<int, int>> movesWorth1;

            if (possibleMoves.size() == 1) {
                std::pair<int, int> onlyLeft = possibleMoves.front();
                int RowCoor = onlyLeft.first;
                int ColCoor = onlyLeft.second;
                board[RowCoor][ColCoor] = -1;
            };
            for (auto i : possibleMoves) {
                int sumR = 0;
                int sumC = 0;
                int sumD = 0;
                int sumAD = 0;
                int abzero = 0;
                int coordinateRow = i.first;
                int coordinateCol = i.second;
                for (int i_2 = 0; i_2 < 4; i_2++) {
                    if (i_2 == 0) { //row sum
                        for (int i_3 = 0; i_3 < 3; i_3++) {
                            sumR += board[coordinateRow][i_3];
                        };
                        if (sumR == -2) {
                            board[coordinateRow][coordinateCol] = -1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumR == 2) {
                            board[coordinateRow][coordinateCol] = -1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumR == -1) {
                            movesWorth1.insert(i);
                        }
                        else if (sumR == 0) {
                            abzero += 1;
                            if (movesWorth1.size() > 2) {
                                if (movesWorth1.count(i) > 1) {
                                    movesWorth1.erase(i);
                                };
                            };
                        }

                    }
                    else if (i_2 == 1) { //column sum
                        for (int i_3 = 0; i_3 < 3; i_3++) {
                            sumC += board[i_3][coordinateCol];
                        };
                        if (sumC == -2) {
                            board[coordinateRow][coordinateCol] = -1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumC == 2) {
                            board[coordinateRow][coordinateCol] = -1;
                            hasMoved += 1;
                            return;
                        }
                        else if (sumC == -1) {
                            movesWorth1.insert(i);
                        }
                        else if (sumC == 0) {
                            abzero += 1;
                            if (movesWorth1.size() > 2) {
                                if (movesWorth1.count(i) > 1) {
                                    movesWorth1.erase(i);
                                };
                            };
                        }

                    }
                    else if (i_2 == 2) { //diag sum 
                        if (coordinateRow == coordinateCol) {
                            sumD = board[0][0] + board[1][1] + board[2][2];
                            if (sumD == -2) {
                                board[coordinateRow][coordinateCol] = -1;
                                hasMoved += 1;
                                return;
                            }
                            else if (sumD == 2) {
                                board[coordinateRow][coordinateCol] = -1;
                                hasMoved += 1;
                                return;
                            }
                            else if (sumD == -1) {
                                movesWorth1.insert(i);
                            }
                            else if (sumD == 0) {
                                abzero += 1;
                                if (movesWorth1.size() > 2) {
                                    if (movesWorth1.count(i) > 1) {
                                        movesWorth1.erase(i);
                                    };
                                };
                            }
                        }

                    }
                    else if (i_2 == 3) { //antediag sum
                        if ((coordinateCol == 1 && coordinateRow == 1) || (coordinateRow == 0 && coordinateCol == 2) || (coordinateRow == 2 && coordinateCol == 0)) {
                            sumAD = board[2][0] + board[1][1] + board[0][2];
                            if (sumAD == -2) {
                                board[coordinateRow][coordinateCol] = -1;
                                hasMoved += 1;
                                return;
                            }
                            else if (sumAD == 2) {
                                board[coordinateRow][coordinateCol] = -1;
                                hasMoved += 1;
                                return;
                            }
                            else if (sumAD == -1) {
                                movesWorth1.insert(i);
                            }
                            else if (sumAD == 0) {
                                abzero += 1;
                                if (movesWorth1.size() > 2) {
                                    if (movesWorth1.count(i) > 1) {
                                        movesWorth1.erase(i);
                                    };
                                };
                            }
                        }
                    }

                };
                if ((abzero >= possibleMoves.size()) and (abzero >= 4)) {
                    board[coordinateRow][coordinateCol] = -1;
                    hasMoved += 1;
                    return;
                };
            };
            std::vector<std::pair<int, int>> vectorMoves(movesWorth1.begin(), movesWorth1.end());
            if (vectorMoves.size() > 0) {
                std::pair<int, int> tempMove = vectorMoves.front();
                board[tempMove.first][tempMove.second] = -1;
                hasMoved += 1;
                return;
            }
            else {
                std::cout << "empty vector" << std::endl;
                exit(0);
            }
        }
    };
}

