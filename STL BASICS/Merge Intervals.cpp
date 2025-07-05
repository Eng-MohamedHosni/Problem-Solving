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

void solve() {

    int n;cin>>n;

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        cin>> v[i].first>>v[i].second;
        if (v[i].first>v[i].second)
            swap(v[i].first,v[i].second);
    }

    sort(all(v));
    vector<pair<int,int>> res;

    int start=v[0].first,end=v[0].second;

    for (int i=1;i<n;i++) {

        if (v[i].first>end){ // if there isn't  any intersection  push and update the working interval
            res.push_back({start, end});

            start=v[i].first,end=v[i].second;
        }
        else {              // if there is intersection take the greatest end
            end=max(end,v[i].second);
        }
    }
    res.push_back({start, end});

    for (auto &it: res)
        cout<<it.first<<" "<<it.second<<endl;

}

signed main() {
    fast();
    file();

    int n;
    n = 0;
    //cin >> n;
    //while (n--)
    solve();


    return 0;
}

