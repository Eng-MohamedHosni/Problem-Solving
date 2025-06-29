#include<iostream>
#include<string>
using namespace std;
 
void solve()
{
   string s;
   cin>>s;
   if(s.find("1111111") != string::npos || s.find("0000000") != string::npos)
   {
       cout<<"YES"<<endl;
   }
   else
   {
       cout<<"NO"<<endl;
   }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   solve();
    
    
    return 0;
}