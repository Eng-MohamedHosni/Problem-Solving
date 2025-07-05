#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
#define int long long
typedef long long ll;
using namespace std;

//int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
//const ll MOD= 1e9+7
void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

//https://codeforces.com/contest/1927/problem/D
void solve() {

    int n;cin>>n;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];

    vector<int>ans(n+1,-1);
    stack<int>s;
    for(int i=1;i<=n;i++) {

        while (!s.empty() && v[s.top()] != v[i]) {
            ans[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }



    int q;cin>>q;
    while(q--) {
        int l,r;cin>>l>>r;

        if (ans[l]>r||ans[l]==-1)
            cout<<-1<<"  "<<-1<<endl;
        else
            cout<<l<<" "<<ans[l]<<endl;

    }


}

signed main() {
    fast();
    file();

    int n;
    n = 0;
    cin >> n;
    while (n--) {

        solve();
        cout<<endl;
    }


    return 0;
}

