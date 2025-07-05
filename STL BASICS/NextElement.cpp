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
//https://codeforces.com/group/c3FDl9EUi9/contest/263096/problem/J
// we track the indices and if the next element >top then save its index and pop the top

void solve() {

    int n;cin>>n;
    vector<int>v(n),result(n,-1);
    stack<int>st;
    for (int i=0;i<n;i++)cin>>v[i];

    for (int i=0;i<n;i++) {
        while (!st.empty() && v[i]>v[st.top()]){
            result[st.top()]=i+1;
            st.pop();
        }
    // if the stack is empty or the element on the top is greater than v[i]
    st.push(i);
    }


    int q;
    cin>>q;
    while (q--) {
        int idx;cin>>idx;
        cout<<result[idx-1]<<endl;
    }



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


