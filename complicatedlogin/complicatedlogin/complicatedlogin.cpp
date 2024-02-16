// complicatedlogin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <string> 
#include <fstream>
using namespace std;

void login();
void registration();

int main()
{
    int choice;
    cout << "\t \t \t ______________________________________________________________ \n\n";
    cout << "\t \t \t                      Welcome to login page \n \n";
    cout << "\t \t \t ____________________________ Menu ____________________________ \n";
    cout << endl;
    cout << endl;
    cout << "\t\t\t Press 1 to LOGIN                       /" << endl;
    cout << "\t\t\t Press 2 to REGISTER                    /" << endl;
    cout << "\t\t\t Press 3 to EXIT                        /" << endl;
    cout << "n \t\t\t Please enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            login();
            break;
        case 2: 
            registration();
            break;
        case 3:
            cout << "\t\t\t Exiting \n \n";
            break;
        default:
            system("cls");
            cout << "\t\t\t Please select an option \n \n";
            main();
    }
}

void login() {
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Enter your username and password: \n";
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    while (input>>id>>pass) {
        if ((id == userId) && (pass == password)) {
            count = 1;
            system("cls");
        }
    }
    input.close();
     
    if (count == 1) {
        cout << userId << "\n Your LOGIN is successfull";
        main();
    }
    else {
        cout << "\n LOGIN ERROR";
        main();
    }
}

void registration() {
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter your USERNAME: ";
    cin >> ruserId;
    cout << "\t\t\t Enter your PASSWORD: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "\n \t\t\t Your REGISTRATION is successfull. \n";
    main();
}

