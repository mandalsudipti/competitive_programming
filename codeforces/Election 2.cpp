#include<bits/stdc++.h>
using namespace std;

bool sort_by_first(const pair<int,int>&A , const pair<int,int>&B)
{
    return A.first > B.first ;
}

int main()
{
    int candidate , polling_station ;
    cin>>candidate>>polling_station;
    
    vector<vector<int>>arr(polling_station,vector<int>(candidate));
    
    for(int i=0;i<polling_station;i++)
    {
        for(int j=0;j<candidate;j++)
            cin>>arr[i][j];
    }
    
    vector<vector<int>>remove_station(candidate);
    for(int i=0;i<candidate-1;i++)
    {
        vector<pair<int,int>>tmp;
        for(int j=0;j<polling_station;j++)
            tmp.push_back( make_pair(arr[j][i]-arr[j][candidate-1],j) );
            
        sort(tmp.begin(),tmp.end(),sort_by_first);
        long long int sum = 0 , j;
        for(j=0;j<tmp.size();j++)
        {
            if(sum+tmp[j].first>=0)
                sum+=tmp[j].first;
            else
                break;
        }
        while(j<tmp.size())
        {
            remove_station[i].push_back(tmp[j].second);
            j++;
        }
    }
    
    int minimum_idx = 0 ;
    for(int i=1;i<candidate-1;i++)
    {
        if(remove_station[i].size()<remove_station[minimum_idx].size())
            minimum_idx = i ;
    }
    
    cout<<remove_station[minimum_idx].size()<<endl;
    for(int i=0;i<remove_station[minimum_idx].size();i++)
        cout<<remove_station[minimum_idx][i]+1<<" ";
        
    return 0;
}
