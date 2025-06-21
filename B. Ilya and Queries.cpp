
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

// https://codeforces.com/problemset/problem/313/B

int main()
{
    fast();

    string s;
    
    cin >> s;
    s = "a" + s;
    ll q; cin >> q;
    ll n = s.size();
    vector<ll>pfx(n, 0);

    for (int i = 1; i < n-1; i++)
    {
        pfx[i] += pfx[i - 1]+(s[i] == s[i + 1]);
    }

    // count the number of chars equals to the next char
    while (q--)
    {
        ll l, r; cin >> l >> r;

        cout << pfx[r-1] - pfx[l - 1]<<endl;
    }
    return 0;
}

