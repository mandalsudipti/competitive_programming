#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , m ;
        cin>>n>>m;
        
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++)
            cin>>arr[i];
            
        int last_mismatch = 0 ;
        for(int i=1;i<=n;i++)
        {
            if(arr[i]!=i)
                last_mismatch = i ;
        }
        
        double failure  = 1 ;
        if(last_mismatch == 0)
            failure = 0 ;
            
        while(m--)
        {
            int range ;
            double probaility ;
            cin>>range>>probaility;
            probaility  = 1 - probaility ;
            if(range >= last_mismatch)
                failure = failure * probaility ;
            
        }
        
        cout<<fixed<<setprecision(6)<<(1 - failure)<<endl;
    }
    
    return 0;
}
