#include <bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()), ((v).end())
typedef long long ll;
using namespace std;
 
int dx8[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy8[8] = {0, 0, 1, -1, 1, -1, 1, -1};
 
void file()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); // freopen("in.txt", "r", stdin);
#else
#endif
}
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
class OrderedSet {
private:
    typedef tree<long long,
            null_type,
            less_equal<long long>,
            rb_tree_tag,
            tree_order_statistics_node_update> ordered_set;
    ordered_set s;
 
public:
    void Insert(long long x) {
        s.insert(x);
    }
 
    bool Exist(long long x) {
        if (s.upper_bound(x) == s.end()) {
            return false;
        }
        return (*s.upper_bound(x)) == x;
    }
 
    void Erase(long long x) {
        if (Exist(x)) {
            s.erase(s.upper_bound(x));
        }
    }
 
    int Idx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        return s.order_of_key(x);
    }
 
    int LastIdx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        if (*s.find_by_order(s.size() - 1) == x) {
            return s.size() - 1;
        }
        return Idx(*s.lower_bound(x)) - 1;
    }
 
    long long Value(int index) {
        return *s.find_by_order(index);
    }
 
    int Count(long long x) {
        if (!Exist(x)) {
            return 0;
        }
        return LastIdx(x) - Idx(x) + 1;
    }
 
    void Clear() {
        s.clear();
    }
 
    int Size() {
        return s.size();
    }
 
    int Lower_bound(int x)
    {
 
        return *s.upper_bound(x);
    }
 
    int Upper_bound(int x)
    {
 
        return *s.lower_bound(x);
    }
 
    int num_of_elements_greater_than_x(int x) {
        return s.size()-s.order_of_key(x+1);
    }
};
 
 
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
void solve() {
    ll n,t;
    cin>>n>>t;
 
    OrderedSet s;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    s.Insert(0);
    ll sum=0;
    ll counter=0;
 
    for (int i=0;i<n;i++) {
 
        sum+=arr[i];
 
        ll search =sum-t;
        counter+=s.num_of_elements_greater_than_x(search);
        s.Insert(sum);
    }
    cout<<counter;
}
 
int32_t main() {
 
    solve();
 
    return 0;
}