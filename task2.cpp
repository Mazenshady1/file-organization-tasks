#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("fruit.txt");
    if (!inFile) {
        cout << "Error: cannot open file for reading" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    ofstream outFile("fruit.txt", ios::app);
    if (!outFile) {
        cout << "Error: cannot open file for writing" << endl;
        return 1;
    }

    outFile << "Fresh Fruits" << endl;
    outFile.close();
    
    system("pause");
    return 0;
}