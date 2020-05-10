#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long int find_sum , start , cur_sum ;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        find_sum=arr[i];
        cur_sum=arr[0] ;
        start=0;
        for(int j=1;j<=n;j++)
        {
            while(cur_sum>find_sum && start<j-1)
            {
                cur_sum-=arr[start];
                start++;
            }
            if(cur_sum==find_sum && start+1<j)
            {
                cnt++;
                break;
            }
            if(j<n)
                cur_sum+=arr[j];
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}