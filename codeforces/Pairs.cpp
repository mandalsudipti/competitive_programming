#include<bits/stdc++.h>
using namespace std;

int main()
{
    int lim , n ;
    cin>>lim>>n;
    vector<int>freq1(lim+1);
    vector<int>freq2(lim+1);
    vector<pair<int,int>>arr(n);
    int x , y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        arr[i]=make_pair(x,y);
    }
    int val1 = arr[0].first , f1 = n , val2 = arr[0].second , f2 = n;
    for(int i=0;i<n;i++)
    {
        if(arr[i].first!=val1 && arr[i].second!=val1)
        {
            freq1[arr[i].first]++;
            freq1[arr[i].second]++;
        }
        else
            f1--;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i].first!=val2 && arr[i].second!=val2)
        {
            freq2[arr[i].first]++;
            freq2[arr[i].second]++;
        }
        else
            f2--;
        
    }
    bool possible = false ;
    for(int i=1;i<=lim;i++)
    {
        if(freq1[i]>=f1 || freq2[i]>=f2)
        {
            possible=true;
            break;
        }
    }
    
    if(possible)
        cout<<"YES";
    else
        cout<<"NO";
        
    return 0;
}
