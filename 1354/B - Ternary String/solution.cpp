#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
#define int long long
typedef long long ll;
using namespace std;
 
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
 
    string s;
    cin>>s;
    int n=s.length();
    map<char,int>mp;
 
    ll ans=INT_MAX;
    ll l=0 ,r=l;
    ll sumForActiveRange = 0;
    auto add=[&](int i) {
        mp[s[i]]++;
    };
 
    auto remove=[&](int i) {
        mp[s[i]]--;
    };
    auto IsValid=[&] {
        string t="123";
        for (int i=0;i<3;i++)
            if (mp[t[i]]==0)
                return false;
        return true;
    };
 
    while (r<n)
    {
        add(r);
 
        if (IsValid())
        {
            ans=min(ans,r-l+1);
        }
        while (IsValid())
        {
            remove(l);
            l++;
            if (IsValid())
            {
                ans=min(ans,r-l+1);
            }
        }
 
        r++;
    }
    // zero when l became after r in some casses
   cout<<(ans==INT_MAX?0:ans)<<endl;
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
 