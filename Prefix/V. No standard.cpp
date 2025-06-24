
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
    vector<ll>arr(n + 2), p(n + 2, 0),slope(n+2,0);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        p[l]++;
        p[r + 1] -= r - l + 1;

        slope[l + 1]++;
        slope[r + 1]--;
        
    }
    for (int i = 1; i <= n; i++) slope[i] += slope[i - 1];

    for (int i = 1; i <= n; i++)
    {
        p[i] += p[i - 1] + slope[i];
    }
    
    
    for (int i = 1; i <= n; i++)
        cout << arr[i] + p[i] << " ";

}

int main()
{
    fast();

    solve();
    return 0;
}

