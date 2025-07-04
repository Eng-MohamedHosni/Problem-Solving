Ordered set 

Difference between set and ordered set : 
There is not so much difference between the set and ordered set although ordered set can be assumed as an extended version of set capable of performing some more advanced functions that are extensively used in competitive programming.


Definition : 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds{
    typedef tree<long long,
            null_type,
            less<long long>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set; 
}
using namespace __gnu_pbds;

How to use : 
define an object like this : ordered_set st ;
then you can deal with it as you deal with set 

Extra Functions : 

find_by_order(k) .. O(log(N))
It returns an iterator to the kth element (counting from zero) in the set in O(log(n)) time.
To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, 
then :
*(s.find_by_order(2)) : 3rd element in the set is 6
*(s.find_by_order(4)) : 5th element in the set is 88

order_of_key(k).. O(log(N))// 
It returns to the number of items that are strictly smaller than our item k in O(log(n)) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}
then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

How to change it to Ordered Multiset :
less -- > less_equal
but if you want to erase an element .. you must erase it like this :
st.erase(st.upper_bound(X));

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
};

Examples : 

1 - https://w...content-available-to-author-only...j.com/problems/ORDERSET/

2- https://c...content-available-to-author-only...s.fi/problemset/task/1076 .. pre-request(Sliding window)

3- https://c...content-available-to-author-only...s.com/contest/1042/problem/D .. pre-request( prefix , subarray sum problem ( https://v...content-available-to-author-only...e.net/contest/600163#problem/B ) )

Another examples : 
https://y...content-available-to-author-only...o.academy/topic-list/ordered_set
  
