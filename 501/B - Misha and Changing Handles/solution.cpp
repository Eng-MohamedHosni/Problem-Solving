#include <bits/stdc++.h>
using namespace std;
 
// https://codeforces.com/problemset/status?my=on
 
void solve2()
{
    int n; cin >> n;
 
    map<string, string>mp;
    while (n--)
    {
        bool IsExist = false;
        string name, email;
        cin >> name >> email;
 
        for (auto &it : mp) // don't forget the reference to apply the effects
        {
            if (name == it.second)
            {
                it.second = email;
                IsExist = true;
                break;
            }
            
       }
            if (!IsExist)
            {
                mp[name] = email;
            }
    }
        cout << mp.size() << endl;
        for (auto it : mp)
            cout << it.first << " " << it.second << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve2();
   
    return 0;
}