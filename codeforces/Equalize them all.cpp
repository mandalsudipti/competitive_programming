#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n);
    map<int,vector<int>>occur ;
    
    int max_freq = -1 ;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        occur[arr[i]].push_back(i);
        if(i == 0)
            max_freq = arr[0];
        else if( occur[max_freq].size() < occur[arr[i]].size())
            max_freq = arr[i];
            
    }
    
    vector<int>type;
    vector<pair<int,int>>idx;
    for(int i = 0 ; i < occur[max_freq].size() ; i++)
    {
        int start = occur[max_freq][i] ;
        while(start - 1 >= 0 && arr[start - 1]!= max_freq)
        {
            if(arr[start - 1] > arr[start])
            {
                type.push_back(2);
            }
            else
            {
                type.push_back(1);
            }
            arr[start-1] = arr[start];
            idx.push_back(make_pair(start-1 , start));
            start--;
        }
    }
    
    if(occur[max_freq].back() != n-1)
    {
        for(int i = occur[max_freq].back() ; i < n-1 ; i++)
        {
            if(arr[i+1] > arr[i])
            {
                type.push_back(2);
            }
            else
            {
                type.push_back(1);
            }
            arr[i+1] = arr[i];
            idx.push_back(make_pair(i+1,i));
        }
    }
    
    cout<<type.size()<<endl;
    for(int i=0;i<type.size();i++)
        cout<<type[i]<<" "<<idx[i].first+1<<" "<<idx[i].second+1<<endl;
        
    return 0 ;
}

