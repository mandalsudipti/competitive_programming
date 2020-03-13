#include<bits/stdc++.h>
using namespace std;

void solve()
{
   int n;
   cin>>n;
   int i , arr[n];
   for(i=0;i<n;i++)
    cin>>arr[i];
   int maximum=0;
   for(i=0;i<n;i++)
   {
       if(arr[i]>maximum)
        maximum=arr[i];
   }
   for(i=0;i<n;i++)
   {
       if((maximum-arr[i])%2==1)
       {
           cout<<"NO"<<endl;
           return;
       }
   }
   cout<<"YES"<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}