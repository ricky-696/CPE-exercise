#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

bool prime[10000000];

void getprime() // prime table
{
    for (int i = 0 ; i <= 9999999 ; i++)
    {
        prime[i] = true;
    }
    prime[0] = false; prime[1] = false;
    for (int i = 2 ; i <= 9999999 ; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j <= 9999999; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

void perm(vector<string> &ans, string s1, string s2) 
{
    if (s2 != "") ans.push_back(s2);
    for (int i = 0 ; i < s1.length() ; i++)
    {       
        string s3 = s1;
        perm(ans, s3.erase(i,1), s2 + s1[i]);
    }
}
int main()
{
    getprime();
    ifstream file;
    file.open("in1.txt", ios::in);
    string r = "";
    getline(file, r);
    while (!file.eof())
    {
        vector<string> ans;    
        string s = "";
        getline(file,s);
        perm(ans,s,"");
        set<int> primes;

        for (auto &i : ans)
        {
            int x = stoi(i);
            if (prime[x]) {
                primes.insert(x);
            }
        }
        cout << primes.size() << endl;
    }
    file.close();
}

