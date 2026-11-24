#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fullName, id, grade;

    cout << "Enter full name: ";
    getline(cin, fullName);

    cout << "Enter ID: ";
    getline(cin, id);

    cout << "Enter grade: ";
    getline(cin, grade);

    ofstream file("Student.txt");

    if (!file) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    file << "Full name: " << fullName << endl;
    file << "ID: " << id << endl;
    file << "Grade: " << grade << endl;

    file.close();
    cout << "Data saved to Student.txt" << endl;

    return 0;
}