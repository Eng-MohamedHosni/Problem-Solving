
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

//https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/K

// think of it like a rectangle and you add items and remove from the top 
// for each one you pop you push the next element 

ll solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll>arr(n+1);
    priority_queue<ll,vector<ll>,greater<ll>>pq;

    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i<=m; i++) {
        pq.push(arr[i]);
    }
    
    for (int i = 1; i < k; i++)
    {
        pq.pop();
        if ((m+1) <= n)
        pq.push(arr[++m]);

    }

    return pq.top();
   
    
}


int main()
{
    fast();

    int T; cin >> T;
    while (T--)cout<< solve()<<endl;

    return 0;
}

//1
//6 3 4
//1 2 4 7 6 3
