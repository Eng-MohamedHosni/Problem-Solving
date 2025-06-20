
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

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<ll>arr(n+2, 0),salp(n+2,0);

    while (q--)
    {
        int l, r, v;
        cin >> l >> r >> v;
        
        arr[l] += v;
        arr[r + 1] -= v;

        salp[r + 1] -= (r - l + 1) * v;
    }
    for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
    for (int i = 1; i <= n; i++) arr[i] += arr[i - 1] + salp[i];
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
}

int main()
{
    fast();

    solve();
    return 0;
}

