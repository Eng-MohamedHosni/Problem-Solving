#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
#define int long long
typedef long long ll;
using namespace std;
#define cin(v)  for(int i=0;i<v.size();i++) cin>>v[i];
 
//int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
//const ll MOD= 1e9+7;
void file()
{
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
 
void solve()
{
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
   cin(v);
 
    ll ans=-1;
    ll l=0 ,r=l;
    ll sumForActiveRange = 0;
    auto add=[&](int i) {
        sumForActiveRange+=v[i];
    };
 
    auto remove=[&](int i) {
        sumForActiveRange-=v[i];
    };
    auto IsValid=[&] {
        if (sumForActiveRange >s)
            return false;
 
        return true;
    };
 
    while (r<n)
    {
        add(r);
 
        while (!IsValid())
        {
            remove(l);
            l++;
        }
 
        if (sumForActiveRange == s)
        {
            ans=max(ans,r-l+1);
        }
        r++;
    }
    cout<<(ans<=0?-1:n-ans)<<endl;
}
 
signed main()
{
    fast();
    file();
 
    int n;
    n = 0;
    cin >> n;
    while (n--)
    solve();
 
 
    return 0;
}
 