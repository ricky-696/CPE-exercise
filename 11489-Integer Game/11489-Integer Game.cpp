
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file;
    file.open("in1.txt",ios::in);
    string r = "";
    getline(file, r);
    int casen = 1;
    while (!file.eof()) 
    {
        string game = "";
        getline(file, game);
        // 拿掉一個數字之後總和一定要是3的倍數
        int total = 0, mod3 = 0;
        for (int i = 0; i < game.length(); i++) {
            int n = game[i] - 48; //char to int
            if (n % 3 == 0) { mod3++; }
            total = total + n;
        }
        if(total % 3 == 0)
        {
            if(mod3 % 2 == 0)
                cout << "case"<< casen++ << ": T" << endl;
            else
                cout << "case" << casen++ << ": S" << endl;
        }
        else
        {
            for (int i = 0; i < game.length(); i++) 
            {
                if((total - game[i]) % 3 == 0)
                {
                    if (mod3 % 2 == 0)
                        cout << "case" << casen++ << ": S" << endl;
                    else
                        cout << "case" << casen++ << ": T" << endl;
                    break;
                }
                else if(i == game.length() - 1 ) cout << "case" << casen++ << ": T" << endl;
            }
    
        }
    }
}
