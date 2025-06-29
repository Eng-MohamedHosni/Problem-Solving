#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
 
 
void solve()
{
    int q;
    cin >> q;
 
    deque<long long>arr;
    bool flag = false;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
 
        if (arr.empty())
        {
            arr.push_back(n);
            cout << 1;
        }
        else if (flag && n <= arr.front()&& n>=arr.back())
        {
            arr.push_back(n);
            cout << 1;
        }
        else if (!flag && (n >= arr.back() || n <= arr.front()))
        {
            if (n < arr.back()) flag = true;
            arr.push_back(n);
            cout << 1;
 
        }
        
        else
        {
            cout << 0;
        }
 
    }
    cout << endl;
}
int main()
{
 
    int T;
    cin >> T;
    while (T--)
        solve();
 
    return 0;
}