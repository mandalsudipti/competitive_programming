#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<pair<int,int>> arr(n+1);
    int i,x;
    for(i=1;i<=n;i++)
    {
       cin>>x;
       arr[i]=make_pair(x-i,x);
    }
    
    sort(arr.begin()+1,arr.end());
    long long int maximum=0 , sum=0;
    //for(i=1;i<=n;i++)
        //cout<<arr[i].second<<" "<<arr[i].first<<endl;
    sum=arr[1].second;
    maximum = sum;
    for(i=2;i<=n;i++)
    {
        if(arr[i].first==arr[i-1].first)
            sum+=arr[i].second;
        if(i==n || arr[i].first!=arr[i-1].first)
        {
            //cout<<sum<<endl;
            maximum = max(maximum , sum);
            sum=arr[i].second;
        }
    }
    maximum = max(sum , maximum);
    cout<<maximum;
    return 0;
}