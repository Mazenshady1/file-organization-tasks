#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("Persons.txt");

    Person p;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name: ";
        cin >> p.name;

        cout << "Enter age: ";
        cin >> p.age;

        outFile << p.name << " " << p.age << endl;
    }

    outFile.close();

    vector<Person> persons;

    ifstream inFile("Persons.txt");

    while (inFile >> p.name >> p.age)
    {
        persons.push_back(p);
    }

    inFile.close();

    if (persons.empty())
    {
        cout << "No data" << endl;
        system("pause");
        return 0;
    }

    Person younger = persons[0];
    Person older = persons[0];

    for (size_t i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < younger.age)
        {
            younger = persons[i];
        }

        if (persons[i].age > older.age)
        {
            older = persons[i];
        }
    }

    ofstream resultFile("Results.txt");

    resultFile << "Younger Person: "
               << younger.name << " "
               << younger.age << endl;

    resultFile << "Older Person: "
               << older.name << " "
               << older.age << endl;

    resultFile.close();

    cout << "Data saved successfully!" << endl;

    system("pause");
    return 0;
}