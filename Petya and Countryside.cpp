
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
//https://codeforces.com/group/wNS3GwuHOE/contest/435607/problem/H

ll Max()
{
    int n;
    cin >> n;
    vector<int>h(n), counter(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (h[j] >= h[j - 1])
                counter[i]++;
            else
                break;
        }
        for (int k = i + 1; k < n; k++)
        {
            if (h[k] <= h[k - 1])
                counter[i]++;
            else
                break;
        }
    }

    return *max_element(all(counter));

}

int main()
{
    fast();

    cout << Max();
    return 0;
}

