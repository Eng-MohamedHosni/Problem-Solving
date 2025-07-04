#include <bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()), ((v).end())
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
using namespace std;

ll dx8[8] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy8[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void file()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
    }
//https://codeforces.com/contest/1042/problem/D

/* in normal contribution type we look for   the subarray that we can subtract from the prefix to get the subarray that its sum is x 
so  pfx[I] - pfx[?]=x 
so pfx[I] -x=pfx[?] which we are looking for  in this type we use the map and check the existence
but in this problem we are looking for all the values that are greater than pfx[?] so that all the result subarrays are smaller than x
so we used the Ordered MultiSet and it gives us directly the items less than pfx[?] so to get the elements greater than  we subtract from the size 
*/

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

    ll Idx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        return s.order_of_key(x);
    }

    ll LastIdx(long long x) {
        if (!Exist(x)) {
            return -1;
        }
        if (*s.find_by_order(s.size() - 1) == x) {
            return s.size() - 1;
        }
        return Idx(*s.lower_bound(x)) - 1;
    }

    long long Value(ll index) {
        return *s.find_by_order(index);
    }

    ll Count(long long x) {
        if (!Exist(x)) {
            return 0;
        }
        return LastIdx(x) - Idx(x) + 1;
    }

    void Clear() {
        s.clear();
    }

    ll Size() {
        return s.size();
    }

    ll Lower_bound(ll x)
    {

        return *s.upper_bound(x);
    }

    ll Upper_bound(ll x)
    {

        return *s.lower_bound(x);
    }

    ll num_of_elements_greater_than_x(ll x) {
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

    int arr[n];

   for (int i=0;i<n;i++) cin>>arr[i];


    ll sum=0,cnt=0;

    OrderedSet s;
    s.Insert(0);
 

    for (int i=0;i<n;i++) {
        sum+=arr[i];
        ll search=sum-t;

        cnt+=s.num_of_elements_greater_than_x(search);
        s.Insert(sum);
    }
    cout<<cnt;

}

int main() {
 file();
    solve();

    return 0;
}
