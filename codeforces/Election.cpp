#include<bits/stdc++.h>
using namespace std;
const long long int RANGE = 30000000000000 ;

long long int get_cost(vector<vector<long long int>>&arr , int len)
{
    long long int cost = 0 , cnt = arr[1].size();
    vector<long long int>extra;
    
    for(int i=2;i<arr.size();i++)
    {
        int j = 0 ;
        while(arr[i].size()-j>=len)
        {
            cost+=arr[i][j];
            cnt++;
            j++;
        }
        while(j<arr[i].size())
        {
            extra.push_back(arr[i][j]);
            j++;
        }
    }
    
    sort(extra.begin(),extra.end());
    for(int i=0;i<extra.size();i++)
    {
        if(cnt>=len)
            break;
        cost+=extra[i];
        cnt++;
    }
    //cout<<cnt<<" "<<len<<endl;
    if(cnt<len)
        return RANGE;
    return cost;
}

int main()
{
    int voter , party ;
    cin>>voter>>party;
    
    vector<vector<long long int>>arr(party+1);
    
    int x , y ;
    for(int i=0;i<voter;i++)
    {
        cin>>x>>y;
        arr[x].push_back(y);
    }
    for(int i=1;i<=party;i++)
        sort(arr[i].begin(),arr[i].end());
        
    long long int min_cost = RANGE ;
    
    for(int i=1;i<=voter;i++)
    {
        min_cost = min( min_cost , get_cost(arr,i));
    }
    
    cout<<min_cost;
    
    return 0;
}
