#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool repeat(int x, int y, bool add0)
{ // use hash
    int n[10] = { 0,0,0,0,0,0,0,0,0,0 };
    if (add0) n[0] = 1;
    while(x > 0)
    {
        if (n[x % 10] == 1) return true;
        n[x % 10] = 1;
        x = x / 10 ; //c的除法為無條件捨去
    }
    while (y > 0)
    {
        if (n[y % 10] == 1) return true;
        n[y % 10] = 1;
        y = y / 10;
    }
    return false;
}

int main()
{
    ifstream file;
    file.open("in1.txt",ios::in);
    while (!file.eof()) 
    {
        string s = "";
        getline(file, s);
        if (s == "0") break;
        int ans = stoi(s);
        bool nans = true;
        for (int i = 1234; i <= 49876 ; i++ ) 
        {
            bool add0 = false;
            if (i >= 1000 && i <= 10000) add0 = true;
            int x = ans * i; 
            if (x < 100000 && x > 10000)
            {
                if(!repeat(x,i,add0))
                { 
                    nans = false;
                    if(add0)
                    {
                        cout << x << " / 0" << i << " = " << ans << endl;
                    }
                    else
                    {
                        cout << x << " / " << i << " = "  << ans << endl;
                    }
                    
                }
            }
            else if(x > 100000) break; 
        }
        if(nans) cout << "There are no solution for " << s << "." << endl;
        cout << endl;
    }
}
