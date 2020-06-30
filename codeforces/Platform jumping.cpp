#include<bits/stdc++.h>
using namespace std;

int main()
{
    int river_length , no_of_platform , jump ;
    cin>>river_length>>no_of_platform>>jump;
    vector<int>arr(no_of_platform);
    int platform_length=0;
    for(int i=0;i<no_of_platform;i++)
    {
        cin>>arr[i];
        platform_length+=arr[i];
    }
    vector<pair<int,int>>loc(no_of_platform);
    bool possible = true;
    int x=0;
    
    for(int i=0;i<no_of_platform;i++)
    {
        int start = x+jump , end = x+jump+arr[i]-1;
        if(river_length - end < platform_length-arr[i])
        {
            int diff = (platform_length-arr[i]) - (river_length - end) ;
            start-=diff;
            end-=diff;
        }
        if(start>x)
        {
            x = end ;
            platform_length-=arr[i];
            loc[i] = make_pair(start,end);
        }
        else
        {
            possible = false;
            break;
        }
    }
    if(possible)
    {
        pair<int,int>last_platform= loc.back();
        if(last_platform.second + jump < river_length+1)
            possible=false;
    }
    if(!possible)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        vector<int>ans(river_length+1,0);
        for(int i=0;i<no_of_platform;i++)
        {
            int start = loc[i].first , end = loc[i].second ;
            //cout<<start<<" "<<end<<endl;
            for(int j=start;j<=end;j++)
                ans[j]=i+1;
        }
        for(int i=1;i<=river_length;i++)
            cout<<ans[i]<<" ";
    }
    return 0;
}