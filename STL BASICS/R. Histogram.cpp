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
//https://codeforces.com/group/3nQaj5GMG5/contest/373244/problem/R

// in this problem any column that is greater than the current we can take a common height which is the heigt of  the current
// for example  3 5 4  for 3 we can take 3 from 3 and 5 and 4
// so we need to find the last greater element than me in other words we need to find the idx of the first element smaller than me
// to implement this we will use monotonic stack to get the smaller element idx
// then there will be a probability that there are elements greater than me but behind me
// so we cout them using a while loop
// then the greatest area is the answer
void solve() {

    int n; cin >> n;
    vector<ll>v(n),result(n,n);
    for (int i = 0; i < n; i++) cin>>v[i];

    stack<ll>s;
// s.top is an idx of the next small element
    for (int i=0;i<n;i++) {
        while(!s.empty()&&v[i]<v[s.top()]) {
            result[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }

    for (int i=0;i<n;i++) {

        int j=i-1;
        while (j>=0&v[j]>v[i]) {
            result[i]++;
            j--;
        }
        result[i]=v[i] *(result[i]-i);
    }
    sort(all(result));
    cout<<result.back()<<endl;


}

signed main() {
    fast();
    file();

    int n;
    n = 0;
    cin >> n;
    while (n--)
    solve();


    return 0;
}

