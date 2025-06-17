
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

ll MaxSum()
{
    ll n, q;
	cin >> n >> q;      

	vector<ll>arr(n +1), freq(n+2, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
		arr[i] = arr[i];
	}
	sort(arr.begin() + 1, arr.end(),greater<int>());

    while(q--) {
        ll l, r;
        cin >> l >> r;
       
        freq[l]++;
        freq[r + 1]--;
	}

    for (ll i = 1; i <= n; i++)
    {
		freq[i] += freq[i - 1];
    }
	sort(freq.begin() + 1, freq.end(), greater<int>());

    ll res = 0;
    for(int i=1;i<= n; i++) {
        
        res += (freq[i] * arr[i]);
	}

    return res;
}

int main()
{
    fast();

	cout << MaxSum() << endl;

    return 0;
}
