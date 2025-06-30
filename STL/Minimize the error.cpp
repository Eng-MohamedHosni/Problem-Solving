
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
//https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/M
void solve()
{
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<ll>arr1(n), arr2(n);
     deque<ll>sub(n);

    for (auto& it : arr1)
        cin >> it;

    for (auto& it : arr2)
        cin >> it;

    int Totalk = k1 + k2;
    for (int i = 0; i < n; i++)
    {
        sub[i] = abs(arr1[i] - arr2[i]);
    }



    priority_queue<ll>pq;

    for (int i = 0; i < sub.size(); i++)
    {
        pq.push(sub[i]);
    }
    // if there is 3 3 2 1  we decrease 3 -> 2  then push it 
    // then descrease the second 3 -> 2  so it becomes 2 2 2 1 then again
    while (Totalk)
    {
        ll top = pq.top();
        pq.pop();

        if (top != 0)
        {
            top--;
            pq.push(top);
            Totalk--;
        }
        else break; // if the greatest number equal 0 so all the values eqal 0

    }

    if (Totalk % 2 == 0 && Totalk != 0) cout << 0;
    else if (Totalk % 2 != 0) cout << 1;

    else {
    ll Sum = 0;

    while (pq.size())
    {
        Sum += pow(pq.top(), 2);
        pq.pop();
    }
    cout << Sum;
    }
    return;

}

int main()
{
    fast();
    solve();

    return 0;
}

