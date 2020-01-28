#include<bits/stdc++.h>
using namespace std;
long long int power_three(int i)
{
    long long int ans=1;
    while(i!=0)
    {
        ans*=3;
        i--;
    }
    return ans;
}
void solve(long long int n)
{
    vector<int> arr;
    while(n!=0)
    {
        arr.push_back(n%3);
        n=n/3;
    }
    for(int i=arr.size()-1;i>=0;i--)
    {
       if(arr[i]==2)
       {
           for(int j=0;j<=i;j++)
                arr[j]=0;
           for(int j=i+1;j<arr.size();j++)
           {
               if(arr[j]==1)
                arr[j]=0;
               else
               {
                   arr[j]=1;
                   break;
               }
           }
           if(arr[arr.size()-1]==0)
                arr.push_back(1);
            break;
       }
    }
    long long int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        ans+=arr[i]*power_three(i);
    }
    cout<<ans<<endl;
}
int main()
{
    int query;
    cin>>query;
    while(query--)
    {
        long long int n;
        cin>>n;
        solve(n);
    }
    return 0;
}