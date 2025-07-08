#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
 
const ll MOD = 1e9 + 7;
 
void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
 
void solve() {
    int x;
    string s;
    cin >> x >> s;
 
    ll res = s.size();  // current size of the string
 
    for (int i = 1; i <= x; i++) {
        int cut = s[i - 1] - '0';  // how many times to paste
 
        if (s.size() < x) {
            string paste = s.substr(i);
            while (--cut && s.size() < x) {  // paste (cut-1) times
                s += paste;
            }
        }
 
        // length simulation (whether s.size() exceeds x or not)
        ll add = (res - i + MOD) % MOD;
        res = (res + add * (s[i - 1] - '0' - 1)) % MOD;
    }
 
    cout << res % MOD << endl;
}
 
int main() {
    fast();
    file();
 
    int t;
    cin >> t;
    while (t--)
        solve();
 
    return 0;
}