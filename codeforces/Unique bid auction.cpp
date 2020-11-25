#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>arr(n);
        map<int,int>freq;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            freq[arr[i]]++;
        }
        
        int minimum = INT_MAX ;
        for(auto itr= freq.begin() ; itr!= freq.end() ; ++itr)
        {
            if(itr->second == 1 && itr->first < minimum)
                minimum = itr->first ;
        }
        
        if(minimum == INT_MAX)
            cout<<"-1"<<endl;
        else
        {
            int idx = -2;
            for(int i=0;i<n;i++)
            {
                if(arr[i] == minimum)
                {
                    idx = i ;
                    break;
                }
            }
            cout<<idx+1<<endl;
        }
    }
    
    return 0;
}