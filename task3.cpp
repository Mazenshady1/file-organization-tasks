#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string text;

    ofstream out("welcome.txt");
    out << "Hello Everybody";
    out.close();

    ifstream in("welcome.txt");
    getline(in, text);
    in.close();

    size_t pos = text.find("body");
    if (pos != string::npos)
    {
        text.replace(pos, 4, "one");
    }

    ofstream out2("welcome.txt");
    out2 << text;
    out2.close();

    cout << text << endl;

    system("pause");
    return 0;
}