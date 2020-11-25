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
        
        vector<pair<int,int>>segment ;
        int start = -1 , end = -1 ;
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 1)
            {
                if(start==-1)
                    start = end = i ;
                else 
                    end = i ;
            }
            if(arr[i]==0 || i==n-1)
            {
                if(start!=-1)
                {
                    segment.push_back(make_pair(start , end ));
                    start = end = -1 ;
                }
            }
        }
        
        int sum = 0 ;
        if(segment.size()<=1)
        {
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0;i<segment.size()-1;i++)
        {
            sum+=(segment[i+1].first - segment[i].second - 1);
        }
        cout<<sum<<endl;
    }
    
    return 0;
}