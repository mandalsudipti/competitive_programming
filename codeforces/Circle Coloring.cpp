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
        vector<int>A(n);
        vector<int>B(n);
        vector<int>C(n);
        
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<n;i++)
            cin>>B[i];
        for(int i=0;i<n;i++)
            cin>>C[i];
            
        vector<int>ans(n);
        ans[0] = A[0] ;
        for(int i=1;i<n-1;i++)
        {
            if(A[i]!=ans[i-1])
                ans[i] = A[i] ;
            else
                ans[i] = B[i] ;
        }
        
        if(A[n-1]!=ans[n-2] && A[n-1]!=ans[0])
            ans[n-1] = A[n-1];
        else if(B[n-1]!=ans[n-2] && B[n-1]!=ans[0])
            ans[n-1] = B[n-1];
        else
            ans[n-1] = C[n-1];
            
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}
