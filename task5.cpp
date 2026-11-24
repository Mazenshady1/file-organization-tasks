#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
using namespace std;

struct Student
{
    char name[20];
    int id;
    float grade;
    char delim;
};

int main()
{
    ofstream file("students.txt", ios::app);

    if (!file)
    {
        cout << "Error: cannot open students.txt" << endl;
        system("pause");
        return 1;
    }

    Student s;
    s.delim = '$';
    char choice;

    do
    {
        cout << "Enter student name: ";
        cin.getline(s.name, 20);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter student ID: ";
        while (!(cin >> s.id))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid ID, try again: ";
        }

        cout << "Enter student grade: ";
        while (!(cin >> s.grade))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid grade, try again: ";
        }

        file << s.name << ", " << s.id << ", "
             << s.grade << " " << s.delim << endl;

        cout << "Add another student? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == 'y' || choice == 'Y');

    file.close();

    cout << "Records saved successfully!" << endl;

    system("pause");
    return 0;
}