#include <iostream> 
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime> //used to seed rand
#include <vector> // used to replace an array of size depending on user entered parameters 
#include <iterator> //maybe used in the template for cout a whole vector (not sure) 
#include <random> //i forgot wether or not i kept the relevant code below
#include <stdlib.h> //used for exit
#include <fstream>

using namespace std;


//Declaring functions
int rand1to10(); 
double rand0to1();
int randfromto(int a, int b);
double rlyrand();
void repeatroll(int x, int y);

//Tool to cout whole vectors
template <typename T>
std::ostream& operator<<(std::ostream& output, std::vector<T> const& values)
{
	for (auto const& value : values)
	{
		output << value << std::endl;
	}
	return output;
}

int main() {
	srand((unsigned int)time(NULL));  //seeding
	//int x, y; 
	//cout << "Pick your lowerbound: ";
	//cin >> x;
	//cout << "Pick your upperbound (not included): ";
	//cin >> y;
	//cout << "Final number = " << randfromto(x, y) << endl;
	//repeatroll(x,y);
	ofstream file("C:\\Users\\sasha\\OneDrive\\Desktop\\gnuplotdata\\testing.txt");
	string text = "test 2";
	for (int k = 0; k < 100; k++) {
		int randF = randfromto(5,10);
		file << randF << endl;
	}
	file.close();
	return 0;
};



	/* keeping this around in case i want to use it 
	std::mt19937_64 generator;
	std::uniform_int_distribution<int> distribution(1, 1000);
	int dice_roll = distribution(generator);  // generates number in the range 1..6
	cout << dice_roll;
	*/

int rand1to10() { //generates a random number from 1 to 10
	return (rand() % 10) + 1;
};

double rlyrand() { //generates a more random number than rand by executing rand a random amount of times
	double RRand;
	int q = rand1to10();
	for (int k = 0; k < q; k++) {
		RRand = rand();
	};
	return RRand;
};

double rand0to1() { //random number generator from 0 to 1
	return rlyrand() / (RAND_MAX + 1.0);
};

int randfromto(int a, int b) { //random number generator from a to b-1 (inclusive) 
	vector <int> selectedRange; 
	int result = 12345; //Error indicator
	double roll = rand0to1();

	for (int k = a; k < b; k++) { //fill the vector with all integers in the range [a,b-1]
		selectedRange.push_back(k);
	};

	int posFinal = selectedRange.size() - 1; 

	for (float c = 0; c <= posFinal; c++) { 
		if ((roll >= c/(posFinal+1)) && (roll < (c+1)/(posFinal+1))) {
			result = selectedRange[c];
		}

	};
	return result;
}


void repeatroll(int x,int y) { //to reroll without having to restart the whole program 
	cout << "1 to reroll, 2 to re-define bounds, 3 to exit: ";
	int c;
	cin >> c;
	switch (c) {
	case 1:
		cout << "Final number = " << randfromto(x, y)<<endl;
		repeatroll(x, y);
		break;
	case 2:
		int x1, y1;
		cout << "Pick your lowerbound: ";
		cin >> x1;
		cout << "Pick your upperbound (not included): ";
		cin >> y1;
		cout << "Final number = " << randfromto(x1, y1) << endl;
		repeatroll(x1, y1);
		break;
	default:
		exit;
		break;
	}
}