
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

void fix(ll& num, ll mod)
{
     num= ((num % mod) + mod) % mod;
}

int main()
{
    fast();

    ll n;
    cin >> n;
    vector<ll>pfx(n+1, 0);
    map<ll, ll>freq;
    for (int i = 1; i <= n; i++)
    {
        cin >> pfx[i];

        pfx[i] += pfx[i - 1];
        fix(pfx[i], n);
    }

    ll ans = 0;
  

    for (int i = 0; i <= n; i++)
    {
        ans += freq[pfx[i]];
        freq[pfx[i]]++;
    }


    cout << ans;

    return 0;
}

