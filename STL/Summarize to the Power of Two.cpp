
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
typedef	long long ll;
using namespace std;

int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void file() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);//freopen("in.txt", "r", stdin);
#else 
#endif
}
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


//https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/I

bool IsFraction(double value)
{
    return (floor(value) != value);
}


// the main idea instead of solving the problem in n^2 
// we can solve it in 32*n by getting all the powers of 2  from 2^1 to 2^32
// and  the needed one is power[j] -arr[I] if it is exist then it is a valid item else then it will be removed
void solve()
{
    int n;
    cin >> n;
    vector<ll>arr(n);
    map<ll,ll>mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    if (n == 1)
    {
        cout << 1;
        return;
    }

    vector<ll>Power;
    Power.push_back(2);
    for (int i = 1; i < 32; i++)
    {
        Power.push_back(2 * Power.back());
    }

    int Good = 0;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < 32; j++)
        {
            ll need = Power[j] - arr[i];
            if (need == arr[i] && mp[need] >= 2)
            {
                Good++;
                break;
            }
            else if (need!= arr[i] && mp.count(need))
            {
                Good++;
                break;
            }
            
        }
    }

    cout <<n-Good;

}
int main()
{
    fast();
    solve();

    return 0;
}

