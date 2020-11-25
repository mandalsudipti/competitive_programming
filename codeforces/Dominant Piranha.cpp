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
        int maximum = 0 ;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            maximum = max( maximum , arr[i]);
        }
        
        int freq = 0 , idx = -1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==maximum)
            {
                freq++;
                if((i>0 && arr[i-1]<maximum) || (i<n-1 && arr[i+1]<maximum))
                    idx = i ;
            }
        }
        
        if(freq == n)
            cout<<"-1"<<endl;
        else
            cout<<idx + 1 <<endl;
    }
    
    return 0;
}