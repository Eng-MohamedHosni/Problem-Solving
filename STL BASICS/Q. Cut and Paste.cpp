#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
typedef long long ll;
using namespace std;

//int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
const ll MOD= 1e9+7;
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
//https://codeforces.com/group/3nQaj5GMG5/contest/373244/problem/Q

void solve() {
    int stop; cin >> stop;
    string s;
    cin >> s;

    ll l = 1;
    // the implementation of the needed string we won't need its size to be more than x  to get a valid indexing with L
    ll sz = s.size();
    string clip;
    for (int l=1;l<=stop;l++) {

        ll times = s[l - 1] - '0';

        // if we haven't got the full needed size which is less than the stop because we indexing l-1 so less than not less than or equal
        if (s.size() < stop) {
            // this is the copied part from l to the end of the string
            clip = s.substr(l);
            // then we apply the cut by  resizing the string from 0 to l-1  which is l digits
            s=s.substr(0,l);
            // then we append the clip to the string n times and check if s.size()<stop to know if we hit the target or not
            for (int i = 1; i <= times && s.size() < stop; i++) {
                s += clip;
            }
        }

        // After getting the needed string , we will simulate the rest of the procedures and not implementing it
        // we will calculate the clipsize which is add by sz- l which is all of the right of the L
        //
        ll add = (sz - l + MOD) % MOD;
        sz = (l + add * (s[l - 1] - '0' )) % MOD;


    }
    cout << sz%MOD << endl;
}
void solve1() {
    int stop; cin >> stop;
    string s;
    cin >> s;

    ll l = 0;
    ll sz = s.size();
    string clip;
    while (s.length() < stop) {
        l++;// move step

        clip = s.substr(l); //   copy step from l to the end of the string
       //original 2(31) 31 is part of the original or the previous string so we add times -1
       //23(131)  then 131  is a part of the original so we add it 2 times instead of 3
        ll times = s[l - 1] - '0' - 1 ;  // we substract 1 because the original one contains a copy

        while (times > 0) {
            s += clip;
            times--;
        }
    }

    for (int i=1; i<=stop; i++) { // we calculate from the beginning
        // i is l   and sz-i is clipboard  and s[i-1] is the times
        sz=i%MOD +(sz-i)%MOD *(s[i-1]-'0')%MOD;

    }

    cout<<sz%MOD<<endl;

    }

signed main(){
    fast();
    file();

    int n;
    n = 0;
    cin >> n;
    while (n--)
        solve1();


    return 0;
}
