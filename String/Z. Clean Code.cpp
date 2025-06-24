
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

// https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/Z
void solve()
{
    string s;
        bool Multi = 0, single = 0;
   while (getline(cin, s))
    {
        if (s == " " || s.size() == 0)
            continue;
        int n = s.size();

        bool ThereIsPrinted = 0;
        for (int i = 0; i < n; i++)
        {
           // if there is a single-line comment, discard the line
            if (s[i] == '/' && s[i + 1] == '/'&& !Multi) break;
            // if there is a block comment opening  i++ to skip also the * and start skipping
            else if ( s[i] == '/' && s[i + 1] == '*') Multi = 1,i++;
            // if we find the closing of the block comment and there is an opening block skip the / 
            // and close the block comment flag
            else if ( s[i] == '*' && s[i+1] == '/'  && Multi)
            {
                i++;
                Multi = 0;
                continue;
            }
            // if we're not in a block comment, print the char and set the flag to 1 
            //It refers to something that has been printed
            else if (!Multi)
            {
                cout << s[i];
                ThereIsPrinted = 1;
            }
        }
        // if something has been printed and there is not a block comment, print end line
        if (ThereIsPrinted&&!Multi)
            cout << endl;
      
    }
}
int main()
{
    fast();

    solve();
    return 0;
}

