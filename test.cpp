#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ifstream ReadFile("data.txt");

    string line;
    string word;
    vector<string> information;

    getline(ReadFile, line);
    stringstream wordsInLine(line);

    while (wordsInLine >> word)
    {
        information.push_back(word);
    }

    for (int j = 2; j < information.size(); j++)
    {
        cout << stoi(information[j]) << endl;
    }

    return 0;
}
