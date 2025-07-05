
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
typedef	long long ll;
using namespace std;

//https://codeforces.com/group/3nQaj5GMG5/contest/374321/problem/R

// we insert one in p1 and one in p2 and p2 بيكمل  p1 and check if p2.top()<p1.top()  then swap if true
int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

 // flag is for the p2 turn
const ll MOD = 1e9 + 7;

void AddToSuitablePQ(priority_queue<ll >& p1,priority_queue<ll,vector<ll>,greater<ll>>& p2,ll item,bool &flag) {


    if (flag) {
        p2.push(item);
    }
    else {
       p1.push(item);
    }

    flag =!flag;

    /*int SizeSum=p1.size()+p2.size();

     if (SizeSum%2==0) p1.push(item);
    else p2.push(item);*/

    if (p1.top()>p2.top()) {
        ll p1top=p1.top(),p2top=p2.top();
        p1.pop(),p2.pop();
        p1.push(p2top),p2.push(p1top);
    }
}

void solve()
{
   priority_queue<ll> p1;
    priority_queue<ll,vector<ll>,greater<ll>> p2;
    ll a, b, c, n;
    cin >> a >> b >> c >> n;

    p1.push(1);
    ll Sum = 1;
    bool flag = true;

    for (int i = 2; i <=n; i++)
    {
        ll Median =p1.top();

        ll f = (a*Median+b*i+c) % MOD;


        AddToSuitablePQ(p1,p2,f,flag);


        Sum +=f;

    }

    cout << Sum << endl;

}

signed main()
{
    file();
    fast();
    int T; cin >> T;
    while(T--)
        solve();

    return 0;
}

