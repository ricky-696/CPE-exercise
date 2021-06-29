#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string date[] = { "Saturday","Sunday","Monday","Tuesday","Wednesday", "Thursday", "Friday" };
    int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    ifstream file;
    file.open("in1.txt",ios::in);
    string r = "";
    getline(file,r);
    while (!file.eof())
    {
        int m, d;
        file >> m;
        file >> d;
        for (int i = 0; i < m - 1; i++) 
        {
            d = d + day[i];
        }

       cout << date[(d - 1) % 7] << endl;
    }
}


