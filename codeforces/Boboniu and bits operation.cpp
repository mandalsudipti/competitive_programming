#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m ;
    cin>>n>>m;
    vector<long long int>A(n);
    vector<long long int>B(m);
    
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<m;i++)
        cin>>B[i];
        
    int ans = 0 ;
    bool possible ;
    for(int i=0;i<=512;i++)
    {
        possible  = true ;
        for(int j=0;j<n;j++)
        {
            possible = false ;
            for(int k=0;k<m;k++)
            {
                if(((A[j]&B[k])|i) == i)
                {
                    
                    possible = true ;
                    break;
                }
            }
            if(!possible)
                break;
        }
        if(possible)
        {
            ans = i ;
            break;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
