#include <iostream>
using namespace std;
void printMenu() {
    cout << "Store your passwords and evaluate their strength" << endl;
    cout << "1. Strength of a password on a scale of 1-10" << endl;
    cout << "2. Add entry to password book" << endl;
    cout << "3. See top 100 passwords" << endl;
}
int main() {
    printMenu();
    return 0;
}
