
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

//https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/O
void solve()
{
    int n; cin >> n;
    vector<ll>arr(n+1),p(n+1,0),s(n+2,0);

    map<ll, pair<ll, ll>>prefixMap;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        p[i] = p[i - 1] + arr[i];
        if(!prefixMap.count(p[i]))
        prefixMap[p[i]] = { 1,i };
    }

    for (int i = n; i >= 1; i--)
    {
        s[i] = s[i + 1] + arr[i];
    }

    vector<ll>res;
    for (int i = n; i >= 1; i--)
    {
        if(prefixMap.find(s[i])!=prefixMap.end())
        {
            if (prefixMap[s[i]].first >= 1 && prefixMap[s[i]].second <= i - 1)
                res.push_back(s[i]);
        }
    }

    sort(all(res), greater<ll>());

    cout<<res.front();


}

int main()
{
    fast();

    solve();
    return 0;
}

