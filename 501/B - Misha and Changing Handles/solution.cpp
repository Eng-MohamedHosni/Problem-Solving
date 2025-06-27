#include <bits/stdc++.h>
using namespace std;
 
 
void solve()
{
    int q;
    cin >> q;
 
    map<string, string> handle; // final -> original
 
    while (q--) {
        string oldName, newName;
        cin >> oldName >> newName;
 
        if (handle.find(oldName) != handle.end()) {
            handle[newName] = handle[oldName]; // carry over original name
            handle.erase(oldName);
        }
        else {
            handle[newName] = oldName; // oldName is the original
        }
    }
 
    cout << handle.size() << '\n';
    
 
}
 
 
void solve2()
{
    int n; cin >> n;
 
    map<string, string>mp;
    while (n--)
    {
        bool IsExist = false;
        string name, email;
        cin >> name >> email;
 
        for (auto &it : mp)
        {
            if (name == it.second)
            {
                it.second = email;
                IsExist = true;
                break;
               
            }
        }
        if (IsExist == false)
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