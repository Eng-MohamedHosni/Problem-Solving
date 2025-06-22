
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

//https://codeforces.com/group/wNS3GwuHOE/contest/435607/problem/R

struct stOP
{
    ll l;
    ll r;
    ll val;
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll>arr(n + 1),part(2e5+3,0),Opfreq(m+2,0);
    vector<stOP>Op(m+1);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    // read queries
    for (int i = 1; i <= m; i++)
    {
       cin>> Op[i].l >> Op[i].r >> Op[i].val;
    }

    // read Operations 
    for (int i = 1; i <= k; i++)
    {
        int l, r;
        cin >> l >> r;
        
        Opfreq[l]++;
        Opfreq[r + 1]--;
    }
    for (int i = 1; i <= m; i++) Opfreq[i] += Opfreq[i - 1];

    for (int i = 1; i <= m ; i++)
    {
        part[Op[i].l] += Op[i].val * Opfreq[i];
        part[Op[i].r + 1] -= Op[i].val * Opfreq[i];
    }
    for (int i = 1; i < part.size(); i++)
    {
        part[i] += part[i - 1];
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i]+part[i] << ' ';
}
int main()
{
    fast();
    solve();

    return 0;
}

