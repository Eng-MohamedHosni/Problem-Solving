
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
//https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/H
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;

    vector<string>word(n + 1);
    vector<ll>cost(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> word[i];

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    map<string, int>GroupNum;
    map<ll, ll>MinCost;

  // to map each word to its group then mapping the minCost to each group
    for (int i = 1; i <= k; i++)
    {
        int GroupIdx = i;

        int SizeOfGroup; cin >> SizeOfGroup;

        for (int j = 1; j <= SizeOfGroup; j++)
        {
            int memberIdx;
            cin >> memberIdx;

            GroupNum[word[memberIdx]] = GroupIdx;

            if (MinCost[GroupIdx] != 0)
                MinCost[GroupIdx] = min(MinCost[GroupIdx], cost[memberIdx]);
            else MinCost[GroupIdx] = cost[memberIdx];

        }
    }

    vector<string>message(m + 1);

    for (int i = 1; i <= m; i++)
    {
        cin >> message[i];
    }

    ll Cost = 0;
    for (int i = 1; i <= m; i++)
    {
        Cost += MinCost[GroupNum[message[i]]];
    }

    cout << Cost;
}

int main()
{
    fast();

    solve();
    return 0;
}

