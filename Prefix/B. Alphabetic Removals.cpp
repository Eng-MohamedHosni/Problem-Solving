
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define endl "\n"
#define all(v) ((v).begin()),((v).end())
typedef	long long ll;
using namespace std;

int dx8[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy8[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void file() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);//freopen("in.txt", "r", stdin);
#else 
#endif
}
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

string solve()
{
	int n, k; cin >> n >> k;

	string s; cin >> s;

	int freq[26] = { 0 };
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
	}

	// to get the exact frequency of each character
    for (int i = 0; i < 26; i++)
    {
        if (k == 0)break;
        if (freq[i] > k)
        {
            freq[i] -= k;
            k = 0;
        }
        else if (freq[i] < k)
        {
            k -= freq[i];
            freq[i] = 0;
        }
        else if (freq[i] == k)
        {
            freq[i] = 0;
            k = 0;
        }
    }
    
    string ans = "";
    vector<bool>del(n);
    // to print the string after removing k characters according to the Algorithm
    for(int i=s.size()-1;i>=0;i--)
    {
        if (freq[s[i] - 'a'] > 0)
        {
            del[i] = 1;
            freq[s[i] - 'a']--;
        }
        else
            del[i] = 0;
	}
    for (int i = 0; i < n; i++)
    {
        if (del[i])
            ans.push_back(s[i]);
    }
    return ans;
     
}

int main()
{
    fast();

  cout<<  solve();
    return 0;
}

