
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

//https://codeforces.com/group/wNS3GwuHOE/contest/435607/problem/F
bool solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll>Coins(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> Coins[i];
    }
    while (m--)
    {
        ll y, x, z;
        cin >> y >> x >> z;

        Coins[y] -= z;
        Coins[x] += z;
    }

    for (int i = 1; i <= n; i++)
    {
        if (Coins[i] < 0)
            return false;
    }
    
    return true;
}

int main()
{
    fast();

    if (solve())
    {
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}

