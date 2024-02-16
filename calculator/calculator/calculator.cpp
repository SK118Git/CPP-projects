// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdarg>
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */
#include <vector>
#include <typeinfo>

std::vector<double> choseNumbers();
double addition(std::vector<double> additionVector);
double substraction(std::vector<double> substractionVector);
double multiplication(std::vector<double> multiplicationVector);
double division(std::vector<double> divisionVector);
void choicemaking();
void retry();
void menu();

/*
template<class... Args>
void print(Args... args)
{
    (std::cout << ... << args << "\n";
}
*/

void printargs(int arg_count, ...) { //if different type of data
    int i,val, sizel;
    va_list vl; // va_list is a type to hold information about variable arguments
    va_start(vl, arg_count); //Requires the last fixed parameter (to get the address
    for (i = 0; i < arg_count; i++) {
        val = va_arg(vl, int); //Requires the type to cast to. Increments ap to the next argument.
        std::cout << val<< std::endl;
    }
    va_end(vl);
    return;
};

void printargs2(std::vector<int> nameVector) {
    int n = nameVector.size()-1;
    for (int i = 0; i <= n; i++) {
        std::cout << nameVector[i] << std::endl;
    }
    return;
};

int main()
{
    //printargs(5, 1, 2, 3, 4, 8);
    //printargs2({1,3,5,6,8});
    menu();
    choicemaking();
    return 0;

}


std::vector<double> choseNumbers() {
    std::vector<double> chosenNumbers;
    int b = 1;
    int c=0;
    int tempc;
    double number;
    while (b != 0) {
        c++;
        std::string s = std::to_string(c);
        std::cout << "Choose your " << s << "th number: ";
        std::cin >> number;
        chosenNumbers.push_back(number);
        std::cout << "Do you want to stopping including more numbers?\nEnter 0 if so: ";
        std::cin >> b;
        if (!std::cin) {
            std::cout << "Bad value!";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> b;
        }
        //std::cout << "Didn't enter 0, continuing number picking." << std::endl;
    };
    return chosenNumbers;
}

void menu() {
    std::cout << "\t \t ______________________ Welcome to this calculator ______________________" << std::endl;
    std::cout << "\n \t \t ______________ Select the type of operation you wish to do ______________" << std::endl;
    std::cout << "\n \n \t \t Enter 1 for addition" << std::endl;
    std::cout << "\t \t Enter 2 for substraction" << std::endl;
    std::cout << "\t \t Enter 3 for mutliplication" << std::endl;
    std::cout << "\t \t Enter 4 for division" << std::endl;
    return;
}


double addition(std::vector<double> additionVector){
    double sum =0;
    int n = additionVector.size() - 1;
    for (int i = 0; i <= n; i++) {
        sum += additionVector[i];
    }
    return sum;
}

double substraction(std::vector<double> substractionVector){
    double diff = 0;
    int n = substractionVector.size() - 1;
    for (int i = 0; i <= n; i++) {
        diff -= substractionVector[i];
    }
    return diff;
}


double multiplication(std::vector<double> multiplicationVector){
    double prod = 1;
    int n = multiplicationVector.size() - 1;
    for (int i = 0; i <= n; i++) {
        prod *= multiplicationVector[i];
    }
    return prod;
}

double division(std::vector<double> divisionVector){
    double div = 1;
    int n = divisionVector.size() - 1;
    for (int i = 0; i <= n; i++) {
        if (divisionVector[i] == 0) {
            std::cout << "Error division by 0 please try again" << std::endl;
            choicemaking();
        };
    };
    div = divisionVector[0];
    for (int i = 1; i <= n; i++) {
        div /= divisionVector[i];
    }
    return div;
}

void retry() {
    std::cout << "Do you want to do another calculation of this type or of another?" << std::endl;
    std::string yn;
    std::cin >> yn;
    if ((yn == "y") or (yn == "yes")) {
        system("Pause");
        system("cls");
        menu();
        choicemaking();
    }
    else if ((yn == "n") or (yn == "no")) {
        std::cout << "Thank you for using this calculator";
        exit(0);
    }
    else {  
        std::cout << "Error, incorrect choice. \n";
        retry();
    }

}

void choicemaking() {
    int choice;
    std::vector<double> picks;
    std::cout << "\n \t \t Your choice: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        system("Pause");
        system("cls");
        std::cout << "You chose addition" << std::endl;
        std::cout << "Please select which numbers you which to sum" << std::endl;
        picks = choseNumbers();
        std::cout << "\n";
        std::cout << "The result is " << addition(picks) << std::endl;
        retry();
        break;
        
    case 2:
        system("Pause");
        system("cls");
        std::cout << "You chose substraction" << std::endl;
        std::cout << "Please select which numbers you which to substract" << std::endl;
        picks = choseNumbers();
        std::cout << "\n";
        std::cout << "The result is " << substraction(picks) << std::endl;
        retry();
        break;

    case 3:
        system("Pause");
        system("cls");
        std::cout << "You chose multiplication" << std::endl;
        std::cout << "Please select which numbers you which to multiply" << std::endl;
        picks = choseNumbers();
        std::cout << "\n";
        std::cout << "The result is " << multiplication(picks) << std::endl;
        retry();
        break;
    case 4:
        system("Pause");
        system("cls");
        std::cout << "You chose division" << std::endl;
        std::cout << "Please select which numbers you which to divide" << std::endl;
        picks = choseNumbers();
        std::cout << "\n";
        std::cout << "The result is " << division(picks) << std::endl;
        retry();
        break;

    default:
        std::cout << "\n \t \t Incorrect choice, please try again."<< std::endl;
        choicemaking();
        break;
    }; 
 }