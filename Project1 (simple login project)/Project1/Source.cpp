#include <iostream>;
#include <fstream>;
#include <string>

using namespace std;

string username;
string password;

void registerfunction() {
	cout << "\n \n You picked register \n \n Enter your username ";
	cin >> username;
	cout << "\n Enter your password ";
	cin >> password;
};

bool checkusername(string username, string password) {
	bool verification;
	cout << "\n \n Enter your username \n";
	string enteredUsername;
	cin >> enteredUsername;
	cout << "\n \n Enter your password \n";
	string enteredPassword;
	cin >> enteredPassword;
	if ((enteredUsername == username) && (enteredPassword == password)) {
		verification = true;
	}
	else {
		cout << "Incorrect Username or password";
		verification = false;
	};
	return verification; 
}


int main() {
	int choice;
	cout << " Pick 1 to register \n Pick 2 to login \n \n";
	cin >> choice;
	if (choice == 1) {
		registerfunction();
		main();
	};
	if (choice == 2) {
		if (checkusername(username, password) == true) {
			cout << "Correct username and password";
		}
		else {
			cout << "Try again" ;
		};
	};
};
