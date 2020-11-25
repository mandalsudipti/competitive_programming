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
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        vector<int>segment ;
        int start = 0 , end = 0 ;
        for(int i=1;i<n;i++)
        {
            if(arr[i] == arr[start])
                end = i ;
            else
            {
                segment.push_back(arr[start]) ;
                start = end = i ;
            }
        }
        
        segment.push_back(arr[start]);
        
        int min_op = INT_MAX  , left = segment[0] , right = segment.back();
        map<int,int>freq ;
        
        if(segment.size() == 1)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<segment.size();i++)
        {
            freq[segment[i]]++;
        }
        
        for(auto itr = freq.begin() ; itr!=freq.end() ; ++itr)
        {
            int tmp = itr->second ;
            if(itr->first == left)
                tmp--;
            if(itr->first == right)
                tmp--;
                
            min_op = min(min_op , tmp + 1);
        }
        
        cout<<min_op<<endl;
    }
    
    return 0;
}