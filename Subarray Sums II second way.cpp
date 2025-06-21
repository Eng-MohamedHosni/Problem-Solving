
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



int main()
{
    fast();

    ll n, x;
    cin >> n >> x;
    vector<ll>pfx(n+1, 0);
    map<ll, ll>freq;
    for (int i = 1; i <= n; i++)
    {
        cin >> pfx[i];
        pfx[i] += pfx[i - 1];
    }
    ll ans = 0;
    

   for (int i = 0; i <= n; i++)
   {
     ll search = pfx[i] - x;
     ans += freq[search];
     // they appear one by one to the next element so that we can prevent 
     // self counting 
     freq[pfx[i]]++;
   }
    cout << ans;

    return 0;
}

