#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<long long int>A(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(i>0)
            A[i]+=A[i-1];
    }
    
    int m;
    cin>>m;
    vector<long long int>B(m);
    for(int i=0;i<m;i++)
    {
        cin>>B[i];
        if(i > 0)
            B[i]+=B[i-1];
    }
    if(A.back()!=B.back())
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    int cnt = 0 ;
    int idx1 = 0 , idx2 = 0 ;
    while(idx1 < A.size() && idx2 < B.size())
    {
        if(A[idx1] == B[idx2])
        {
            cnt++;
            idx1++;
            idx2++;
        }
        else if(A[idx1] > B[idx2])
            idx2++;
        else
            idx1++;
    }
    
    
    cout<<cnt<<endl;
    
    return 0;
}
