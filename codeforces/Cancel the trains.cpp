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
        vector<int>A(n);
        vector<int>B(m);
        
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<m;i++)
            cin>>B[i];
            
        int idx1 = 0 , idx2 = 0 , cnt = 0;
        while(idx1 < n && idx2 < m)
        {
            if(A[idx1] == B[idx2])
            {
                cnt++;
                idx1++;
                idx2++;
            }
            else if(A[idx1] < B[idx2])
                idx1++;
            else
                idx2++;
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}