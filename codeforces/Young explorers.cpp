#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n ;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int team_cnt=0 , team_member = 0;
    for(int i=0;i<n;i++)
    {
        team_member++;
        if(arr[i]<=team_member)
        {
            team_member=0;
            team_cnt++;
        }
    }
    cout<<team_cnt<<endl;
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