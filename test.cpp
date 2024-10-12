#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string lines;
    ifstream ReadFile("data.txt");

    getline(ReadFile, lines);
    cout << lines << endl;


    return 0;
}
