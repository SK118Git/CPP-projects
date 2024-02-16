#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream file("C:\\Users\\sasha\\OneDrive\\Desktop\\gnuplotdata\\testing.txt");
    string text = "test 2";
    for (int k = 0; k < 10; k++) {
        int y = 2 * k;
        file << y << "  " << k << endl;
    }


    file.close();

    return 0;
};
