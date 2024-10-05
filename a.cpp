//C++ Program to validate the data type of the input
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int number;
    cout << "Enter an integer: ";
    while (!(cin >> number)) {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "You entered: " << number << endl;
    return 0;
}
