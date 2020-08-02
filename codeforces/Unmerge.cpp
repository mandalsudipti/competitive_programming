#include<bits/stdc++.h>
using namespace std;

void subset_sum(vector<int>segment , int sum)
{
    vector<vector<int>>grid(2,vector<int>(sum+1,0));
    int idx ;
    grid[0][0] = 1;
    grid[1][0] = 1 ;
    for(int i=0;i<segment.size();i++)
    {
        i%2==0 ? idx = 0 : idx = 1 ;
        
        if(i==0)
        {
            if(segment[i]<=sum)
                grid[idx][segment[i]] = 1 ;
            continue;
        }
        
        for(int j=1;j<=sum;j++)
        {
            if(j<segment[i])
                grid[idx][j] = grid[(idx+1)%2][j] ;
            else
                grid[idx][j] = (grid[(idx+1)%2][j] || grid[(idx+1)%2][j - segment[i]]);
        }
    }
    
    if((segment.size()-1)%2==0 && grid[0][sum]==1)
        cout<<"YES"<<endl;
    else if((segment.size() - 1)%2==1 && grid[1][sum]==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        //cout<<"test case -> "<<T<<endl;
        int n ;
        cin>>n;
        vector<int>arr(2*n);
        vector<int>local_max(2*n,0);
        for(int i=0;i<2*n;i++)
            cin>>arr[i];
            
        local_max[0] = arr[0];
        for(int i=1;i<2*n;i++)
            local_max[i] = max(local_max[i-1],arr[i]);
        
        vector<int>segment ;
        int start = 0 , end = 0 ;
        for(int i=1;i<2*n;i++)
        {
            if(local_max[i]==local_max[start])
                end++;
            if(local_max[i]!=local_max[start] || i==2*n-1)
            {
                segment.push_back(end-start+1);
                start = end = i ;
            }
        }
        subset_sum(segment , n) ;
    }
    return 0;
}


