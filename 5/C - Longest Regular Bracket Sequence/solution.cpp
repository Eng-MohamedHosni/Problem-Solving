#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
#define int long long
typedef long long ll;
using namespace std;
 
//int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
//const ll MOD= 1e9+7;
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
    string s;
    cin>>s;
    stack<char>st;
    stack<int>stidx;
    vector<int>result(s.size()+1);
    result.back()=-1;
    for(int i=0;i<s.size();i++) {
 
        if (s[i]=='('||s[i]=='['||s[i]=='{'||s[i]=='<') {
            st.push(s[i]);
            stidx.push(i);
        }
        else if (s[i]==')'||s[i]==']'||s[i]=='}'||s[i]=='>') {
            if (st.empty()) {
                result[i] =-1;
            }
            else {
                char top=st.top();
                char close=s[i];
                if (top=='('&&close==')'||top=='['&& close==']'||top=='{'&&close=='}'||top=='<'&&close=='>') {
                    result[i]=1,result[stidx.top()]=1;
                    st.pop();
                    stidx.pop();
                }
                else result[i]=-1;
            }
        }
    }
    while (!stidx.empty()) {
        result[stidx.top()]=-1;
        stidx.pop();
        st.pop();
    }
    map<int,int>mp;
    int counter=0;
    for (int i=0;i<result.size();i++) {
 
        if (result[i]==-1) {
            mp[counter]++;
            counter=0;
        }
        else {
            counter++;
        }
    }
 
    auto it=mp.end();
   it= std::prev(mp.end());
    if (it->first!=0)
    cout<<it->first<<" "<<it->second<<endl;
    else cout<<"0 1";
 
 
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
 