// https://vjudge.net/problem/CSES-1661

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

// X= prefix[R] - prefix[L]  we have x and prefix[R]  and we need to find prefix[L]

ll CountSubArrays()
{
    ll res = 0;
    
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> arr(n+1,0),pfx(n+1);
    map<ll, ll>freq;
   
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pfx[i] = arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pfx[i] += pfx[i - 1];
        
        freq[pfx[i]]++;
    }
    freq[0]++;


    for (int i = n;i>=0;i--)
    {
		freq[pfx[i]]--;
        
        res+=freq[pfx[i]-x];
    }
    return res;
}

int main()
{
    fast();

    cout << CountSubArrays();

    return 0;
}

